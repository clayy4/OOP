 cmake_minimum_required(VERSION 3.12)

 project("lab4" CXX)

 set(CMAKE_CXX_STANDARD 20)
 set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
add_library(VAMPIRE "library/vampire.cpp")

add_executable(${PROJECT_NAME} "main.cpp" "game.cpp")

target_link_libraries(${PROJECT_NAME} VAMPIRE)
target_include_directories(${PROJECT_NAME} PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/library)


 if(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "G++")
   target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Weffc++" "-Wextra" "-Wpedantic")
 elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
   if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
     string(REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
   endif()
   target_compile_options(${PROJECT_NAME} PRIVATE "/W4" "/utf-8")
 endif()