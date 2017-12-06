
#project(frontend)

set(CMAKE_C_FLAGS "-ffunction-sections -Wall -mfloat-abi=softfp -mfpu=neon -Wfatal-errors -pthread -fPIC -Wno-ignored-attributes")
set(CMAKE_CXX_FLAGS  "${CMAKE_C_FLAGS}  -std=c++14 -march=armv7-a -mtune=cortex-a9 -mfpu=neon")

file(GLOB_RECURSE SRCS *.cpp)

include_directories(${CMAKE_SOURCE_DIR})
link_directories($ENV{HOME}/libscapi/install/lib/)

add_executable(frontend_libOTe  ${SRCS})

target_link_libraries(frontend_libOTe libOTe_Tests tests_cryptoTools libboost_system.a libboost_thread.a)