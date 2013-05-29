Sophia - Intelligent Vietnamese Input Method Editor for Android
===

A complete, ready-to-use, smart keyboard for Android. 

See more at:

https://play.google.com/store/apps/details?id=com.htruong.inputmethod.latin

http://www.tnhh.net/2013/04/02/sophia-ime-easter-awesomeness.html

After a while I have decided it would be the best interest of the Vietnamese community for me to release this software as open source.

I welcome you to the brave new world of innovations, collaboration and inventions.


Please send pull requests, bug reports to _ @ tnhh.net


#### Screenshots

![Screenshot](http://i.imgur.com/0uzGMEh.jpg)
![Screenshot](http://i.imgur.com/aFIrxU7.jpg)
![Screenshot](http://i.imgur.com/ULfSJZs.jpg)



#### License

Copyright (C) 2013 Huan Truong < _ @ tnhh.net >

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#### Credits

The original code was pulled from Android Jelly Bean source code (AOSP) by @sugree. The binary works for Android 4.1 and above.

The toolchain are forked from https://github.com/sugree/android-thaiime.

#### Prerequisites

1. Android SDK Tools 20.0.1
2. Android SDK Platform-tools 13
3. Android 4.1 API 16 SDK Platform 16.2
4. Android NDK r8b

#### local.properties

    You need to add local.properties file in each directory with single configuration

    $ sdk.dir = [PATH to Android SDK]

#### Preparation

    $ mkdir latinime/libs

#### Library Compilation (one time)

    $ cd inputmethodcommon
    $ ant release
    $ cd ..
    $ cp inputmethodcommon/bin/classes.jar latinime/libs/inputmethodcommon.jar
    $ cd support-v4
    $ ant release
    $ cd ..
    $ cp support-v4/bin/classes.jar latinime/libs/android-support-v4.jar

#### Native Compilation

    $ cd latinime
    $ ndk-build
    $ cd ..

#### IME Compilation

    $ cd latinime
    $ ant debug

#### Testing Stage

    The compiled binaries will be located in latinime/bin. 
    Copy it to your Android environment using ADB. 
    Enabling it in Settings/Language.
