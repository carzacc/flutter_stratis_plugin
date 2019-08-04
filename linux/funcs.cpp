#include "overloads.h"
#include <dbus/dbus.h>
#include <flutter/standard_method_codec.h>

#include <iostream>
#include <string>

struct Filesystem_data {
    /*
    Example:
    {
        path:/org/storage/stratis1/4
        Created:2019-08-04T13:12:50Z
        Devnode:/stratis/mypool/fs1
        Name:fs1
        Pool:/org/storage/stratis1/1
        Used:12345678
        Uuid:f451fd274e0e4e5fb65591bd0db0b30d
    }
     */
    DBus::Path path;
    std::string Created;
    std::string Devnode;
    std::string Name;
    DBus::Path Pool;
    std::string Used;
    std::string Uuid;
};


struct Blockdev_data {
    /*
    Example:
    {
        path:/org/storage/stratis1/3
        Devnode:/dev/example1
        HardwareInfo:
        InitializationTime:1564920213
        Pool:/org/storage/stratis1/1
        State:4
        Tier:0
        TotalPhysicalSize:2097152
        UserInfo:
        Uuid:f7b52baf60a54b18b65c7497b4e869cc
    }
     */
    DBus::Path path;
    std::string Devnode;
    std::string HardwareInfo;
    uint64_t InitializationTime;
    DBus::Path Pool;
    uint16_t State;
    uint16_t Tier;
    std::string TotalPhysicalSize;
    std::string UserInfo;
    std::string Uuid;
};

struct Pool_data {
    /*
    Example:
    {
        path:/org/storage/stratis1/1
        ExtendedState:2
        Name:mypool
        SpaceState:1
        State:1
        TotalPhysicalSize:1152921504606846976
        TotalPhysicalUsed:0
        Uuid:44e18b08bef74755a5950525e75a71b1
    }
     */
    DBus::Path path;
    uint16_t ExtendState;
    std::string Name;
    uint16_t SpaceState;
    uint16_t State;
    std::string TotalPhysicalSize;
    std::string TotalPhysicalUsed;
    std::string Uuid;
};

struct StratisException : public std::exception
{
	const char * what () const throw ()
    {
    	return "Stratis exception";
    }
};

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
}
