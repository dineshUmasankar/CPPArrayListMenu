set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})
# set(SOURCES AppMessages.h Command.h ExitCommand.h ListCommand.h Formula.h AppMessages.cpp ExitCommand.cpp ListCommand.cpp Formula.cpp main.cpp)

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})
