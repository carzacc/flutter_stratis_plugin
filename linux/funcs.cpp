#include "overloads.h"
#include <dbus-1.0/dbus/dbus.h>
#include <flutter/standard_method_codec.h>

#include <string>


namespace funcs {
    std::string createPoolOld(std::unique_ptr<flutter::EncodableValue> args) {
        flutter::EncodableValue arguments = *args.get();
        DBusError dbus_error;
        DBusConnection * dbus_conn;
        DBusMessage * dbus_msg;
        DBusMessage * dbus_reply;
        const char * dbus_result;
        std::string to_return;

        

        // Initialize D-Bus error
        dbus_error_init(&dbus_error);
        dbus_conn = dbus_bus_get(DBUS_BUS_SYSTEM, &dbus_error);

        // Compose remote procedure call
        dbus_msg =
          dbus_message_new_method_call(
            "org.storage.stratis1",
            "/org/storage/stratis1",
            "org.storage.stratis1.Manager",
            "CreatePool"
          );

        // Invoke remote procedure call, block for response
        dbus_reply = dbus_connection_send_with_reply_and_block(dbus_conn, dbus_msg, DBUS_TIMEOUT_USE_DEFAULT, &dbus_error);

        // Parse response
        dbus_message_get_args(dbus_reply, &dbus_error, DBUS_TYPE_STRING, &dbus_result, DBUS_TYPE_INVALID);

        // Work with the results of the remote procedure call
        to_return = dbus_result;
        dbus_message_unref(dbus_msg);
        dbus_message_unref(dbus_reply);

        /*
        * Applications must not close shared connections -
        * see dbus_connection_close() docs. This is a bug in the application.
        */
        //::dbus_connection_close(dbus_conn);

        // When using the System Bus, unreference
        // the connection instead of closing it
        dbus_connection_unref(dbus_conn);

        return to_return;
    }

    DBus::BusDispatcher dispatcher;

    std::map< ::DBus::Path, std::map< std::string, std::map< std::string, ::DBus::Variant > > > get_managed_objects() {
        DBus::default_dispatcher = &dispatcher;
        DBus::Connection bus = DBus::Connection::SessionBus();

        overloads::ObjectManager object_manager(bus, "/org/storage/stratis1", "org.storage.stratis1.Manager");

        return object_manager.GetManagedObjects();
    }

    void createPool(std::unique_ptr<flutter::EncodableValue> args) {
        flutter::EncodableValue arguments = *args.get();

        std::string pool_name;
        const DBus::Struct<bool, uint16_t> &redundancy = {
            true, 2
        };

        DBus::default_dispatcher = &dispatcher;
        DBus::Connection bus = DBus::Connection::SessionBus();
        std::vector<std::string> blockdevs;

        overloads::Manager manager(bus, "/org/storage/stratis1", "org.storage.stratis1.Manager");

        manager.CreatePool(pool_name, redundancy, blockdevs, ...); // TODO: continue

        return object_manager.GetManagedObjects();
    }

}