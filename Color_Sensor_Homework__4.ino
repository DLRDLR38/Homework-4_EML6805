//frequency scaling pins of the TCS3200 color sensor So,S1
const int S0 = 2;
const int S1 = 3;
//pins of the TCS3200 color sensor for selecting photodiodes that activiate the blue, green, and red light being detected
const int S2 = 4;
const int S3 = 5;
//frequency out pin of the TCS3200 color sensor
const int frequencyOut = 6;
//enable pin of the TCS3200 that is active low and turns on the frequencyOut pin which allows the user to read the data reported back thus identifying the different colors
const int enable = 7;
//variable to store the recorded information for the red, green, and blue light
int redLight = 0;
int blueLight = 0;
int greenLight = 0;
int colorIdentified = 0;


void setup()
{
 //initializing serial communication
Serial.begin(9600);
//setting up digital pins of the Arduino Uno
pinMode(S0,OUTPUT);
pinMode(S1,OUTPUT);
pinMode(S2,OUTPUT);
pinMode(S3,OUTPUT);
pinMode(enable,OUTPUT);
pinMode(frequencyOut,INPUT);
//Sets the frequency scaling to 20% which is common for this sensor
digitalWrite(S0,HIGH);
digitalWrite(S1,LOW);

}

void loop()
{
//setting pins of the TCS3200 color sensor to detect red light
digitalWrite(S2, LOW);
digitalWrite(S3, LOW);
//turning on enable to frequency enable
digitalWrite(enable, LOW);
//saving data read into redLight variable
redLight = digitalRead(frequencyOut);
//turning off enable to frequency output
digitalWrite(enable, HIGH);

//setting pins of the TCS3200 color sensor to detect blue light
digitalWrite(S2, LOW);
digitalWrite(S3, HIGH);
//turning on enable to frequency enable
digitalWrite(enable, LOW);
//saving data read into blueLight variable
blueLight = digitalRead(frequencyOut);
//turning off enable to frequency output
digitalWrite(enable, HIGH);

//setting pins of the TCS3200 color sensor to detect green light
digitalWrite(S2, HIGH);
digitalWrite(S3, HIGH);
//turning on enable to frequency enable
digitalWrite(enable, LOW);
//saving data read into greenLight variable
greenLight = digitalRead(frequencyOut);
//turning off enable to frequency output
digitalWrite(enable, HIGH);

//enabling the frequency out pin
digitalWrite(enable, LOW);

//while loop to check for blue objects
//The previous code found and saved the values of the red and green light; however, since we know the value of blue light in this instance and that's the only light were 
//concerned with identifying a simple if statement that compares the value of the blue light to any other value found would suffice in identifying it for the robotic arm to act.
while(1)
{
//save value read from the frequencyOut pin of the TCS3200 color sensor into the variable colorTested
colorIdentified = digitalRead(frequencyOut);

}

//if statement to compare value read from frequencyOut pin of TCS3200 and compare it to the known value of blueLight.
//To allow for small discrepancies the value of 10 has been added/subtracted to blueLight
if (colorIdentified > constrain(blueLight, blueLight - 10, blueLight +10))
{
Serial.println("A blue object has been detected for the robotic arm to pick up");
}

}
