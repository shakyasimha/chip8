cmake_minimum_required(VERSION 3.10)
project(CHIP8-Emulator C)

# Use C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include SDL2
set(SDL2_PATH "$ENV{HOME}/scoop/apps/sdl2/current")
include_directories("${SDL2_PATH}/include")

# Source files
file(GLOB SOURCES "src/*.c")

# Add executable
add_executable(chip8_emu ${SOURCES})

# Link SDL2
target_link_directories(chip8_emulator PRIVATE "${SDL2_PATH}/lib")
target_link_directories(chip8_emulator SDL2)
