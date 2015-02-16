#define BLUETOOTH_SPEED 9600
// If you are modifying your existing configuration, use this:
// #define BLUETOOTH_SPEED 57600

#include <SoftwareSerial.h>
#include <Servo.h>

Servo lservo;    // Create servo object to control the servo
Servo rservo;    // Create servo object to control the servo
int readValue;
int val;   // for incoming serial data
int rval;
int lval;
// Swap RX/TX connections on bluetooth chip
//   Pin 10 --> Bluetooth TX
//   Pin 11 --> Bluetooth RX
SoftwareSerial mySerial(10, 11); // RX, TX


/*
  The posible baudrates are:
    AT+BAUD1-------1200
    AT+BAUD2-------2400
    AT+BAUD3-------4800
    AT+BAUD4-------9600 - Default for hc-06
    AT+BAUD5------19200
    AT+BAUD6------38400
    AT+BAUD7------57600 - Johnny-five speed
    AT+BAUD8-----115200
    AT+BAUD9-----230400
    AT+BAUDA-----460800
    AT+BAUDB-----921600
    AT+BAUDC----1382400
*/


void setup()
{
  Serial.begin(9600);
  Serial.println("Starting config");
  mySerial.begin(BLUETOOTH_SPEED);
  
  lservo.attach(5);        // Attach the servo object to pin 9
  lservo.write(84);        // Attach the servo object to pin 9
  rservo.attach(6);        // Attach the servo object to pin 9
  rservo.write(88);         // Initialize servo position to 0
}

void loop() {
  if (mySerial.available() > 0) {
                // read the incoming byte:
                val = mySerial.parseInt();
                
                // Hard left
                if ((val >= 0) && (val < 30))
                {
                  lservo.write(82);
                  rservo.write(0); 
                }
                // Soft left
                else if ((val >= 30) && (val < 45))
                {
                  rservo.write(0);
                  lservo.write(135);
                }
                // Straight
                else if ((val >= 45) && (val < 55))
                {
                  rservo.write(0);
                  lservo.write(180);
                }
                // Soft right
                else if ((val >= 55) && (val < 70))
                {
                  lservo.write(180);
                  rservo.write(45);
                }
                // Hard right
                else if ((val >= 70) && (val <= 100))
                {
                  lservo.write(180);
                  rservo.write(90);
                }

                // say what you got:
                // Serial.print("I received: ");
                Serial.println(val);
                
                //delay(15);
                
 }
    
/*while (c == 1)
{
  myservo.write(0);
}
while (c == 4)
{
  myservo.write(84);
}*/


/*switch (val)
{
  // straight
  case 1:
  rservo.write(0);
  lservo.write(180);
  break;
  // right
  case 2:
  lservo.write(180);
  rservo.write(90);
  break;
  // left
  case 3:
  lservo.write(82);
  rservo.write(0); 
  break;
  // backwards
  case 4:
  lservo.write(0);
  rservo.write(180);
  break;
  // stop
  case 5:
  lservo.write(84);
  rservo.write(88);
  break;
}*/
}
