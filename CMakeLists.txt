cmake_minimum_required(VERSION 3.7)

project(GBT-Emulator C)
# set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

find_package(SDL2 CONFIG REQUIRED)

file(GLOB SOURCE_FILES
	src/*.c src/*.h src/**/*.c src/**/*.h)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(gbt ${SOURCE_FILES})

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
if(MSVC)
  target_compile_options(gbt PRIVATE /wd4996 /W3 /WX)
else()
  target_compile_options(gbt PRIVATE -Wno-unused-parameter -Wall -Wextra -pedantic)
endif()

target_link_libraries(gbt PRIVATE SDL2::SDL2 SDL2::SDL2main)
