cmake_minimum_required(VERSION 3.14)

project("lab5" CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Создаем библиотеку
add_library(CHARACTERS "Characters/character.cpp" "Characters/vampire.cpp" "Characters/assasin.cpp" "Characters/gunslinger.cpp" "Characters/paladin.cpp" "library/wrapcharacter.h")
add_library(GAME "library/dice.cpp" "library/game.cpp" "library/wrapcharacter.h")

# Основной исполняемый файл
add_executable(${PROJECT_NAME}  "main.cpp" "library/wrapcharacter.h")
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/library)
target_link_libraries(${PROJECT_NAME} GAME CHARACTERS)

# Настройки компилятора
if(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR
   CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
   CMAKE_CXX_COMPILER_ID STREQUAL "G++")
  target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Weffc++" "-Wextra" "-Wpedantic")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  endif()
  target_compile_options(${PROJECT_NAME} PRIVATE "/W4" "/utf-8")
endif()