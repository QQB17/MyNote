var fs = require('fs');

fs.appendFile('newfile2.txt','Append new text using "fs.appendFile".', function(err){
    if(err) throw err;
    console.log('Update content to "newfile2.txt".');
});


fs.writeFile('newfile3.txt','Replaces the text using "fs.writeFile".',function(err){
    if(err) throw err;
    console.log('Replace content to "newfile3.txt".');
});