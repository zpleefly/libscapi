cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_COMPILER /usr/bin/arm-linux-gnueabi-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabi-g++)

project(SemiHonestYao)

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=armv8-a -mtune=cortex-a53 -mfpu=neon -mfloat-abi=softfp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++14  -march=armv8-a -mtune=cortex-a53 -mfpu=neon -mfloat-abi=softfp")

INCLUDE_DIRECTORIES( $ENV{HOME} $ENV{HOME}/libscapi/install/include
        $ENV{HOME}/libscapi/lib/OTExtensionBristol
        $ENV{HOME}/libscapi/install/include $ENV{HOME}/libscapi/install/include/libOTe/cryptoTools/
        $ENV{HOME}/libscapi/install/include/libOTe
        $ENV{HOME}/libscapi/install/include/gmp-6.1.2/include)

set(SOURCE_FILES YaoParties.cpp App1.cpp)


link_directories($ENV{HOME}/libscapi/install/lib)


add_executable(SemiHonestYao ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(SemiHonestYao
        $ENV{HOME}/libscapi/libscapi.a gmp gmpxx
        libjsoncpp.a OTExtensionBristol libsimpleot.a libOTe.a libcryptoTools.a libmiracl.a
        crypto dl ssl z rt stdc++fs)
