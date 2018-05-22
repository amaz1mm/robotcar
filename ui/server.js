var net = require('net');
var keypress = require('keypress');

// make `process.stdin` begin emitting "keypress" events 
keypress(process.stdin);

var net = require('net');

var client = new net.Socket();
client.connect(2001, '192.168.1.1', function() {
    console.log('Connected');
	
    process.stdin.on('keypress', function(ch, key) {
        if (key && key.ctrl && key.name == 'c') {
            process.exit();
        }
        // listen for the "keypress" event 
        switch (key.name) {
            case 'up':
                client.write('m_f#');
                break;
    
            case 'down':
                client.write('m_b#');
                break;
    
            case 'left':
                client.write('t_l#');
                break;
    
            case 'right':
                client.write('t_r#');
                break;
        }
    });
    
    process.stdin.setRawMode(true);
    process.stdin.resume();
});

