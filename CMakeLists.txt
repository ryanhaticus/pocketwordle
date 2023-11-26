cmake_minimum_required(VERSION 3.24.2)
project(PocketWordle)

# Set compiler flags
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add sources
file(GLOB BASE_SOURCES ./src/*.cpp)
file(GLOB_RECURSE SUBDIR_SOURCES ./src/**/*.cpp)
set(SOURCES ${BASE_SOURCES} ${SUBDIR_SOURCES})
add_executable(pocketwordle ${SOURCES})

# Add Curses
find_package(Curses REQUIRED)

if(CURSES_FOUND)
  target_link_libraries(pocketwordle PRIVATE ${CURSES_LIBRARIES})
  target_include_directories(pocketwordle PRIVATE ${CURSES_INCLUDE_DIRS})
else()
  message(FATAL_ERROR "Curses not found. Please install ncurses to continue.")
endif()