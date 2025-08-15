# Arduino-Water-Level-Monitoring-with-I2C-LCD-and-LEDs
This sketch is a Water Level Monitoring System using Arduino, LCD, and LEDs.

🔍 How it works
1️⃣ Hardware used

Arduino (Uno, Nano, etc.)

Analog water level sensor (e.g., resistive or capacitive type on A0)

16×2 I2C LCD display (address 0x27)

2 LEDs for visual high-level indication

2️⃣ Program flow

Setup:

Initialize LCD and turn on backlight.

Configure 2 LEDs as output pins.

Begin Serial communication for monitoring.

Loop:

Read the water level from the analog sensor.

Display the water level value on the LCD.

If the water level exceeds the highLevelThreshold (600), turn on both LEDs and display “FULL”.

Otherwise, turn off LEDs and display “LOW”.

Update every 1 second.

3️⃣ Notes

highLevelThreshold can be adjusted depending on your water tank’s characteristics.

LCD provides real-time visual feedback, while LEDs give instant status indication
