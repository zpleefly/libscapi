
#project(libOTe_Tests)

set(CMAKE_C_FLAGS "-ffunction-sections -Wall -mfloat-abi=softfp -mfpu=neon -Wfatal-errors -pthread -fPIC -Wno-ignored-attributes")
set(CMAKE_CXX_FLAGS  "${CMAKE_C_FLAGS}  -std=c++14 -march=armv7-a -mtune=cortex-a9 -mfpu=neon")

file(GLOB_RECURSE SRCS *.cpp)
add_library(libOTe_Tests STATIC ${SRCS})

target_include_directories(libOTe_Tests PUBLIC ${CMAKE_SOURCE_DIR}) 
target_link_libraries(libOTe_Tests libOTe)
