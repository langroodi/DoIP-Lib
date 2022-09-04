########################################################################
#
# Requirements and dependencies:

cmake_minimum_required(VERSION 3.14)
project(DoIP_Lib)

set(CMAKE_CXX_STANDARD 14)
# Enable 'rdyamic' switch to export the executable's symbols for debugging
set(CMAKE_ENABLE_EXPORTS 1)
# Fetching GoogleTest 1.12.1 for unit testing
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)

FetchContent_MakeAvailable(googletest)

########################################################################
#
# Options:

option(build_tests "Build all the tests." ON)

########################################################################
#
# Include Directory:

set(include_dir
  "${PROJECT_SOURCE_DIR}/include")

# Source Directory:

set(source_dir
  "${PROJECT_SOURCE_DIR}/src")

# Test Directory:

set(test_dir
  "${PROJECT_SOURCE_DIR}/test")

########################################################################

include_directories(${include_dir})

add_library(
  doip_lib
  ${source_dir}/message.cpp
  ${source_dir}/generic_nack.cpp
  ${source_dir}/vehicle_id_request.cpp
  ${source_dir}/eid_vehicle_id_request.cpp
  ${source_dir}/vin_vehicle_id_request.cpp
)

target_include_directories(doip_lib
  INTERFACE ${include_dir}
)

if(build_tests)
  enable_testing()

  add_executable(
    doip_lib_test
    ${test_dir}/convert_test.cpp
    ${test_dir}/message_test.cpp
    ${test_dir}/generic_nack_test.cpp
    ${test_dir}/vehicle_id_request_test.cpp
    ${test_dir}/eid_vehicle_id_request_test.cpp
    ${test_dir}/vin_vehicle_id_request_test.cpp
  )

  target_link_libraries(
    doip_lib_test
    gtest_main
    doip_lib
  )

  include(GoogleTest)
  gtest_discover_tests(doip_lib_test)
endif()