#include <LedControl.h>

const int DIN_PIN = 11;
const int CS_PIN = 10;
const int CLK_PIN = 13;

const uint64_t IMAGES[] = {
  0x0000000001010101,
  0x0000020203010101,
  0x0004060603010101,
  0x080c060603010101,
  0x181c060603010101,
  0x183c262603010101,
  0x183c666643010101,
  0x183c6666c3818181,
  0x183c6666c2808080,
  0x183c6464c0808080,
  0x18386060c0808080,
  0x10306060c0808080,
  0x00206060c0808080,
  0x00004040c0808080,
  0x0000000080808080,
  0x0000000000000000,
  0x2000000000000004,
  0x2020000000000404,
  0x2020600000060404,
  0x2020606006060404,
  0x2020606666060404,
  0x2020646666260404,
  0x2020646e76260404,
  0x2020646e76260404
};
const int IMAGES_LEN = sizeof(IMAGES)/8;



LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN);


void setup() {
  display.clearDisplay(0);
  display.shutdown(0, false);
  display.setIntensity(0, 5);
}

void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(0, i, j, bitRead(row, j));
    }
  }
}

int i = 0;

void loop() {
  displayImage(IMAGES[i]);
  if (++i >= IMAGES_LEN ) {
    i = 0;
  }
  delay(100);
}