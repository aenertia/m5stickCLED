## M5StickCLED

A fork of the execelent WLED project for the M5StickC - the M5StickC makes an excellent LED Controller and offers a range of possibilities such as MIC/Audio reactive

### M5StickC Specific features:

- Full IR Support on Esp32 basic Send and Receive
- Basic LCD Display
- Some Changes to the Neopixelbus driver to better handle the ESP32
- Uses the M5StickC arduino library for Power control
- Able to use the IMU on the M5StickC (basic input/reactive support)

### Known issues
- I2C / Wire / Grove init seems to result in bootloop
- Gyro Support/Feedback incomplete
- Better ifdef for m5stick and generalized display framework
- Implement button 2 function hooks
- Have not investigated using the I2S bus for the MEMS Mics (possible audio reactive Strip)
- Implement the Multi-strip support that others have added to WLED 

### Untested

![WLED logo](https://raw.githubusercontent.com/Aircoookie/WLED/master/wled_logo.png)   

[![](https://img.shields.io/github/release/Aircoookie/WLED.svg?style=flat-square)](https://github.com/Aircoookie/WLED/releases)
[![](https://img.shields.io/discord/473448917040758787.svg?colorB=blue&label=discord&style=flat-square)](https://discord.gg/KuqP7NE)
[![](https://img.shields.io/badge/quick_start-wiki-blue.svg?style=flat-square)](https://github.com/Aircoookie/WLED/wiki)
[![](https://img.shields.io/badge/app-wled-blue.svg?style=flat-square)](https://github.com/Aircoookie/WLED-App)

## Welcome to my project WLED!

A fast and feature-rich implementation of an ESP8266/ESP32 webserver to control NeoPixel (WS2812B) LEDs!

### Features:
- WS2812FX library integrated for 80 special effects
- FastLED noise effects and palettes
- Customizable Mobile and desktop UI with color and effect controls
- Settings page - configuration over network
- Access Point and station mode - automatic failsafe AP
- Support for RGBW strips
- 25 user presets to save and load colors/effects easily, supports cycling through them.
- Macro functions to automatically execute API calls
- Nightlight function (gradually dims down)
- Full OTA software updatability (HTTP + ArduinoOTA), password protectable
- Configurable analog clock + support for the Cronixie kit by Diamex
- Configurable Auto Brightness limit for safer operation

### Supported light control interfaces:
- WLED Android app
- HTTP and JSON request APIs
- Blynk IoT
- MQTT
- E1.31
- Hyperion
- UDP realtime
- Alexa voice control (including dimming and color)
- Sync to Philips hue lights
- Adalight (PC ambilight via serial)
- Sync color of multiple WLED devices (UDP notifier)
- Infrared remotes (24-key RGB, receiver required)
- Simple timers/schedules (time from NTP, timezones/DST supported)

### Quick start guide and documentation:

See the [wiki](https://github.com/Aircoookie/WLED/wiki)!

### Other

Licensed under the MIT license  
Credits [here](https://github.com/Aircoookie/WLED/wiki/Contributors-&-About)!

Uses Linearicons by Perxis!

Join the Discord [server](https://discord.gg/KuqP7NE) to discuss everything about WLED!  
You can also send me mails to [dev.aircoookie@gmail.com](mailto:dev.aircoookie@gmail.com).  
If WLED really brightens up your every day, you can [![](https://img.shields.io/badge/send%20me%20a%20small%20gift-paypal-blue.svg?style=flat-square)](https://paypal.me/aircoookie)
