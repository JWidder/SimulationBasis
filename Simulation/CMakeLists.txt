set(SOURCE_SIMCONTROL	state.cpp 
			simulationControll.cpp 
			stateAbort.cpp 
			stateFeedback.cpp 
			statePrepare.cpp 
			statePresent.cpp 
			stateSimulate.cpp 
			SimulateDevelopment.cpp 
			Customer.cpp
			Development.cpp
			ModelCustomer.cpp
			ModelDevelopment.cpp
			Reporter.cpp
			Bestellung.cpp
			Lieferung.cpp
			state.md)
set(HEADER_SIMCONTROL	state.hpp 
			CustomerErgebnis.hpp
			simulationControll.hpp 
			SimulationDaten.hpp 
			SimulationErgebnis.hpp
			ModelCustomer.hpp
			Customer.hpp
			Development.hpp
			Reporter.hpp
			ModelDevelopment.hpp
			Bestellung.hpp
			Lieferung.hpp
			SimulateDevelopment.hpp
			BestellungErgebnis.hpp)
set(SOURCE_SIM_CL	EingabeAusgabe.cpp)
set(HEADER_SIM_CL	EingabeAusgabe.hpp)

include_directories(${Boost_INCLUDE_DIR})

add_library(simControl STATIC ${SOURCE_SIMCONTROL} ${HEADER_SIMCONTROL})
add_library(SIM_CL STATIC ${SOURCE_SIM_CL} ${HEADER_SIM_CL})

add_executable(simulation main.cpp)

target_link_libraries(simulation websocket ${Boost_LIBRARIES} simControl SIM_CL)
target_include_directories(simControl PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(test)