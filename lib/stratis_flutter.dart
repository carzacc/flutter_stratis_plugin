import 'dart:async';

import 'package:flutter/services.dart';

class Filesystem_data {
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
  static Future<String> addCacheBlockdevs(String poolName, List<String> blockdevs) async {
    final args = {
      'pool_name': poolName,
      'blockdevs': blockdevs
    };
    final pool = await _channel.invokeMethod('addCacheDevs', args);
    return pool;
  }

  /// Adds data block devices to the pool called `poolName`
  static Future<String> addDataBlockdevs(String poolName, List<String> blockdevs) async {
    final args = {
      'pool_name': poolName,
      'blockdevs': blockdevs
    };
    final pool = await _channel.invokeMethod('addDataDevs', args);
    return pool;
  }

  /// This method returns the version of the stratis
  /// daemon
  static Future<String> getVersion() async {
    final version = await _channel.invokeMethod('getVersion');

    return version;
  }
}
