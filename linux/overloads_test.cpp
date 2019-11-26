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

#include <dbus/dbus.h>
#include "funcs.h"

#include <string>
#include <cstring>
#include <iostream>


using std::cout;

int main(int argc, char** argv) {
/*
    for(auto el: get_managed_objects()) {
        cout << "\t" << el.first << ": {" << std::endl;
        for(auto ell : el.second) {
            cout << "\t\t" << ell.first << ": {" << std:: endl;
            for(auto elll : ell.second) {
                cout << "\t\t\t" << elll.first << ": " << elll.second.signature()  << std::endl;  
            }
            cout << "\t\t}," << std::endl;
        }
        cout << "\t}," << std::endl;
        
    }   
    cout << "}" << std::endl;*/
    cout << "Pools:" << std::endl;

    for(Filesystem_data fs : funcs::get_filesystems()) {
        std::cout << "{\n";
        std::cout << "\tpath:" << fs.path << std::endl;
        std::cout << "\tCreated:" << fs.Created << std::endl;
        std::cout << "\tDevnode:" << fs.Devnode << std::endl;
        std::cout << "\tName:" << fs.Name << std::endl;
        std::cout << "\tPool:" << fs.Pool << std::endl;
        std::cout << "\tUsed:" << fs.Used << std::endl;
        std::cout << "\tUuid:" << fs.Uuid << std::endl;
        std::cout << "}\n"; 
    }

    cout << "Filesystems:" << std::endl;

    for(Pool_data pool : funcs::get_pools()) {
        std::cout << "{\n";
        std::cout << "\tpath:" << pool.path << std::endl;
        std::cout << "\tExtendedState:" << pool.ExtendState << std::endl;
        std::cout << "\tName:" << pool.Name << std::endl;
        std::cout << "\tSpaceState:" << pool.SpaceState << std::endl;
        std::cout << "\tState:" << pool.State << std::endl;
        std::cout << "\tTotalPhysicalSize:" << pool.TotalPhysicalSize << std::endl;
        std::cout << "\tTotalPhysicalUsed:" << pool.TotalPhysicalUsed << std::endl;
        std::cout << "\tUuid:" << pool.Uuid << std::endl;
        std::cout << "}\n"; 
    }

    cout << "Block Devices:" << std::endl;

    for(Blockdev_data blockdev : funcs::get_blockdevs()) {
        std::cout << "{\n";
        std::cout << "\tpath:" << blockdev.path << std::endl;
        std::cout << "\tDevnode:" << blockdev.Devnode << std::endl;
        std::cout << "\tHardwareInfo:" << blockdev.HardwareInfo << std::endl;
        std::cout << "\tInitializationTime:" << blockdev.InitializationTime << std::endl;
        std::cout << "\tPool:" << blockdev.Pool << std::endl;
        std::cout << "\tState:" << blockdev.State << std::endl;
        std::cout << "\tTier:" << blockdev.Tier << std::endl;
        std::cout << "\tTotalPhysicalSize:" << blockdev.TotalPhysicalSize << std::endl;
        std::cout << "\tUserInfo:" << blockdev.UserInfo << std::endl;
        std::cout << "\tUuid:" << blockdev.Uuid << std::endl;
        std::cout << "}\n"; 
    }
        
    flutter::EncodableMap map;
    map[flutter::EncodableValue(std::string("name"))] = "examplepool";
    flutter::EncodableValue blockdev1(std::string("/dev/mysda"));
    flutter::EncodableValue blockdev2(std::string("/dev/mysdb"));
    flutter::EncodableList blockdevs = {blockdev1, blockdev2};
    
    map[flutter::EncodableValue(std::string("blockdevs"))] = blockdevs;

    flutter::EncodableValue args(map);
    
    funcs::create_pool(args);

}