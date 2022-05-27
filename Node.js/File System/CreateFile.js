var fs = require('fs');

// Append content to file if file exists,
// else create a new file and add the content.
fs.appendFile('newfile.txt','Create a file using "fs.appendFile".\n', function(err){
    if(err) throw err;
    console.log('Saved content to "newfile.txt".');
});

// Create an empty file
fs.open('newfile2.txt','w', function(err,file){
    if(err) throw err;
    console.log('Create an empty file.');
});

fs.writeFile('newfile3.txt','Create a file using "fs.writeFile".', function(err) {
    if(err) throw err;
    console.log('Saved content to "newfile3.txt".');
});