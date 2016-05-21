void setup() { //Code that "Sets Up" the program and prepares the arduino for what you want it to do, this code is executed at launch and does not loop or continue running.
  // initialize pins as an output.
  pinMode(11, OUTPUT);//Tells arduino to use pin 11 as an output
  pinMode(12, OUTPUT);//Tells arduino to use pin 12 as an output
  pinMode(6, OUTPUT);//Tells arduino to use pin 6 as an output
  Serial.begin(9600);//Tells the arduino the baudrate (Sampling rate) for an input the computer will take (For debugging purposes)
  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(12, HIGH); //outputs power
  int sensorValue = analogRead(A0);//Tells the computer and arduino that it will be reading values under the name of the integer, sensor value, and that the input will be from pin A0 (Analog pin 0)
  Serial.println(sensorValue); //Displays the sensor value in the terminal
  delay(100);//Tells the computer to wait 100ms before it updates the viewable value.
  if(sensorValue <=400){ //Conditional that tells the arduino how to intereperit the values coming from the sensor, the sensors values range from 0-1023 based on the resistance(Pressure put) on the softPot.
    analogWrite(6, 200);

  }
  else if(sensorValue >400 && sensorValue <450){
    analogWrite(6, 50);

  }
   else if(sensorValue >=450&& sensorValue <700){
    analogWrite(6, 35);

  }
   else if(sensorValue >=700 && sensorValue <1050){
    analogWrite(6, 25);

  }
    else if(sensorValue >=1050){
    analogWrite(6, 0);

  }
  else{
    digitalWrite(6,HIGH); //if the value is none of the above the lights are 100% on
  }
}
