cmake_minimum_required(VERSION 3.0.0)
project(war3hack VERSION 0.1.0)

# include(CTest)
# enable_testing()

file(GLOB war3hack_SRC
     "*.h"
     "*.cpp"
     "jass/*.h"
     "jass/*.cpp"
     "jass/*/*.h"
     "jass/*/*.cpp"
     "inject/*.h"
     "inject/*.cpp"

     "minhook/src/*"
     "minhook/src/hde/*"
)

add_library(war3hack SHARED ${war3hack_SRC})
target_include_directories(war3hack PRIVATE "minhook/include")


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
