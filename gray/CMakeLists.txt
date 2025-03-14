cmake_minimum_required(VERSION 3.24)
project(mlx_jpeg_grayscale)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(
  Python 3.12.3
  COMPONENTS Interpreter Development.Module
  REQUIRED)
execute_process(
  COMMAND "${Python_EXECUTABLE}" -m mlx --cmake-dir
  OUTPUT_STRIP_TRAILING_WHITESPACE
  OUTPUT_VARIABLE MLX_ROOT)

find_package(MLX CONFIG REQUIRED)

# Download STB Image headers
include(FetchContent)
FetchContent_Declare(
  stb
  GIT_REPOSITORY https://github.com/nothings/stb.git
  GIT_TAG master
)
FetchContent_MakeAvailable(stb)

# Add executable
add_executable(grayscale_converter grayscale_converter.cpp)

# Include STB directory
target_include_directories(grayscale_converter PRIVATE ${stb_SOURCE_DIR})

# Link against MLX libraries
target_link_libraries(grayscale_converter PRIVATE mlx)
