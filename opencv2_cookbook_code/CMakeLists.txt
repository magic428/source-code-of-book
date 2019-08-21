# ----------------------------------------------------------------------------
#  根目录的 CMake 文件
#
#  magic428 <zack200x11@gmail.com>
#
# ----------------------------------------------------------------------------

#####################################################
# Win32
# cmake -G "Visual Studio 14 2015" ../ -D -D OpenCV_DIR="D:/workSpace/thirdparty20170624/OpenCV2411/build" ../
#
# Win64
# cmake -G "Visual Studio 14 2015 Win64" -D OpenCV_DIR="D:/workSpace/thirdparty20170624/OpenCV2411/build" -D BOOST_INCLUDEDIR="D:/workSpace/thirdparty20170624/Boost" ../
#
#
# VS 开启 OpenMP: 
#    属性 | 配置属性 | C/C++ | 语言 | “OpenMP 支持” 选择 “是” 
#
#####################################################

CMAKE_MINIMUM_REQUIRED (VERSION 2.8)#设定最小版CMake版本号

PROJECT (OPENCV2_COOKBOOK)#设定工程名称

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake") # 添加本地CMake脚本目录

# 抑制生成 ZERO_CHECK 工程
SET( CMAKE_SUPPRESS_REGENERATION ON ) 
SET( CMAKE_SUPPRESS_REGENERATION ON ) 

#INCLUDE(cmake/script_version_number.cmake REQUIRED)#添加项目版本号

#设置路径
SET(OPENCV2_COOKBOOK_BINARY_DIR  ${PROJECT_BINARY_DIR})

SET(CMAKE_DEBUG_POSTFIX  "d")#设置Debug下lib的名称后添加d，如openmvo_XXX100d.lib

#用于项目中添加筛选器
IF (CMAKE_VERSION VERSION_GREATER 2.8.0)
    SET(ENABLE_SOLUTION_FOLDERS ON CACHE BOOL "Group projects under virtual folders of the compiler IDE (e.g. VisualStudio)")
ENDIF (CMAKE_VERSION VERSION_GREATER 2.8.0)

if (ENABLE_SOLUTION_FOLDERS)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
  set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")
endif (ENABLE_SOLUTION_FOLDERS)

#添加c++11支持
IF(CMAKE_COMPILER_IS_GNUCC)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
ELSE()
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ENDIF()


#添加 MSVC 支持 UTF-8 和 sse 指令支持
# /Wall Wall enables all warnings that are off by default. 
# If you use this option, you can turn off individual warnings by using the /wd option.

# https://stackoverflow.com/questions/1480916/how-do-i-enable-the-sse-sse2-instruction-set-in-visual-studio-2008-using-cmake
# MSDN says:
#    /arch:SSE and /arch:SSE2 are only available when you compile for the x86 platform.
#    and that SSE is used on x64 anyways. Hence I just removed the option now.
# You will see this message if you try to enable /arch:SSE2 option while building x64 code. This basically tells you that you don't need it. SSE/SSE2 is used by default in x64 builds. – ahmd0 Jul 6 '17 at 10:24
IF(MSVC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8  /wd4828")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++14")
    MESSAGE(STATUS "WINDOWS MSVC PLATFORM")
    # ADD_DEFINITIONS(/arch:SSE /arch:SSE2) # /arch:SSE and /arch:SSE2 are only available when you compile for the x86 platform.
ELSEIF(CMAKE_COMPILER_IS_GNUCC) 
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmmx -msse -msse -msse2 -msse3 -mssse3")
ENDIF()

#添加libs
# add by magic428
SET(OpenCV_DIR D:/workSpace/thirdparty20170624/OpenCV2411/build)
FIND_PACKAGE(OpenCV REQUIRED) #通过CMake系统添加OpenCV
SET(OpenCV_STATIC OFF CACHE BOOL "Use Share OpenCV Lib")

#构建静态库还是动态库，目前先设置为静态库，后期更改为默认动态库
SET(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)")
IF(BUILD_SHARED_LIBS)
    SET(CMAKE_OPENMVO_BUILD_SHARED_LIB "#define OPENMVO_BUILT_AS_DLL")
    SET(CMAKE_OPENMVO_BUILD_SHARED_LIB_ONOFF 1)
ELSE(BUILD_SHARED_LIBS)
    SET(CMAKE_OPENMVO_BUILD_SHARED_LIB "/* #define OPENMVO_BUILT_AS_DLL */")
    SET(CMAKE_OPENMVO_BUILD_SHARED_LIB_ONOFF 0)
ENDIF(BUILD_SHARED_LIBS)


#设置 include 和 link 路径
INCLUDE_DIRECTORIES(".")#设置包含当前目录
LINK_DIRECTORIES("${CMAKE_BINARY_DIR}/build/lib")


# ----------------------------------------------------------------------------
#      					处理子目录
# ----------------------------------------------------------------------------
ADD_SUBDIRECTORY("Chapter 02")  
ADD_SUBDIRECTORY("Chapter 03")   
ADD_SUBDIRECTORY("Chapter 04")   
ADD_SUBDIRECTORY("Chapter 05")   

SET( BUILD_APPLICATIONS ON CACHE BOOL "If you only want the OPENMVO libraries, disable this.")

# IF(BUILD_APPLICATIONS)
    # ADD_SUBDIRECTORY(apps)    # 添加小应用程序目录
# ENDIF(BUILD_APPLICATIONS)


#   添加单元测试
# ----------------------------------------------------------------------------
# SET( BUILD_TESTING ON CACHE BOOL "Build OPENMVO tests")
# IF( BUILD_TESTING)
# 	ADD_SUBDIRECTORY(tests)  # 添加单元测试
# ENDIF( BUILD_TESTING)
