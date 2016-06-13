#include <MsTimer2.h>

#define COIL0_PIN (8)
#define COIL1_PIN (6)
#define COIL2_PIN (5)
#define COIL3_PIN (4)

const byte coilOutput4[4][4] = { {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {1, 0, 0, 1} };
const byte coilOutput8[8][4] = { {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}, {1, 0, 0, 1}, {1, 0, 0, 0} };

long stepIndex;
long currentStepIndex;
/*
void motorHander(void)
{
    if (stepIndex != currentStepIndex)
    {
        if (stepIndex < currentStepIndex)
            currentStepIndex--;
        else
            currentStepIndex++;

        byte coilIndex = currentStepIndex % 8;
        digitalWrite(COIL0_PIN, coilOutput8[coilIndex][0]);
        digitalWrite(COIL1_PIN, coilOutput8[coilIndex][1]);
        digitalWrite(COIL2_PIN, coilOutput8[coilIndex][2]);
        digitalWrite(COIL3_PIN, coilOutput8[coilIndex][3]);
    }
}
*/


void motorHander(void)
{
    currentStepIndex++;

    byte coilIndex = currentStepIndex % 8;
    digitalWrite(COIL0_PIN, coilOutput8[coilIndex][0]);
    digitalWrite(COIL1_PIN, coilOutput8[coilIndex][1]);
    digitalWrite(COIL2_PIN, coilOutput8[coilIndex][2]);
    digitalWrite(COIL3_PIN, coilOutput8[coilIndex][3]);
}

void setup(void)
{
    pinMode(LED_BUILTIN, OUTPUT);

    pinMode(COIL0_PIN, OUTPUT);
    pinMode(COIL1_PIN, OUTPUT);
    pinMode(COIL2_PIN, OUTPUT);
    pinMode(COIL3_PIN, OUTPUT);

    stepIndex        = 0L;
    currentStepIndex = 0L;

    MsTimer2::set(1, motorHander); 
    MsTimer2::start(); 
}

void loop(void)
{
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);

    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
}
