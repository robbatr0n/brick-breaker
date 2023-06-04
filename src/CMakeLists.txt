find_package(raylib 4.2 REQUIRED) # Requires at least version 3.0
find_package(glm REQUIRED)

set(SOURCE_LIST
    ${SOURCE_CODE_DIR}/main.cpp
    ${SOURCE_CODE_DIR}/game.cpp
    ${SOURCE_CODE_DIR}/brick_breaker.cpp
    ${SOURCE_CODE_DIR}/paddle.cpp
    ${SOURCE_CODE_DIR}/ball.cpp
    ${SOURCE_CODE_DIR}/gui.cpp
    ${SOURCE_CODE_DIR}/debug.cpp
)

set(HEADER_LIST
    ${INCLUDE_DIR}/game.hpp
    ${INCLUDE_DIR}/brick_breaker.hpp
    ${INCLUDE_DIR}/paddle.hpp
    ${INCLUDE_DIR}/ball.hpp
    ${INCLUDE_DIR}/gui.hpp
    ${INCLUDE_DIR}/debug.hpp
)

add_executable(${PROJECT_NAME}_run ${SOURCE_LIST} ${HEADER_LIST})
add_library(${PROJECT_NAME}_lib STATIC ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(${PROJECT_NAME}_lib PUBLIC ${INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME}_lib raylib)
target_compile_features(${PROJECT_NAME}_lib PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME}_run PRIVATE ${PROJECT_NAME}_lib)

