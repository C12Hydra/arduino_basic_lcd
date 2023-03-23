#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//portas do arduino conectadas no lcd
char x;
void setup() {
  lcd.begin(16, 2);//inicializa
  lcd.setCursor(0, 0);//coluna 0 linha 0
  lcd.print("whatsapp:");
  lcd.setCursor(0, 1);//coluna 0 linha 1 
  lcd.print("TRAVADO");
  Serial.begin(9600);//inicializa comunicaçao entre maquina e placa
}
void loop() {
  x=Serial.read();//le uma entrada
  if (x=='s'){//se for s 
    delay(1500);//espera 1.5s e
    lcd.clear();//limpa o display
    lcd.setCursor(0, 0);
    lcd.print("aunque digan");//escreve
    lcd.setCursor(0, 1);
    delay(200);
    lcd.print("que soy");
    delay(750);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("un bandolero");
    lcd.setCursor(0, 1);
    delay(200);
    lcd.print("donde voy");
    delay(750);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("le doy gracias a");
    lcd.setCursor(0, 1);
    delay(200);
    lcd.print("dios por hoy");
    delay(750);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("estar donde");
    delay(200);
    lcd.setCursor(0, 1);
    lcd.print("estoy");
  }
}
