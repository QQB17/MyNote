var fs = require('fs');

fs.rename('newfile3.txt','newfile4.txt', function(err) {
    if(err) throw err;
    console.log('Rename "newfile3" to "newfile2".');
})