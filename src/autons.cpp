#include "autons.h"
#include "robotConfigs.h"

#include "titanselect/titanselect.hpp"

// lateral PID controller
lemlib::ControllerSettings lateral_controller_settings(6, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              0.25, // derivative gain (kD)
                                              3, // anti windup
                                              0.5, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              1, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller_settings(1.9, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10.405, // derivative gain (kD)
                                              3, // anti windup
                                              0.25, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              0.5, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
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

    chassis.moveToPoint(0,18,999999999);
}

void red_right_auton() {
    chassis.setPose(0,0,0);
}

void red_left_elims_auton() {
    chassis.setPose(0,0,0);
}

void red_right_elims_auton() {
    chassis.setPose(0,0,0);
}

void blue_left_auton() {
    chassis.setPose(0,0,0);
}

void blue_right_auton() {
    chassis.setPose(0,0,0);
}

void blue_left_elims_auton() {
    chassis.setPose(0,0,0);
}

void blue_right_elims_auton() {
    chassis.setPose(0,0,0);
}

void programming_skills_auton() {
    chassis.setPose(0,0,0);
}
