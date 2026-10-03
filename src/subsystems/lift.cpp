#include "subsystems/lift.h"
#include "lemlib/pid.hpp"
#include "robotConfigs.h"

double target_position = 0.0;

lemlib::PID lift_pid(
    0.5,
    0.0, 
    0.0,
    false
);

void lift_logic() {
    lift_encoder.reset_position(); // zero sensor on startup
    
    while (true) {
        //get current sensor position (rotation sensor reports in centidegrees, convert to degrees)
        double current_position = lift_encoder.get_position() / 100.0;
        
        //calculate error
        double error = target_position - current_position;
        
        //get output power from Lemlib PID API (-127 to 127)
        double output = lift_pid.update(error);
        
        //command the lift motors
        lift_motors.move(output);
        
        pros::delay(20); // Run every 20ms
    }
}

void set_lift_target(double degrees) {
    target_position = degrees;
}