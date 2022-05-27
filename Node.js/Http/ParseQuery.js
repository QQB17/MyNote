var http = require('http');
var url = require('url');

// create a server object
http.createServer(function (req,res){
    res.writeHead(200, {'Content-Type' : 'Text/plain'}); // write a response to the client
    res.write("Request url from the client: " + req.url + "\n");

    // Use the url module to turn the querystring into an object
    var q = url.parse(req.url, true).query;

    // Test - /?month=June&year=2022
    var txt = q.year + " " + q.month;
    res.end(txt); // end the response
}).listen(8080); // the server objec listent on port 8080