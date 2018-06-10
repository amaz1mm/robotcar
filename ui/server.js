// var net = require('net');
// var keypress = require('keypress');

// // make `process.stdin` begin emitting "keypress" events 
// keypress(process.stdin);

// var net = require('net');

// var client = new net.Socket();
// client.connect(2001, '192.168.1.1', function() {
//     console.log('Connected');
	
//     process.stdin.on('keypress', function(ch, key) {
//         if (key && key.ctrl && key.name == 'c') {
//             process.exit();
//         }
//         // listen for the "keypress" event 
//         switch (key.name) {
//             case 'up':
//                 client.write('m_f#');
//                 break;
    
//             case 'down':
//                 client.write('m_b#');
//                 break;
    
//             case 'left':
//                 client.write('t_l#');
//                 break;
    
//             case 'right':
//                 client.write('t_r#');
//                 break;
//         }
//     });
    
//     process.stdin.setRawMode(true);
//     process.stdin.resume();
// });

var net = require('net');
var keypress = require('keypress');

// make `process.stdin` begin emitting "keypress" events 
keypress(process.stdin);

var net = require('net');

var http = require('http');

var connect = require('connect');
var serveStatic = require('serve-static');

connect().use(serveStatic(__dirname)).listen(8000, function(){
    console.log('Server running on 8000...');
});

http.createServer(function (req, res) {
    console.log(req.url);
    res.setHeader("Access-Control-Allow-Origin", "*");
    res.setHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    switch(req.url) {
            case '/up':
                client.write('m_f#');
                res.writeHead(200, {'Content-Type': 'text/plain'});
                break;
    
            case '/down':
                client.write('m_b#');
                res.writeHead(200, {'Content-Type': 'text/plain'});
                break;
    
            case '/left':
                client.write('t_l#');
                res.writeHead(200, {'Content-Type': 'text/plain'});
                break;
    
            case '/right':
                client.write('t_r#');
                res.writeHead(200, {'Content-Type': 'text/plain'});
                break;
    }
    res.end();
}).listen(8080);

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



