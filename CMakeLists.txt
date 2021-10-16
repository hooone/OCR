#cmake最低版本需求，不加入此行会受到警告信息
CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

#项目名称
PROJECT(OCR)

#设置编译器支持c++11
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

include_directories("C:/Program Files/Java/jdk-17/include")
include_directories("C:/Program Files/Java/jdk-17/include/win32")

#把当前目录(.)下所有源代码文件和头文件加入变量SRC_LIST
include_directories("${CMAKE_SOURCE_DIR}/")
AUX_SOURCE_DIRECTORY(./src/demo SRC_LIST)
AUX_SOURCE_DIRECTORY(./src/mhd MHD_LIST)

#生成应用程序 ocrdemo
ADD_EXECUTABLE(ocrdemo ${SRC_LIST})
#生成mhd_dll ocr
ADD_LIBRARY(ocr SHARED ${MHD_LIST})

#gflags
SET(gflags_DIR "C:/ThirdParty/gflags/build")
FIND_PACKAGE(gflags REQUIRED)
include_directories(${gflags_INCLUDE_DIR})
target_link_libraries(ocrdemo ${gflags_LIBRARIES})


#OPENCV
SET(OpenCV_DIR "C:/opencv/mybuild")
FIND_PACKAGE(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(ocrdemo ${OpenCV_LIBS})
