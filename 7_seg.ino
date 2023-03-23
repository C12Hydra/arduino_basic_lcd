#include <LiquidCrystal.h>
LiquidCrystal lcd = LiquidCrystal(A1, A2, 2, 3, 4, 5);
int u = 6;
int d = 12;
int t = 11;
int q = 10;
int c = 9;
int s = 8;
int se = 7;
int g;
int b_esq = 13;
int b_dir = A0;
int i;
int k;
int flag;
int flag2;
int x[5] = {0, 0, 0, 0, 0};
int y[5] = {0, 0, 0, 0, 0};
byte customChar1[8] = {
  0b00011,
  0b00001,
  0b11111,
  0b01110,
  0b10001,
  0b10101,
  0b10001,
  0b01110
};//olho1
byte customChar2[8] = {
  0b00000,
  0b00000,
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b01110,
  0b00000
};//selecaovazia
byte customChar3[8] = {
  0b00000,
  0b00000,
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00000
};//selecao3
byte customChar4[8] = {
  0b00001,
  0b00001,
  0b00001,
  0b00010,
  0b01100,
  0b00000,
  0b00000,
  0b00000
};//braço mesa
byte customChar5[8] = {
  0b00111,
  0b00101,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};//olho mesa
byte customChar6[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b01111,
  0b01001,
  0b01001,
  0b01111,
  0b00000
};//boca mesa
byte customChar7[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};//vento mesa
byte customChar8[8] = {
  0b00000,
  0b00000,
  0b00010,
  0b00010,
  0b00010,
  0b11111,
  0b00000,
  0b00000
};//mesa1
byte customChar9[8] = {
  0b00000,
  0b00000,
  0b00100,
  0b00100,
  0b00100,
  0b11111,
  0b00000,
  0b00000
};//mesa 2
byte customChar10[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b10000,
  0b00000,
  0b00000
};//mesa 3
void setup() {
  // put your setup code here, to run once:
  flag = 1;
  flag2 = 1;
  g = 500;
  i = 0;
  pinMode(u, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(t, OUTPUT);
  pinMode(q, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(s, OUTPUT);
  pinMode(se, OUTPUT);
  pinMode(b_esq, INPUT);
  pinMode(b_dir, INPUT);
  Serial.begin(9600);
  lcd.clear();
  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
  lcd.createChar(3, customChar3);
  lcd.createChar(4, customChar4);
  lcd.createChar(5, customChar5);
  lcd.createChar(6, customChar6);
  lcd.createChar(7, customChar7);
  lcd.createChar(8, customChar8);
  lcd.createChar(9, customChar9);
  lcd.createChar(10, customChar10);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}
void reset() {
  digitalWrite(u, 0);
  digitalWrite(d, 0);
  digitalWrite(t, 0);
  digitalWrite(q, 0);
  digitalWrite(c, 0);
  digitalWrite(s, 0);
  digitalWrite(se, 0);
}
void seq() {
  digitalWrite(u, 1);
  delay(300);
  digitalWrite(d, 1);
  delay(300);
  digitalWrite(t, 1);
  delay(300);
  digitalWrite(q, 1);
  delay(300);
  digitalWrite(c, 1);
  delay(300);
  digitalWrite(s, 1);
  delay(300);
  digitalWrite(se, 1);
  delay(300);
}
int ler_u() {
  if ((digitalRead(b_esq) == 1) && (digitalRead(b_dir) == 0)) {
    return (1);
  } else if ((digitalRead(b_esq) == 0) && (digitalRead(b_dir) == 0)) {
    delay(200);
    return (ler_u());
  } else
    return 0;
}
int ler_d() {
  if ((digitalRead(b_esq) == 1) && (digitalRead(b_dir) == 0)) {
    return (1);
  } else if ((digitalRead(b_esq) == 0) && (digitalRead(b_dir) == 0)) {
    delay(200);
    return (ler_d());
  } else
    return 0;
}
int ler_c() {

  if ((digitalRead(b_esq) == 1) && (digitalRead(b_dir) == 0)) {
    return (1);
  } else if ((digitalRead(b_esq) == 0) && (digitalRead(b_dir) == 0)) {
    delay(200);
    return (ler_c());
  } else {
    return 0;
  }
}
int ler_m() {
  if ((digitalRead(b_esq) == 1) && (digitalRead(b_dir) == 0)) {
    return (1);
  } else if ((digitalRead(b_esq) == 0) && (digitalRead(b_dir) == 0)) {
    delay(200);
    return (ler_m());
  } else
    return 0;
}
int ler_botao() {
  int u = 2;
  int d = 2;
  int c = 2;
  int m = 2;
  u = ler_u();
  if ((u == 1) || (u == 0)) {
    delay(500);
    d = ler_d();
    if ((d == 1) || (d == 0)) {
      delay(500);
      c = ler_c();
      if ((c == 1) || (c == 0)) {
        delay(500);
        m = ler_m();
        delay(500);
      }
    }
  }
  return ((1000 * u) + (100 * d) + (10 * c) + m);
}
void zero() {
  digitalWrite(u, 1);
  digitalWrite(d, 1);
  digitalWrite(t, 1);
  digitalWrite(q, 1);
  digitalWrite(c, 1);
  digitalWrite(s, 1);
  digitalWrite(se, 0);

}
void um() {
  digitalWrite(u, 0);
  digitalWrite(d, 0);
  digitalWrite(t, 1);
  digitalWrite(q, 1);
  digitalWrite(c, 0);
  digitalWrite(s, 0);
  digitalWrite(se, 0);

}
void dois() {
  digitalWrite(u, 0);
  digitalWrite(d, 1);
  digitalWrite(t, 1);
  digitalWrite(q, 0);
  digitalWrite(c, 1);
  digitalWrite(s, 1);
  digitalWrite(se, 1);

}
void tres() {
  digitalWrite(u, 0);
  digitalWrite(d, 1);
  digitalWrite(t, 1);
  digitalWrite(q, 1);
  digitalWrite(c, 1);
  digitalWrite(s, 0);
  digitalWrite(se, 1);

}
void quatro() {
  digitalWrite(u, 1);
  digitalWrite(d, 0);
  digitalWrite(t, 1);
  digitalWrite(q, 1);
  digitalWrite(c, 0);
  digitalWrite(s, 0);
  digitalWrite(se, 1);

}
void cinco() {
  digitalWrite(u, 1);
  digitalWrite(d, 1);
  digitalWrite(t, 0);
  digitalWrite(q, 1);
  digitalWrite(c, 1);
  digitalWrite(s, 0);
  digitalWrite(se, 1);

}
void seis() {
  digitalWrite(u, 1);
  digitalWrite(d, 1);
  digitalWrite(t, 0);
  digitalWrite(q, 1);
  digitalWrite(c, 1);
  digitalWrite(s, 1);
  digitalWrite(se, 1);

}
void sete() {
  digitalWrite(u, 0);
  digitalWrite(d, 1);
  digitalWrite(t, 1);
  digitalWrite(q, 1);
  digitalWrite(c, 0);
  digitalWrite(s, 0);
  digitalWrite(se, 0);

}
void oito() {
  digitalWrite(u, 1);
  digitalWrite(d, 1);
  digitalWrite(t, 1);
  digitalWrite(q, 1);
  digitalWrite(c, 1);
  digitalWrite(s, 1);
  digitalWrite(se, 1);

}
void nove() {
  digitalWrite(u, 1);
  digitalWrite(d, 1);
  digitalWrite(t, 1);
  digitalWrite(q, 1);
  digitalWrite(c, 0);
  digitalWrite(s, 0);
  digitalWrite(se, 1);

}
void a_() {
  digitalWrite(u, 1);
  digitalWrite(d, 1);
  digitalWrite(t, 1);
  digitalWrite(q, 1);
  digitalWrite(c, 0);
  digitalWrite(s, 1);
  digitalWrite(se, 1);

}
void b_() {
  digitalWrite(u, 1);
  digitalWrite(d, 0);
  digitalWrite(t, 0);
  digitalWrite(q, 1);
  digitalWrite(c, 1);
  digitalWrite(s, 1);
  digitalWrite(se, 1);

}
void c_() {
  digitalWrite(u, 1);
  digitalWrite(d, 1);
  digitalWrite(t, 0);
  digitalWrite(q, 0);
  digitalWrite(c, 1);
  digitalWrite(s, 1);
  digitalWrite(se, 0);

}
void d_() {
  digitalWrite(u, 0);
  digitalWrite(d, 0);
  digitalWrite(t, 1);
  digitalWrite(q, 1);
  digitalWrite(c, 1);
  digitalWrite(s, 1);
  digitalWrite(se, 1);

}
void e_() {
  digitalWrite(u, 1);
  digitalWrite(d, 1);
  digitalWrite(t, 0);
  digitalWrite(q, 0);
  digitalWrite(c, 1);
  digitalWrite(s, 1);
  digitalWrite(se, 1);

}
void f_() {
  digitalWrite(u, 1);
  digitalWrite(d, 1);
  digitalWrite(t, 0);
  digitalWrite(q, 0);
  digitalWrite(c, 0);
  digitalWrite(s, 1);
  digitalWrite(se, 1);

}
void acender(int k) {
  switch (k) {
    case 0:
      zero();
      delay(2000);
      break;
    case 1:
      um();
      delay(2000);
      break;
    case 10:
      dois();
      delay(2000);
      break;
    case 11:
      tres();
      delay(2000);
      break;
    case 100:
      quatro();
      delay(2000);
      break;
    case 101:
      cinco();
      delay(2000);
      break;
    case 110:
      seis();
      delay(2000);
      break;
    case 111:
      sete();
      delay(2000);
      break;
    case 1000:
      oito();
      delay(2000);
      break;
    case 1001:
      nove();
      delay(2000);
      break;
    case 1010:
      a_();
      delay(2000);
      break;
    case 1011:
      b_();
      delay(2000);
      break;
    case 1100:
      c_();
      delay(2000);
      break;
    case 1101:
      d_();
      delay(2000);
      break;
    case 1110:
      e_();
      delay(2000);
      break;
    case 1111:
      f_();
      delay(2000);
      break;
    default:
      Serial.println("Deu zebra");
      delay(2000);
      break;
  }
}
void entrar_senha() {
  for (i = 0; i < 5; i++) {
    x[i] = ler_botao();
    delay(1000);
  }
}
void criar_senha() {
  for (i = 0; i < 5; i++) {
    y[i] = ler_botao();
  }
  lcd.clear();
  lcd.print("senha criada:");
  for (i = 0; i < 5; i++) {
    acender(x[i]);
    delay(750);
    reset();
  }
  lcd.clear();
  tela_selecao1();
}
void tela_seguranca3() {
  lcd.clear();
  lcd.print("voltar ");
  lcd.write(byte(2));
  lcd.print("att ");
  lcd.write(byte(3));
  k = ler_u();
  if (k == 0) {
    //atualizar_senha();
  } else {
    tela_selecao1();

  }
}
void tela_seguranca4() {
  lcd.clear();
  lcd.print("voltar ");
  lcd.write(byte(2));
  lcd.print("att ");
  lcd.write(byte(3));
  k = ler_u();
  if (k == 0) {
    atualizar_senha();
  } else {
    tela_seguranca3();

  }
}
void tela_seguranca3() {
  lcd.clear();
  lcd.print("voltar ");
  lcd.write(byte(3));
  lcd.print("att ");
  lcd.write(byte(2));
  k = ler_u();
  if (k == 0) {
    tela_selecao1();
  } else {
    tela_seguranca3();

  }
}
void tela_seguranca() {
  k=2;
  lcd.clear();
  lcd.print("1   ");
  lcd.write(byte(3));
  lcd.print(" 2  ");
  lcd.write(byte(2));
  lcd.print(" 3  ");
  lcd.write(byte(3));
  k = ler_u();
  delay(g);
  if (k == 0) {
    tela_selecao1();
  } else {
    tela_seguranca2();
}
int interface_inicial(int flag) {
  lcd.clear();
  lcd.print("Boas vindas.");
  delay(2000);
  lcd.clear();
  lcd.print("1 p/ navegacao");
  delay(g);
  lcd.clear();
  lcd.print("0 p/ selecao");
  delay(g);
  lcd.clear();
  lcd.print("seg =seguranca");
  delay(g);
  lcd.clear();
  lcd.print("con=controle");
  delay(g);
  lcd.clear();
  lcd.print("etc =outros");
  delay(g);
  lcd.clear();
  lcd.print("pressione 0 para");
  delay(g);
  lcd.clear();
  lcd.print("sair");
  flag = ler_u();
  delay(500);
  return (flag);
}
void tela_selecao3() {
  lcd.clear();
  lcd.print("seg");
  lcd.write(byte(2));
  lcd.print(" con");
  lcd.write(byte(2));
  lcd.print(" etc");
  lcd.write(byte(3));
  k = ler_u();
  delay(g);
  if (k == 0) {
    //    tela_outros();
  } else
    tela_selecao1();
}
void tela_selecao2() {
  k = 2;
  lcd.clear();
  lcd.print("seg");
  lcd.write(byte(2));
  lcd.print(" con");
  lcd.write(byte(3));
  lcd.print(" etc");
  lcd.write(byte(2));
  k = ler_u();
  delay(g);
  if (k == 0) {
    if (!flag) {
      tela_controle();
    }
  } else
    tela_selecao3();
}
void tela_selecao1() {
  k = 2;
  lcd.clear();
  lcd.print("seg");
  lcd.write(byte(3));
  lcd.print(" con");
  lcd.write(byte(2));
  lcd.print(" etc");
  lcd.write(byte(2));
  k = ler_u();
  delay(g);
  if (k == 0) {
    if (flag2) {
      lcd.clear();
      lcd.print("1-voltar 2-criar");
      delay(g);
      lcd.clear();
      lcd.print("3-resetar");
      delay(g);
      tela_seguranca();
    } else tela_seguranca3();
  }
  else
    tela_selecao2();
}
void loop() {
  while (flag) {
    flag = interface_inicial(flag);
  }
  while (flag3) {
    tela_selecao1();
  }
}
