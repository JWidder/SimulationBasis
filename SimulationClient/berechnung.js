function start()
{
    connected = document.getElementById("connected");
    log = document.getElementById("log");
    chat = document.getElementById("chat");
    form = chat.form;
    state = document.getElementById("status");

    if (window.WebSocket === undefined)
    {
        state.innerHTML = "sockets not supported";
        state.className = "fail";
    }
    else
    {
        if (typeof String.prototype.startsWith != "function")
        {
            String.prototype.startsWith = function (str)
            {
                return this.indexOf(str) == 0;
            };
        }
    
        window.addEventListener("load", onLoad, false);
    }
}

	/*
	Diese Funktion wird beim Laden der Seite durch "addEventListener" 
	aufgerufen. 
	
	Referenz: https://www.w3schools.com/jsref/event_onload.asp
	*/
    function onLoad()
    {
        var wsUri = "ws://127.0.0.1:7777";  

		// Registrieren der 
        websocket = new WebSocket(wsUri);
        websocket.onopen = function(evt) { onOpen(evt) };
        websocket.onclose = function(evt) { onClose(evt) };
        websocket.onmessage = function(evt) { onMessage(evt) };
        websocket.onerror = function(evt) { onError(evt) };
    }
  
    function onOpen(evt)
    {
        state.className = "success";
        state.innerHTML = "Connected to server";	

		var mesage  = { 
			"application"  : "Simulation",
			"Version"  : 1 ,
			"Variante" : 1 ,
			"Revision" : 1
		};
		
		var jsonString = JSON.stringify(mesage);
		
       websocket.send(jsonString);
    }
  
    function onClose(evt)
    {
        state.className = "fail";
        state.innerHTML = "Not connected";
        connected.innerHTML = "0";        
    }
  
    function onMessage(evt)
    {
        // There are two types of messages: 
        //     1. a chat participant message itself
        //     2. a message with a number of connected chat participants
  
        var message = evt.data;
	
        if (message.startsWith("log:"))
        {
            message = message.slice("log:".length);
            log.innerHTML = '<li class="message">' + message + "</li>" + log.innerHTML;	
        }
        else if (message.startsWith("connected:"))
        {
            message = message.slice("connected:".length);
            connected.innerHTML = message;	
        }    
    }

    function onError(evt)
    { 
        state.className = "fail";
        state.innerHTML = "Communication error";
    }
	
    function addMessage()
    {
        // var message = chat.value + " " + chat1.value + " " + chat2.value;
		
		var mesage  = { 
			"quality"  : chat.value,
			"function" : chat1.value,
			"kosten"   : chat2.value,
		};
		
		var jsonString = JSON.stringify(mesage);
		
       websocket.send(jsonString);
    }	