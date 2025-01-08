class LED{
  private:
    int pin;
  public:
    LED(int p); // Servo myServo   LED myLed(13)
    void begin();
    void on();
    void off();
};
