# Install script for directory: F:/GRPC/grpcSource/grpc/third_party/boringssl-with-bazel

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/grpc")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("F:/GRPC/grpcSource/grpc/.build/third_party/boringssl-with-bazel/crypto/cmake_install.cmake")
  include("F:/GRPC/grpcSource/grpc/.build/third_party/boringssl-with-bazel/ssl/cmake_install.cmake")
  include("F:/GRPC/grpcSource/grpc/.build/third_party/boringssl-with-bazel/ssl/test/cmake_install.cmake")
  include("F:/GRPC/grpcSource/grpc/.build/third_party/boringssl-with-bazel/tool/cmake_install.cmake")
  include("F:/GRPC/grpcSource/grpc/.build/third_party/boringssl-with-bazel/util/fipstools/cavp/cmake_install.cmake")
  include("F:/GRPC/grpcSource/grpc/.build/third_party/boringssl-with-bazel/util/fipstools/acvp/modulewrapper/cmake_install.cmake")
  include("F:/GRPC/grpcSource/grpc/.build/third_party/boringssl-with-bazel/decrepit/cmake_install.cmake")

endif()

