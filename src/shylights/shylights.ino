// 2014/03/15
// initial hack 
// project: shy lights
// tom van den bon (http://www.tomvandenbon.co.za)

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62

#define E_STEP_PIN         26
#define E_DIR_PIN          28
#define E_ENABLE_PIN       24

#define Q_STEP_PIN         36
#define Q_DIR_PIN          34
#define Q_ENABLE_PIN       30

#define SENSOR_1            29
#define SENSOR_2            16
#define SENSOR_3            17
#define SENSOR_4            23
#define SENSOR_5            25
#define SENSOR_6            27

#define LIGHT_1            6
#define LIGHT_2            5
#define LIGHT_3            4
#define LIGHT_4            11
#define LIGHT_5            44

void setup() {
  
  Serial.begin(9600);
  
  pinMode( SENSOR_1, INPUT );
  pinMode( SENSOR_2, INPUT );
  pinMode( SENSOR_3, INPUT );
  pinMode( SENSOR_4, INPUT );
  pinMode( SENSOR_5, INPUT );
  
  pinMode( LIGHT_1, OUTPUT );
  pinMode( LIGHT_2, OUTPUT );
  pinMode( LIGHT_3, OUTPUT );
  pinMode( LIGHT_4, OUTPUT );
  pinMode( LIGHT_5, OUTPUT );
  
  pinMode(X_STEP_PIN  , OUTPUT);
  pinMode(X_DIR_PIN    , OUTPUT);
  pinMode(X_ENABLE_PIN    , OUTPUT);
  
  pinMode(Y_STEP_PIN  , OUTPUT);
  pinMode(Y_DIR_PIN    , OUTPUT);
  pinMode(Y_ENABLE_PIN    , OUTPUT);
  
  pinMode(Z_STEP_PIN  , OUTPUT);
  pinMode(Z_DIR_PIN    , OUTPUT);
  pinMode(Z_ENABLE_PIN    , OUTPUT);
  
  pinMode(E_STEP_PIN  , OUTPUT);
  pinMode(E_DIR_PIN    , OUTPUT);
  pinMode(E_ENABLE_PIN    , OUTPUT);
  
  pinMode(Q_STEP_PIN  , OUTPUT);
  pinMode(Q_DIR_PIN    , OUTPUT);
  pinMode(Q_ENABLE_PIN    , OUTPUT);
  
   digitalWrite(X_ENABLE_PIN    , LOW);
   digitalWrite(Y_ENABLE_PIN    , LOW);
   digitalWrite(Z_ENABLE_PIN    , LOW);
   digitalWrite(E_ENABLE_PIN    , LOW);
   digitalWrite(Q_ENABLE_PIN    , LOW);
}


int duration = 1000;
unsigned long start = 0;

int state1 = LOW;
int on1 = true;

int height = 2400;

int pos1 = height;
int pos2 = height;
int pos3 = height;
int pos4 = height;
int pos5 = height;
int pos6 = height;


void stepmotor( int which, int dir )
{
  switch( which )
  {
    case 1: 
    digitalWrite(X_DIR_PIN  , dir);
    digitalWrite(X_STEP_PIN , LOW);
    delay(1);
    break;
    
    case 2: 
    digitalWrite(Y_DIR_PIN  , dir);
    digitalWrite(Y_STEP_PIN , LOW);
    break;    

    case 3: 
    digitalWrite(Z_DIR_PIN  , dir);
    digitalWrite(Z_STEP_PIN , LOW);
    break;    

    case 4: 
    digitalWrite(E_DIR_PIN  , dir);
    digitalWrite(E_STEP_PIN , LOW);
    break;    
    
    case 5: 
    digitalWrite(Q_DIR_PIN  , dir);
    digitalWrite(Q_STEP_PIN , LOW);
    break;    


  }
}

void loop () {
  
  int sensor1 = digitalRead( SENSOR_1 );
  int sensor2 = digitalRead( SENSOR_2 );
  int sensor3 = digitalRead( SENSOR_3 );
  int sensor4 = digitalRead( SENSOR_4 );
  int sensor5 = digitalRead( SENSOR_5 );
  int sensor6 = digitalRead( SENSOR_6 );
      
  if ( sensor1 == HIGH )
  {  
    if ( pos1 < height )
    {
      pos1++;
      stepmotor(1, HIGH);
    }
  }

  if ( sensor2 == HIGH )
  {  
    if ( pos2 < height )
    {
      pos2++;
      stepmotor(2, HIGH);
    }
  }
  if ( sensor3 == HIGH )
  {  
    if ( pos3 < height )
    {
      pos3++;
      stepmotor(3, HIGH);
    }
  }
  if ( sensor4 == HIGH )
  {  
    if ( pos4 < height )
    {
      pos4++;
      stepmotor(4, HIGH);
    }
  }
  if ( sensor5 == HIGH )
  {  
    if ( pos5 < height )
    {
      pos5++;
      stepmotor(5, LOW);
    }
  }
  
  if ( sensor1 == LOW )
  {
    if ( pos1 > 0 )
    {
      pos1--;
      stepmotor(1,LOW);
    }
  }
  
  if ( sensor2 == LOW )
  {
    if ( pos2 > 0 )
    {
      pos2--;
      stepmotor(2, LOW);
    }
  }

  if ( sensor3 == LOW )
  {
    if ( pos3 > 0 )
    {
      pos3--;
      stepmotor(3, LOW);
    }
  }

  if ( sensor4 == LOW )
  {
    if ( pos4 > 0 )
    {
      pos4--;
      stepmotor(4,LOW);
    }
  }

  if ( sensor5 == LOW )
  {
    if ( pos5 > 0 )
    {
      pos5--;
      stepmotor(5, HIGH);
    }
  }

    delay(1);
    digitalWrite(X_STEP_PIN , HIGH);
    digitalWrite(Y_STEP_PIN , HIGH);
    digitalWrite(Z_STEP_PIN , HIGH);
    digitalWrite(E_STEP_PIN , HIGH);
    digitalWrite(Q_STEP_PIN , HIGH);

 
}

