import 'dart:async';

import 'package:flutter/services.dart';

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
      "pool_name": poolName,
      "blockdevs": blockdevs
    }
    final pool = await _channel.invokeMethod('addCacheDevs', poolName);
    return pool;
  }

  /// Adds data block devices to the pool called `poolName`
  static Future<String> addDataBlockdevs(String poolName, List<String> blockdevs) async {
    final args = {
      "pool_name": poolName,
      "blockdevs": blockdevs
    }
    final pool = await _channel.invokeMethod('addDataDevs', poolName);
    return pool;
  }

  /// This method returns the version of the stratis
  /// daemon
  static Future<String> getVersion() async {
    final version = await _channel.invokeMethod('getVersion');

    return version;
  }
}
