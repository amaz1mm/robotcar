## Uploading the firmware

1. Install platform.io :

        sudo easy_install pip
        sudo pip install -U platformio
        sudo rm -rf $HOME/.platformio/

2. Upload the firmware :

        cd firmware
        pio run --target upload

## Installing web app

1. Install the Node modules :

        cd ui
        npm install

2. Run the app :

        node server.js