#include <LiquidCrystal.h> // Library

LiquidCrystal lcd(11, 12, 5, 4, 3, 2); // (RS, E, D4, D5, D6, D7) 
const int pingPin_length = 8; // Trig of Ultrasonic Sensor_length
const int echoPin_length = 9; // Echo of Ultrasonic Sensor_length
const int pingPin_width = 10; // Trig of Ultrasonic Sensor_width
const int echoPin_width = 13; // Echo of Ultrasonic Sensor_width
const int pingPin_height = A0; // Trig of Ultrasonic Sensor_height
const int echoPin_height = 7; // Echo of Ultrasonic Sensor_height

void setup() { 
 lcd.begin(16,2); // (width, height) 16 x 2 is the max
 analogWrite(6, 100); // (contrast of lcd module)
}

void loop() { 
 lcd.noBlink(); // Turns off the blinking LCD cursor 
 long duration_length, duration_width, duration_height, inches_length, inches_width, inches_height; // Ultrasonic variables 

 // Length Calculation
 pinMode(pingPin_length, OUTPUT);
 digitalWrite(pingPin_length, LOW);
 delayMicroseconds(2);
 digitalWrite(pingPin_length, HIGH);
 delayMicroseconds(10);
 digitalWrite(pingPin_length, LOW);
 pinMode(echoPin_length, INPUT);
 duration_length = pulseIn(echoPin_length, HIGH); 
 inches_length = MicroToInch(duration_length);

 // Width Calculation
 pinMode(pingPin_width, OUTPUT);
 digitalWrite(pingPin_width, LOW);
 delayMicroseconds(2);
 digitalWrite(pingPin_width, HIGH);
 delayMicroseconds(10);
 digitalWrite(pingPin_width, LOW);
 pinMode(echoPin_width, INPUT);
 duration_width = pulseIn(echoPin_width, HIGH);
 inches_width = MicroToInch(duration_width);

 // Height Calculation
 pinMode(pingPin_height, OUTPUT);
 digitalWrite(pingPin_height, LOW);
 delayMicroseconds(2);
 digitalWrite(pingPin_height, HIGH);
 delayMicroseconds(10);
 digitalWrite(pingPin_height, LOW);
 pinMode(echoPin_height, INPUT);
 duration_height = pulseIn(echoPin_height, HIGH);
 inches_height = MicroToInch(duration_height);

 // String Conversion
 String l = String(inches_length);
 String w = String(inches_width);
 String h = String(inches_height);

 // Printing on lcd
 lcd.clear();
 lcd.print("L:");
 lcd.print(l);
 lcd.setCursor(5,0);
 lcd.print("W:");
 lcd.print(w);
 lcd.setCursor(10,0);
 lcd.print("H:");
 lcd.print(h);
 delayMicroseconds(2000);
 lcd.setCursor(0, 0);
}

long MicroToInch(long microseconds) {
   return microseconds / 74 / 2;
}
