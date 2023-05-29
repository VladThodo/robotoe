#include "HCPCA9685.h"
 
/* I2C slave address for the device/module. For the HCMODU0097 the default I2C address
   is 0x40 */
#define  I2CAdd 0x40


#define BASE_START 130
#define SHOULDER_START 0
#define ELBOW_START 300
#define JAW_START 50

#define BASE_SERVO 4
#define SHOULDER_SERVO 5
#define ELBOW_SERVO 6
#define JAW_SERVO 7
 
 
/* Create an instance of the library */
HCPCA9685 HCPCA9685(I2CAdd);

unsigned int prev_base_pos = BASE_START;
unsigned int prev_shoulder_pos = SHOULDER_START;  
unsigned int prev_elbow_pos = ELBOW_START;
unsigned int prev_jaw_pos = JAW_START;

bool isHumanPlayer = true;
bool buttonPressed = false;

void update_servo_pos(int servo, int new_pos){
  switch(servo){
    case BASE_SERVO:
      prev_base_pos = new_pos;
      break;
    case SHOULDER_SERVO:
      prev_shoulder_pos = new_pos;
      break;
    case ELBOW_SERVO:
      prev_elbow_pos = new_pos;
      break;
    case JAW_SERVO:
      prev_jaw_pos = new_pos;
      break;
  }
}

void sweep_servo(int servo, int start_pos, int stop_pos){
  update_servo_pos(servo, stop_pos);
  if(start_pos < stop_pos){
    for(int i = start_pos; i < stop_pos; i++){
       HCPCA9685.Servo(servo, i);
       delay(3);
    }
  } else {
    for(int i = start_pos; i > stop_pos; i--){
        HCPCA9685.Servo(servo, i);
       delay(3);
    }
  }
}

void wakeUp(){       // Init all servo positions
   HCPCA9685.Servo(JAW_SERVO, JAW_START);
   delay(200);
   HCPCA9685.Servo(SHOULDER_SERVO, SHOULDER_START);
   delay(200);
   HCPCA9685.Servo(ELBOW_SERVO, ELBOW_START);
   delay(200);
   HCPCA9685.Servo(BASE_SERVO, BASE_START);
   delay(200);
}

void makeWay(){    // MOve our fat ass out of the way and let the player place a ball on the board
  sweep_servo(SHOULDER_SERVO, prev_shoulder_pos, SHOULDER_START);
  sweep_servo(ELBOW_SERVO, prev_elbow_pos, ELBOW_START);
}

void grabBall(){     // Get ourselves in the right position and grab that ball
  HCPCA9685.Servo(JAW_SERVO, 50);
  update_servo_pos(JAW_SERVO, 50);
  sweep_servo(BASE_SERVO, prev_base_pos, 45);
  sweep_servo(ELBOW_SERVO, prev_elbow_pos, 175);
  sweep_servo(SHOULDER_SERVO, prev_shoulder_pos, 87);
  HCPCA9685.Servo(JAW_SERVO, 360);
  update_servo_pos(JAW_SERVO, 360);
}

void rest(){
  HCPCA9685.Servo(JAW_SERVO, 50);
  update_servo_pos(JAW_SERVO, 50);
  sweep_servo(BASE_SERVO, prev_base_pos, 45);
  sweep_servo(ELBOW_SERVO, prev_elbow_pos, 175);
  sweep_servo(SHOULDER_SERVO, prev_shoulder_pos, 90);
}

void ball_up(){        // Get up after the ball was grabbed
  sweep_servo(ELBOW_SERVO, prev_elbow_pos, 300);
  sweep_servo(SHOULDER_SERVO, prev_shoulder_pos, 0);
  sweep_servo(BASE_SERVO, prev_base_pos, 150);
}

void ball_0(){
  sweep_servo(SHOULDER_SERVO, prev_shoulder_pos, 177);
  sweep_servo(ELBOW_SERVO, prev_elbow_pos, 300);
  sweep_servo(BASE_SERVO, prev_base_pos, 170);
  delay(200);
  HCPCA9685.Servo(JAW_SERVO, 50);
  update_servo_pos(JAW_SERVO, 50);
}

void ball_1() {
  sweep_servo(BASE_SERVO, prev_base_pos, 163);
  sweep_servo(SHOULDER_SERVO, prev_shoulder_pos, 90);
  sweep_servo(ELBOW_SERVO, prev_elbow_pos, 207);
  delay(200);
  HCPCA9685.Servo(JAW_SERVO, 50);
  update_servo_pos(JAW_SERVO, 50);
}

void ball_2() {
  sweep_servo(BASE_SERVO, prev_base_pos, 143);
  sweep_servo(SHOULDER_SERVO, prev_shoulder_pos, 18);
  sweep_servo(ELBOW_SERVO, prev_elbow_pos, 200);
  delay(200);
  HCPCA9685.Servo(JAW_SERVO, 50);
  update_servo_pos(JAW_SERVO, 50);
}

