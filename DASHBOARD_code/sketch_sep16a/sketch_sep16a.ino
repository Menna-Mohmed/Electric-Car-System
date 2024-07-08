
#include <LiquidCrystal_I2C.h>


#define WindowPot A0
#define flButtonPin 7
#define frButtonPin 6
#define rlButtonPin 5
#define rrButtonPin 4
#define ToggleMode A2


bool fl_door = false;
bool fr_door = false;
bool rl_door = false;
bool rr_door = false;
bool Mode = false;
bool check = false;

LiquidCrystal_I2C lcd(0x27,16,2);

int WindowRead = 0;


void Doors(void);
void Window(void);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();         
  lcd.backlight();  
  pinMode(frButtonPin, INPUT_PULLUP);
  pinMode(flButtonPin, INPUT_PULLUP);
  pinMode(rlButtonPin, INPUT_PULLUP);
  pinMode(rrButtonPin, INPUT_PULLUP);
  pinMode(ToggleMode, INPUT_PULLUP);

  pinMode(WindowPot, INPUT);
}

void loop() {
  check = Serial.available();
  while (check) {

    switch(Serial.read())
    {
      case 'Z':
       curr_volt_alram();
       break;
      case 'S':
       curr_alram();
       break;
      case 'W':
      volt_alram();
       break;
      case 'D':
      check=false;
       break;
    }

  }
  if (!digitalRead(ToggleMode)) {
    Mode ^= 1;
    delay(200);
    lcd.clear();
  }
  if (!Mode) {
    Doors();
  } else {
    Window();
  }
}

void Doors(void) {
  fl_door = digitalRead(flButtonPin) == LOW;
  fr_door = digitalRead(frButtonPin) == LOW;
  rl_door = digitalRead(rlButtonPin) == LOW;
  rr_door = digitalRead(rrButtonPin) == LOW;

  lcd.setCursor(0, 0);
  lcd.print("FL:");
  lcd.print(fl_door ? "Open" : "Shut");

  lcd.setCursor(7, 0);
  lcd.print("_FR:");
  lcd.print(fr_door ? "Open" : "Shut");

  lcd.setCursor(0, 1);
  lcd.print("RL:");
  lcd.print(rl_door ? "Open" : "Shut");

  lcd.setCursor(7, 1);
  lcd.print("_RR:");
  lcd.print(rr_door ? "Open" : "Shut");
}

void Window(void) {
  WindowRead = analogRead(WindowPot);
  int Percentage = map(WindowRead, 0, 1024, 0, 101);
  lcd.setCursor(4, 0);
  lcd.print("Window :");
  lcd.setCursor(4, 1);
  lcd.print("%");
  lcd.print(Percentage);
  lcd.print(" shut");
  lcd.print("  ");
}
void volt_alram() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Warning over");
  lcd.setCursor(0, 1);
  lcd.print("     voltage    ");
  digitalWrite(A1,HIGH);
  delay(600);
  digitalWrite(A1,LOW);
}
void curr_alram() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Warning over");
  lcd.setCursor(0, 1);
  lcd.print("    current    ");
  digitalWrite(A1,HIGH);
  delay(600);
  digitalWrite(A1,LOW);
}
void curr_volt_alram() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Warning OVER");
  lcd.setCursor(0, 1);
  lcd.print(" Current & Volt");
  digitalWrite(A1,HIGH);
  delay(600);
  digitalWrite(A1,LOW);
}
