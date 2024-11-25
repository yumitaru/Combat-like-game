cmake_minimum_required(VERSION 3.22)
project(Combat-like-game)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Combat-like-game main.cpp
        Bullet1.cpp
        Bullet1.h
        Bullet2.cpp
        Bullet2.h
        Game.cpp
        Game.h
        LinkedList1.cpp
        LinkedList1.h
        LinkedList2.cpp
        LinkedList2.h
        LinkedListNode1.cpp
        LinkedListNode1.h
        LinkedListNode2.cpp
        LinkedListNode2.h
        LoadGame.cpp
        LoadGame.h
        SaveGame.cpp
        SaveGame.h
        Tank1.cpp
        Tank1.h
        Tank2.cpp
        Tank2.h
        # GameEngine.cpp
        # GameEngine.hpp
        State.cpp
        State.h
        GameState.cpp
        GameState.h
        # States/MenuState.cpp
        # States/MenuState.hpp
                                )
target_link_libraries(Combat-like-game PRIVATE sfml-graphics)
target_compile_features(Combat-like-game PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET Combat-like-game
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Combat-like-game>
            VERBATIM)
endif()