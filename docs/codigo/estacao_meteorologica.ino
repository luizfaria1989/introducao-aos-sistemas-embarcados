// Estação Meteorológica — Oficina de Sistemas Embarcados
// Lê o BME280 pelo barramento I2C e mostra os valores no display OLED.

#include <Wire.h>
#include <Adafruit_BME280.h>
#include <Adafruit_SSD1306.h>

constexpr uint8_t ENDERECO_BME = 0x76;  // 0x77 se o pino SDO estiver em nivel alto
constexpr uint8_t ENDERECO_OLED = 0x3C;
constexpr uint32_t INTERVALO_MS = 30000;

Adafruit_BME280 sensor;
Adafruit_SSD1306 display(128, 64, &Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);  // SDA, SCL

  if (!sensor.begin(ENDERECO_BME)) {
    Serial.println("BME280 nao encontrado — confira as ligacoes I2C.");
    while (true) {
      delay(1000);
    }
  }

  display.begin(SSD1306_SWITCHCAPVCC, ENDERECO_OLED);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  const float temperatura = sensor.readTemperature();
  const float umidade = sensor.readHumidity();
  const float pressao = sensor.readPressure() / 100.0F;  // Pa -> hPa

  Serial.printf("%.1f C  %.1f %%  %.1f hPa\n", temperatura, umidade, pressao);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.printf("%.1f C\n", temperatura);
  display.setTextSize(1);
  display.printf("Umidade: %.1f %%\n", umidade);
  display.printf("Pressao: %.1f hPa\n", pressao);
  display.display();

  delay(INTERVALO_MS);
}
