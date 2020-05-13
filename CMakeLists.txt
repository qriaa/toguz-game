cmake_minimum_required(VERSION 3.17.2)
project(toguz-game VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_BUILD_TYPE Debug)

SET(SFML_DIR /usr/local/lib/SFML-2.5.1/lib/cmake/SFML)
message("SFML_DIR "  ${SFML_DIR})
find_package(SFML 2 COMPONENTS graphics window system)

set( sourceFilesLocation ${CMAKE_SOURCE_DIR}/Toguz\ Algorithm/src/)
set( headerFilesLocation ${CMAKE_SOURCE_DIR}/Toguz\ Algorithm/include/)

set( sourceFilesList 
	"Application.cpp" 
	"Board.cpp" 
	"Button.cpp" 
	"DialogueBox.cpp" 
	"DialogueCloseButton.cpp" 
	"DragBar.cpp" 
	"GameFinishBox.cpp" 
	"GameObject.cpp" 
	"GameState.cpp" 
	"HasText.cpp" 
	"HoleButton.cpp" 
	"Kazan.cpp" 
	"MenuState.cpp" 
	"NoText.cpp" 
	"ObjectManager.cpp" 
	"State.cpp" 
	"StateButton.cpp" 
	"StateManager.cpp" 
	"TextBehavior.cpp" 
	"TuzSlot.cpp"
	)

set( headerFilesList
	"Application.h" 
	"Board.h" 
	"Button.h" 
	"DialogueBox.h" 
	"DialogueCloseButton.h" 
	"DragBar.h" 
	"GameFinishBox.h" 
	"GameObject.h" 
	"GameState.h" 
	"HasText.h" 
	"HoleButton.h" 
	"Kazan.h" 
	"MenuState.h" 
	"NoText.h" 
	"ObjectManager.h" 
	"State.h" 
	"StateButton.h" 
	"StateManager.h" 
	"TextBehavior.h" 
	"TuzSlot.h"
	)

list(TRANSFORM sourceFilesList PREPEND ${sourceFilesLocation})
list(TRANSFORM headerFilesList PREPEND ${headerFilesLocation})

add_library(toguzLib STATIC ${sourceFilesList} ${headerFilesList})
target_include_directories(toguzLib PUBLIC ${CMAKE_SOURCE_DIR}/Toguz\ Algorithm/include)
target_include_directories(toguzLib PRIVATE /usr/local/lib/SFML-2.5.1/include/)

add_executable(toguz-game "Toguz Algorithm/main.cpp")
target_include_directories(toguz-game PRIVATE ${headerFilesLocation})

target_link_libraries(toguz-game PUBLIC toguzLib)
target_link_libraries(toguz-game PUBLIC sfml-graphics sfml-window sfml-system)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
