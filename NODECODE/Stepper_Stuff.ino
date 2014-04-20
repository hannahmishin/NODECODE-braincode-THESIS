


void potStepperRun(){

  // Read new position
  
  potVal  = analogRead(Pot);
 speedVal = map(potVal, 0, 1023, 0, 100);
 speedVal = speedVal *speedVal;
 posVal = map(potVal, 0, 1023, 0, 5000);
  stepper.moveTo(posVal);
  stepper.setSpeed(speedVal);
  stepper.runSpeedToPosition();
}


