#include "subsystems/lift.h"
#include "robotConfigs.h"

void lift(int degrees) {
    double kp = 0.5; //proportional

    double error = degrees - lift_encoder.get_position();
    double velocity = kp * error;

    lift_motors.move(velocity);
}