var SerialPort = require('serialport');
// Change your SerialPort here
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

var connect = require("connect");
var serveStatic = require("serve-static");

connect()
  .use(serveStatic(__dirname))
  .listen(8000, function() {
    console.log("Server running on 8000...");
  });

var http = require("http");
http
  .createServer(function(req, res) {
    console.log(req.url);
    res.setHeader("Access-Control-Allow-Origin", "*");
    res.setHeader(
      "Access-Control-Allow-Headers",
      "Origin, X-Requested-With, Content-Type, Accept"
    );
    res.writeHead(200, { "Content-Type": "text/html" });
    res.write(req.url);

    switch (req.url) {
      case "/up":
        serialport.write("m_f#");
        break;

      case "/down":
        serialport.write("m_b#");
        break;

      case "/left":
        serialport.write("t_l#");
        break;

      case "/right":
        serialport.write("t_r#");
        break;
    }
    res.end();
  })
  .listen(8080);
