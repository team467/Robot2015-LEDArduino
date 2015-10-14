#define GREEN_CHANNEL  10
#define RED_CHANNEL 11
#define BLUE_CHANNEL 9

void setup() 
{
  
}

//void loop_debug() 
//{
//    //debug mode that links each digital input with a color channel if things are
//    //not working as they should
//
//    if (digitalRead(autoOut) == HIGH)
//    {
//        analogWrite(Ri,255); 
//    }
//    else
//    {
//        analogWrite(Ri,0);
//    }   
//    if (digitalRead(teleopOut) == HIGH)
//    {
//        analogWrite(Gi,255); 
//    }
//    else
//    {
//        analogWrite(Gi,0);
//    }   
//    if (digitalRead(warningOut) == HIGH)
//    {
//        analogWrite(Bi,255); 
//    }
//    else
//    {
//        analogWrite(Bi,0);
//    }
//}

/* 
 * Set the LED strip to the specified RGB values
 * 
 */
void RGBWrite(int red, int green, int blue)
{
    analogWrite(RED_CHANNEL, red);
    analogWrite(GREEN_CHANNEL, green);
    analogWrite(BLUE_CHANNEL, blue);
}

/*
 * set a given RGB color then wait for the specified delay
 * 
 * red, green, blue - bytes in range 0 to 255
 * delay - delay in milliseconds to wait
 *
 */
void RGBWriteDelay(int red, int green, int blue, int delayMS)
{
    RGBWrite(red, green, blue);
    delay(delayMS);
}

/*
 * pulse the given color
 *
 * The input red, green and blue values should be 0 or 1
 *
 */
void RGBPulse(float red, float green, float blue)
{
    for (int i = 1; i < 255; i++) 
    {
        // Ramp up brightness
        RGBWrite(red*i, green*i, blue*i); 
        delay(1);
    }
    for (int i = 255; i > 1; i--) 
    {
        // Ramp down brightness
        RGBWrite(red*i, green*i, blue*i);
        delay(3);
    }
}

/*
 * Fast pulse a given color
 *
 * The input red, green and blue values should be 0 or 1
 *
 */
void RGBFastPulse(float red, float green, float blue)
{
    for (int i = 1; i < 255; i+=2) 
    {
        // Ramp up brightness
        RGBWrite(red*i, green*i, blue*i); 
        delay(1);
    }
    for (int i = 255; i > 1; i--) 
    {
        // Ramp down brightness
        RGBWrite(red*i, green*i, blue*i);
        delay(3);
    }
}

/*
 * These enums should be the same as used on the Java side for the 
 * robot code
 *
 */
 enum LEDMode
{
    OFF           = 0,
    RAINBOW       = 11,
    PULSE_RED     = 12,
    PULSE_BLUE    = 13,
    BLUE_AND_GOLD = 14,
    YELLOW        = 16
    REESES_PIECES = 1,
    PULSE_ORANGE  = 2,
    PULSE_PURPLE  = 3,
    CANDY_CORN    = 4,
    WHITE        = 6
};

/*
 * Different modes are encoded into 3 digital output channels from the RoboRio
 * map these to the enum
 *
 */
int readInput()
{
  enum LEDMode m = OFF;
    int b0 = (digitalRead(0) == HIGH) ? 0x01 : 0;
    int b1 = (digitalRead(1) == HIGH) ? 0x02 : 0;
    int b2 = (digitalRead(2) == HIGH) ? 0x04 : 0;

    return ( b0 | b1 | b2);
}

void loop()
{
    switch (readInput())
    {
        case RAINBOW:
            //rainbow mode that switches colors every 100 milleseconds
    
            RGBWriteDelay(255, 0, 0, 100);    // Red for 100 ms
            RGBWriteDelay(255, 255, 0, 100);  // Yellow for 100ms
            RGBWriteDelay(0, 255, 0, 100);    // Green for 100ms
            RGBWriteDelay(0, 255, 255, 100);  // Cyan for 100ms     
            RGBWriteDelay(0, 0, 255, 100);    // Blue for 100ms
            RGBWriteDelay(255, 0, 255, 100);  // Magenta for 100ms
            break;

        case PULSE_RED:
            RGBPulse(1, 0, 0);  // Pulse Red
            break;

        case PULSE_BLUE:
            RGBPulse(0, 0, 1);  // Pulse Blue
            break;

        case BLUE_AND_GOLD:
            RGBPulse(1, 1, 0);  // Pulse Yellow
            RGBPulse(0, 0, 1);  // Pulse Blue
            break;

        case YELLOW:
            RGBFastPulse(1, 1, 0);  // Pulse Yellow
            break;

        case REESES_PIECES:
            RGBWriteDelay(255, 165, 0, 100);   // Orange for 100ms
            RGBWriteDelay(255, 255, 0, 100);   // Yellow for 100ms
            RGBWriteDelay(255, 165, 0, 100);   // Brown for 100ms
            break;

        case PULSE_ORANGE:
            RGBPulse(1, 0.6, 0);
            break;

        case PULSE_PURPLE:
            RGBPulse(0.5, 0, 0.5);
            break;

        case CANDY_CORN:
            RGBFastPulse(1, 1, 0);  // Pulse Yellow
            RGBFastPulse(1, 0.6, 0); // Pulse Orange
            RGBFastPulse(1, 1, 1); // Pulse White
            break;

        case WHITE:
            RGBFastPulse(1, 1, 1);

        default:
            RGBWrite(0, 0, 0);
            break;
    }
}
