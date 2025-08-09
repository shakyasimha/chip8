cmake_minimum_required(VERSION 3.10)
project(CHIP8-Emulator C)

# Use C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Use pkg-config to find SDL2
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

# Include SDL2
include_directories(${SDL2_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)

# Source files
file(GLOB SOURCES "src/*.c")

# Add executable
add_executable(chip8_emu ${SOURCES})

# Link SDL2
target_link_libraries(chip8_emu ${SDL2_LIBRARIES})
