#include "main.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/misc.h"
#include "robotConfigs.h"
#include "titanselect/titanselect.hpp"

#include "subsystems/intake.h"
#include "subsystems/lift.h"

ts::selector* selector = ts::selector::get();

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.

 */

 pros::Task* lift_task = nullptr;

void initialize() {
    chassis.calibrate(); // calibrate sensors and chassis coordinates
    lift_encoder.reset_position(); // zero sensor on startup
    controller.clear();
    ts::selector::get()->display();

    lift_task = new pros::Task(lift_logic, "Lift PID Task");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
    
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	if(!selector->is_auton_selected()) // if no auton selected
	{
		chassis.setPose(0,0,0); // reset chassis cords

		chassis.moveToPoint(0, 1, 2000); // move forward an inch to not touch wall
	}
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    selector->run_selected_auton(); // run the selected auton

    selector->run_auton("Red Left");
   //chassis.moveToPoint(0, -9.2, 2000, {.minSpeed = 50});
   /*lift_motors.move(-50);
    pros::delay(1500);
     lift_motors.move(0);
     pros::delay(1000);
    intake_motor.move(-30);
    pros::delay(250);
    intake_motor.move(0);
    chassis.moveToPoint(-10, 13.22, 20000, {.forwards = false});
     //chassis.moveToPose(8.2, 1.5, 180, 2000);
    //intake_motor.move(50);*/
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

// max = -810
void opcontrol() {
    if (lift_task != nullptr) {
        lift_task->remove(); 
        lift_task = nullptr; // Reset pointer for safety
    }

    lift_motors.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);

    while (true) {
        // get left y and right x positions

        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            intake_motor.move(127);
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            intake_motor.move(-60);
        } else {
            intake_motor.move(60);
        }

        double current_position = -lift_encoder.get_position() / 100.0;

        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && current_position < 700.0) {
            lift_motors.move(-70);
        } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && current_position > 0.0) {
            lift_motors.move(70);
        } else {
            lift_motors.move(0);
        }

        controller.print(1, 0, "Lift: %f", current_position);

        chassis.curvature(leftY, rightX); // main drive function

        pros::screen::set_pen(pros::c::COLOR_WHITE);
        pros::screen::print(pros::E_TEXT_SMALL, 9, "X: %f", chassis.getPose().x);
        pros::screen::print(pros::E_TEXT_SMALL, 10, "Y: %f", chassis.getPose().y);
        pros::screen::print(pros::E_TEXT_SMALL, 11, "Theta: %f", chassis.getPose().theta);

        // delay to save resources
        pros::delay(25);
    }
}