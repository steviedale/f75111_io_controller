cmake_minimum_required(VERSION 3.5)

project(f75111_io_controller VERSION 0.1.0 LANGUAGES CXX C)

include(cmake/f75111_io_controller_macros.cmake)

find_package(ament_cmake REQUIRED)

add_library(${PROJECT_NAME} SHARED
  src/f75111_io_controller.cpp
  src/f75111.c
  src/smbus.c
)
target_include_directories(${PROJECT_NAME} PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include>"
)

add_executable(${PROJECT_NAME}_test
  src/test_f75111_io_controller.cpp
  src/f75111_io_controller.cpp
  src/f75111.c
  src/smbus.c
)
target_include_directories(${PROJECT_NAME}_test PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include>"
)

ament_export_include_directories(include)

configure_package(NAMESPACE ${PROJECT_NAME}
    TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_test)

install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION include/${PROJECT_NAME}/
)
 
ament_package()
