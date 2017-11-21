#include <Servo.h> // Librería para controlar el servomotor
Servo servob; 
Servo servoy;
Servo servox;
Servo servog;


int x, y, g, dcha, izqda;
int angulox=90;
int anguloy=90;
int grip=70;
int base=70;
int salto=3;

void setup() {
  pinMode(2, INPUT_PULLUP); // Pulsador izquierda. Los ponemos en pullup, así nos ahorramos una resistencia necesaria en los joystick.
  pinMode(3, INPUT_PULLUP); // Pulsador derecha.
  servob.attach(9); 
  servoy.attach(10); 
  servox.attach(11);
  servog.attach(7);
}
void loop() { 
  x = analogRead(A0);
  if(x < 400) angulox = angulox + salto;
  else if(x > 600) angulox = angulox - salto;
  if(angulox <0) angulox = 0; // If para que los movimientos sean exactos
  if(angulox >180) angulox = 180; // If para que los movimientos sean exactos
  servox.write(angulox);
  
  delay(40);
  
  
  // eje y 
  y = analogRead(A2);
  if(y < 400) anguloy = anguloy - salto;
  else if(y > 600) anguloy = anguloy + salto;
  servoy.write(anguloy);
  if(anguloy <0) anguloy = 0; // If para que los movimientos sean exactos
  if(anguloy >180) anguloy = 180; // If para que los movimientos sean exactos
  Serial.println(anguloy);
  delay(40);
  
  // derecha e izquierda ¡¡PULL UP!!
  dcha = digitalRead(3);
  izqda = digitalRead(2);
  if(dcha == 0) base = base + salto;
  else if(izqda == 0) base = base - salto;
  servob.write(base);
  if(base <0) base = 0; // If para que los movimientos sean exactos
  if(base >180) base = 180; // If para que los movimientos sean exactos
  delay(40);
  
  // pinza gripple
  g = analogRead(A3);
  if(g < 400) grip = grip + 10;
  else if(g > 600) grip = grip - 10;
  servog.write(grip);
  if(grip <70) grip = 70; // If para que los movimientos sean exactos
  if(grip >180) grip = 180;  // If para que los movimientos sean exactos
  
  delay(30);
}
