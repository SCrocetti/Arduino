#include <SPI.h>
#include <MFRC522.h>

/* ================== RFID ================== */
constexpr uint8_t RST_PIN = 9;   // Reset RC522
constexpr uint8_t SS_PIN  = 10;  // SDA / SS RC522

MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
/* ================== PINS ================== */
constexpr uint8_t READ_BUTTON_PIN  = 2;
constexpr uint8_t WRITE_BUTTON_PIN = 3;

constexpr uint8_t READ_LED_PIN  = 4;
constexpr uint8_t WRITE_LED_PIN = 5;

/* ================== STATE ================== */
enum Mode {
  MODE_IDLE,
  MODE_READ,
  MODE_WRITE
};

Mode currentMode = MODE_IDLE;

/* ================== SETUP ================== */
void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  // Use default key (FF FF FF FF FF FF)
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

  pinMode(READ_BUTTON_PIN, INPUT);
  pinMode(WRITE_BUTTON_PIN, INPUT);

  pinMode(READ_LED_PIN, OUTPUT);
  pinMode(WRITE_LED_PIN, OUTPUT);

  setMode(MODE_READ);  // Default mode at startup
}

/* ================== LOOP ================== */
void loop() {
  handleButtons();

  if (currentMode == MODE_READ) {
    readCard();
  }
  else if(currentMode == MODE_WRITE){
    writeCard();
  }
}

/* ================== FUNCTIONS ================== */

void handleButtons() {
  if (digitalRead(READ_BUTTON_PIN) == HIGH) {
    setMode(MODE_READ);
  } 
  else if (digitalRead(WRITE_BUTTON_PIN) == HIGH) {
    setMode(MODE_WRITE);
  }
}

void setMode(Mode mode) {
  if (currentMode == mode) return;

  currentMode = mode;

  digitalWrite(READ_LED_PIN,  mode == MODE_READ  ? HIGH : LOW);
  digitalWrite(WRITE_LED_PIN, mode == MODE_WRITE ? HIGH : LOW);

  Serial.print("Mode: ");
  Serial.println(mode == MODE_READ ? "READ" : "WRITE");
}

void readCard() {
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  Serial.print("Card UID:");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
  }
  Serial.println("\n");

  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++)
    key.keyByte[i] = 0xFF;

  byte buffer[18];
  byte size = sizeof(buffer);

  // Authenticate + read ALL sectors
  for (byte sector = 0; sector < 16; sector++) {

    byte firstBlock = sector * 4;

    byte status = rfid.PCD_Authenticate(
      MFRC522::PICC_CMD_MF_AUTH_KEY_A,
      firstBlock,
      &key,
      &rfid.uid
    );

    if (status != MFRC522::STATUS_OK) {
      Serial.print("Sector ");
      Serial.print(sector);
      Serial.print(" auth failed: ");
      Serial.println(rfid.GetStatusCodeName(status));
      continue;
    }

    for (byte block = firstBlock; block < firstBlock + 3; block++) {

      status = rfid.MIFARE_Read(block, buffer, &size);
      if (status != MFRC522::STATUS_OK) {
        Serial.print("Block ");
        Serial.print(block);
        Serial.print(" read failed: ");
        Serial.println(rfid.GetStatusCodeName(status));
        continue;
      }

      Serial.print("Block ");
      Serial.print(block);
      Serial.print(": ");

      for (byte i = 0; i < 16; i++) {
        if (buffer[i] < 0x10) Serial.print("0");
        Serial.print(buffer[i], HEX);
        Serial.print(" ");
      }

      Serial.print("| ");

      for (byte i = 0; i < 16; i++) {
        if (buffer[i] >= 32 && buffer[i] <= 126)
          Serial.write(buffer[i]);
        else
          Serial.print('.');
      }

      Serial.println();
    }
  }

  // STOP crypto ONCE
  rfid.PCD_StopCrypto1();
  rfid.PICC_HaltA();
}


void writeCard() {
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  Serial.println("Writing to card...");

  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++)
    key.keyByte[i] = 0xFF; // default key

  byte block = 4; // SAFE block
  byte dataBlock[16] = {
    'H','E','L','L','O','_','R','F','I','D',
    0,0,0,0,0,0
  };

  // Authenticate
  byte status = rfid.PCD_Authenticate(
    MFRC522::PICC_CMD_MF_AUTH_KEY_A,
    block,
    &key,
    &rfid.uid
  );

  if (status != MFRC522::STATUS_OK) {
    Serial.print("Auth failed: ");
    Serial.println(rfid.GetStatusCodeName(status));
    return;
  }

  // Write block
  status = rfid.MIFARE_Write(block, dataBlock, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Write failed: ");
    Serial.println(rfid.GetStatusCodeName(status));
    return;
  }

  Serial.println("Write successful!");

  rfid.PCD_StopCrypto1();
  rfid.PICC_HaltA();
}

