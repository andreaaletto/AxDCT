cmake_minimum_required(VERSION 3.3)
project( AxDCT )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(OpenCV_STATIC ON)

add_subdirectory(utils)
add_subdirectory(core)
add_subdirectory(algorithms)
add_subdirectory(metrics)

if (AXDCT_BUILD_MUTANTS)
    add_subdirectory(mutants_eval)
endif()

if (AXDCT_BUILD_ZYBO)
    add_subdirectory(zybo_drivers)
endif()


add_executable( axdct axdct.cpp )

target_include_directories(axdct PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(axdct PUBLIC ${CMAKE_SOURCE_DIR}/include/core)
target_include_directories(axdct PUBLIC ${CMAKE_SOURCE_DIR}/include/algorithms)
target_include_directories(axdct PUBLIC ${CMAKE_SOURCE_DIR}/include/utils)

target_link_libraries( axdct utils ${OpenCV_LIBS} axdctCore axdctAlgorithms)


add_executable( image_eval image_eval.cpp )

target_include_directories(image_eval PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(image_eval PUBLIC ${CMAKE_SOURCE_DIR}/include/core)
target_include_directories(image_eval PUBLIC ${CMAKE_SOURCE_DIR}/include/algorithms)
target_include_directories(image_eval PUBLIC ${CMAKE_SOURCE_DIR}/include/utils)
target_include_directories(image_eval PUBLIC ${CMAKE_SOURCE_DIR}/include/metrics)

target_link_libraries( image_eval utils ${OpenCV_LIBS} axdctCore axdctAlgorithms metrics)