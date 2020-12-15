
void setup()
{
  Serial.begin(115200);
  delay(100); 
  Serial.println("Esp32 Door Automation");
  pinMode(2, OUTPUT);
}

void loop()
{             //initialsing varibles
  int a1=0;   // a1,a2,a3,a4 are the 4-bits for the password 
  int a2=0;   // my roll number is 82 hence my password will be 2 i.e 0010
  int a3=1;    // this is the pre-assigned password 
  int a4=0;
  int n=0;
  int b1=0;   // b1,b2,b3,b4 are used to detect the touch input so as to detect the password
  int b2=0;
  int b3=0;
  int b4=0;
  int p=0;
  Serial.println("Enter the password");
  while(n<3)      // LED blinks for 3 times.
  {
    digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);
    digitalWrite(2, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(500);
    n++;  
  }
unsigned long startTime = millis();
   
      if(touchRead(T0)<20)    // for the values that I tested for touchread values 
        {                     // serial monitor shows values from 0 to 30 
         b1=0;                // hence i considered <20 as touch
        }                     // sets the bit1 to 0 when touched
     else
        { 
        b1=1;                 // sets the bit to 1 when no touch is detected
        }
   Serial.println(b1);        
   delay(1000);

      if(touchRead(T0)<20)
        {
         b2=0; 
        }
     else
        { 
        b2=1;  
        }
   Serial.println(b2);
   delay(1000);
   
      if(touchRead(T0)<20)
        {
         b3=0; 
        }
     else
        { 
        b3=1 ; 
        }
   Serial.println(b3);
   delay(1000);
  
      if(touchRead(T0)<20)
        {
         b4=0; 
        }
     else
        { 
        b4=1;  
        }
   Serial.println(b4);
   delay(1000);


if(b1==a1 && b2==a2 && b3==a3 && b4==a4) // checking if all the input 4 bits are same as 
{                                         // the password bits
   Serial.println("Welcome Home Vinay Kumar"); 
   
}
else
{
  Serial.println("Wrong Password");
  
}
}
