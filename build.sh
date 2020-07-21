#!/bin/bash 
export ANDROID_NDK_ROOT="/home/jake/Android/Sdk/ndk/21.3.6528147"
mkdir -p build && cd build
/home/jake/Qt/5.12.7/android_armv7/bin/qmake CONFIG+=qtusb-static ..
make install

