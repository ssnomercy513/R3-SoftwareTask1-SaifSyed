static byte cdPins[2][4] = {
  {4, 5, 6, 7},
  {8, 9, 10, 11}
  
};
int potentiometer = A5;
int val,input,tens,ones;

void setup() {
  for (byte i=0; i<=9; i++){
    pinMode(i, OUTPUT); 
  }
  pinMode(potentiometer,INPUT);  
  writeDigit(0, 0); writeDigit(1, 0); 
}

void loop() {
        
    input= analogRead(potentiometer);
        val= map(input,0,1024,0,99);
        tens = val / 10;     
        ones = val % 10;      
        writeDigit(0,byte(ones));
        writeDigit(1,byte(tens));
        delay(100);
}

void writeDigit(byte chipId, byte number) {
  byte pins[] = {cdPins[chipId][0], cdPins[chipId][1], cdPins[chipId][2], cdPins[chipId][3]};
  for (byte z=0; z<=3; z++){
    digitalWrite(pins[z], LOW); 
  }
  if (number == 0){ 
    /* Do nothing, data already set to 0 */ 
  }
  if (number == 1){
    digitalWrite(pins[0], HIGH); 
  }
  if (number == 2){
    digitalWrite(pins[1], HIGH); 
  }
  if (number == 3){
    digitalWrite(pins[1], HIGH); 
    digitalWrite(pins[0], HIGH); 
  }
  if (number == 4){
    digitalWrite(pins[2], HIGH); 
  }
  if (number == 5){
    digitalWrite(pins[2], HIGH); 
    digitalWrite(pins[0], HIGH); 
  }
  if (number == 6){
    digitalWrite(pins[2], HIGH); 
    digitalWrite(pins[1], HIGH); 
  }
  if (number == 7){
    digitalWrite(pins[2], HIGH); 
    digitalWrite(pins[1], HIGH); 
    digitalWrite(pins[0], HIGH); 
  }
  if (number == 8){
    digitalWrite(pins[3], HIGH); 
  }
  if (number == 9){
    digitalWrite(pins[3], HIGH); 
    digitalWrite(pins[0], HIGH); 
  }
}

