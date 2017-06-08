set(SOURCE_SIMCONTROL	state.cpp simulationControll.cpp stateAbort.cpp stateFeedback.cpp statePrepare.cpp statePresent.cpp stateSimulate.cpp SimulationDaten.cpp SimulateDevelopment.cpp state.md)
set(HEADER_SIMCONTROL	state.hpp simulationControll.hpp SimulationDaten.hpp SimulateDevelopment.hpp)
set(SOURCE_SIM_CL	EingabeAusgabe.cpp)
set(HEADER_SIM_CL	EingabeAusgabe.hpp)

include_directories(${Boost_INCLUDE_DIR})

add_library(simControl STATIC ${SOURCE_SIMCONTROL} ${HEADER_SIMCONTROL})
add_library(SIM_CL STATIC ${SOURCE_SIM_CL} ${HEADER_SIM_CL})

add_executable(simulation main.cpp)
target_link_libraries(simulation websocket ${Boost_LIBRARIES} simControl SIM_CL)

# target_include_directories(developper PUBLIC .)
# target_include_directories(modell PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_include_directories(reporter PUBLIC .)

add_subdirectory(test)