#include <AccelStepper.h>

//MISC SUPERFLOUSPOUS POT FOR STEPPER CONTROL
int Pot = A2;
int potVal;
int speedVal;
int posVal;




///STEPPER SHIT

int motorSpeed = 9600; //maximum steps per second (about 3rps / at 16 microsteps)
int motorAccel = 80000; //steps/second/second to accelerate

int motorDirPin = 0; //digital pin 2
int motorStepPin = 1; //digital pin 3

//set up the accelStepper intance
//the "1" tells it we are using a driver
AccelStepper stepper(1, motorStepPin, motorDirPin); 

///limit switch timer 
int waitTime = 500;


////DC MOTOR ////////////////
/////////////////////////////



///NOTES:
///  if TLone == 0 - TLleft issued - and if moving right before preDirTL = 1 - likewise opposite if TLone == 1
/// if TLone = = 2 - then TLone is null and can be addressed
///ALLL DC's ARE BORN MOVING RIGHT!!!

///////////////////////////
//Top Left DC
////////////////////////
//////////////////////

const int TL1 = 2;  //pins
const int TL2 = 3; //pins
const int TLswitch = 14;  //pins

int TLstate = 0;  ///read the switch pin

///SWITCH SHIT
boolean  switchHitTL = false; ///sets to true as soon as switch is hit the 1st time
int SwitchcounterTL= 1;// counter begins to reverse the DC once switch has been hit
boolean TL = false; //variable to allow exit from switch function


///DIRECTION SHIT
int TLone; //variable to know direction
int ChangecounterTL =1; ///timer for change 
int TLDirState =0;///allows Dir change to occur when it is a 0, when a 1 it does not allow change Dir commands 
boolean TLDir = false; 
int preDirTL = 2; ///sets previous DIrection to Null

///variables for resuming fucntionality after limit switch resets
int ResumecounterTL = 1;
boolean executeLimitSwitchTL = false;  //////allows function EXECUTELIMITSWITCH to be entered into. LIMIT SWITCh function auto resets this once switch == HIGH 


/////////////////////////////////////
//Bottom Left DC
///////////////////////////////

const int BL1 = 4; 
const int BL2 = 5; 
const int BLswitch = 15;
int BLstate = 0;


///SWITCH SHIT
boolean  switchHitBL = false; ///sets to true as soon as switch is hit the 1st time
int SwitchcounterBL= 1;// counter begins to reverse the DC once switch has been hit
boolean BL = false; //variable to allow exit from switch function


///DIRECTION SHIT
int BLone; //variable to know direction
int ChangecounterBL =1; ///timer for change 
int BLDirState =0;///allows Dir change to occur when it is a 0, when a 1 it does not allow change Dir commands 
boolean BLDir = false; 
int preDirBL = 2; ///sets previous DIrection to Null

///variables for resuming fucntionality after limit switch resets
int ResumecounterBL = 1;
boolean executeLimitSwitchBL = false;  //////allows function EXECUTELIMITSWITCH to be entered into. LIMIT SWITCh function auto resets this once switch == HIGH 

/////////////////////////////
// Top Right DC
///////////////////////////////

const int TR1 = 8;  
const int TR2 = 9; 
const int TRswitch = 16;
int TRstate = 0;

///SWITCH SHIT
boolean  switchHitTR = false; ///sets to true as soon as switch is hit the 1st time
int SwitchcounterTR= 1;// counter begins to reverse the DC once switch has been hit
boolean TR = false; //variable to allow exit from switch function


///DIRECTION SHIT
int TRone; //variable to know direction
int ChangecounterTR =1; ///timer for change 
int TRDirState =0;///allows Dir change to occur when it is a 0, when a 1 it does not allow change Dir commands 
boolean TRDir = false; 
int preDirTR = 2; ///sets previous DIrection to Null

///variables for resuming fucntionality after limit switch resets
int ResumecounterTR = 1;
boolean executeLimitSwitchTR = false;  //////allows function EXECUTELIMITSWITCH to be entered into. LIMIT SWITCh function auto resets this once switch == HIGH 



////////////////////////////////////
//Bottom Right DC
////////////////////////

const int BR1 = 11;   
const int BR2 = 10;  
const int BRswitch = 17;
int BRstate = 0;


///SWITCH SHIT
boolean  switchHitBR = false; ///sets to true as soon as switch is hit the 1st time
int SwitchcounterBR= 1;// counter begins to reverse the DC once switch has been hit
boolean BR = false; //variable to allow exit from switch function


///DIRECTION SHIT
int BRone; //variable to know direction
int ChangecounterBR =1; ///timer for change 
int BRDirState =0;///allows Dir change to occur when it is a 0, when a 1 it does not allow change Dir commands 
boolean BRDir = false; 
int preDirBR = 2; ///sets previous DIrection to Null

///variables for resuming fucntionality after limit switch resets
int ResumecounterBR = 1;
boolean executeLimitSwitchBR = false;  //////allows function EXECUTELIMITSWITCH to be entered into. LIMIT SWITCh function auto resets this once switch == HIGH 





///STEPPER SHIT////
////////////////////
#define DIR_PIN 0
#define STEP_PIN 1

///my RX and TX... I need pins! can I make my switches analog YES

////NOTES- when I hit the switch without calling the moveAfterSwitchTL(); function- I am able to 



void setup() {


  Serial.begin (9600);

  ///Stepepr shit
  stepper.setMaxSpeed(1000);

  ////stepper MOTOR///
  pinMode(DIR_PIN, OUTPUT); 
  pinMode(STEP_PIN, OUTPUT); 

  ////DC MOTOR ////////////////
  /////////////////////////////

  //Top Left DC
  pinMode(TL1, OUTPUT); 
  pinMode(TL2, OUTPUT);
  pinMode(TLswitch, INPUT);
  TLstate = digitalRead(TLswitch);


  //Bottom Left DC
  pinMode(BL1, OUTPUT); 
  pinMode(BL2, OUTPUT);
  pinMode(BLswitch, INPUT); 
  BLstate = digitalRead(BLswitch);


  // Top Right DC
  pinMode(TR1, OUTPUT); 
  pinMode(TR2, OUTPUT);
  pinMode(TRswitch, INPUT); 
  TRstate = digitalRead(TRswitch); 

  //Bottom Right DC
  pinMode(BR1, OUTPUT); 
  pinMode(BR2, OUTPUT);
  pinMode(BRswitch, INPUT); 




}

void loop() {
  //RunTLDC();///CHECKED- WORKING
  
 RunBLDC();
}












