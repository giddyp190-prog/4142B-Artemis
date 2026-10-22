#include "autons.h"
#include "robotConfigs.h"

#include "titanselect/titanselect.hpp"

#include "subsystems/lift.h"

// lateral PID controller
lemlib::ControllerSettings lateral_controller_settings(5, // proportional gain (kP)
                                              0.25,// integral gain (kI)
                                              0.01, // derivative gain (kD)
                                              3, // anti windup
                                              0.5, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              0.5, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller_settings(1.8, // proportional gain (kP)
                                              0.15,// integral gain (kI)
                                              0.01, //rivative gain (kD)
                                              3, // anti windup
                                              0.25, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              0.5, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

ts::auton red_L("Red Left", red_left_auton);
ts::auton red_R("Red Right", red_right_auton);
ts::auton red_eL("Red L Elims", red_left_elims_auton);
ts::auton red_eR("Red R Elims", red_right_elims_auton);

ts::auton blue_L("Blue Left", blue_left_auton);
ts::auton blue_R("Blue Right", blue_right_auton);
ts::auton blue_eL("Blue L Elims", blue_left_elims_auton);
ts::auton blue_eR("Blue R Elims", blue_right_elims_auton);

ts::auton programSkills("Skills", programming_skills_auton);

void red_left_auton() {
    chassis.setPose(0,0,0);
    intake_motor.move(80);
    chassis.moveToPoint(0, 13, 500);
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(17, 13, 500);
    /*chassis.moveToPose(0,15,0, 500,{.minSpeed = 60});
    chassis.moveToPose(0,12,0, 250,{.forwards=false,.minSpeed = 60});
    chassis.moveToPose(19.5, 13, 90, 1750);*/
    set_lift_target(-90, 95);
    pros::delay(1000);
    set_lift_target(-10, 95);
    pros::delay(250);
    intake_motor.move(-30);
    pros::delay(100);
    set_lift_target(-10, 85);
    pros::delay(250);
    chassis.moveToPoint(-4.5, 13, 500, {.forwards=false});
    //chassis.moveToPose(-7, 13.22, 90, 750, {.forwards=false,.minSpeed = 60});
    intake_motor.move(127);
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(-4, 1, 1500);
    pros::delay(500);
    chassis.moveToPoint(-4, 8, 1250,{.forwards=false});
    chassis.moveToPose(4, 59, 0, 20000);
    pros::delay(1250);
    set_lift_target(-175, 100);
    pros::delay(1000);   
    //set_lift_target(-40, 95);
    intake_motor.move(-60);
    pros::delay(100);
    set_lift_target(-0, 100);
    pros::delay(500);
    intake_motor.move(0);
    chassis.moveToPoint(0, 30, 1000, {.forwards=false});
    chassis.turnToHeading(-90, 1000);
    chassis.moveToPoint(40, 30, 2000, {.forwards=false, .minSpeed = 100});
    chassis.turnToHeading(0, 500);
    chassis.moveToPoint(40,-7, 2000, {.forwards=false, .minSpeed = 127});
    //set_lift_target(-400, 95);
    pros::delay(250);
    set_lift_target(-20, 95);
    //chassis.moveToPose(53, -5, 0, 1250,{.forwards=false, .minSpeed = 120});
    chassis.moveToPoint(40, -7, 1000, {.minSpeed = 127});
}

void red_right_auton() {
    chassis.setPose(0,0,0);
    intake_motor.move(80);
    chassis.moveToPoint(0, 13, 500);
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(-17, 13, 500);
    /*chassis.moveToPose(0,15,0, 500,{.minSpeed = 60});
    chassis.moveToPose(0,12,0, 250,{.forwards=false,.minSpeed = 60});
    chassis.moveToPose(19.5, 13, 90, 1750);*/
    set_lift_target(-90, 95);
    pros::delay(1000);
    set_lift_target(-10, 95);
    pros::delay(250);
    intake_motor.move(-127);
    pros::delay(1000);
    set_lift_target(-10, 85);
    pros::delay(500);
    chassis.moveToPoint(4.5, 13, 500, {.forwards=false});
    //chassis.moveToPose(-7, 13.22, 90, 750, {.forwards=false,.minSpeed = 60});
    intake_motor.move(127);
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(4, 1, 1500);
    pros::delay(500);
    chassis.moveToPoint(4, 8, 1250,{.forwards=false});
    chassis.moveToPose(-4, 59, 0, 20000);
    pros::delay(1250);
    set_lift_target(-175, 100);
    pros::delay(1000);   
    //set_lift_target(-40, 95);
    intake_motor.move(-60);
    set_lift_target(-0, 100);
    pros::delay(500);
    intake_motor.move(127);
    chassis.moveToPoint(0, 30, 1000, {.forwards=false});
     chassis.moveToPose(4, 1,180, 2000);
     
}

void red_left_elims_auton() {
    chassis.setPose(0,0,0);
    intake_motor.move(80);
    set_lift_target(-50, 100);
    pros::delay(500);
    chassis.moveToPose(0,12,0, 750,{.minSpeed = 60});
    chassis.moveToPose(-19.85, 12.5, -90, 1500);
    set_lift_target(-85, 100);
    pros::delay(1750);
    set_lift_target(-10, 100);
    intake_motor.move(-30);
    pros::delay(100);
    set_lift_target(0, 85);
    pros::delay(250);
    chassis.moveToPose(7, 13.22, -90, 750, {.forwards=false,.minSpeed = 60});
    intake_motor.move(127);
    chassis.moveToPose(5.5, -0.65, 180, 1500);
    pros::delay(500);
    chassis.moveToPose(5.5, 8, 180, 1250,{.forwards=false});
    chassis.moveToPose(-2.5, 53.5, 0, 2000,{.minSpeed = 60});
    pros::delay(1000);
    set_lift_target(-150, 100);
    pros::delay(1250);
    intake_motor.move(-30);
    set_lift_target(-0, 100);
    pros::delay(250);
    intake_motor.move(0);
    chassis.moveToPose(-2.5, 32, 0, 2000, {.forwards=false,.minSpeed = 100});
    chassis.moveToPose(-40, 32, 90, 1250, {.forwards=false,.minSpeed = 100});
    chassis.moveToPose(-50, 6, 0, 1750,{.forwards=false});
    set_lift_target(-500,100);
    chassis.moveToPose(-50, -1, 0, 1750,{.forwards=false});
    pros::delay(750);
    set_lift_target(-350,100);
    chassis.moveToPose(-50, 6, 0, 1750,{.minSpeed = 100});
}

void red_right_elims_auton() {
    chassis.setPose(0,0,0);
    intake_motor.move(80);
    chassis.moveToPose(0,15,0, 750,{.minSpeed = 60});
    chassis.moveToPose(0,15,90, 1250,{.minSpeed = 60});
    chassis.moveToPose(11.5,15,90, 1250,{.minSpeed = 60});
    chassis.moveToPose(11.5,22,0, 3000);
    set_lift_target(-80, 100);
    pros::delay(1000);
    set_lift_target(-45, 100);
    intake_motor.move(-30);
    pros::delay(1000);
    set_lift_target(0, 85);
    pros::delay(250);
    intake_motor.move(-80);
}

void blue_left_auton() {    
    chassis.setPose(0,0,0);
    intake_motor.move(80);
    chassis.moveToPoint(0, 6, 2000);
    chassis.moveToPose(11.5, 24, 0, 5000);
    set_lift_target(-80, 100);
    pros::delay(1750);
    set_lift_target(-35, 50);
    //pros::delay(1000);
    intake_motor.move(-30);
    //pros::delay(1000);
    set_lift_target(-20, 85);
    //pros::delay(250);
    intake_motor.move(-30);
    chassis.moveToPoint(11.3, -7, 750,{.forwards=false});
    chassis.turnToHeading(-90, 1000);
    intake_motor.move(127);
    chassis.moveToPoint(-1.5, -7, 2000);
    pros::delay(1000);
    chassis.moveToPoint(11.5, -7, 2000,{.forwards=false});
    chassis.turnToHeading(0, 1000);
    chassis.moveToPoint(11.25, 20, 3000);
    set_lift_target(-165, 70);
    pros::delay(1750);
    set_lift_target(-160, 100);
    intake_motor.move(-30);
    pros::delay(1000);
    set_lift_target(0, 85);
    pros::delay(500);
    intake_motor.move(-80);
    chassis.moveToPoint(11.5, -7, 1500,{.forwards=false});
    chassis.turnToHeading(-90, 750);
    intake_motor.move(127);chassis.moveToPoint(-1.5, -7, 2000);
    pros::delay(1000);
}

void blue_right_auton() {
    chassis.setPose(0,0,0);
    intake_motor.move(80);
    chassis.moveToPoint(0, 6, 750);
    // chassis.turnToHeading(90, 500);
    chassis.moveToPose(11.5, 23, 0, 2000);
    set_lift_target(-85, 100);
    pros::delay(1750);
    set_lift_target(-35, 100);
    //pros::delay(1000);
    intake_motor.move(-30);
    //pros::delay(1000);
    set_lift_target(-20, 85);
    //pros::delay(250);
    intake_motor.move(-30);
    chassis.moveToPoint(11.5, -6, 1000,{.forwards=false,.minSpeed = 50});
    pros::delay(250);
    chassis.turnToHeading(-90, 500);
    intake_motor.move(127);
    chassis.moveToPoint(-1.5, -6, 1000);
    pros::delay(1000);
    chassis.moveToPoint(11.5, -6, 1000,{.forwards=false,.minSpeed = 50});
    pros::delay(250);
    chassis.turnToHeading(0, 500);
    chassis.moveToPose(11.5 , 23, 0,1750);
    set_lift_target(-165, 70);
    pros::delay(1750);
    set_lift_target(-160, 100);
    intake_motor.move(-30);
    pros::delay(1000);
    set_lift_target(0, 85);
    pros::delay(500);
    intake_motor.move(-30);
    chassis.moveToPoint(11.5, -6, 1000,{.forwards=false,.minSpeed = 50});
    intake_motor.move(127);
    chassis.turnToHeading(-90, 1000);
    chassis.moveToPose(-1.5, -6, -90,1250);
    chassis.moveToPose(11.5,-6, -90,750,{.forwards=false});
    chassis.moveToPose(54, 6, 90, 4000,{.minSpeed = 50});
    pros::delay(1000);
    set_lift_target(-150, 100);
    pros::delay(1250);
    intake_motor.move(-30);
    set_lift_target(-0, 100);
    pros::delay(250);
    intake_motor.move(0);
}

void blue_left_elims_auton() {
    chassis.setPose(0,0,0);
}

void blue_right_elims_auton() {
    chassis.setPose(0,0,0);
}

void programming_skills_auton() {
    chassis.setPose(0,0,0);

    intake_motor.move(127);
    chassis.moveToPoint(0, -27, 1000, {.forwards = false});
    set_lift_target(-100, 50);
    chassis.turnToHeading(90, 1000);
    chassis.moveToPoint(61.2, -27, 2000, {.maxSpeed = 60});
    chassis.turnToHeading(180, 1000);
    chassis.moveToPoint(61.2, -52, 2000, {.maxSpeed = 60});
    set_lift_target(-300, 50);
    chassis.moveToPoint(61.2, -65, 2500, {.maxSpeed = 30}, false);
    set_lift_target(-100, 10);
    pros::delay(500);
    intake_motor.move(-60);
    chassis.moveToPoint(61.2, -52, 1000);
}
