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

    // Active
    OFF          = 0,
    AUTONOMOUS   = 1,
    TEAM_RED     = 2,
    TEAM_BLUE    = 3,
    NO_TEAM      = 4,
    DISABLED     = 5,
    TIME_IS_UP   = 6
};

void rainbow()
{
    //rainbow mode that switches colors every 100 milleseconds
    
    RGBWrite(255, 0, 0); // Red
    delay(100);
    RGBWrite(255, 255, 0); // Yellow
    delay(100);
    RGBWrite(0, 255, 0); // Green
    delay(100);
    RGBWrite(0, 255, 255); // Cyan
    delay(100);     
    RGBWrite(0, 0, 255); // Blue
    delay(100);
    RGBWrite(255, 0, 255); // Magenta
    delay(100);
}

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
        case AUTONOMOUS:
            rainbow();
            break;

        case TEAM_RED:
            RGBPulse(1, 0, 0);  // Pulse Red
            break;

        case TEAM_BLUE:
            RGBPulse(0, 0, 1);  // Pulse Blue
            break;

        case NO_TEAM:
            RGBPulse(1, 0.84, 0);  // Pulse Yellow
            RGBPulse(0, 0, 1);  // Pulse Blue
            break;

        case DISABLED:
            RGBPulse(1, 0.84, 0);  // Pulse Yellow
            RGBPulse(0, 0, 1);  // Pulse Blue
            break;

        case TIME_IS_UP:
            RGBFastPulse(1, 1, 0);  // Pulse Yellow
            break;

        default:
            RGBWrite(0, 0, 0);
            break;
    }
}
