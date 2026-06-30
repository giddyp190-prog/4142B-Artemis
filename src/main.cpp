#include "main.h"
#include "robotConfigs.h"
#include "titanselect/titanselect.hpp"

#include "subsystems/intake.h"
#include "subsystems/toggle.h"
#include "subsystems/lift.h"

ts::selector* selector = ts::selector::get();

pros::Optical optical_sensor(20);
pros::Motor toggle_Motor(19, pros::MotorGears::red);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.

 */

void initialize() {
    chassis.calibrate(); // calibrate sensors
    ts::selector::get()->display();

    toggle(2, 5000);

    while (true) {
        pros::screen::set_pen(pros::c::COLOR_WHITE);
        pros::screen::print(pros::E_TEXT_SMALL, 9, "X: %f", chassis.getPose().x);
        pros::screen::print(pros::E_TEXT_SMALL, 10, "Y: %f", chassis.getPose().y);
        pros::screen::print(pros::E_TEXT_SMALL, 11, "Theta: %f", chassis.getPose().theta);

        pros::delay(20);
    }
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

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
	selector->run_selected_auton();
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
void opcontrol() {
    while (true) {
        // get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot


        chassis.curvature(leftY, rightX);

        // delay to save resources
        pros::delay(25);
    }
}