var net = require('net');

var client = new net.Socket();
client.connect(2001, '192.168.1.1', function() {
    console.log('Connected');
	client.write('f\r\n\r\n');
	client.destroy(); // kill client after server's response
});
