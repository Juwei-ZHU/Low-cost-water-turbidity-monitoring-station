
String printHeader = "DS3231 (UTC+2), Power voltage (mV), WR1 voltage (mV), WR2 voltage (mV), WR3 voltage (mV), Temperature (°C)";
String allData;
String allShow;

void preparePrint(){
  allData = 
  stringRTC() + 
  ", " +
  String(Pow)
  +','
  +String(WR1)
  +','
  +String(WR2)
  +','
  +String(WR3)
  +','
  +String(Temp); 

  allShow =  
  "Pow:" +
  String(Pow)
  +"mVWR1:"
  +String(WR1)
  +"mVWR2:"
  +String(WR2)
  +"mVWR3:"
  +String(WR3)
  +"mV";
}
