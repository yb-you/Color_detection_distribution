#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6


int frequency = 0;
char color=0;
int R=0;
int G=0;
int Y=0;
int O=0;

int s=0;
void color_detect();
void color_select(char c);
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);  
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);


  Serial.begin(115200);
}

void loop() {
  color = 0;
  R=G=Y=O=0;
  s=Serial.read();
  if(s>0)
  {
    for(int i=0;i<10;i++)
    {
      color_detect();
    }
    if(R>G & R>Y & R>O) color = 'R';
    else if(G>R & G>Y & G>O) color = 'G';
    else if(Y>R & Y>G & Y>O) color = 'Y';
    else if(O>R & O>G & O>Y) color = 'O';
    
    if(color != 0){Serial.print(color);delay(5000);}
  }
}
void color_detect()
{ 
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
   delay(50);


  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
    delay(50);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  delay(50);

  R=R*R/100;
  G=G*G/100;
  B=B*B/100;

  
  /*
  Serial.print(R);Serial.print("\t");
  Serial.print(G);Serial.print("\t");
  Serial.print(B);Serial.print("\t");
  Serial.print("\n");
  
  delay(100);
  */

  
  if(R<15 & R>5 & G<35 & G>20 & B<30 & B>15){
    color_select('R');
  }
  else if(R<20 & R>10 & G<25 & G>10 & B<25 & B>15){
    color_select('G');
  }
  else if(R<15 & R>1 & G<20 & G>5 & B<25 & B>10){
    color_select('Y');
  }
  else if(R<15 & R>1 & G<30 & G>15 & B<25 & B>15){
    color_select('O');
  }
  
}
void color_select(char c)
{
  switch (c)
  {
    case 'R':
      R++;
      break;
    case 'G':
      G++;
      break;
    case 'Y':
      Y++;
      break;
    case 'O':
      O++;
      break;
  }
}