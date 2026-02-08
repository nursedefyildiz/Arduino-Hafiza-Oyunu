// Pin Tanımlamaları
const int ledPins[] = {2, 3, 4, 5};      
const int buttonPins[] = {8, 9, 10, 11};  
const int buzzerPin = 12;

// Ses Frekansları (Do, Mi, Sol, Si)
const int tones[] = {262, 330, 392, 494}; 

int gameSequence[100]; // Arduino'nun hafızası
int level = 0;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(buzzerPin, OUTPUT);
  randomSeed(analogRead(A0)); // Boşta kalan A0 pininden rastgelelik alır
}

void loop() {
  // 1. Yeni adım ekle
  gameSequence[level] = random(0, 4);
  level++;

  // 2. Arduino seriyi çalsın ve göstersin
  for (int i = 0; i < level; i++) {
    int currentStep = gameSequence[i];
    playTone(currentStep, 400);
    delay(150);
  }

  // 3. Kullanıcıdan cevap bekle
  for (int i = 0; i < level; i++) {
    int expectedButton = gameSequence[i];
    int pressedButton = -1;

    // Butona basılana kadar bekle
    while (pressedButton == -1) {
      for (int b = 0; b < 4; b++) {
        if (digitalRead(buttonPins[b]) == LOW) {
          pressedButton = b;
          playTone(b, 250);
          while (digitalRead(buttonPins[b]) == LOW); // Elini çekene kadar bekle
        }
      }
    }

    // 4. Doğruluk kontrolü
    if (pressedButton != expectedButton) {
      gameOver();
      return;
    }
  }
  delay(800); // Seviye atlamadan önce kısa bir mola
}

// Ses ve Işık fonksiyonu
void playTone(int index, int duration) {
  digitalWrite(ledPins[index], HIGH);
  tone(buzzerPin, tones[index], duration);
  delay(duration);
  digitalWrite(ledPins[index], LOW);
}

// Hata efekti
void gameOver() {
  tone(buzzerPin, 100, 1000); // Kalın bir hata sesi
  for (int i = 0; i < 5; i++) {
    for (int l = 0; l < 4; l++) digitalWrite(ledPins[l], HIGH);
    delay(100);
    for (int l = 0; l < 4; l++) digitalWrite(ledPins[l], LOW);
    delay(100);
  }
  level = 0; // Başa dön
  delay(1000);
}
