set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES Command.h ExitCommand.h Formula.h ExitCommand.cpp Formula.cpp main.cpp)

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})
