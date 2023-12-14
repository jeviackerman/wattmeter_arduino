

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   // initialize the library with the numbers of the interface pins
float vin=0.0;
float power=0.0;
float temp=0.0;
float Iin=0.0;
float r1=36000.0;                       // Set the value of resister R1
float r2=4000.0;                       // Set the value of resister R2

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);                    // set up the LCD's number of columns and rows: 
  lcd.print("Wattmeter 219031465");     // Print a message to the LCD.
  delay(1000);
  lcd.clear();
  lcd.print("Wattmeter");
}

void loop() {
  int analog_val=analogRead(A0);      // read the value of analog pin A0 and store it in the variable analog_val
  int analog_val2=analogRead(A1);
  temp = (analog_val * 5.0)/1024.0;   
  vin = temp/(r2/(r1+r2));
  Iin = (analog_val2*0.00489)/(0.47);
  power = vin*Iin;
  if(power<0.1)
  {
    power=0.0;
  }
  lcd.setCursor(0, 1);        // set the cursor to column 0 line 1
  lcd.print("Power = ");    // print the voltage
  lcd.println(power);
  delay(300);
}