#include "overloads.h"
#include <dbus-1.0/dbus/dbus.h>
#include <flutter/standard_method_codec.h>

#include <string>


namespace funcs {
    DBus::BusDispatcher dispatcher;
    DBus::Connection bus = DBus::Connection::SystemBus();

    overloads::Manager get_manager() {
        return overloads::Manager(bus, "/org/storage/stratis1", "org.storage.stratis1");
    }


    std::map< ::DBus::Path, std::map< std::string, std::map< std::string, ::DBus::Variant > > > get_managed_objects() {
        DBus::default_dispatcher = &dispatcher;

        overloads::ObjectManager object_manager(bus, "/org/storage/stratis1", "org.storage.stratis1.Manager");

        return object_manager.GetManagedObjects();
    }

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

        DBus::default_dispatcher = &dispatcher;
        
        DBus::Struct<DBus::Path, std::vector<DBus::Path> > result;
        uint16_t return_code;
        std::string return_string;

        overloads::Manager manager = get_manager();

        manager.CreatePool(pool_name, redundancy, blockdevs, result, return_code, return_string); 

        return return_string;

    }
}
