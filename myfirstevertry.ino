#include <MFRC522.h>
#include <SPI.h>
#include <ArduinoJson.h>

#define SDA_PIN 5
#define RST_PIN 22

MFRC522 mfrc522(SDA_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

void setup() {
  // put your setup code here, to run once:
  StaticJsonDocument<200> doc;
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  //Serial.println("Awaiting for a card");
  //for (byte i = 0; i < 6; i++) {
  //  key.keyByte[i] = 0xFF;
  //}
  //dump_byte_array(key.keyByte, MFRC522::MF_KEY_SIZE, doc);
}

void loop() {
  // put your main code here, to run repeatedly:
  //check jika ada kartu atau nggk jangkauan sensor
  if (!mfrc522.PICC_IsNewCardPresent()){
    return;
  }

  //check jika dapat membaca serial number
  if (!mfrc522.PICC_ReadCardSerial()){
    return;
  }

  dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
  
  /*String cardSerial = "";
  Serial.println(mfrc522.uid.size);
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    cardSerial += mfrc522.uid.uidByte[i];
  }

  Serial.println(cardSerial);
  Serial.println("================================");
  delay(1000);
  */
}

/*void dump_byte_array_loop(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }

    for (byte i = 0; i < bufferSize; i++) {
        doc["rfid_serial"] = (buffer[i] < 0x10 ? " 0" : " ");
        doc["rfid_serial"] = (buffer[i], HEX);
    }
    doc["scan_number"] = 1;
    serializeJson(doc, Serial);
    delay(2000);
*/

void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
    Serial.println();
    delay(250);
}
