
/*
 *	This file was automatically generated by dbusxx-xml2cpp; DO NOT EDIT!
 */

#ifndef __dbusxx__proxy_h__PROXY_MARSHAL_H
#define __dbusxx__proxy_h__PROXY_MARSHAL_H

#include <dbus-c++/dbus.h>
#include <cassert>

namespace org {
namespace freedesktop {
namespace DBus {

class ObjectManager_proxy
: public ::DBus::InterfaceProxy
{
public:

    ObjectManager_proxy()
    : ::DBus::InterfaceProxy("org.freedesktop.DBus.ObjectManager")
    {
    }

public:

    /* properties exported by this interface */
public:

    /* methods exported by this interface,
     * this functions will invoke the corresponding methods on the remote objects
     */
    std::map< ::DBus::Path, std::map< std::string, std::map< std::string, ::DBus::Variant > > > GetManagedObjects()
    {
        ::DBus::CallMessage call;
        call.member("GetManagedObjects");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        std::map< ::DBus::Path, std::map< std::string, std::map< std::string, ::DBus::Variant > > > argout;
        ri >> argout;
        return argout;
    }


public:

    /* signal handlers for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual signal handler)
     */
};

} } } 
namespace org {
namespace storage {
namespace stratis1 {

class Manager_proxy
: public ::DBus::InterfaceProxy
{
public:

    Manager_proxy()
    : ::DBus::InterfaceProxy("org.storage.stratis1.Manager")
    {
    }

public:

    /* properties exported by this interface */
        const std::string Version() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.Manager";
            const std::string property_name  = "Version";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
public:

    /* methods exported by this interface,
     * this functions will invoke the corresponding methods on the remote objects
     */
    void ConfigureSimulator(const uint32_t& denominator, uint16_t& return_code, std::string& return_string)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << denominator;
        call.member("ConfigureSimulator");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        ri >> return_code;
        ri >> return_string;
    }

    void CreatePool(const std::string& name, const ::DBus::Struct< bool, uint16_t >& redundancy, const std::vector< std::string >& devices, ::DBus::Struct< ::DBus::Path, std::vector< ::DBus::Path > >& result, uint16_t& return_code, std::string& return_string)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << name;
        wi << redundancy;
        wi << devices;
        call.member("CreatePool");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        ri >> result;
        ri >> return_code;
        ri >> return_string;
    }

    void DestroyPool(const ::DBus::Path& pool, bool& action, uint16_t& return_code, std::string& return_string)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << pool;
        call.member("DestroyPool");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        ri >> action;
        ri >> return_code;
        ri >> return_string;
    }


public:

    /* signal handlers for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual signal handler)
     */
};

} } } 
namespace org {
namespace storage {
namespace stratis1 {

class pool_proxy
: public ::DBus::InterfaceProxy
{
public:

    pool_proxy()
    : ::DBus::InterfaceProxy("org.storage.stratis1.pool")
    {
    }

public:

    /* properties exported by this interface */
        const std::string Name() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.pool";
            const std::string property_name  = "Name";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const std::string TotalPhysicalSize() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.pool";
            const std::string property_name  = "TotalPhysicalSize";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const std::string TotalPhysicalUsed() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.pool";
            const std::string property_name  = "TotalPhysicalUsed";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const std::string Uuid() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.pool";
            const std::string property_name  = "Uuid";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const uint16_t State() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.pool";
            const std::string property_name  = "State";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const uint16_t ExtendState() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.pool";
            const std::string property_name  = "ExtendState";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const uint16_t SpaceState() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.pool";
            const std::string property_name  = "SpaceState";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
public:

    /* methods exported by this interface,
     * this functions will invoke the corresponding methods on the remote objects
     */
    void AddCacheDevs(const std::vector< std::string >& devices, std::vector< ::DBus::Path >& results, uint16_t& return_code, std::string& return_string)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << devices;
        call.member("AddCacheDevs");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        ri >> results;
        ri >> return_code;
        ri >> return_string;
    }

    void AddDataDevs(const std::vector< std::string >& devices, std::vector< ::DBus::Path >& results, uint16_t& return_code, std::string& return_string)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << devices;
        call.member("AddDataDevs");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        ri >> results;
        ri >> return_code;
        ri >> return_string;
    }

