cmake_minimum_required(VERSION 3.29.0)

project(LightYears
    VERSION 1.0.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the FetchContent module to download SFML
include(FetchContent)
set(SFML_LIB_NAME SFML)

# Add the SFML library as a dependency
FetchContent_Declare(
    ${SFML_LIB_NAME}
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1
    GIT_SHALLOW FALSE
)

# Ensures that the SFML library is downloaded and available
FetchContent_MakeAvailable(${SFML_LIB_NAME})

set(LIGHT_YEARS_ENGINE_TARGET_NAME LightYearsEngine)
set(LIGHT_YEARS_GAME_TARGET_NAME LightYearsGame)

add_subdirectory(${LIGHT_YEARS_ENGINE_TARGET_NAME})
add_subdirectory(${LIGHT_YEARS_GAME_TARGET_NAME})


