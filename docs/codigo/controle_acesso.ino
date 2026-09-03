// Controle de Acesso RFID — Oficina de Sistemas Embarcados
// Le cartoes MIFARE pelo RC522 e aciona um rele quando o UID e autorizado.

#include <SPI.h>
#include <MFRC522.h>

constexpr uint8_t PINO_SS = 5;
constexpr uint8_t PINO_RST = 27;
constexpr uint8_t PINO_RELE = 26;
constexpr uint8_t PINO_BUZZER = 25;
constexpr uint32_t TEMPO_ABERTO_MS = 3000;

MFRC522 leitor(PINO_SS, PINO_RST);

// Substitua pelos UIDs lidos no monitor serial.
const char* uidsAutorizados[] = {
    "A1 B2 C3 D4",
    "11 22 33 44",
};

String lerUid() {
  String uid;
  for (uint8_t i = 0; i < leitor.uid.size; i++) {
    if (i > 0) {
      uid += " ";
    }
    if (leitor.uid.uidByte[i] < 0x10) {
      uid += "0";
    }
    uid += String(leitor.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();
  return uid;
}

bool autorizado(const String& uid) {
  for (const char* permitido : uidsAutorizados) {
    if (uid == permitido) {
      return true;
    }
  }
  return false;
}

void bipar(uint8_t vezes) {
  for (uint8_t i = 0; i < vezes; i++) {
    tone(PINO_BUZZER, 2000, 120);
    delay(200);
  }
}

void setup() {
  Serial.begin(115200);
  SPI.begin();
  leitor.PCD_Init();

  pinMode(PINO_RELE, OUTPUT);
  pinMode(PINO_BUZZER, OUTPUT);
  digitalWrite(PINO_RELE, LOW);

  Serial.println("Pronto — aproxime um cartao.");
}

void loop() {
  if (!leitor.PICC_IsNewCardPresent() || !leitor.PICC_ReadCardSerial()) {
    return;
  }

  const String uid = lerUid();
  Serial.print("UID lido: ");
  Serial.println(uid);

  if (autorizado(uid)) {
    Serial.println("Acesso liberado.");
    bipar(1);
    digitalWrite(PINO_RELE, HIGH);
    delay(TEMPO_ABERTO_MS);
    digitalWrite(PINO_RELE, LOW);
  } else {
    Serial.println("Acesso negado.");
    bipar(2);
  }

  leitor.PICC_HaltA();
}
