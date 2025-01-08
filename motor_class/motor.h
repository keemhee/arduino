class MOTOR{
  private:
    int motor_aia;
    int motor_aib;
  public:
    motor(int aia, int aib); // Servo myServo   LED myLed(13)
    void begin();
    void forward();
    void stop();
    void backward();
};
