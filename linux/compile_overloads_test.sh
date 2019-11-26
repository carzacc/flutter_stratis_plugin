#!/bin/bash
g++  overloads_test.cpp funcs.cc -Iflutter -Iflutter/cpp_client_wrapper/include -I/usr/include/dbus-1.0 -I/usr/lib64/dbus-1.0/include -I/usr/include/dbus-c++-1 -DDBUS_API_SUBJECT_TO_CHANGE -ldbus-c++-1 -ldbus-1 -ggdb -o overloads_test
