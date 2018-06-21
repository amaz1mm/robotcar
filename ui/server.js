var SerialPort = require('serialport');
var serialport = new SerialPort('/dev/rfcomm0', {
    autoOpen: false
});

var keypress = require('keypress');

serialport.open(function(err) {
    if (err) {
        return console.log('Error opening port: ', err.message);
    }
});

// The open event is always emitted
serialport.on('open', function() {
    // open logic
});

// make `process.stdin` begin emitting "keypress" events 
keypress(process.stdin);

// listen for the "keypress" event 
process.stdin.on('keypress', function(ch, key) {
    if (key && key.ctrl && key.name == 'c') {
        process.exit();
    }

    switch (key.name) {
        case 'up':
            serialport.write('m_f#');
            break;

        case 'down':
            serialport.write('m_b#');
            break;

        case 'left':
            serialport.write('t_l#');
            break;

        case 'right':
            serialport.write('t_r#');
            break;
    }
});

process.stdin.setRawMode(true);
process.stdin.resume();