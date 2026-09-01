#include "subsystems/pivot.h"
#include "robotConfigs.h"

/*
void toggle(int setting, int timeout) {
    toggle_optical.set_led_pwm(100); //Turns on light for the optical
    intake_motor.move(127); //Spin the motor max speed
    
    int time_spent = 0; // Initialize time spent to 0

    while (time_spent < timeout) { 
        double hue = toggle_optical.get_hue(); 
        bool is_blue = (hue > 190 && hue < 215); //Rnage for blue hue
        bool is_red  = (hue > 5 && hue < 30); //Range for red hue

        if ((setting == 1 && is_blue) || (setting == 2 && is_red)) { //If we have the correct color
            intake_motor.move(0); //Stops the motor
            toggle_optical.set_led_pwm(0); //Turn off light
            return; // Exit the function 
        }

        pros::delay(10); //Relaxes CPU
        time_spent += 10; // Track time elapsed
    }
    
    // If we reach here, it timed out without seeing the color
    intake_motor.move(0); // Safety shutoff
} */

void setPivot(int deg){
    pivot_Motor.move_absolute(deg, 100); // Move the pivot motor to the specified degree at speed 100
}