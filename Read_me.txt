:Author: Aamirali Tinwala  
:Email: {aamirfiretv777@gmail.com}
:Date: 28/01/2024
:Revision: v1.0
:License: Public Domain

= Project: Temperature & Humidity Sensor with IR-Controlled Display

This project uses a **DHT11 sensor** to measure temperature and humidity, with values displayed on an **I2C LCD** screen. An **IR remote** is used to control the display and toggle LEDs, making it an interactive and educational IoT setup.

It combines sensor readings, user interaction, and real-time feedback through an LCD display, all powered by an Arduino-compatible microcontroller.

== Step 1: Installation

1. Download the sketch files and libraries (DHT, LiquidCrystal_I2C, IRremote).
2. Open the `sketch123.ino` in the Arduino IDE.
3. Install required libraries via the Library Manager:
   - `DHT sensor library`
   - `LiquidCrystal_I2C`
   - `IRremote`
4. Upload the sketch to your Arduino board.
5. Ensure your Serial Monitor is set to 9600 baud for debugging info.

== Step 2: Assemble the circuit

Connect the components according to the `layout.png` schematic.

**Wiring Overview:**

- **DHT11 Sensor (4-pin):**
  - VCC → 5V  
  - GND → GND  
  - DATA → Pin 7  
  - (Not Connected or NC if 4th pin unused)

- **IR Receiver:**
  - Signal → Pin 8  
  - VCC → 5V  
  - GND → GND  

- **I2C LCD (16x2):**
  - SDA → A4  
  - SCL → A5  
  - VCC → 5V  
  - GND → GND  

- **LEDs:**
  - LED 1 (Red?) → Pin 4  
  - LED 2 (Yellow?) → Pin 5  
  - LED 3 (Green?) → Pin 6  
  - Each with 220Ω resistor to GND

== Step 3: Load the code

Upload the code using the Arduino IDE. The device will begin displaying temperature and humidity readings to the serial monitor and respond to IR remote inputs to:

- Toggle individual LEDs
- Display readings on LCD
- Shut off all LEDs and LCD backlight

=== Folder structure

....
 temp_humidity_monitor/           => Arduino sketch folder
 ├── sketch123.ino                => Main Arduino file
 ├── layout.png                   => (optional) circuit layout diagram
 └── ReadMe.adoc                  => This file
....

=== License

This project is released under a Public Domain License.

=== Contributing

To contribute to this project please contact fyre_aspec_
