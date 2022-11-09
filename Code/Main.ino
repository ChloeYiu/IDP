#include <Adafruit_MotorShield.h>
#include <Servo.h>

class LineFollower{
  private:
  static const threshold = 4;
  int inputPin;
  public:
  LineFollower (int p) {
    inputPin = p;
    pinMode(p, INPUT);
  }
  bool getLineData(){
    analog = digitalRead(inputPin)
    if (analog > threshold){
      return true;
    }else{
      return false
    }
  }
}

class Crisps{
  private:
  LineFollower lineFollowers[4];

  public:
  Crisps (int line1, int line2, int line3, int line4, int motor1, int motor2){
    lineFollowers[0] = LineFollower(line1);
    lineFollowers[1] = LineFollower(line1);
    lineFollowers[2] = LineFollower(line1);
    lineFollowers[3] = LineFollower(line1);

  boolean* getLineData(){
    static boolean r[4];
    for(int i = 0; i<4; i++){
      r[i] = lineFollowers[i].getLineData();
    }
    return r;
  }
  }

}

class Motors
{
public:
  // class field
  Adafruit_MotorShield MotorShield = Adafruit_MotorShield();
  Adafruit_DCMotor *MotorL = MotorShield.getMotor(1);
  Adafruit_DCMotor *MotorR = MotorShield.getMotor(2);

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
    MotorL->setSpeed(150);
    MotorL->run(FORWARD);
    MotorL->run(RELEASE);

    MotorR->setSpeed(150);
    MotorR->run(FORWARD);
    MotorR->run(RELEASE);
  }

  void forward(int speed)
  {
    // set speed of motor
    MotorL->setSpeed(speed);
    MotorR->setSpeed(speed);

    // make motor move forward
    MotorL->run(FORWARD);
    MotorR->run(FORWARD);
  }

  void backward(int speed)
  {
    // set speed of motor
    MotorL->setSpeed(speed);
    MotorR->setSpeed(speed);

    // make motor move backward
    MotorL->run(BACKWARD);
    MotorR->run(BACKWARD);
  }

  void stop()
  {
    // make motor stop
    MotorL->run(RELEASE);
    MotorR->run(RELEASE);
  }

  void forwardLeft(int speed)
  { // for turning left
    // set speed of motor
    MotorL->setSpeed(speed / 2);
    MotorR->setSpeed(speed);

    // make motor move forward
    MotorL->run(FORWARD);
    MotorR->run(FORWARD);
  }

  void forwardRight(int speed)
  { // for turning right
    // set speed of motor
    MotorL->setSpeed(speed);
    MotorR->setSpeed(speed / 2);

    // make motor move forward
    MotorL->run(FORWARD);
    MotorR->run(FORWARD);
  }
};

void setup () {

}

void loop () {

}
