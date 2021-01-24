cmake_minimum_required(VERSION 3.17)
project(Mini_Country)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -pthread)

set(COMMANDER Commander/src/CommandExecuter.cpp
        Commander/src/Command.cpp
        Commander/src/BuildFactory.cpp
        Commander/src/BuildCity.cpp
        Commander/src/BuyFreightTrain.cpp
        Commander/src/BuyPassengerTrain.cpp
        Commander/src/SendTrain.cpp
        Commander/src/ShowPopulation.cpp
        Commander/src/ShowFactories.cpp
        Commander/src/ShowProducts.cpp
        Commander/src/ShowTrains.cpp
        Commander/src/Help.cpp
        Commander/src/Exit.cpp)

set(FACTORY Factory/src/TrainFactory.cpp
        Factory/src/Train.cpp
        Factory/src/FreightTrain.cpp
        Factory/src/FreightTrainFactory.cpp
        Factory/src/PassengerTrain.cpp
        Factory/src/PassengerTrainFactory.cpp)

set(SINGLETON Singleton/src/World.cpp)

set(OTHER Other/src/City.cpp
        Other/src/ResourceFactory.cpp
        Other/src/CarsTypes.cpp
        Other/src/MaternityHospital.cpp)

set(SRC main.cpp ${COMMANDER} ${FACTORY} ${SINGLETON} ${OTHER})

include_directories(Other/include/
        ${CMAKE_CURRENT_LIST_DIR}/Commander/include/
        ${CMAKE_CURRENT_LIST_DIR}/Factory/include/
        ${CMAKE_CURRENT_LIST_DIR}/Singleton/include/
        ${CMAKE_CURRENT_LIST_DIR}/Other/include/)

add_executable(Mini_City ${SRC})