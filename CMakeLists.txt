project(cySkat)


#
# CMake
#

cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

set(BIN_PATH "bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${BIN_PATH}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${BIN_PATH}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${BIN_PATH}")

#
# Compiler
#

set(GCC_COMPILE_FLAGS "-Wall -Wextra -ansi -pedantic")
#set(GCC_COMPILE_FLAGS "-Wall -Wextra -ansi -pedantic -O3")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

#set(CMAKE_BUILD_TYPE RELEASE)

include_directories(src)
include_directories(../Cyanide/code/include)
link_directories(../Cyanide/build/lib)

set(SOURCES
    src/structures/Card.hpp
    src/structures/Card.cpp
    src/structures/Deck.hpp
    src/structures/Deck.cpp
    src/structures/Dealer.hpp
    src/structures/Dealer.cpp
    src/structures/Hand.hpp
    src/structures/Hand.cpp
    src/structures/Table.hpp
    src/structures/Table.cpp
    src/game/Game.cpp
    src/game/Game.hpp
    src/game/Player.cpp
    src/game/Player.hpp)

add_executable(cySkat src/main.cpp ${SOURCES})

target_link_libraries(cySkat cygui cyinput cymath cysystem cyutil cyvideo)