    void CreateFilesystems(const std::vector< std::string >& specs, std::vector< ::DBus::Struct< ::DBus::Path, std::string > >& filesystems, uint16_t& return_code, std::string& return_string)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << specs;
        call.member("CreateFilesystems");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        ri >> filesystems;
        ri >> return_code;
        ri >> return_string;
    }

    void DestroyFilesystems(const std::vector< ::DBus::Path >& filesystems, std::vector< std::string >& results, uint16_t& return_code, std::string& return_string)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << filesystems;
        call.member("DestroyFilesystems");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        ri >> results;
        ri >> return_code;
        ri >> return_string;
    }

    void SetName(const std::string& name, bool& action, uint16_t& return_code, std::string& return_string)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << name;
        call.member("SetName");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        ri >> action;
        ri >> return_code;
        ri >> return_string;
    }

    void SnapshotFilesystem(const ::DBus::Path& origin, const std::string& snapshot_name, ::DBus::Path& result, uint16_t& return_code, std::string& return_string)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << origin;
        wi << snapshot_name;
        call.member("SnapshotFilesystem");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        ri >> result;
        ri >> return_code;
        ri >> return_string;
    }


public:

    /* signal handlers for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual signal handler)
     */
};

} } } 
namespace org {
namespace storage {
namespace stratis1 {

class filesystem_proxy
: public ::DBus::InterfaceProxy
{
public:

    filesystem_proxy()
    : ::DBus::InterfaceProxy("org.storage.stratis1.filesystem")
    {
    }

public:

    /* properties exported by this interface */
        const std::string Created() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.filesystem";
            const std::string property_name  = "Created";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const std::string Devnode() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.filesystem";
            const std::string property_name  = "Devnode";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const std::string Name() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.filesystem";
            const std::string property_name  = "Name";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const ::DBus::Path Pool() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.filesystem";
            const std::string property_name  = "Pool";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const std::string Used() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.filesystem";
            const std::string property_name  = "Used";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const std::string Uuid() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.filesystem";
            const std::string property_name  = "Uuid";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
public:

    /* methods exported by this interface,
     * this functions will invoke the corresponding methods on the remote objects
     */
    void SetName(const std::string& name, bool& action, uint16_t& return_code, std::string& return_string)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << name;
        call.member("SetName");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        ri >> action;
        ri >> return_code;
        ri >> return_string;
    }


public:

    /* signal handlers for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual signal handler)
     */
};

} } } 
namespace org {
namespace storage {
namespace stratis1 {

class blockdev_proxy
: public ::DBus::InterfaceProxy
{
public:

    blockdev_proxy()
    : ::DBus::InterfaceProxy("org.storage.stratis1.blockdev")
    {
    }

public:

    /* properties exported by this interface */
        const std::string Devnode() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.blockdev";
            const std::string property_name  = "Devnode";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const std::string HardwareInfo() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.blockdev";
            const std::string property_name  = "HardwareInfo";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const uint64_t InitializationTime() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.blockdev";
            const std::string property_name  = "InitializationTime";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const ::DBus::Path Pool() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.blockdev";
            const std::string property_name  = "Pool";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const uint16_t State() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.blockdev";
            const std::string property_name  = "State";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const uint16_t Tier() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.blockdev";
            const std::string property_name  = "Tier";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const std::string TotalPhysicalSize() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.blockdev";
            const std::string property_name  = "TotalPhysicalSize";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const std::string UserInfo() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.blockdev";
            const std::string property_name  = "UserInfo";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
        const std::string Uuid() {
            ::DBus::CallMessage call ;
             call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
            ::DBus::MessageIter wi = call.writer(); 
            const std::string interface_name = "org.storage.stratis1.blockdev";
            const std::string property_name  = "Uuid";
            wi << interface_name;
            wi << property_name;
            ::DBus::Message ret = this->invoke_method (call);
            ::DBus::MessageIter ri = ret.reader ();
            ::DBus::Variant argout; 
            ri >> argout;
            return argout;
        };
public:

    /* methods exported by this interface,
     * this functions will invoke the corresponding methods on the remote objects
     */
    void SetUserInfo(const std::string& id, bool& changed, uint16_t& return_code, std::string& return_string)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << id;
        call.member("SetUserInfo");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        ri >> changed;
        ri >> return_code;
        ri >> return_string;
    }


public:

    /* signal handlers for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual signal handler)
     */
};

} } } 
#endif //__dbusxx__proxy_h__PROXY_MARSHAL_H
