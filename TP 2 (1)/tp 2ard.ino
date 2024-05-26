// C++ code
//
  int red1 = 9;
  int green1 = 10;
  int blue1 = 11;

  int red2 = 6;
  int green2 = 5;
  int blue2 = 3;

  int red3 = 2;
  int green3 = 4;
  int blue3 = 7;
  int buzzer = 8;
  int potePin = A0;
  int boton = 12;



void setup()
{
  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(blue1, OUTPUT);

  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(blue2, OUTPUT);

  pinMode(red3, OUTPUT);
  pinMode(green3, OUTPUT);
  pinMode(blue3, OUTPUT);
  

  pinMode(buzzer, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
}

void loop()
{
  int boton2 = digitalRead(boton);

  if (boton2 == LOW) {
    // Si el botón está presionado, apagar todos los LEDs y detener la secuencia
    analogWrite(red1, 0);
    analogWrite(green1, 0);
    analogWrite(blue1, 0);

    digitalWrite(red2, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(blue2, LOW);

    analogWrite(red3, 0);
    analogWrite(green3, 0);
    analogWrite(blue3, 0);
  } else {
    // Leer el valor del potenciómetro
    int potenciometro = analogRead(potePin);
    // Mapear el valor del potenciómetro al rango de 200 ms a 1500 ms
    int delaye = map(potenciometro, 0, 1023, 200, 1500);

    // 1° LED en color rojo fuerte (analógico)
    analogWrite(red1, 255);
    analogWrite(green1, 0);
    analogWrite(blue1, 0);
    delay(delaye);
    analogWrite(red1, 0);
    analogWrite(green1, 0);
    analogWrite(blue1, 0);

    // Zumbido de 100 ms
    tone(buzzer, 1000); // 1000 Hz
    delay(100);
    noTone(buzzer);

    // 2° LED en color magenta (digital)
    digitalWrite(red2, HIGH);
    digitalWrite(green2, HIGH);
    digitalWrite(blue2, LOW);
    delay(delaye);
    digitalWrite(red2, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(blue2, LOW);

    // Zumbido de 100 ms
    tone(buzzer, 1000); // 1000 Hz
    delay(100);
    noTone(buzzer);

    // 3° LED en color cian clarito (analógico)
    analogWrite(red3,255);
    analogWrite(green3, 0); // Valor medio para verde
    analogWrite(blue3, 255);  // Azul fuerte
    delay(delaye);
    analogWrite(red3, 0);
    analogWrite(green3, 0);
    analogWrite(blue3, 0);

    // Zumbido de 100 ms
    tone(buzzer, 1000); // 1000 Hz
    delay(100);
    noTone(buzzer);
  }

 

 
}