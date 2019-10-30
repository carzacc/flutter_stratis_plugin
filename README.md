# Flutter Stratis Plugin

This plugins will allow a Flutter Desktop Linux app (ran with root privileges with `sudo` on X.Org) to interact with the Stratis daemon.

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

Contributions are welcome both for the app and the plugin. Both are at an incredibly early stage, and it would be a good idea to prioritize getting the plugin to support Stratis's features.

Obviously, design/implementation ideas and documentation improvements are appreciated, especially the former, given that there are multiple ways of getting the features implemented and, at the moment, the existing ones are hacked together in the shortest time possible for lack of time to dedicate to this project.

Also, the code in the repo right now (especially the Dart part) might not even be all correct, let alone good quality.
