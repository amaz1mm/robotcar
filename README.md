## Uploading the firmware

1. Install platform.io :

        sudo easy_install pip
        sudo pip install -U platformio
        sudo rm -rf $HOME/.platformio/

2. Upload the firmware :

* Remember to disconnect the WiFi shield(green board) before uploading the firmware.

        cd firmware
        pio run --target upload

## Running the demo

1. Install the Node modules :

        cd ui
        npm install

2. Run the car :
* Connect your machine to the car's access point - GEEKOUT* and run the control software

        cd ui
        node server.js