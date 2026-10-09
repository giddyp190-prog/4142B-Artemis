#include "subsystems/lift.h"
#include "lemlib/pid.hpp"
#include "robotConfigs.h"

#include <algorithm>

double target_position = 0.0;
double target_speed = 0;

lemlib::PID lift_pid(
    2.2,
    0.0, 
    3.0,
    false
);

void lift_logic() {
    lift_encoder.reset_position(); // zero sensor on startup

    lift_motors.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
    
    while (true) {
        //get current sensor position (rotation sensor reports in centidegrees, convert to degrees)
        double current_position = lift_encoder.get_position() / 100.0;
        
        //calculate error
        double error = target_position - current_position;
        
        //get output power from Lemlib PID API (-127 to 127)
        double output = lift_pid.update(error);

        if (current_position <= -700.0 && output < 0.0) {
            output = 0.0;
        }
        //0 is the starting point, prevent it from grinding against the bottom limit.
        else if (current_position >= 0.0 && output > 0.0) {
            output = 0.0;
        }
        
        //command the lift motors
        lift_motors.move(output * target_speed);
        
        pros::delay(20); // Run every 20ms
    }
}

void set_lift_target(double degrees, double speed) {
    target_position = std::clamp(degrees, -700.0, 0.0);
    target_speed = speed / 100;
}