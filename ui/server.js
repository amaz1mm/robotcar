var express = require('express');
var app = express();
var server = require('http').createServer(app);
var io = require('socket.io')(server);
var port = process.env.PORT || 8000;

var SerialPort = require('serialport');
var serialport = new SerialPort('/dev/rfcomm0', {
    autoOpen: false
});

var keypress = require('keypress');

server.listen(port, function() {
    console.log('Server listening at port %d', port);
});

app.use(express.static(__dirname));

io.sockets.on('connection', function(socket) {
    socket.emit("hello", "Hello from Server");
    socket.on("hello", function(data) {
        console.log(data);
    });
});

serialport.open(function(err) {
    if (err) {
        return console.log('Error opening port: ', err.message);
    }

    // Because there's no callback to write, write errors will be emitted on the port:
    // serialport.write('f');
});

// The open event is always emitted
serialport.on('open', function() {
    // open logic
});

// make `process.stdin` begin emitting "keypress" events 
keypress(process.stdin);

// listen for the "keypress" event 
process.stdin.on('keypress', function(ch, key) {
    // console.log('got "keypress"', key);
    if (key && key.ctrl && key.name == 'c') {
        process.stdin.pause();
    }

    switch (key.name) {
        case 'up':
            serialport.write('f');
            break;

        case 'down':
            serialport.write('b');
            break;

        case 'left':
            serialport.write('l');
            break;

        case 'right':
            serialport.write('r');
            break;
    }

});

process.stdin.setRawMode(true);
process.stdin.resume();