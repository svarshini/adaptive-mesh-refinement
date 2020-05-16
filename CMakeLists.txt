project(adaptive)

cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -DBOOST_MATH_DISABLE_FLOAT128")

set(SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/quadtree.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/neighbors.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/diag_neighbors.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/balance.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/strong_balance.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/conn_util.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/stencil.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/rotranscale.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/label.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/duplicates.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/duplicate_util.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/output.cpp
  )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${SRCS})
