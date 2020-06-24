cmake_minimum_required(VERSION 3.1)

project(sfml)

set(CMAKE_PREFIX_PATH ./lib)
find_package(SFML REQUIRED audio network graphics window system)

file(GLOB SRC
    "src/*.h"
    "src/*.cpp"
)


include_directories(src)
add_executable(main 
    main.cpp
    ${SRC}
)
target_link_libraries(main sfml-graphics sfml-system sfml-network sfml-window sfml-audio)
include_directories(${SFML_INCLUDE_DIR})

