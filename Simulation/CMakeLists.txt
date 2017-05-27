# set(SOURCES_DEVELOPPER 	developper.cpp goal.cpp goalFactory.cpp)
# set(HEADER_DEVELOPPER 	developper.hpp goal.hpp goalFactory.hpp structureGoal)
# set(SOURCES_MODELL 	modell.cpp modellGenerator.cpp product.cpp productFactory.cpp feature.cpp modell.md featureFactory.cpp)
# set(HEADER_MODELL 	modell.hpp modellGenerator.hpp product.hpp productFactory.hpp feature.hpp featureFactory.hpp)
set(SOURCE_SIMCONTROL	state.cpp simulationControll.cpp stateAbort.cpp stateFeedback.cpp statePrepare.cpp statePresent.cpp stateSimulate.cpp SimulationDaten.cpp simulationControll.cpp state.md)
set(HEADER_SIMCONTROL	state.hpp simulationControll.hpp SimulationDaten.hpp simulationControll.hpp)
set(SOURCE_SIM_CL	EingabeAusgabe.cpp)
set(HEADER_SIM_CL	EingabeAusgabe.hpp)

include_directories(${Boost_INCLUDE_DIR})

# add_library(developper STATIC ${SOURCES_DEVELOPPER} ${HEADER_DEVELOPPER})
# add_library(modell STATIC ${SOURCES_MODELL} ${HEADER_MODELL})
# add_library(reporter STATIC ${SOURCES_REPORTER} ${HEADER_REPORTER})
add_library(simControl STATIC ${SOURCE_SIMCONTROL} ${HEADER_SIMCONTROL})
add_library(SIM_CL STATIC ${SOURCE_SIM_CL} ${HEADER_SIM_CL})

add_executable(simulation main.cpp)

target_link_libraries(simulation websocket ${Boost_LIBRARIES} simControl SIM_CL)
# target_link_libraries(simulationCl ${Boost_LIBRARIES} simControl SIM_CL)

# target_include_directories(developper PUBLIC .)
# target_include_directories(modell PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_include_directories(reporter PUBLIC .)

add_subdirectory(test)