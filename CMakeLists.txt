cmake_minimum_required(VERSION 3.22)

set(PROJ_LIB_TYPE STATIC) # If LIBRARY (STATIC, SHARED or MODULE)
set(PROJ_NAME "mean")
set(SRC_DIR "src")
set(INC_DIR "include")

set(
    SRC_FILES

    "mean.cpp"
)

project(
    ${PROJ_NAME}
    VERSION 0.1
    DESCRIPTION "A project"
    LANGUAGES C CXX 
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

###################

list(TRANSFORM SRC_FILES PREPEND "${SRC_DIR}/")

###################

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

if(UNIX)
    message(STATUS "STATUS - ${PROJ_NAME}: Building for UNIX.")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++2a")

    # Override to newer compiler usually needed on ubuntu cause shits old
    # set(CMAKE_C_COMPILER gcc-13)
    # set(CMAKE_CXX_COMPILER g++-13)

    add_compile_definitions(__unix__)
elseif(WIN32)
    message(STATUS "STATUS - ${PROJ_NAME}: Building for Windows.")

    add_compile_definitions(__win32__)
elseif(APPLE)
    message(STATUS "STATUS - ${PROJ_NAME}: Building for Apple.")

    add_compile_definitions(__apple__)
endif()

add_library(${PROJ_NAME} STATIC ${SRC_FILES})

set(${PROJ_NAME}_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/${INC_DIR})
set(${PROJ_NAME}_LIB ${PROJ_NAME}) # Expose library

target_include_directories(${PROJ_NAME} PUBLIC ${INC_DIR})

if("${CMAKE_BUILD_TYPE}" STREQUAL Debug)
    target_compile_definitions(${PROJ_NAME} PRIVATE _DEBUG)
else()
    target_compile_definitions(${PROJ_NAME} PRIVATE _RELEASE)
endif()

add_subdirectory(test)
