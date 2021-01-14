cmake_minimum_required(VERSION 3.17)
project(Mini_City)

set(CMAKE_CXX_STANDARD 20)
set(COMMANDER Commander/src/CommandExecuter.cpp
              Commander/src/Command.cpp
              Commander/src/BuildFactory.cpp
              Commander/src/BuildShop.cpp
              Commander/src/Buy.cpp
              Commander/src/Deliver.cpp
              Commander/src/Produice.cpp
              Commander/src/Help.cpp
              Commander/src/Exit.cpp)

set(FACTORY Factory/src/AbstractFactory.cpp )
set(SRC main.cpp src/Shop.cpp ${COMMANDER} ${FACTORY})

include_directories(${CMAKE_CURRENT_LIST_DIR}/include/
                    ${CMAKE_CURRENT_LIST_DIR}/Commander/include/
                    ${CMAKE_CURRENT_LIST_DIR}/Factory/include/)

add_executable(Mini_City ${SRC})