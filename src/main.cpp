#include <M5Stack.h>

float value1 = 0;
float voltage1 = 0;
const int CH1_PIN = 36;
const float MAX_VOLTAGE = 5.0f;
const float ANALOG_MAX = 4095.0f; // ESP32の場合
const float sampling_us = 1000.0f;
unsigned long ts = 0;
unsigned long te = 0;

void setup()
{
  M5.begin(); // 初期化処理
  delay(500);
  // 文字の色とサイズ
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(4);
  ts = micros();
}

void loop()
{
  // CH1, CH2(35, 36pin)のアナログ入力を取得し電圧に変換
  value1 = analogRead(CH1_PIN);
  voltage1 = value1 * MAX_VOLTAGE / ANALOG_MAX;
  Serial.println(value1);
  while (true)
  {
    te = micros();
    if (te - ts >= sampling_us)
    {
      ts = micros();
      break;
    }
  }
}
