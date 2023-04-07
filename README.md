# Hei-Hei-Bot ESP8266

This repository contains the code for a simple ESP8266-based bot called Hei-Hei-Bot, which is controlled via a web server. When the bot is activated, it flashes an LED light with a specific pattern and toggles an output pin. The project uses PlatformIO for building the ESP8266 code and relies on the ESPAsyncWebServer library.

## Features

- Web server for controlling the bot
- LED light pattern
- Toggling an output pin (whhich activates Hei Hei)

## Dependencies

- ESPAsyncWebServer
- FastLED

## Hardware

- ESP8266-based microcontroller
- WS2812 LED strip
- Resistor and capacitor for the LED strip (optional, but recommended)

## Getting Started

### 1. Clone the repository

Clone the repository to your local machine using:

~~~
git clone https://github.com/yourusername/hei-hei-bot_esp8266.git
~~~

### 2. Install PlatformIO

Follow the instructions in the [PlatformIO documentation](https://docs.platformio.org/en/latest/core/installation.html) to install PlatformIO on your machine.

### 3. Configure WiFi Secrets

Create a `wifi_secrets.h` file in the `src` directory and add the following content:

~~~cpp
#define SSID_SECRET "your_wifi_ssid"
#define PASSWORD_SECRET "your_wifi_password"
#define HOSTNAME_SECRET "your_desired_hostname"
~~~

Replace `your_wifi_ssid`, `your_wifi_password`, and `your_desired_hostname` with the appropriate values for your network and device.

### 4. Compile and Upload

Connect your ESP8266-based microcontroller to your computer via USB. In the terminal, navigate to the repository's root directory and run:

~~~
platformio run --target upload
~~~

This will compile the code and upload it to the connected device.

### 5. Test the Hei-Hei-Bot

Once the code is uploaded to the device, it should connect to your Wi-Fi network. Check your router's administration panel to determine the IP address of the Hei-Hei-Bot.

Open a web browser and navigate to `http://<ip_address>/` to activate the Hei-Hei-Bot. The LED light should flash with the programmed pattern, and the output pin should toggle accordingly.

## License

This project is licensed under the [MIT License](LICENSE).
