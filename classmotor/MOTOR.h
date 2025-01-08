class MOTOR {
  private:
    int fpin, bpin;
    int speed;
  public:
    MOTOR(int f, int b, int s);
    void begin();
    void on(bool is_forward);
    void off();
    void changeSpeed(int addnum);
};