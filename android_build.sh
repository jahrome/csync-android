export NDK=/home/jer/Projet_android/android-ndk-r5
export TOOLCHAIN=/home/jer/standalone-toolchain
export AOSP=/home/jer/cm7
export PRODUCT=vision
export PATH=$TOOLCHAIN/bin/:$PATH

export CC=arm-linux-androideabi-gcc
export CXX=arm-linux-androideabi-g++
export CFLAGS="-march=armv7-a -mfloat-abi=softfp -I$AOSP/external/sqlite/dist -I$AOSP/out/target/product/$PRODUCT/obj/include"
export CPPFLAGS=$CFLAGS
export LDFLAGS="-Wl,--fix-cortex-a8 -lsupc++ -L$AOSP/out/target/product/$PRODUCT/system/lib"
export LIBS="$TOOLCHAIN/arm-linux-androideabi/lib/libstdc++.a"

#rm -rf $TOOLCHAIN
#$NDK/build/tools/make-standalone-toolchain.sh --platform=android-9 --install-dir=$TOOLCHAIN

cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_LINK_LIBRARY_FILE_FLAG=$TOOLCHAIN/arm-linux-androideabi/lib/libstdc++.a -DCMAKE_INSTALL_PREFIX=$AOSP/out/target/product/$PRODUCT/obj ..
sed -i 's/-Wl,-soname,libcsync.so.0/-Wl,-soname,libcsync.so/' src/CMakeFiles/csync.dir/link.txt
make -j2 # VERBOSE=1

arm-linux-androideabi-strip client/csync
arm-linux-androideabi-strip src/libcsync.so
arm-linux-androideabi-strip modules/csync_sftp.so

cp client/csync $AOSP/vendor/cyanogen/prebuilt/common/bin
cp src/libcsync.so $AOSP/vendor/cyanogen/prebuilt/common/lib
cp modules/csync_sftp.so $AOSP/vendor/cyanogen/prebuilt/common/lib
