cmake_minimum_required(VERSION 3.10)
project(deadass_im_making_a_new_folder)

# Tell CMake to use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/game.cpp
    src/player.cpp
    src/block.cpp
    src/tile.cpp
)


# Include headers
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/raylib/include
)

# Link raylib and system libs
target_link_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/external/raylib/lib
)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} raylib opengl32 gdi32 winmm)
elseif (APPLE)
    target_link_libraries(${PROJECT_NAME} raylib "-framework OpenGL" "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
else() # Linux
    target_link_libraries(${PROJECT_NAME} raylib m pthread dl GL X11)
endif()
