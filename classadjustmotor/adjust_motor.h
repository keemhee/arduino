class ADJUSTMOTOR{
  private:
    int encoder_R;
    int encoder_L;
    unsigned long time_prev;
    unsigned long time_curr;
    unsigned long start_time;
    volatile int encoder_R_cnt;
    volatile int encoder_L_cnt;
    int delta_R;
    int delta_L;
    int speed_R;
    int speed_L;
    bool stop_flag;

  public:
    void encoder_R_ISR();
    void encoder_L_ISR();
    void speed_correct();
    void begin();
};
