#ifndef WALL_FOLLOW_H
#define WALL_FOLLOW_H

namespace wall_fns
{
  class RobotMoves
  {
    private:
      const int led_green;
      const int led_yellow;
      const int led_red;

      const int sensorPin0;
      const int sensorPin1;
      const int sensorPin2;

      const int servoPin0;
      const int servoPin1;

      const int x_min;
      const int x0;
      const int y_min;
      const int y_max;
      const int y0;

      Servo servoRight;
      Servo servoLeft;

      SharpIR sensor0 = SharpIR( SharpIR::GP2Y0A21YK0F, A3 );
      SharpIR sensor1 = SharpIR( SharpIR::GP2Y0A21YK0F, A4 );
      SharpIR sensor2 = SharpIR( SharpIR::GP2Y0A21YK0F, A5 );

    public:
      RobotMoves();

  };
}

#endif