var fs = require('fs');

// Remove archeive
fs.unlink('newfile3.txt', function(err){
    if(err) throw err;
    console.log('File: "newfile3.txt" was deleted.')
}) 

// Remove directory if that is empty
fs.rmdir('Test',function(err){
    if(err) throw err;
    console.log('Remove the directory');
});

// Remove file and directory
fs.rm('Test', {'recursive': true, 'force': true}, function(err){
    if(err) throw err;
    console.log('Force to remove non-empty content directories');
});