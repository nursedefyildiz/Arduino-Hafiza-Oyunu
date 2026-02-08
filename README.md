# 🧠 Simon Says: Arduino Hafıza Oyunu 🕹️

Bu proje, oyuncunun görsel ve işitsel hafızasını test eden, klasik "Simon Says" oyununun Arduino Uno ile geliştirilmiş versiyonudur. Proje, 4 farklı renkteki LED'in yanma sırasını aklınızda tutmanızı ve aynı sırayla butonlara basmanızı gerektirir.

## 🚀 Özellikler
* **İşitsel Hafıza:** Her renk için farklı bir nota (frekans) çalar.
* **Artan Zorluk:** Her başarılı turda sistem seriye bir adım daha ekler.
* **Görsel Geribildirim:** Yanlış basıldığında tüm LED'ler yanıp sönerek uyarı verir.
* **Dinamik Akış:** Her oyun başladığında farklı bir rastgele sıra oluşturulur.

---

## 🛠️ Gerekli Malzemeler

| Miktar | Malzeme | Açıklama |
| :--- | :--- | :--- |
| 1 Adet | **Arduino Uno** | Kontrol Ünitesi |
| 4 Adet | **LED** | Kırmızı, Yeşil, Mavi, Sarı |
| 4 Adet | **Buton** | Push Button (LED renkleriyle uyumlu olması önerilir) |
| 4 Adet | **220Ω Direnç** | LED'lerin ömrünü korumak için |
| 1 Adet | **Buzzer** | Ses efektleri ve notalar için |
| 1 Adet | **Breadboard** | Devre kurulum alanı |

---

## 🔌 Devre Bağlantı Şeması

Devreyi kurarken aşağıdaki tabloyu rehber alabilirsiniz. 



### 💡 LED Bağlantıları
| LED Rengi | Arduino Pin | Bağlantı Tipi |
| :--- | :--- | :--- |
| **Kırmızı** | Pin 2 | Uzun bacak (+) Pin 2'ye, Kısa bacak GND'ye |
| **Yeşil** | Pin 3 | Uzun bacak (+) Pin 3'e, Kısa bacak GND'ye |
| **Mavi** | Pin 4 | Uzun bacak (+) Pin 4'e, Kısa bacak GND'ye |
| **Sarı** | Pin 5 | Uzun bacak (+) Pin 5'e, Kısa bacak GND'ye |

### 🔘 Buton Bağlantıları
*Not: Butonlar için `INPUT_PULLUP` kullanılmıştır, harici direnç gerekmez.*
| Buton | Arduino Pin | Bağlantı Tipi |
| :--- | :--- | :--- |
| **Buton 1** | Pin 8 | Bir bacak Pin 8'e, Diğer bacak GND'ye |
| **Buton 2** | Pin 9 | Bir bacak Pin 9'e, Diğer bacak GND'ye |
| **Buton 3** | Pin 10 | Bir bacak Pin 10'e, Diğer bacak GND'ye |
| **Buton 4** | Pin 11 | Bir bacak Pin 11'e, Diğer bacak GND'ye |

### 🔊 Ses (Buzzer)
* **Buzzer (+) bacağı:** Pin 12
* **Buzzer (-) bacağı:** GND

---

## 📝 Kurulum Adımları

1.  Yukarıdaki şemaya göre devrenizi breadboard üzerinde kurun.
2.  Bilgisayarınıza **Arduino IDE** programını indirin.
3.  Dosyalar içerisindeki `.ino` uzantılı kodu Arduino IDE ile açın.
4.  Arduino Uno kartınızı USB ile bilgisayara bağlayın.
5.  `Yükle` butonuna basarak kodu kartınıza gönderin.

---

## 🛠️ Teknik Detaylar (Geliştiriciler İçin)
* **Randomness:** `randomSeed(analogRead(A0))` kullanılarak her seferinde farklı bir oyun dizisi oluşturulur.
* **Logic:** Oyun dizisi `gameSequence[]` dizisinde saklanır ve kullanıcı girişiyle anlık olarak karşılaştırılır.
* **Sound:** `tone()` kütüphanesi ile notalar üretilir.

---

## 👤 Hazırlayan
* **İsim:** Nursedef YTLDIZ
* **Okul:** Düzce Üniversitesi - Bilgisayar Mühendisliği
* **İletişim:** 2nursedefyildiz@gmail.com veya linkedIn/Nursedef Yıldız
