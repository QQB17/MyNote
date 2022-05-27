var fs = require('fs');
fs.stat('newfile.txt', function(err,stats) {
    if(err) throw err;
    console.log('Stats object: ');
    console.log(stats);
})
