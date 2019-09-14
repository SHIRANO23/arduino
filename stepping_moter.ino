int Index;


#define enable_pin 8
#define direction_pin 6
#define step_pin 3
#define import_pin1 A5
#define import_pin2 A4


int value;
int value2;
int pulse_width;

void setup() 
{
  Serial.begin(9600);
  pinMode(enable_pin, OUTPUT); //Enable
  pinMode(step_pin, OUTPUT); //Step
  pinMode(direction_pin, OUTPUT); //Direction
  digitalWrite(enable_pin,LOW);
}

void loop() 
{
    value2 = analogRead(import_pin2) ;
    Serial.println(value2) ;
    if(value2 = 1023)
          digitalWrite(direction_pin,LOW);//回転方向 HIGH or LOW?
    else if(value2 < 10)
          digitalWrite(direction_pin,HIGH);//回転方向 HIGH or LOW
 
    value =  analogRead(import_pin1);
    pulse_width=map(value, 0, 1023, 0, 16000);
    
    digitalWrite(step_pin,HIGH);//HIGH and LOWのパルス信号を形成
    delayMicroseconds(pulse_width);//パルス幅(us)　パルス周波数=1/(パルス幅×2)
    digitalWrite(step_pin,LOW);
    delayMicroseconds(pulse_width);
