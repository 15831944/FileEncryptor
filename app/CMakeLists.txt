cmake_minimum_required(VERSION 3.4.1)

include_directories(src/main/cpp)
add_library(libcrypto STATIC IMPORTED)
add_library(libssl STATIC IMPORTED)
set_target_properties(libcrypto
  PROPERTIES IMPORTED_LOCATION
  ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libcrypto.a)
  set_target_properties(libssl
    PROPERTIES IMPORTED_LOCATION
    ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libssl.a)

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp )

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

target_link_libraries( native-lib
                       ${log-lib}
                        libcrypto
                        libssl)