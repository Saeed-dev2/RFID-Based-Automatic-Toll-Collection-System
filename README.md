# RFID-Based Access Control System with Servo Lock

## Overview
This project implements an RFID-based access control system using an **MFRC522 RFID reader**, an **OLED display (SSD1306)**, and a **servo motor** for locking and unlocking mechanisms. When an authorized RFID card is scanned, access is granted, and the servo unlocks. If an unauthorized card is scanned, access is denied.

## Features
- **RFID Authentication**: Reads RFID tags and verifies against a predefined ID.
- **OLED Display Feedback**: Provides real-time access status and prompts.
- **Servo Control**: Opens and closes the lock upon authentication.
- **Efficient Power Usage**: Optimized to minimize energy consumption.

## Components Required
- **Microcontroller**: Arduino (Uno, Mega, or compatible)
- **RFID Module**: MFRC522
- **Display**: Adafruit SSD1306 OLED (128x64)
- **Servo Motor**: SG90 or similar
- **Jump Wires**: For connections
- **Power Supply**: 5V source (e.g., USB or battery pack)

## Circuit Diagram
| Component          | Pin Connection |
|-------------------|---------------|
| MFRC522 SS       | Pin 10        |
| MFRC522 RST      | Pin 9         |
| MFRC522 MOSI     | Pin 11        |
| MFRC522 MISO     | Pin 12        |
| MFRC522 SCK      | Pin 13        |
| OLED SDA         | A4 (SDA)      |
| OLED SCL         | A5 (SCL)      |
| Servo Signal     | Pin 6         |

## Installation & Usage
### **1. Setup the Hardware**
- Connect all components as per the circuit diagram.
- Ensure power connections are stable.

### **2. Upload the Code**
- Install the required Arduino libraries:
  - `SPI.h`
  - `MFRC522.h`
  - `Wire.h`
  - `Adafruit_GFX.h`
  - `Adafruit_SSD1306.h`
  - `Servo.h`
- Open the provided `main.ino` file in Arduino IDE.
- Select the correct board and port.
- Upload the code.

### **3. Operation**
1. The OLED display will prompt **"Scan Your Card..."**.
2. Place an RFID card near the reader.
3. If the scanned ID matches the predefined ID:
   - The display shows **"ACCESS GRANTED!"**.
   - The servo unlocks.
4. If the ID does not match:
   - The display shows **"ACCESS DENIED!"**.
   - The servo remains locked.
5. The system resets and waits for the next scan.

## Customization
- Modify the **`My_ID`** variable in the code to change the authorized RFID tag.
- Adjust the servo angles in **`openServo()`** and **`closeServo()`** for different lock mechanisms.
- Modify the display messages to suit your application.

## Troubleshooting
| Issue | Solution |
|-------|----------|
| No response from RFID reader | Check wiring and ensure proper power supply. |
| Wrong card detected | Ensure the card's ID is correctly stored in `My_ID`. |
| Servo not moving | Verify the servo connection and pin assignment. |
| Display not working | Ensure the OLED is correctly connected to SDA and SCL. |

## Future Enhancements
- **Multiple RFID Card Support**: Store multiple valid IDs.
- **Wi-Fi Integration**: Log access attempts to a cloud server.
- **Buzzer Alert System**: Sound an alarm for unauthorized attempts.
- **Mobile App Control**: Unlock via Bluetooth or Wi-Fi.

## License
This project is open-source and distributed under the **MIT License**.

## Author
**Muhammad Saeed**  
[GitHub Profile](https://github.com/Saeed-dev2)  

---
### **Contributions are Welcome!**
Feel free to fork this repository, improve the project, and submit a pull request! 🚀

