var fs = require('fs');

fs.open('newfile2.txt','w', function(err,file){
    if(err) throw err;
    console.log(file.valueOf());
})