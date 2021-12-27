# Depend packages


if(NOT OPENSSL_FOUND)
  find_package(OpenSSL)
endif()


# Targets
include(${CMAKE_CURRENT_LIST_DIR}/gRPCTargets.cmake)
