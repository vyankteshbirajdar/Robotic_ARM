#include <Servo.h>

// Creating servo objects
Servo B_servo;
Servo S_servo;
Servo E_servo;
Servo P_servo;
Servo R_servo;

// Servo pin attachment defining
#define BASE_PIN 3         // BASE_SERVO_PIN ATTACH TO PIN 3
#define SHOULDER_PIN 5     // SHOULDER_SERVO_PIN ATTACH TO PIN 5
#define ELBOW_PIN 6        // ELBOW_SERVO_PIN ATTACH TO PIN 6
#define WRIST_PITCH_PIN 9  // WRIST_PITCH_PIN ATTACH TO PIN 9
#define WRIST_ROLL_PIN 10  // WRIST_ROLL_PIN ATTACH TO PIN 10

// Defining limitation parameters
int16_t B_min, B_max, S_min, S_max, E_min, E_max, P_min, P_max, R_min, R_max;  // angle
int8_t L1, L2, L3 ;                                               // link

// const value 
const int S_dealy = 700 ;

//_____________________________________________________________________________________________ DECLEARNING ROTATIONNAL ANGLE LIMIT  ________________________________________________________________________________________________________________//
void Rotation_lim() {
  Serial.println("Enter each angle limit one at a time when prompted (press Enter after each value):");
  Serial.println("Format: Enter integer values between 0-360");

  // Get Base min
  Serial.print("min base angle       : ");
  while (Serial.available() == 0) { delay(100); }  // Wait for input
  B_min = Serial.parseInt();
  Serial.println(B_min);
  while (Serial.available() > 0) Serial.read();    // Clear buffer

  // Get Base max
  Serial.print("max base angle       : ");
  while (Serial.available() == 0) { delay(100); }
  B_max = Serial.parseInt();
  Serial.println(B_max);
  while (Serial.available() > 0) Serial.read();

  // Get Shoulder min
  Serial.print("min shoulder angle   : ");
  while (Serial.available() == 0) { delay(100); }
  S_min = Serial.parseInt();
  Serial.println(S_min);
  while (Serial.available() > 0) Serial.read();

  // Get Shoulder max
  Serial.print("max shoulder angle   : ");
  while (Serial.available() == 0) { delay(100); }
  S_max = Serial.parseInt();
  Serial.println(S_max);
  while (Serial.available() > 0) Serial.read();

  // Get Elbow min
  Serial.print("min elbow angle      : ");
  while (Serial.available() == 0) { delay(100); }
  E_min = Serial.parseInt();
  Serial.println(E_min);
  while (Serial.available() > 0) Serial.read();

  // Get Elbow max
  Serial.print("max elbow angle      : ");
  while (Serial.available() == 0) { delay(100); }
  E_max = Serial.parseInt();
  Serial.println(E_max);
  while (Serial.available() > 0) Serial.read();

  // Get Wrist Pitch min
  Serial.print("min wrist pitch angle: ");
  while (Serial.available() == 0) { delay(100); }
  P_min = Serial.parseInt();
  Serial.println(P_min);
  while (Serial.available() > 0) Serial.read();

  // Get Wrist Pitch max
  Serial.print("max wrist pitch angle: ");
  while (Serial.available() == 0) { delay(100); }
  P_max = Serial.parseInt();
  Serial.println(P_max);
  while (Serial.available() > 0) Serial.read();

  // Get Wrist Roll min
  Serial.print("min wrist roll angle : ");
  while (Serial.available() == 0) { delay(100); }
  R_min = Serial.parseInt();
  Serial.println(R_min);
  while (Serial.available() > 0) Serial.read();

  // Get Wrist Roll max
  Serial.print("max wrist roll angle : ");
  while (Serial.available() == 0) { delay(100); }
  R_max = Serial.parseInt();
  Serial.println(R_max);
  while (Serial.available() > 0) Serial.read();

  // Verify all inputs
  Serial.println("\nEntered Limits:");
  Serial.print("Base: "); Serial.print(B_min); Serial.print(" to "); Serial.println(B_max);delay(S_dealy);
  Serial.print("Shoulder: "); Serial.print(S_min); Serial.print(" to "); Serial.println(S_max);delay(S_dealy);
  Serial.print("Elbow: "); Serial.print(E_min); Serial.print(" to "); Serial.println(E_max);delay(S_dealy);
  Serial.print("Wrist Pitch: "); Serial.print(P_min); Serial.print(" to "); Serial.println(P_max);delay(S_dealy);
  Serial.print("Wrist Roll: "); Serial.print(R_min); Serial.print(" to "); Serial.println(R_max);delay(S_dealy);
}