void ball_3() {
  sweep_servo(BASE_SERVO, prev_base_pos, 204);
  sweep_servo(SHOULDER_SERVO, prev_shoulder_pos, 146);
  sweep_servo(ELBOW_SERVO, prev_elbow_pos, 249);
  delay(200);
  HCPCA9685.Servo(JAW_SERVO, 50);
  update_servo_pos(JAW_SERVO, 50);
}

void ball_4() {
  sweep_servo(BASE_SERVO, prev_base_pos, 206);
  sweep_servo(SHOULDER_SERVO, prev_shoulder_pos, 86);
  sweep_servo(ELBOW_SERVO, prev_elbow_pos, 215);
  delay(200);
  HCPCA9685.Servo(JAW_SERVO, 50);
  update_servo_pos(JAW_SERVO, 50);
}

void ball_5() {
  sweep_servo(BASE_SERVO, prev_base_pos, 201);
  sweep_servo(SHOULDER_SERVO, prev_shoulder_pos, 0);
  sweep_servo(ELBOW_SERVO, prev_elbow_pos, 205);
  delay(200);
  HCPCA9685.Servo(JAW_SERVO, 50);
  update_servo_pos(JAW_SERVO, 50);
}

void ball_6() {
  sweep_servo(BASE_SERVO, prev_base_pos, 231);
  sweep_servo(SHOULDER_SERVO, prev_shoulder_pos, 158);
  sweep_servo(ELBOW_SERVO, prev_elbow_pos, 270);
  delay(200);
  HCPCA9685.Servo(JAW_SERVO, 50);
  update_servo_pos(JAW_SERVO, 50);
}

void ball_7() {
  sweep_servo(BASE_SERVO, prev_base_pos, 239);
  sweep_servo(SHOULDER_SERVO, prev_shoulder_pos, 85);
  sweep_servo(ELBOW_SERVO, prev_elbow_pos, 215);
  delay(200);
  HCPCA9685.Servo(JAW_SERVO, 50);
  update_servo_pos(JAW_SERVO, 50);
}

void ball_8() {
  sweep_servo(BASE_SERVO, prev_base_pos, 242);
  sweep_servo(SHOULDER_SERVO, prev_shoulder_pos, 28);
  sweep_servo(ELBOW_SERVO, prev_elbow_pos, 200);
  delay(200);
  HCPCA9685.Servo(JAW_SERVO, 50);
  update_servo_pos(JAW_SERVO, 50);
}

void setup() 
{
  /* Initialise the library and set it to 'servo mode' */ 
  HCPCA9685.Init(SERVO_MODE);
 
  /* Wake the device up */
  HCPCA9685.Sleep(false);

  Serial.begin(9600);

  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(2), roboturn, HIGH);

  wakeUp();
}

void loop() 
{

  
  unsigned int base_pos;
  unsigned int shoulder_pos;
  unsigned int elbow_pos;
  unsigned int jaw_pos;

  if(Serial.available()){    // Check for serial messages

    byte command = Serial.read();

    if(command == 'b'){             // We're being asked to move the base
      base_pos = Serial.parseInt();
      //sweep_servo(BASE_SERVO, prev_base_pos, base_pos);
      HCPCA9685.Servo(BASE_SERVO, base_pos);
      prev_base_pos = base_pos;
    }

    if(command == 's'){             // We're being asked to move the base
      shoulder_pos = Serial.parseInt();
      //sweep_servo(BASE_SERVO, prev_base_pos, base_pos);
      HCPCA9685.Servo(SHOULDER_SERVO, shoulder_pos);
      prev_shoulder_pos = base_pos;
    }

     if(command == 'e'){             // We're being asked to move the base
      elbow_pos = Serial.parseInt();
      //sweep_servo(BASE_SERVO, prev_base_pos, base_pos);
      HCPCA9685.Servo(ELBOW_SERVO, elbow_pos);
      prev_elbow_pos = elbow_pos;
    }

     if(command == 'j'){             // We're being asked to move the base
      jaw_pos = Serial.parseInt();
      //sweep_servo(BASE_SERVO, prev_base_pos, base_pos);
      HCPCA9685.Servo(JAW_SERVO, jaw_pos);
      prev_jaw_pos = jaw_pos;
     }

     if(command == 'g'){
        grabBall();
     }

     if(command == 'r'){
        rest();
     }

     if(command == 'u'){
        ball_up();
     }

     if(command == '0'){
        ball_0();
     }

     if(command == '1'){
        ball_1();
     }

     if(command == '2'){
        ball_2();
     }

     if(command == '3'){
        ball_3();
     }

     if(command == '4'){
        ball_4();
     }

     if(command == '5'){
        ball_5();
     }
     
     if(command == '6'){
        ball_6();
     }

     if(command == '7'){
        ball_7();
     }

     if(command == '8'){
        ball_8();
     }

     if(command == 'h'){
       digitalWrite(13, HIGH);
     }

     if(command == 'l'){
        digitalWrite(13, LOW);
     }

  }
}

void roboturn(){
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 200ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 300) 
  {
    Serial.println("HIGH");
  }
  last_interrupt_time = interrupt_time;
}
