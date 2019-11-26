# Flutter Stratis Plugin

This plugins will allow a Flutter Desktop Linux app (ran with root privileges with `sudo` on X.Org) to interact with the Stratis daemon.

## Dependencies

make, GCC with C++14 support, DBus (with the headers for development purposes), Stratis, Flutter SDK with support for desktop development. More details will be provided later.

## Building the Plugin

At the moment Flutter Linux plugin tooling for desktop plugins hasn't yet been implemented but is being implemented, so it's rather painful to use the plugin as things are now but it is being worked on by the Flutter team. Hopefully progress on that front will help us more than the changes to the API on the Stratis side will slow us down.

This plugin is supposed to be built using the `Makefile` by runnning

~~~
$ make -C linux
~~~

when in root of this repository.

After doing that, you'll find a file called `libflutter_linux.so` in the `build/linux` subdirectory.

The `copy_result.sh` script in this directory will copy that file to `../../stratis_gui_flutter/linux/`.

If `../../stratis_gui_flutter` is where you have the [`flutter_stratis_gui`](https://github.com/carzacc/flutter_stratis_gui) app source, you will simply have to then run the [`flutter_stratis_gui`](https://github.com/carzacc/flutter_stratis_gui)'s `copy_result.sh` and that app's modified `Makefile` will make sure that file will get linked with the app's code and the modified `flutter_embedder_example` file will make sure to use this plugin.

All that's left to do is to use the plugin just like any regular mobile plugin in the Dart code, just like the aforementioned `flutter_stratis_gui` app does.

# Contributing

Contributions are welcome both for the app and the plugin.

Right now the focus is on writing tests for the various Stratis features.

Obviously, design/implementation ideas and documentation improvements are appreciated, especially the former, given that there are multiple ways of getting the features implemented and, at the moment, the existing ones are hacked together in the shortest time possible for lack of time to dedicate to this project.

## Structure of the Code

The code is made up of three main components:

* the C++ code that interacts with the Stratis daemon over D-Bus, made up of the automatically generated `overloads.h` and `proxy.h` files, which should be generated automatically again only in case of changes to the Stratis D-Bus interface, and the `funcs.cc` file that contains the C++ functions that easily translate user Stratis commands into Stratis D-Bus method calls and which should implement the same features currently supported by the Stratis CLI tool, anything else that might be nice to have when buidling the GUI tool is something we should worry about when at least the basic features are covered;
* the C++ code that acts as a bridge between the low-level C++ interface and the Dart interface, made up of `stratis_flutter.cc` and `helpers.cc`, which call functions in `funcs.cc` and listen for Dart platform channel method calls;
* a Dart interface that calls method on the platform channel.
