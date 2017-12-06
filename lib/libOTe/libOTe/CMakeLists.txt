
#project(libOTe)

file(GLOB_RECURSE SRCS *.cpp)
#include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_C_FLAGS "-ffunction-sections -Wall -mfloat-abi=softfp -mfpu=neon -Wfatal-errors -pthread -fPIC -Wno-ignored-attributes")
set(CMAKE_CXX_FLAGS  "${CMAKE_C_FLAGS}  -std=c++14 -march=armv7-a -mtune=cortex-a9 -mfpu=neon")

add_library(libOTe STATIC ${SRCS})

target_include_directories(libOTe PUBLIC ${CMAKE_SOURCE_DIR}) 
target_link_libraries(libOTe cryptoTools)

#############################################
#            Install                        #
#############################################

# install library
install(TARGETS libOTe DESTINATION lib)

# install headers
install(DIRECTORY . DESTINATION include/libOTe FILES_MATCHING PATTERN "*.h")
