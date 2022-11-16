#include <Adafruit_MotorShield.h>
#define SLOW 100.1
#define FAST 255
#define TIME 10000
#define AMBER_LIGHT 8

class Motors{
public:
  // class field
  Adafruit_MotorShield MotorShield = Adafruit_MotorShield();
  Adafruit_DCMotor *Motor;
  int lightPin;

  // constructor
  Motors(int pin, int light)
  {
    Motor = MotorShield.getMotor(pin);
    lightPin = light;
  }

  // functions
  void begin()
  {
    // Find MotorShield
    if (!MotorShield.begin())
    {
      Serial.println("Could not find Motor Shield. Check wiring.");
      while (1)
        ;
    }
    Serial.println("Motor Shield found.");

    // Initial configuration - turn on
    Motor->setSpeed(150);
    Motor->run(FORWARD);
    Motor->run(RELEASE);

    // configure amber light
    pinMode(lightPin, OUTPUT);

  }

  void forward(int speed)
  {
    // set speed of motor
    Motor->setSpeed(speed);
    Motor->run(FORWARD);

    // turn on light
    digitalWrite(lightPin, HIGH);
  }

  void backward(int speed)
  {
    // set speed of motor
    Motor->setSpeed(speed);
    Motor->run(BACKWARD);

    // turn on light
    digitalWrite(lightPin, HIGH);
  }

  void stop()
  {
    // make motor stop
    Motor->run(RELEASE);

    // turn off light
    digitalWrite(lightPin, LOW);
  }
};

Motors motorL(1, AMBER_LIGHT);
Motors motorR(2, AMBER_LIGHT);

void setup() {
  Serial.begin(9600);
  motorL.begin();
  motorR.begin();
}

void loop()
{
  Serial.println("Backward slow");
  motorL.backward(SLOW);
  motorR.backward(SLOW);
  delay(TIME);
  Serial.println("Backward fast");
  motorL.backward(FAST);
  motorR.backward(FAST);
  delay(TIME);
  Serial.println("Forward slow");
  motorL.forward(SLOW);
  motorR.forward(SLOW);
  delay(TIME);
  Serial.println("Forward fast");
  motorL.forward(FAST);
  motorR.forward(FAST);
  delay(TIME);

}
