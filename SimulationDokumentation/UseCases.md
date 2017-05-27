# Use Cases and Scenarios

[$UseCase 1] Basic Simulation Flow

### Prerequesits:

 - __Server__ starts and listens on port 7777
 - __Client__ is a web application and started in a web browser.

### Scenario Standard Communication
 
 - __Client:__ Starts in teh Webbrauowser and opens a communication via a 
			websocket with the server.
 
 - __Server:__ answers by sending a list of options 
 
  - __Client:__ selects the option to run and sends the yeelction to the server. 
  
  - __Server:__ starts the simulation and sends the client the simulation result 
			and the list of possible next action.
  
  - __Client:__ displays the simulation result and sends the next selected action 
			to the server
  
 ### Open Points
 
  - How to close technicaly a Web application