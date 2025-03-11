cmake_minimum_required( VERSION 3.22 )

project( posix_demo )

include( FetchContent )

FetchContent_Declare( FreeRTOS_Kernel
                      GIT_REPOSITORY https://github.com/FreeRTOS/FreeRTOS-Kernel.git
                      GIT_TAG V11.2.0 )

set( FREERTOS_PLUS_POSIX_PATH "../../" )

add_compile_options( -Wall -Wextra -Wno-unused-function -Wno-shift-count-overflow )

# Add the freertos_config for FreeRTOS-Kernel.
add_library( freertos_config INTERFACE )

target_include_directories( freertos_config
                            INTERFACE
                            ./ )

# Select the heap port.
set( FREERTOS_HEAP "3" CACHE STRING "" FORCE )

# Select the FreeRTOS port.
set( FREERTOS_PORT "GCC_POSIX" CACHE STRING "" FORCE )

# Fetch FreeRTOS-Kernel.
FetchContent_MakeAvailable( FreeRTOS_Kernel )

file( GLOB FREERTOS_PLUS_POSIX_SOURCES
           ${FREERTOS_PLUS_POSIX_PATH}/FreeRTOS-Plus-POSIX/source/*.c )

add_executable( posix_demo
                main.c
                ${FREERTOS_PLUS_POSIX_SOURCES} )

target_include_directories( posix_demo
                            PRIVATE
                            ${FREERTOS_PLUS_POSIX_PATH}/include
                            ${FREERTOS_PLUS_POSIX_PATH}/include/private
                            ${FREERTOS_PLUS_POSIX_PATH}/FreeRTOS-Plus-POSIX/include
                            ${FREERTOS_PLUS_POSIX_PATH}/FreeRTOS-Plus-POSIX/include/portable
                            ${FREERTOS_PLUS_POSIX_PATH}/FreeRTOS-Plus-POSIX/include/portable/pc/windows )

target_link_libraries( posix_demo freertos_kernel freertos_config )
