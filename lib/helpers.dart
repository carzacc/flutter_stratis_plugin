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

  /// Lists the block devices available in the system (including those not managed by Stratis)
  static Future<List<String>> getBlockdevs() async =>
    await _channel.invokeMethod('getBlockdevs');
}