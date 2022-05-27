var http = require('http');
var url = require('url');
var fs = require('fs');

// create a server object
http.createServer(function (req,res){
     // Use the url module to turn the querystring into an object
     var q = url.parse(req.url, true);
     var filename = "." + q.pathname + ".html";
     console.log(q);
     fs.readFile(filename, function(err,data){
         if(err){
             res.writeHead(404, {'Content-Type' : 'text/html'});
             return res.end("404 Not found");
         }

         res.writeHead(200, {'Content-Type' : 'text/html'}); // write a response to the client
         res.write(data);
         return res.end();
     });
}).listen(8080); // the server objec listent on port 8080