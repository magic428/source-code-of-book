SET(PROJECT_NAME "Chapter 05")
PROJECT(${PROJECT_NAME})

# 设置 lib 和 bin 的路径 
IF(MSVC)
    # SET( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OPENCV2_COOKBOOK_BINARY_DIR}/lib/{PROJECT_NAME} CACHE PATH "Output directory for libraries" )
    SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OPENCV2_COOKBOOK_BINARY_DIR}/bin/${PROJECT_NAME} )
    # ADD_DEFINITIONS(/arch:SSE /arch:SSE2) # /arch:SSE and /arch:SSE2 are only available when you compile for the x86 platform.
ELSEIF(CMAKE_COMPILER_IS_GNUCC) 
    # SET( CMAKE_ARCHIVE_OUTPUT_DIRECTORY   ${OPENCV2_COOKBOOK_BINARY_DIR}/lib/{PROJECT_NAME} CACHE PATH "Output directory for libraries" )
    SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY   ${OPENCV2_COOKBOOK_BINARY_DIR}/bin/${PROJECT_NAME} )
ENDIF()


file( GLOB Chapter04_source 
      "${PROJECT_SOURCE_DIR}/src/*.cpp"
    )

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

FOREACH (SRC_FILE ${Chapter04_source})
    # 提取文件名前缀
    STRING( REGEX REPLACE ".*/(.*).cpp$" "\\1" prjName ${SRC_FILE} )   
    # 提取目录
    # STRING( REGEX REPLACE "(.*)/.*.cpp$" "\\1" prjName ${SRC_FILE} )   
    
    ADD_EXECUTABLE(${prjName} ${SRC_FILE})
    TARGET_LINK_LIBRARIES(${prjName} ${OpenCV_LIBS}) 
ENDFOREACH()