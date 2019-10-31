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
#include "stratis_flutter.h"
#include "funcs.h"

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar.h>
#include <flutter/standard_method_codec.h>

#include <cstddef>
#include <cstdio>

namespace {

class StratisFlutter : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrar *registrar);

  // Creates a plugin that communicates on the given channel.
  StratisFlutter(
      std::unique_ptr<flutter::MethodChannel<flutter::EncodableValue>> channel);

  virtual ~StratisFlutter();

 private:
  // Called when a method is called on |channel_|;
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);

  // The MethodChannel used for communication with the Flutter engine.
  std::unique_ptr<flutter::MethodChannel<flutter::EncodableValue>> channel_;
};

// static
void StratisFlutter::RegisterWithRegistrar(flutter::PluginRegistrar *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
        registrar->messenger(),
        std::string("stratis_flutter"),
        &flutter::StandardMethodCodec::GetInstance()
      );
  auto *channel_pointer = channel.get();

  auto plugin = std::make_unique<StratisFlutter>(std::move(channel));

  channel_pointer->SetMethodCallHandler(
    [plugin_pointer = plugin.get()](const auto &call, auto result) {
      plugin_pointer->HandleMethodCall(call, std::move(result));
    }
  );

  registrar->AddPlugin(std::move(plugin));
}

StratisFlutter::StratisFlutter(
    std::unique_ptr<flutter::MethodChannel<flutter::EncodableValue>> channel)
    : channel_(std::move(channel)) {}

StratisFlutter::~StratisFlutter(){};

void StratisFlutter::HandleMethodCall(
  const flutter::MethodCall<flutter::EncodableValue> &method_call,
  std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
  if (method_call.method_name().compare(std::string("createPool")) == 0) {
    
    std::string pool = funcs::create_pool(*method_call.arguments());
    
    flutter::EncodableValue response(pool);
    
    result->Success(&response);
  } else if (method_call.method_name().compare(std::string("getVersion")) == 0) {
    
    std::string version = funcs::get_version();
    
    flutter::EncodableValue response(version);
    
    result->Success(&response);
  } else if (method_call.method_name().compare(std::string("destroyPool")) == 0) {
    
    auto pool_name = (*method_call.arguments()).StringValue();
    
    auto result_string = funcs::destroy_pool(pool_name);
    
    flutter::EncodableValue response(result_string);
    
    result->Success(&response);
  } else if (method_call.method_name().compare(std::string("addDataDevs")) == 0) {
    
    auto return_code = funcs::add_data_blockdevs(*method_call.arguments());
    
    flutter::EncodableValue response(return_code);
    
    result->Success(&response);
  } else if (method_call.method_name().compare(std::string("addCacheDevs")) == 0) {
    
    auto return_code = funcs::add_cache_blockdevs(*method_call.arguments());
    
    flutter::EncodableValue response(return_code);
    
    result->Success(&response);
  } else if (method_call.method_name().compare(std::string("createPool")) == 0) {
    
    auto return_string = funcs::create_pool(*method_call.arguments());
    
    flutter::EncodableValue response(return_string);
    
    result->Success(&response);
  }  else {
    result->NotImplemented();
  }
}

}  // namespace

void StratisFlutterRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  // The plugin registrar owns the plugin, registered callbacks, etc., so must
  // remain valid for the life of the application.
  static auto *plugin_registrar = new flutter::PluginRegistrar(registrar);

  StratisFlutter::RegisterWithRegistrar(plugin_registrar);


}

