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
#ifndef FUNCS_H
#define FUNCS_H

#include <dbus/dbus.h>
#include <flutter/standard_method_codec.h>
#include "overloads.h"

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

std::string get_version();
std::map< ::DBus::Path, std::map< std::string, std::map< std::string, ::DBus::Variant > > > get_managed_objects();
std::vector<Filesystem_data> get_filesystems();
std::vector<Blockdev_data> get_blockdevs();
std::vector<Pool_data> get_pools();
std::string destroy_pool(std::string pool_name);
std::string create_pool(flutter::EncodableValue arguments);
int add_data_blockdevs(flutter::EncodableValue arguments);
int add_cache_blockdevs(flutter::EncodableValue arguments);
int destroy_filesystem(flutter::EncodableValue arguments);
}

#endif /* FUNCS_H */