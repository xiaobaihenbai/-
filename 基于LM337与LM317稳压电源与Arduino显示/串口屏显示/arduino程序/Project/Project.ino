#define TJC Serial


void SendEnd()
{
  
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);
  
  }


void setup() {
  // put your setup code here, to run once:
TJC.begin(9600);
}



void loop() {
// put your main code here, to run repeatedly:
char str[100];

if(analogRead(A0)>0)
{
double a = analogRead(A0);
double b = analogRead(A1);

double val = (8.2/(8.2+24))*a;


sprintf(str, "n0.txt=%d V ",val);
TJC.print(str);
SendEnd();

sprintf(str, "n1.txt=%d A ",b);
TJC.print(str);
SendEnd();
}
else
{
  TJC.print("n0.txt=无电压");
  SendEnd();

  TJC.print("n1.txt=无电流");
  SendEnd();
  }

}
