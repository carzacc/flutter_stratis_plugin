#ifndef OVERLOADS_H
#define OVERLOADS_H
#include "proxy.h"

namespace overloads {

class ObjectManager : public org::freedesktop::DBus::ObjectManager_proxy,
        public DBus::IntrospectableProxy,
        public DBus::ObjectProxy
{
public:
    ObjectManager(DBus::Connection &connection, const char *path, const char *name):
    DBus::ObjectProxy(connection, path, name)
    {
    }
};


class Manager : public org::storage::stratis1::Manager_proxy,
        public DBus::IntrospectableProxy,
        public DBus::ObjectProxy
{
public:
    Manager(DBus::Connection &connection, const char *path, const char *name):
    DBus::ObjectProxy(connection, path, name)
    {
    }
};

class pool : public org::storage::stratis1::pool_proxy,
        public DBus::IntrospectableProxy,
        public DBus::ObjectProxy
{
public:
    pool(DBus::Connection &connection, const char *path, const char *name):
    DBus::ObjectProxy(connection, path, name)
    {
    }
};

class filesystem : public org::storage::stratis1::filesystem_proxy,
        public DBus::IntrospectableProxy,
        public DBus::ObjectProxy
{
public:
    filesystem(DBus::Connection &connection, const char *path, const char *name):
    DBus::ObjectProxy(connection, path, name)
    {
    }
};

class blockdev : public org::storage::stratis1::blockdev_proxy,
        public DBus::IntrospectableProxy,
        public DBus::ObjectProxy
{
public:
    blockdev(DBus::Connection &connection, const char *path, const char *name):
    DBus::ObjectProxy(connection, path, name)
    {
    }
};


}
#endif /* OVERLOADS_H */