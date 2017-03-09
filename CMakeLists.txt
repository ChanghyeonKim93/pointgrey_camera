
# project
SET(PROJECT_NAME get_pointgrey)
PROJECT(${PROJECT_NAME} CXX C)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)
SET(CMAKE_BUILD_TYPE Release) # Release, RelWithDebInfo
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/CMakeModules/")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})


##set(SENSE_LIB_DIR "/usr/local/lib" CACHE PATH " ") # realsense *.so file location
set(PGRFLYCAP_LIB_DIR "/usr/lib" CACHE PATH " ") # pointgrey location
#find_library(FLYCAPTURE2 flycapture)

set(Boost_USE_MULTITHREADED ON)

# Add plain cmake packages
FIND_PACKAGE(OpenCV REQUIRED)
FIND_PACKAGE(Boost COMPONENTS system filesystem thread REQUIRED)
FIND_PACKAGE(Threads REQUIRED)



# Include dirs
INCLUDE_DIRECTORIES(
  include
  ${Eigen_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}

)


# Set link libraries
LIST(APPEND LINK_LIBS
  ${OpenCV_LIBS}
  ${Boost_LIBRARIES}
  ${CMAKE_THREAD_LIBS_INIT}
  ##${SENSE_LIB_DIR}/librealsense.so
  ${PGRFLYCAP_LIB_DIR}/libflycapture.so
)


# Set sourcefiles
LIST(APPEND SOURCEFILES
  src/main_script.cpp)


# Set build flags, set ARM_ARCHITECTURE environment variable on Odroid
set(CMAKE_CXX_FLAGS "-msse3")
set(CMAKE_BUILD_TYPE Release) # Release, RelWithDebInfo
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg  -m64 -Ofast -flto -march=native -mfpmath=sse")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3  -DEIGEN_NO_DEBUG -fopenmp -DNDEBUG")


################################################################################
# TESTS

ADD_EXECUTABLE(get_pointgrey ${SOURCEFILES})
TARGET_LINK_LIBRARIES(get_pointgrey ${LINK_LIBS})
