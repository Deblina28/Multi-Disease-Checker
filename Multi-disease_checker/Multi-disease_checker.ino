#define Q1 "Do you have a fever for more than three days?"
#define Q2 "Are you suffering from dry cough?"
#define Q3 "Are you getting tired easily?"
#define Q4 "Are you facing any shortness of breath or difficulty in breathing?" 
#define Q5 "Are you experiencing chest pain or pressure?"
#define Q6 "Are you experiencing any loss of speech or movement?"
#define Q7 "Have you lost your sense of taste or smell recently?"
#define Q8 "Are you suffering from congestion or a case of runny nose?"
#define Q9 "Have you experienced nausea or tendency of vominiting recently?"
#define Q10 "Are you suffering or have you recently suffered from diarrhoea?"

/*const char* [][] ques PROGMEM = {
  {"Do you have a fever for more than three days?",
                    "Are you suffering from dry cough?",
                    "Are you getting tired easily?",
                    "Are you facing any shortness of breath or difficulty in breathing?",
                    "Are you experiencing chest pain or pressure?",
                    "Are you experiencing any loss of speech or movement?",
                    "Have you lost your sense of taste or smell recently?",
                    "Are you suffering from congestion or a case of runny nose?",
                    "Have you experienced nausea or tendency of vominiting recently?",
                    "Are you suffering or have you recently suffered from diarrhoea?", },

                {   "Do you have a runny or stuffy nose (nasal congestion)?",
                    "Are you suffering from a high fever (>100° F)?",
                    "Have you been continuously sneezing?",
                    "Are you experiencing a headache?",
                    "Do you have a sore throat?",
                    "Are you experiencing intense pain and fatigue?",
                    "Do you have a mild fever (>99° F)?",
                    "define Q38: Are you having severe and frequent dry cough?",
                    "Do you have a mild cough?", }
                    };*/

void setup() 
{
  DDRD = 0x02;
  PORTD = 0xfe;
  Serial.begin(38400);
}

int ans = -1, n = 1;
int data[10];

void loop() 
{
  dispQ (n);
   do 
   {
    ans = mapp(PIND);
    data[n-1]=ans;
   }
   while (ans == -1);

    
   delay (200);
   n++;

   if(ans==1)
    Serial.println("YES");   
   else if(ans==0)
     Serial.println("NO");   
   

  if(n==10)
   {
     Serial.println();
     
     Serial.println(checkPos());

     Serial.println();
   n=1; 
   
   Serial.println("Test Ended");
   Serial.println("____________________________________________________");
   for(int i=0;i<10;i++)
   data[i]=0;
   }
   

   
   
 }

void dispQ (byte x)
{
  if (x == 1)
  Serial.println (Q1);

  else if (x == 2)
  Serial.println (Q2);

  else if (x == 3)
  Serial.println (Q3);

  else if (x == 4)
  Serial.println (Q4);

  else if (x == 5)
  Serial.println (Q5);

  else if (x == 6)
  Serial.println (Q6);

  else if (x == 7)
  Serial.println (Q7);

  else if (x == 8)
  Serial.println (Q8);

  else if (x == 9)
  Serial.println (Q9);

  else 
  Serial.println(Q10);
}

int mapp (byte x)
{
  if (x == 251)
  return 1;

  else if (x == 247)
  return 0;

  //Serial.println(x);

  return -1;
}

String checkPos()
{
 
  
  if(data[0]&&data[1]&&data[2])
  return "Get Tested, You May be Covid Positive !";

  if(data[0]&&data[1]&&data[3]&&data[6])
  return "Get Tested, You May be Covid Positive !";

  if(data[0]&&data[1]&&data[3]&&data[4])
  return "Get Tested, You May be Covid Positive !";

  if(data[0]&&data[1]&&data[2]&&data[3]&&data[4]&&data[5]&&data[6]&&data[7]&&data[8]&&data[9])
  return "Immidiately Consult a Doctor, You are Most Probably Covid Positive !";

  if(!(data[0]||data[1]||data[2]||data[3]||data[4]||data[5]||data[6]||data[7]||data[8]||data[9]))
  return "You are Safe for Now, But since you are doing this test, You are Alarmed ! Stay Safe !";

  return "Stay In Home Quarrantine for at least 3 days and take this Test again !";

  
}
