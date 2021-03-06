/*
   Copyright 2019 Carmine Zaccagnino

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
  limitations under the License.
*/

#include "overloads.h"
#include "funcs.h"
#include <dbus/dbus.h>
#include <flutter/standard_method_codec.h>

#include <iostream>
#include <string>


namespace funcs {
std::string get_version() {
    DBus::BusDispatcher dispatcher = DBus::BusDispatcher();
    DBus::default_dispatcher = &dispatcher;
    DBus::Connection bus = DBus::Connection::SystemBus();

    overloads::Manager manager = overloads::Manager(bus, "/org/storage/stratis1", "org.storage.stratis1");

    return manager.Version();
}


std::map< ::DBus::Path, std::map< std::string, std::map< std::string, ::DBus::Variant > > > get_managed_objects() {
    DBus::BusDispatcher dispatcher = DBus::BusDispatcher();
    DBus::default_dispatcher = &dispatcher;
    DBus::Connection bus = DBus::Connection::SystemBus();

    overloads::ObjectManager object_manager(bus, "/org/storage/stratis1", "org.storage.stratis1");

    return object_manager.GetManagedObjects();
}

std::vector<Filesystem_data> get_filesystems() {
    auto managed_objects = get_managed_objects();

    std::vector<Filesystem_data> list;

    for(auto el : managed_objects) {
        for(auto ell: el.second) {
            if(ell.first.compare("org.storage.stratis1.filesystem") == 0) {
                Filesystem_data fs;
                fs.path  = el.first;
                fs.Created = ell.second["Created"].reader().get_string();
                fs.Devnode = ell.second["Devnode"].reader().get_string();
                fs.Name = ell.second["Name"].reader().get_string();
                fs.Pool = ell.second["Pool"].reader().get_path();
                fs.Used = ell.second["Used"].reader().get_string();
                fs.Uuid = ell.second["Uuid"].reader().get_string();
                list.push_back(fs);
            }
        }
    }
    return list;
}

std::vector<Blockdev_data> get_blockdevs() {
    auto managed_objects = get_managed_objects();

    std::vector<Blockdev_data> list;

    for(auto el : managed_objects) {
        for(auto ell: el.second) {
            if(ell.first.compare("org.storage.stratis1.blockdev") == 0) {
                Blockdev_data blockdev;
                blockdev.path  = el.first;
                blockdev.Devnode = ell.second["Devnode"].reader().get_string();
                blockdev.HardwareInfo = ell.second["HardwareInfo"].reader().get_string();
                blockdev.InitializationTime = ell.second["InitializationTime"].reader().get_uint64();
                blockdev.Pool = ell.second["Pool"].reader().get_path();
                blockdev.State = ell.second["State"].reader().get_uint16();
                blockdev.Tier = ell.second["Tier"].reader().get_uint16();
                blockdev.TotalPhysicalSize = ell.second["TotalPhysicalSize"].reader().get_string();
                blockdev.UserInfo = ell.second["UserInfo"].reader().get_string();
                blockdev.Uuid = ell.second["Uuid"].reader().get_string();
                list.push_back(blockdev);
            }
        }
    }
    return list;
}

std::vector<Pool_data> get_pools() {
    auto managed_objects = get_managed_objects();

    std::vector<Pool_data> list;

    for(auto el : managed_objects) {
        for(auto ell: el.second) {
            if(ell.first.compare("org.storage.stratis1.pool") == 0) {
                Pool_data pool;
                pool.path  = el.first;
                pool.ExtendState = ell.second["ExtendState"].reader().get_uint16();
                pool.Name = ell.second["Name"].reader().get_string();
                pool.SpaceState = ell.second["SpaceState"].reader().get_uint16();
                pool.State = ell.second["State"].reader().get_uint16();
                pool.TotalPhysicalSize = ell.second["TotalPhysicalSize"].reader().get_string();
                pool.TotalPhysicalUsed = ell.second["TotalPhysicalUsed"].reader().get_string();
                pool.Uuid = ell.second["Uuid"].reader().get_string();
                list.push_back(pool);
            }
        }
    }
    return list;
}


std::string destroy_pool(std::string pool_name) {
    DBus::BusDispatcher dispatcher = DBus::BusDispatcher();
    DBus::default_dispatcher = &dispatcher;
    DBus::Connection bus = DBus::Connection::SystemBus();
    overloads::Manager manager = overloads::Manager(bus, "/org/storage/stratis1", "org.storage.stratis1");
    bool action;
    uint16_t return_code;
    std::string return_string("Default");


    auto pools = get_pools();

    for(Pool_data pool_data : pools) {
        if(pool_data.Name.compare(pool_name) == 0) {
            manager.DestroyPool(pool_data.path, action, return_code, return_string);
        }
    }
    return return_string !=  "Default" ? return_string : "Error";
}
// overloads::pool pool(bus, pool_data.path.data, "org.storage.stratis1");
std::string create_pool(flutter::EncodableValue arguments) {
    flutter::EncodableMap args_map = arguments.MapValue();
    
    std::string pool_name = args_map[flutter::EncodableValue(std::string("name"))].StringValue();
    flutter::EncodableList blockdev_list_encoded = args_map[flutter::EncodableValue(std::string("blockdevs"))].ListValue();
    std::vector<std::string> blockdevs;
    for(size_t i = 0; i < blockdev_list_encoded.size(); i++) {
        blockdevs.push_back(
            blockdev_list_encoded[i].StringValue()
        );
    }

    const DBus::Struct<bool, uint16_t> &redundancy = {
        true, 0
    };
    
    DBus::BusDispatcher dispatcher = DBus::BusDispatcher();
    DBus::default_dispatcher = &dispatcher;
    DBus::Connection bus = DBus::Connection::SystemBus();
    
    DBus::Struct<DBus::Path, std::vector<DBus::Path> > result;
    uint16_t return_code;
    std::string return_string;

    overloads::Manager manager = overloads::Manager(bus, "/org/storage/stratis1", "org.storage.stratis1");
    manager.CreatePool(pool_name, redundancy, blockdevs, result, return_code, return_string); 

    return return_string;

}

int add_data_blockdevs(flutter::EncodableValue arguments) {
    flutter::EncodableMap args_map = arguments.MapValue();


    std::string pool_name = args_map[flutter::EncodableValue(std::string("pool_name"))].StringValue();
    flutter::EncodableList blockdev_list_encoded = args_map[flutter::EncodableValue(std::string("blockdevs"))].ListValue();

    std::vector<std::string> blockdevs;
    
    for(size_t i = 0; i < blockdev_list_encoded.size(); i++) {
        blockdevs.push_back(
            blockdev_list_encoded[i].StringValue()
        );
    }

    DBus::BusDispatcher dispatcher = DBus::BusDispatcher();
    DBus::default_dispatcher = &dispatcher;
    DBus::Connection bus = DBus::Connection::SystemBus();

    uint16_t return_code;
    std::vector<DBus::Path> returned_paths;
    std::string return_string;

    std::vector<Pool_data> pools = get_pools();
    std::string pool_path;

    for(Pool_data cur_pool : pools) {
        if(cur_pool.Name.compare(pool_name) == 0) {
            pool_path = cur_pool.path;
        } 
    }


    overloads::pool pool = overloads::pool(bus, pool_path.data(), "org.storage.stratis1");
    pool.AddDataDevs(blockdevs, returned_paths, return_code, return_string);

    return return_code;

}

int add_cache_blockdevs(flutter::EncodableValue arguments) {
    flutter::EncodableMap args_map = arguments.MapValue();


    std::string pool_name = args_map[flutter::EncodableValue(std::string("pool_name"))].StringValue();
    flutter::EncodableList blockdev_list_encoded = args_map[flutter::EncodableValue(std::string("blockdevs"))].ListValue();

    std::vector<std::string> blockdevs;
    
    for(size_t i = 0; i < blockdev_list_encoded.size(); i++) {
        blockdevs.push_back(
            blockdev_list_encoded[i].StringValue()
        );
    }

    DBus::BusDispatcher dispatcher = DBus::BusDispatcher();
    DBus::default_dispatcher = &dispatcher;
    DBus::Connection bus = DBus::Connection::SystemBus();

    uint16_t return_code;
    std::vector<DBus::Path> returned_paths;
    std::string return_string;

    std::vector<Pool_data> pools = get_pools();
    std::string pool_path;

    for(Pool_data cur_pool : pools) {
        if(cur_pool.Name.compare(pool_name) == 0) {
            pool_path = cur_pool.path;
        } 
    }


    overloads::pool pool = overloads::pool(bus, pool_path.data(), "org.storage.stratis1");
    pool.AddCacheDevs(blockdevs, returned_paths, return_code, return_string);

    return return_code;

}

int destroy_filesystems(flutter::EncodableValue arguments) {
    flutter::EncodableMap args_map = arguments.MapValue();


    std::string pool_name = args_map[flutter::EncodableValue(std::string("pool_name"))].StringValue();
    flutter::EncodableList fs_names_encoded = args_map[flutter::EncodableValue(std::string("fs_names"))].ListValue();

    std::vector<std::string> fs_names;
    
    for(size_t i = 0; i < fs_names_encoded.size(); i++) {
        fs_names.push_back(
            fs_names_encoded[i].StringValue()
        );
    }

    DBus::BusDispatcher dispatcher = DBus::BusDispatcher();
    DBus::default_dispatcher = &dispatcher;
    DBus::Connection bus = DBus::Connection::SystemBus();

    uint16_t return_code;
    std::vector<std::string> results;
    std::string return_string;

    std::vector<Pool_data> pools = get_pools();
    DBus::Path pool_path;

    for(Pool_data cur_pool : pools) {
        if(cur_pool.Name.compare(pool_name) == 0) {
            pool_path = cur_pool.path;
        } 
    }

    overloads::pool pool = overloads::pool(bus, pool_path.data(), "org.storage.stratis1");

    std::vector<Filesystem_data> filesystems = get_filesystems();
    std::vector<DBus::Path> fs_paths;

    for(Filesystem_data cur_fs : filesystems) {
        for(std::string fs_name : fs_names) {
            if(fs_name.compare(cur_fs.Name) == 0 && cur_fs.Pool.compare(pool.path()))
              fs_paths.push_back(cur_fs.path);
        } 
    }

    
    pool.DestroyFilesystems(fs_paths, results, return_code, return_string);

    return return_code;

}

int create_filesystems(flutter::EncodableValue arguments) {
    flutter::EncodableMap args_map = arguments.MapValue();


    std::string pool_name = args_map[flutter::EncodableValue(std::string("pool_name"))].StringValue();
    flutter::EncodableList fs_names_encoded = args_map[flutter::EncodableValue(std::string("fs_name"))].ListValue();

    std::vector<std::string> specs; // filesystem specs, currently just the names 
    
    for(size_t i = 0; i < fs_names_encoded.size(); i++) {
        specs.push_back(
            fs_names_encoded[i].StringValue()
        );
    }

    DBus::BusDispatcher dispatcher = DBus::BusDispatcher();
    DBus::default_dispatcher = &dispatcher;
    DBus::Connection bus = DBus::Connection::SystemBus();

    uint16_t return_code;
    std::vector< ::DBus::Struct< ::DBus::Path, std::string > > results;
    std::string return_string;

    std::vector<Pool_data> pools = get_pools();
    DBus::Path pool_path;

    for(Pool_data cur_pool : pools) {
        if(cur_pool.Name.compare(pool_name) == 0) {
            pool_path = cur_pool.path;
        } 
    }

    overloads::pool pool = overloads::pool(bus, pool_path.data(), "org.storage.stratis1");    
    pool.CreateFilesystems(specs, results, return_code, return_string);

    return return_code;

}

}
