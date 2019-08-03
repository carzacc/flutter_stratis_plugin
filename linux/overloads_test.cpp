#include "overloads.h"
#include <dbus/dbus.h>

#include <string>
#include <iostream>

std::string create_pool() {
        DBus::BusDispatcher dispatcher = DBus::BusDispatcher();
        DBus::default_dispatcher = &dispatcher;
        DBus::Connection bus = DBus::Connection::SystemBus();

       
        std::string pool_name = std::string("mypol");
        std::vector<std::string> blockdevs;
        
        blockdevs.push_back(std::string("/dev/example1"));

        const DBus::Struct<bool, uint16_t> &redundancy = {
            true, 0
        };

        
        
        DBus::Struct<DBus::Path, std::vector<DBus::Path> > result;
        uint16_t return_code;
        std::string return_string;

        overloads::Manager manager = overloads::Manager(bus, "/org/storage/stratis1", "org.storage.stratis1");
        manager.CreatePool(pool_name, redundancy, blockdevs, result, return_code, return_string); 
       

        return return_string;

    }

std::string get_version() {
    DBus::BusDispatcher dispatcher = DBus::BusDispatcher();
    DBus::default_dispatcher = &dispatcher;
    DBus::Connection bus = DBus::Connection::SystemBus();

    overloads::Manager manager = overloads::Manager(bus, "/org/storage/stratis1", "org.storage.stratis1");

    return manager.Version();

}

int main(void) {    
    std::cout << create_pool() << std::endl;
}