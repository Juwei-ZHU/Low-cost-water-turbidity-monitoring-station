 #include <Wire.h>
#include <DFRobot_ADS1115.h>

int16_t Pow, WR1, WR2, WR3;

DFRobot_ADS1115 ads(&Wire);

void ADS1115setup(void) 
{
    ads.setAddr_ADS1115(ADS1115_IIC_ADDRESS1);   // 0x49
    ads.setGain(eGAIN_TWOTHIRDS);   // 2/3x gain
    ads.setMode(eMODE_SINGLE);       // single-shot mode
    ads.setRate(eRATE_128);          // 128SPS (default)
    ads.setOSMode(eOSMODE_SINGLE);   // Set to start a single-conversion
    ads.init(); 
  
}

void ADS1115get(void) 
{
    if (ads.checkADS1115())
    {        
        Pow = ads.readVoltage(0);
        WR1 = ads.readVoltage(1);
        WR2 = ads.readVoltage(2);
        WR3 = ads.readVoltage(3);
    }

    delay(100);
}
