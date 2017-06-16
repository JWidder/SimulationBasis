include_directories(${Boost_INCLUDE_DIR})

add_executable(test.simulation 
	testBestellung.cpp
	testCustomer.cpp
	testDevelopment.cpp
	testLieferung.cpp
	testModelCustomer.cpp
	testModelDevelopment.cpp
	testReporter.cpp 
	testSimulateDevelopment.cpp
	testSimulation.cpp
) 

target_link_libraries(test.simulation ${Boost_LIBRARIES} simControl)

add_custom_target(TestSimulation
  COMMAND ${CMAKE_COMMAND} -E copy ${BOOST_ROOT}/boost_unit_test_framework-vc141-mt-gd-1_64.dll  ${CMAKE_CURRENT_BINARY_DIR}/DEBUG/boost_unit_test_framework-vc141-mt-gd-1_64.dll
)

add_dependencies(simulation TestSimulation)
