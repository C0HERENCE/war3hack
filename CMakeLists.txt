cmake_minimum_required(VERSION 3.0.0)
project(war3hack VERSION 0.1.0)

# include(CTest)
# enable_testing()

file(GLOB war3hack_SRC
     "*.h"
     "*.cpp"
     "jass/*.h"
     "jass/*.cpp"
     "jass/string/*.h"
     "jass/string/*.cpp"
     "jass/table/*.h"
     "jass/table/*.cpp"
)

add_library(war3hack SHARED ${war3hack_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
