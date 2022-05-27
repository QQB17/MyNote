var http = require('http');

// create a server object
http.createServer(function (req,res){
    res.writeHead(200, {'Content-Type' : 'Text/plain'}); // write a response to the client
    res.write("Request url from the client: " + req.url);
    res.end(); // end the response
}).listen(8080); // the server objec listent on port 8080