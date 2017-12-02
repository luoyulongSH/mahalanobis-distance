cmake_minimum_required(VERSION 3.7)
project(mahal_distance)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

aux_source_directory(. SOURCE_FILES)
aux_source_directory(./mahalanobis_distance SOURCE_FILES)

add_executable(mahal_distance ${SOURCE_FILES})
target_link_libraries(mahal_distance gtest)