#cmake最低版本需求，不加入此行会受到警告信息
CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

#项目名称
PROJECT(OCR)

#设置编译器支持c++11
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

#把当前目录(.)下所有源代码文件和头文件加入变量SRC_LIST
AUX_SOURCE_DIRECTORY(./src SRC_LIST)

#生成应用程序 hello (在windows下会自动生成hello.exe)
ADD_EXECUTABLE(ocr ${SRC_LIST})


#gflags
SET(gflags_DIR "C:/ThirdParty/gflags/build")
FIND_PACKAGE(gflags)
if(gflags_FOUND)
    include_directories(${gflags_INCLUDE_DIR})
    target_link_libraries(ocr ${gflags_LIBRARIES})
else(gflags_FOUND)
    message(FATAL_ERROR ”gflags library not found”)
endif(gflags_FOUND)