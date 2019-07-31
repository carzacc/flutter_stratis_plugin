
/*
 *	This file was automatically generated by dbusxx-xml2cpp; DO NOT EDIT!
 */

#ifndef __dbusxx__adaptor_h__ADAPTOR_MARSHAL_H
#define __dbusxx__adaptor_h__ADAPTOR_MARSHAL_H

#include <dbus-c++/dbus.h>
#include <cassert>

namespace org {
namespace freedesktop {
namespace DBus {

class ObjectManager_adaptor
: public ::DBus::InterfaceAdaptor
{
public:

    ObjectManager_adaptor()
    : ::DBus::InterfaceAdaptor("org.freedesktop.DBus.ObjectManager")
    {
        register_method(ObjectManager_adaptor, GetManagedObjects, _GetManagedObjects_stub);
    }

    ::DBus::IntrospectedInterface *introspect() const 
    {
        static ::DBus::IntrospectedArgument GetManagedObjects_args[] = 
        {
            { "objpath_interfaces_and_properties", "a{oa{sa{sv}}}", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedMethod ObjectManager_adaptor_methods[] = 
        {
            { "GetManagedObjects", GetManagedObjects_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedMethod ObjectManager_adaptor_signals[] = 
        {
            { 0, 0 }
        };
        static ::DBus::IntrospectedProperty ObjectManager_adaptor_properties[] = 
        {
            { 0, 0, 0, 0 }
        };
        static ::DBus::IntrospectedInterface ObjectManager_adaptor_interface = 
        {
            "org.freedesktop.DBus.ObjectManager",
            ObjectManager_adaptor_methods,
            ObjectManager_adaptor_signals,
            ObjectManager_adaptor_properties
        };
        return &ObjectManager_adaptor_interface;
    }

public:

    /* properties exposed by this interface, use
     * property() and property(value) to get and set a particular property
     */

public:

    /* methods exported by this interface,
     * you will have to implement them in your ObjectAdaptor
     */
    virtual std::map< ::DBus::Path, std::map< std::string, std::map< std::string, ::DBus::Variant > > > GetManagedObjects() = 0;

public:

    /* signal emitters for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual interface method)
     */
    ::DBus::Message _GetManagedObjects_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::map< ::DBus::Path, std::map< std::string, std::map< std::string, ::DBus::Variant > > > argout1 = GetManagedObjects();
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        return reply;
    }
};

} } } 
namespace org {
namespace storage {
namespace stratis1 {

class Manager_adaptor
: public ::DBus::InterfaceAdaptor
{
public:

    Manager_adaptor()
    : ::DBus::InterfaceAdaptor("org.storage.stratis1.Manager")
    {
        bind_property(Version, "s", true, false);
        register_method(Manager_adaptor, ConfigureSimulator, _ConfigureSimulator_stub);
        register_method(Manager_adaptor, CreatePool, _CreatePool_stub);
        register_method(Manager_adaptor, DestroyPool, _DestroyPool_stub);
    }

    ::DBus::IntrospectedInterface *introspect() const 
    {
        static ::DBus::IntrospectedArgument ConfigureSimulator_args[] = 
        {
            { "denominator", "u", true },
            { "return_code", "q", false },
            { "return_string", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument CreatePool_args[] = 
        {
            { "name", "s", true },
            { "redundancy", "(bq)", true },
            { "devices", "as", true },
            { "result", "(oao)", false },
            { "return_code", "q", false },
            { "return_string", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument DestroyPool_args[] = 
        {
            { "pool", "o", true },
            { "action", "b", false },
            { "return_code", "q", false },
            { "return_string", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedMethod Manager_adaptor_methods[] = 
        {
            { "ConfigureSimulator", ConfigureSimulator_args },
            { "CreatePool", CreatePool_args },
            { "DestroyPool", DestroyPool_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedMethod Manager_adaptor_signals[] = 
        {
            { 0, 0 }
        };
        static ::DBus::IntrospectedProperty Manager_adaptor_properties[] = 
        {
            { "Version", "s", true, false },
            { 0, 0, 0, 0 }
        };
        static ::DBus::IntrospectedInterface Manager_adaptor_interface = 
        {
            "org.storage.stratis1.Manager",
            Manager_adaptor_methods,
            Manager_adaptor_signals,
            Manager_adaptor_properties
        };
        return &Manager_adaptor_interface;
    }

public:

    /* properties exposed by this interface, use
     * property() and property(value) to get and set a particular property
     */
    ::DBus::PropertyAdaptor< std::string > Version;

public:

    /* methods exported by this interface,
     * you will have to implement them in your ObjectAdaptor
     */
    virtual void ConfigureSimulator(const uint32_t& denominator, uint16_t& return_code, std::string& return_string) = 0;
    virtual void CreatePool(const std::string& name, const ::DBus::Struct< bool, uint16_t >& redundancy, const std::vector< std::string >& devices, ::DBus::Struct< ::DBus::Path, std::vector< ::DBus::Path > >& result, uint16_t& return_code, std::string& return_string) = 0;
    virtual void DestroyPool(const ::DBus::Path& pool, bool& action, uint16_t& return_code, std::string& return_string) = 0;

public:

    /* signal emitters for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual interface method)
     */
    ::DBus::Message _ConfigureSimulator_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        uint32_t argin1; ri >> argin1;
        uint16_t argout1;
        std::string argout2;
        ConfigureSimulator(argin1, argout1, argout2);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        wi << argout2;
        return reply;
    }
    ::DBus::Message _CreatePool_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        ::DBus::Struct< bool, uint16_t > argin2; ri >> argin2;
        std::vector< std::string > argin3; ri >> argin3;
        ::DBus::Struct< ::DBus::Path, std::vector< ::DBus::Path > > argout1;
        uint16_t argout2;
        std::string argout3;
        CreatePool(argin1, argin2, argin3, argout1, argout2, argout3);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        wi << argout2;
        wi << argout3;
        return reply;
    }
    ::DBus::Message _DestroyPool_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        ::DBus::Path argin1; ri >> argin1;
        bool argout1;
        uint16_t argout2;
        std::string argout3;
        DestroyPool(argin1, argout1, argout2, argout3);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        wi << argout2;
        wi << argout3;
        return reply;
    }
};

} } } 
namespace org {
namespace storage {
namespace stratis1 {

class pool_adaptor
: public ::DBus::InterfaceAdaptor
{
public:

    pool_adaptor()
    : ::DBus::InterfaceAdaptor("org.storage.stratis1.pool")
    {
        bind_property(Name, "s", true, false);
        bind_property(TotalPhysicalSize, "s", true, false);
        bind_property(TotalPhysicalUsed, "s", true, false);
        bind_property(Uuid, "s", true, false);
        bind_property(State, "q", true, false);
        bind_property(ExtendState, "q", true, false);
        bind_property(SpaceState, "q", true, false);
        register_method(pool_adaptor, AddCacheDevs, _AddCacheDevs_stub);
        register_method(pool_adaptor, AddDataDevs, _AddDataDevs_stub);
        register_method(pool_adaptor, CreateFilesystems, _CreateFilesystems_stub);
        register_method(pool_adaptor, DestroyFilesystems, _DestroyFilesystems_stub);
        register_method(pool_adaptor, SetName, _SetName_stub);
        register_method(pool_adaptor, SnapshotFilesystem, _SnapshotFilesystem_stub);
    }

    ::DBus::IntrospectedInterface *introspect() const 
    {
        static ::DBus::IntrospectedArgument AddCacheDevs_args[] = 
        {
            { "devices", "as", true },
            { "results", "ao", false },
            { "return_code", "q", false },
            { "return_string", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument AddDataDevs_args[] = 
        {
            { "devices", "as", true },
            { "results", "ao", false },
            { "return_code", "q", false },
            { "return_string", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument CreateFilesystems_args[] = 
        {
            { "specs", "as", true },
            { "filesystems", "a(os)", false },
            { "return_code", "q", false },
            { "return_string", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument DestroyFilesystems_args[] = 
        {
            { "filesystems", "ao", true },
            { "results", "as", false },
            { "return_code", "q", false },
            { "return_string", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument SetName_args[] = 
        {
            { "name", "s", true },
            { "action", "b", false },
            { "return_code", "q", false },
            { "return_string", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument SnapshotFilesystem_args[] = 
        {
            { "origin", "o", true },
            { "snapshot_name", "s", true },
            { "result", "o", false },
            { "return_code", "q", false },
            { "return_string", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedMethod pool_adaptor_methods[] = 
        {
            { "AddCacheDevs", AddCacheDevs_args },
            { "AddDataDevs", AddDataDevs_args },
            { "CreateFilesystems", CreateFilesystems_args },
            { "DestroyFilesystems", DestroyFilesystems_args },
            { "SetName", SetName_args },
            { "SnapshotFilesystem", SnapshotFilesystem_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedMethod pool_adaptor_signals[] = 
        {
            { 0, 0 }
        };
        static ::DBus::IntrospectedProperty pool_adaptor_properties[] = 
        {
            { "Name", "s", true, false },
            { "TotalPhysicalSize", "s", true, false },
            { "TotalPhysicalUsed", "s", true, false },
            { "Uuid", "s", true, false },
            { "State", "q", true, false },
            { "ExtendState", "q", true, false },
            { "SpaceState", "q", true, false },
            { 0, 0, 0, 0 }
        };
        static ::DBus::IntrospectedInterface pool_adaptor_interface = 
        {
            "org.storage.stratis1.pool",
            pool_adaptor_methods,
            pool_adaptor_signals,
            pool_adaptor_properties
        };
        return &pool_adaptor_interface;
    }

public:

    /* properties exposed by this interface, use
     * property() and property(value) to get and set a particular property
     */
    ::DBus::PropertyAdaptor< std::string > Name;
    ::DBus::PropertyAdaptor< std::string > TotalPhysicalSize;
    ::DBus::PropertyAdaptor< std::string > TotalPhysicalUsed;
    ::DBus::PropertyAdaptor< std::string > Uuid;
    ::DBus::PropertyAdaptor< uint16_t > State;
    ::DBus::PropertyAdaptor< uint16_t > ExtendState;
    ::DBus::PropertyAdaptor< uint16_t > SpaceState;

public:

    /* methods exported by this interface,
     * you will have to implement them in your ObjectAdaptor
     */
    virtual void AddCacheDevs(const std::vector< std::string >& devices, std::vector< ::DBus::Path >& results, uint16_t& return_code, std::string& return_string) = 0;
    virtual void AddDataDevs(const std::vector< std::string >& devices, std::vector< ::DBus::Path >& results, uint16_t& return_code, std::string& return_string) = 0;
    virtual void CreateFilesystems(const std::vector< std::string >& specs, std::vector< ::DBus::Struct< ::DBus::Path, std::string > >& filesystems, uint16_t& return_code, std::string& return_string) = 0;
    virtual void DestroyFilesystems(const std::vector< ::DBus::Path >& filesystems, std::vector< std::string >& results, uint16_t& return_code, std::string& return_string) = 0;
    virtual void SetName(const std::string& name, bool& action, uint16_t& return_code, std::string& return_string) = 0;
    virtual void SnapshotFilesystem(const ::DBus::Path& origin, const std::string& snapshot_name, ::DBus::Path& result, uint16_t& return_code, std::string& return_string) = 0;

public:

    /* signal emitters for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual interface method)
     */
    ::DBus::Message _AddCacheDevs_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::vector< std::string > argin1; ri >> argin1;
        std::vector< ::DBus::Path > argout1;
        uint16_t argout2;
        std::string argout3;
        AddCacheDevs(argin1, argout1, argout2, argout3);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        wi << argout2;
        wi << argout3;
        return reply;
    }
    ::DBus::Message _AddDataDevs_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::vector< std::string > argin1; ri >> argin1;
        std::vector< ::DBus::Path > argout1;
        uint16_t argout2;
        std::string argout3;
        AddDataDevs(argin1, argout1, argout2, argout3);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        wi << argout2;
        wi << argout3;
        return reply;
    }
    ::DBus::Message _CreateFilesystems_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::vector< std::string > argin1; ri >> argin1;
        std::vector< ::DBus::Struct< ::DBus::Path, std::string > > argout1;
        uint16_t argout2;
        std::string argout3;
        CreateFilesystems(argin1, argout1, argout2, argout3);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        wi << argout2;
        wi << argout3;
        return reply;
    }
    ::DBus::Message _DestroyFilesystems_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::vector< ::DBus::Path > argin1; ri >> argin1;
        std::vector< std::string > argout1;
        uint16_t argout2;
        std::string argout3;
        DestroyFilesystems(argin1, argout1, argout2, argout3);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        wi << argout2;
        wi << argout3;
        return reply;
    }
    ::DBus::Message _SetName_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        bool argout1;
        uint16_t argout2;
        std::string argout3;
        SetName(argin1, argout1, argout2, argout3);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        wi << argout2;
        wi << argout3;
        return reply;
    }
    ::DBus::Message _SnapshotFilesystem_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        ::DBus::Path argin1; ri >> argin1;
        std::string argin2; ri >> argin2;
        ::DBus::Path argout1;
        uint16_t argout2;
        std::string argout3;
        SnapshotFilesystem(argin1, argin2, argout1, argout2, argout3);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        wi << argout2;
        wi << argout3;
        return reply;
    }
};

} } } 
namespace org {
namespace storage {
namespace stratis1 {

class filesystem_adaptor
: public ::DBus::InterfaceAdaptor
{
public:

    filesystem_adaptor()
    : ::DBus::InterfaceAdaptor("org.storage.stratis1.filesystem")
    {
        bind_property(Created, "s", true, false);
        bind_property(Devnode, "s", true, false);
        bind_property(Name, "s", true, false);
        bind_property(Pool, "o", true, false);
        bind_property(Used, "s", true, false);
        bind_property(Uuid, "s", true, false);
        register_method(filesystem_adaptor, SetName, _SetName_stub);
    }

    ::DBus::IntrospectedInterface *introspect() const 
    {
        static ::DBus::IntrospectedArgument SetName_args[] = 
        {
            { "name", "s", true },
            { "action", "b", false },
            { "return_code", "q", false },
            { "return_string", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedMethod filesystem_adaptor_methods[] = 
        {
            { "SetName", SetName_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedMethod filesystem_adaptor_signals[] = 
        {
            { 0, 0 }
        };
        static ::DBus::IntrospectedProperty filesystem_adaptor_properties[] = 
        {
            { "Created", "s", true, false },
            { "Devnode", "s", true, false },
            { "Name", "s", true, false },
            { "Pool", "o", true, false },
            { "Used", "s", true, false },
            { "Uuid", "s", true, false },
            { 0, 0, 0, 0 }
        };
        static ::DBus::IntrospectedInterface filesystem_adaptor_interface = 
        {
            "org.storage.stratis1.filesystem",
            filesystem_adaptor_methods,
            filesystem_adaptor_signals,
            filesystem_adaptor_properties
        };
        return &filesystem_adaptor_interface;
    }

public:

    /* properties exposed by this interface, use
     * property() and property(value) to get and set a particular property
     */
    ::DBus::PropertyAdaptor< std::string > Created;
    ::DBus::PropertyAdaptor< std::string > Devnode;
    ::DBus::PropertyAdaptor< std::string > Name;
    ::DBus::PropertyAdaptor< ::DBus::Path > Pool;
    ::DBus::PropertyAdaptor< std::string > Used;
    ::DBus::PropertyAdaptor< std::string > Uuid;

public:

    /* methods exported by this interface,
     * you will have to implement them in your ObjectAdaptor
     */
    virtual void SetName(const std::string& name, bool& action, uint16_t& return_code, std::string& return_string) = 0;

public:

    /* signal emitters for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual interface method)
     */
    ::DBus::Message _SetName_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        bool argout1;
        uint16_t argout2;
        std::string argout3;
        SetName(argin1, argout1, argout2, argout3);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        wi << argout2;
        wi << argout3;
        return reply;
    }
};

} } } 
namespace org {
namespace storage {
namespace stratis1 {

class blockdev_adaptor
: public ::DBus::InterfaceAdaptor
{
public:

    blockdev_adaptor()
    : ::DBus::InterfaceAdaptor("org.storage.stratis1.blockdev")
    {
        bind_property(Devnode, "s", true, false);
        bind_property(HardwareInfo, "s", true, false);
        bind_property(InitializationTime, "t", true, false);
        bind_property(Pool, "o", true, false);
        bind_property(State, "q", true, false);
        bind_property(Tier, "q", true, false);
        bind_property(TotalPhysicalSize, "s", true, false);
        bind_property(UserInfo, "s", true, false);
        bind_property(Uuid, "s", true, false);
        register_method(blockdev_adaptor, SetUserInfo, _SetUserInfo_stub);
    }

    ::DBus::IntrospectedInterface *introspect() const 
    {
        static ::DBus::IntrospectedArgument SetUserInfo_args[] = 
        {
            { "id", "s", true },
            { "changed", "b", false },
            { "return_code", "q", false },
            { "return_string", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedMethod blockdev_adaptor_methods[] = 
        {
            { "SetUserInfo", SetUserInfo_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedMethod blockdev_adaptor_signals[] = 
        {
            { 0, 0 }
        };
        static ::DBus::IntrospectedProperty blockdev_adaptor_properties[] = 
        {
            { "Devnode", "s", true, false },
            { "HardwareInfo", "s", true, false },
            { "InitializationTime", "t", true, false },
            { "Pool", "o", true, false },
            { "State", "q", true, false },
            { "Tier", "q", true, false },
            { "TotalPhysicalSize", "s", true, false },
            { "UserInfo", "s", true, false },
            { "Uuid", "s", true, false },
            { 0, 0, 0, 0 }
        };
        static ::DBus::IntrospectedInterface blockdev_adaptor_interface = 
        {
            "org.storage.stratis1.blockdev",
            blockdev_adaptor_methods,
            blockdev_adaptor_signals,
            blockdev_adaptor_properties
        };
        return &blockdev_adaptor_interface;
    }

public:

    /* properties exposed by this interface, use
     * property() and property(value) to get and set a particular property
     */
    ::DBus::PropertyAdaptor< std::string > Devnode;
    ::DBus::PropertyAdaptor< std::string > HardwareInfo;
    ::DBus::PropertyAdaptor< uint64_t > InitializationTime;
    ::DBus::PropertyAdaptor< ::DBus::Path > Pool;
    ::DBus::PropertyAdaptor< uint16_t > State;
    ::DBus::PropertyAdaptor< uint16_t > Tier;
    ::DBus::PropertyAdaptor< std::string > TotalPhysicalSize;
    ::DBus::PropertyAdaptor< std::string > UserInfo;
    ::DBus::PropertyAdaptor< std::string > Uuid;

public:

    /* methods exported by this interface,
     * you will have to implement them in your ObjectAdaptor
     */
    virtual void SetUserInfo(const std::string& id, bool& changed, uint16_t& return_code, std::string& return_string) = 0;

public:

    /* signal emitters for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual interface method)
     */
    ::DBus::Message _SetUserInfo_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        bool argout1;
        uint16_t argout2;
        std::string argout3;
        SetUserInfo(argin1, argout1, argout2, argout3);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        wi << argout2;
        wi << argout3;
        return reply;
    }
};

} } } 
#endif //__dbusxx__adaptor_h__ADAPTOR_MARSHAL_H
