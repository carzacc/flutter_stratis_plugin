import 'dart:async';

import 'package:flutter/services.dart';

/// The interface between our Flutter code and
/// the C++ code that interacts with the Stratis
/// daemon
class StratisFlutter {
  /// The method channel we'll use to send our methods
  /// calls
  static const MethodChannel _channel =
      const MethodChannel('stratis');

  /// This method creates a pool with the given name
  /// and blockdevs
  static Future<List<String>> getBlockdevs() async =>
    await _channel.invokeMethod('getBlockdevs');
}