int Data[] = {1,0,1,0};
int sum1 = 0;
int sum2 = 0;


void setup() {
  
   Serial.begin(115200);
   Serial.println("CheckSum Begin");
   int len =  (sizeof(Data)/sizeof(Data[0]));
   Check(Data, len);   
}

void loop() {
}  

int Fletcher(int data[], int len){
  for(int i = 0; i < len; i++){
    sum1 = (sum1 + int(Data[i])) % 255;
    sum2 = (sum2 + sum1) % 255;
  }

  return (sum2 << 8) | sum1;
} 

void Check(int Data[], int len){
  
    int CheckSum = Fletcher(Data, len);
    Serial.println(CheckSum);
    int fletcher0 = CheckSum & 255;
    int fletcher1 = (CheckSum >> 8) & 255;
    int tempR = 255 - ((fletcher0 + fletcher1) % 255);
    int tempL = 255 - ((fletcher0 + tempR) % 255);
    Serial.print(tempL);
    Serial.print(", ");
    Serial.println(tempR);
}
