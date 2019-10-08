int incomingByte = 0; // for incoming serial data
int value = 0;
int charInput = 0;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  while (true){
   // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    value = incomingByte -48;
  
    if (value==-38){
      break;
    }

    // say what you got:
    Serial.print("I received: ");
    Serial.println(value);
    charInput = 10*charInput + value;
    
  }
  }
  Serial.println(charInput);
  charInput = 0; 
}
