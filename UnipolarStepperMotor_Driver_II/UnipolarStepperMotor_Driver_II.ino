#define COIL0_PIN (8)
#define COIL1_PIN (6)
#define COIL2_PIN (5)
#define COIL3_PIN (4)

const unsigned long stepDelay         = 800;
const byte          coilOutput8[8][4] = { {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}, {1, 0, 0, 1}, {1, 0, 0, 0} };

unsigned long nextStepTime;
long currentStepIndex;

void setup(void)
{
    pinMode(LED_BUILTIN, OUTPUT);

    pinMode(COIL0_PIN, OUTPUT);
    pinMode(COIL1_PIN, OUTPUT);
    pinMode(COIL2_PIN, OUTPUT);
    pinMode(COIL3_PIN, OUTPUT);

    nextStepTime     = micros() + stepDelay;
    currentStepIndex = 0L;
}

void loop(void)
{
    while (micros() < nextStepTime) ;
    nextStepTime += stepDelay;

    byte coilIndex = currentStepIndex % 8;
    digitalWrite(COIL0_PIN, coilOutput8[coilIndex][0]);
    digitalWrite(COIL1_PIN, coilOutput8[coilIndex][1]);
    digitalWrite(COIL2_PIN, coilOutput8[coilIndex][2]);
    digitalWrite(COIL3_PIN, coilOutput8[coilIndex][3]);
    currentStepIndex++;
}
