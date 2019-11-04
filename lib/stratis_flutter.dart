import 'dart:async';

import 'package:flutter/services.dart';

class Filesystem_data {
  /// Creates a Filesystem_data object with the given attributes.
  /// The constructor takes the parameters in the same order as they are given
  /// by the C++ backend when sending the attributes through the platform channel.
    Filesystem_data(this.path, this.Created, this.Devnode, this.Name, this.Pool, this.Used, this.Uuid);
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
    String path;
    String Created;
    String Devnode;
    String Name;
    String Pool;
    String Used;
    String Uuid;
}


class Blockdev_data {
  /// Creates a Blockdev_data object with the given attributes.
  /// The constructor takes the parameters in the same order as they are given
  /// by the C++ backend when sending the attributes through the platform channel.
    Blockdev_data(this.path, this.Devnode, this.HardwareInfo, this.InitializationTime, this.Pool, this.State, this.Tier, this.TotalPhysicalSize, this.UserInfo, this.Uuid);
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
    String path;
    String Devnode;
    String HardwareInfo;
    int InitializationTime;
    String Pool;
    int State;
    int Tier;
    String TotalPhysicalSize;
    String UserInfo;
    String Uuid;
}

class Pool_data {
  /// Creates a Pool_data object with the given attributes.
  /// The constructor takes the parameters in the same order as they are given
  /// by the C++ backend when sending the attributes through the platform channel.
  Pool_data(this.path, this.ExtendState, this.Name, this.SpaceState, this.State, this.TotalPhysicalSize, this.TotalPhysicalUsed, this.Uuid);
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
    String path;
    int ExtendState;
    String Name;
    int SpaceState;
    int State;
    String TotalPhysicalSize;
    String TotalPhysicalUsed;
    String Uuid;
}


/// The interface between our Flutter code and
/// the C++ code that interacts with the Stratis
/// daemon
class StratisFlutter {
  /// The method channel we'll use to send our methods
  /// calls
  static const MethodChannel _channel =
      const MethodChannel('stratis_flutter');

  /// This method creates a pool with the given name
  /// and blockdevs
  static Future<String> createPool({String name, List<String> blockdevs}) async {
    final args = {
      'name': name,
      'blockdevs': blockdevs
    };
    final pool = await _channel.invokeMethod('createPool', args);
    return pool;
  }


  /// Destroys the pool called `poolName`
  static Future<String> destroyPool(String poolName) async {
    final pool = await _channel.invokeMethod('destroyPool', poolName);
    return pool;
  }

  /// Adds cache block devices to the pool called `poolName`
  static Future<int> addCacheBlockdevs(String poolName, List<String> blockdevs) async {
    final args = {
      'pool_name': poolName,
      'blockdevs': blockdevs
    };
    final pool = await _channel.invokeMethod('addCacheDevs', args);
    return pool;
  }

  /// Adds data block devices to the pool called `poolName`
  static Future<int> addDataBlockdevs(String poolName, List<String> blockdevs) async {
    final args = {
      'pool_name': poolName,
      'blockdevs': blockdevs
    };
    final pool = await _channel.invokeMethod('addDataDevs', args);
    return pool;
  }

  /// Destroys the filesystems with the names listed in `fsNames` from the pool `poolName`
  static Future<int> destroyFilesystems(String poolName, List<String> fsNames) async {
    final args = {
      'pool_name': poolName,
      'fs_names': fsNames
    };
    final pool = await _channel.invokeMethod('destroyFilesystems', args);
    return pool;
  }

  /// Create filesystems in the pool `poolName` with the given `fsNames`
  static Future<int> createFilesystems(String poolName, List<String> fsNames) async {
    final args = {
      'pool_name': poolName,
      'fs_names': fsNames
    };
    final res = await _channel.invokeMethod('createFilesystems', args);
    return res;
  }

  /// This a list of pools managed by Stratis
  static Future<List<Pool_data>> listPools() async {
    final List<dynamic> pool_list = await _channel.invokeMethod('listPools');
    List<Pool_data> pools;

    for(var i = 0; i < pool_list.length; i+=10) {
      pools.add(
        Pool_data(
          pool_list[i],
          pool_list[i+1],
          pool_list[i+2],
          pool_list[i+3],
          pool_list[i+4],
          pool_list[i+5],
          pool_list[i+6],
          pool_list[i+7],
        )
      );
    }

    return pools;
  }

  /// This method returns a list of filesystems managed by Stratis
  static Future<List<Filesystem_data>> listFilesystems() async {
    final List<dynamic> filesystem_list = await _channel.invokeMethod('listFilesystems');
    List<Filesystem_data> filesystems;

    for(var i = 0; i < filesystem_list.length; i+=10) {
      filesystems.add(
        Filesystem_data(
          filesystem_list[i],
          filesystem_list[i+1],
          filesystem_list[i+2],
          filesystem_list[i+3],
          filesystem_list[i+4],
          filesystem_list[i+5],
          filesystem_list[i+6],
        )
      );
    }

    return filesystems;
  }

  /// This method returns the version of block devices managed by Stratis
  static Future<List<Blockdev_data>> listBlockdevs() async {
    final List<dynamic> blockdev_list = await _channel.invokeMethod('listBlockdevs');

    List<Blockdev_data> blockdevs;

    for(var i = 0; i < blockdev_list.length; i+=10) {
      blockdevs.add(
        Blockdev_data(
          blockdev_list[i],
          blockdev_list[i+1],
          blockdev_list[i+2],
          blockdev_list[i+3],
          blockdev_list[i+4],
          blockdev_list[i+5],
          blockdev_list[i+6],
          blockdev_list[i+7],
          blockdev_list[i+8],
          blockdev_list[i+9],          
        )
      );
    }

    return blockdevs;
  }

  

  /// This method returns the version of the stratis
  /// daemon
  static Future<String> getVersion() async {
    final version = await _channel.invokeMethod('getVersion');

    return version;
  }
}