//_____________________________________________________________________________________________ DECLEARNING LINK LENGTH  LIMIT ________________________________________________________________________________________________________________//

void link_lim() {
  Serial.println("Enter each link length one at a time when prompted (press Enter after each value):");
  Serial.println("Format: Enter integer values for link lengths");

  // Get Link 1
  Serial.print("Link 1 length: ");
  while (Serial.available() == 0) { delay(100); }  // Wait for input
  L1 = Serial.parseInt();
  Serial.println(L1);
  while (Serial.available() > 0) Serial.read();    // Clear buffer

  // Get Link 2
  Serial.print("Link 2 length: ");
  while (Serial.available() == 0) { delay(100); }
  L2 = Serial.parseInt();
  Serial.println(L2);
  while (Serial.available() > 0) Serial.read();

  // Get Link 3
  Serial.print("Link 3 length: ");
  while (Serial.available() == 0) { delay(100); }
  L3 = Serial.parseInt();
  Serial.println(L3);
  while (Serial.available() > 0) Serial.read();

  // Verify all inputs
  Serial.println("\nEntered Link Lengths:");
  Serial.print("Link 1: "); Serial.println(L1);
  Serial.print("Link 2: "); Serial.println(L2);
  Serial.print("Link 3: "); Serial.println(L3);
}

//_____________________________________________________________________________________________HOME POSTION FUNCTION________________________________________________________________________________________________________________//
void movetohome() {

  B_servo.write(90); 
  S_servo.write(90);
  E_servo.write(90); 
  P_servo.write(90); 
  R_servo.write(90); 
   Serial.println("base servo set at 90 degree");delay(S_dealy);
   Serial.println("shoulder servo set at 90 degree");delay(S_dealy);
   Serial.println("elbow servo set at 90 degree");delay(S_dealy);
   Serial.println("wrist pitch servo set at 90 degree");delay(S_dealy);
   Serial.println("wrist roll servo set at 90 degree");delay(S_dealy);
}


//_____________________________________________________________________________________________SETUP  START ________________________________________________________________________________________________________________//

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect
  }
  Serial.println("5-Axis Robotic Arm Initialization");

  // Servo SETUP
  B_servo.attach(BASE_PIN);
  S_servo.attach(SHOULDER_PIN);
  E_servo.attach(ELBOW_PIN);
  P_servo.attach(WRIST_PITCH_PIN);
  R_servo.attach(WRIST_ROLL_PIN);
 

  // Declaring limit of Servo angle 
  Rotation_lim();
  Serial.println("-------------------------------------------------------------------------------------------------------------------------------------");

  // declearing link lenth 
  link_lim();
  Serial.println("-------------------------------------------------------------------------------------------------------------------------------------");

  // Setup arm to home position
  movetohome();
  Serial.println("-------------------------------------------------------------------------------------------------------------------------------------");

}

//_____________________________________________________________________________________________SETUP END ________________________________________________________________________________________________________________//



//  Current angle
int8_t B_angle = 90;  // BASE_SERVO_ANGLE
int8_t S_angle = 90;  // SHOULDER_SERVO_ANGLE
int8_t E_angle = 90;  // ELBOW_SERVO_ANGLE
int8_t P_angle = 90;  // WRIST_PITCH_ANGLE
int8_t R_angle = 90;  // WRIST_ROLL_ANGLE

//  current co-ordinate 
int X = 0 , Y = 0 , Z = L1 +L2+L3 ;



//_____________________________________________________________________________________________ MAIN LOOP BEGINE  ________________________________________________________________________________________________________________//


void loop() {
  


}