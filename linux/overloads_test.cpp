#include "overloads.h"
#include <dbus-1.0/dbus/dbus.h>

#include <string>
#include <iostream>

DBus::BusDispatcher dispatcher;


std::string introspectManager() {
    DBus::default_dispatcher = &dispatcher;
    DBus::Connection bus = DBus::Connection::SystemBus();

    overloads::Manager manager(bus, "/org/storage/stratis1", "org.storage.stratis1");

    return manager.Introspect();
}

int main(void) {
    std::cout << introspectManager() << std::endl;
}