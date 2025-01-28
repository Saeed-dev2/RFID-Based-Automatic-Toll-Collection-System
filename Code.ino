#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h> // Include the Servo library

#define RST_PIN 9
#define SS_PIN 10

byte readCard[4];
String My_ID = "B3156C9F";
String ID = "";

MFRC522 mfrc522(SS_PIN, RST_PIN);
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1);
Servo servo; // Create a servo object

void setup()
{
  SPI.begin();
  mfrc522.PCD_Init();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  servo.attach(6); // Attach the servo to pin 6

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print("Scan Your Card...");
  display.display();
}

void loop()
{
  while (getID())
  {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(1);

    if (ID == My_ID)
    {
      display.print("ACCESS GRANTED!");
      openServo(); // Call the openServo function if access is granted
    }
    else
    {
      display.print("ACCESS DENIED!");
    }

    display.display();
    display.setCursor(0, 10);
    display.print(" ID : ");
    display.print(ID);
    display.display();

    delay(2000);

    display.clearDisplay();
    display.print(" Access Control ");
    display.setCursor(0, 10);
    display.print("Scan Your Card...");
    display.display();
    closeServo(); // Call the closeServo function after a delay
  }
}

boolean getID()
{
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return false;
  }
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return false;
  }
  ID = "";
  for (uint8_t i = 0; i < 4; i++)
  {
    //readCard[i] = mfrc522.uid.uidByte[i];
    ID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  ID.toUpperCase();
  mfrc522.PICC_HaltA();
  return true;
}

void openServo()
{
  servo.write(90); // Set the servo to the open position (adjust the angle as needed)
  delay(1000);    // Delay to allow the servo to move
}

void closeServo()
{
  servo.write(0); // Set the servo to the closed position (adjust the angle as needed)
  delay(1000);   // Delay to allow the servo to move
}
