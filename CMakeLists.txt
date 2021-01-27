cmake_minimum_required(VERSION 3.17)
project(Mini_Country)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

set(CMAKE_CXX_FLAGS -pthread)

set(COMMANDER Commander/src/CommandExecuter.cpp
        Commander/src/Command.cpp
        Commander/src/BuildCity.cpp
        Commander/src/BuyTrain.cpp
        Commander/src/SellTrain.cpp
        Commander/src/SendTrain.cpp
        Commander/src/ShowBudget.cpp
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
        Other/src/MaternityHospital.cpp
        Other/src/Warehouse.cpp)

set(SRC main.cpp mainwindow.cpp ${COMMANDER} ${FACTORY} ${SINGLETON} ${OTHER})

include_directories(Other/include/
        ${CMAKE_CURRENT_LIST_DIR}/Commander/include/
        ${CMAKE_CURRENT_LIST_DIR}/Factory/include/
        ${CMAKE_CURRENT_LIST_DIR}/Singleton/include/
        ${CMAKE_CURRENT_LIST_DIR}/Other/include/)

add_executable(${PROJECT_NAME} ${SRC})

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})