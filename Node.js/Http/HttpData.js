var http = require('http');
var url = require('url');

http.createServer(function(req,res) {
    res.writeHead(200, {'Content-Type': 'text/html'});

    // parse url
    var q = url.parse(req.url, true);
    console.log("Get URL Object information:")
    console.log(q);;

    console.log("http.IncomingMessage:");
    console.log(req);

    console.log("http.ServerResponse:");
    console.log(res);
    
    return res.end();
}).listen(8080);