#ifndef _PROS_AUTONS_H_
#define _PROS_AUTONS_H_

#include "titanselect/titanselect.hpp"
#include "lemlib/chassis/chassis.hpp"

extern lemlib::ControllerSettings lateral_controller_settings;
extern lemlib::ControllerSettings angular_controller_settings;

extern ts::auton redL_auton;
extern ts::auton redR_auton;
extern ts::auton redLelims_auton;
extern ts::auton redRelims_auton;

extern ts::auton blueL_auton;
extern ts::auton blueR_auton;
extern ts::auton blueLelims_auton;
extern ts::auton blueRelims_auton;

extern ts::auton autonomous_skills_auton;

void red_left_auton();
void red_right_auton();
void red_left_elims_auton();
void red_right_elims_auton();

void blue_left_auton();
void blue_right_auton();
void blue_left_elims_auton();
void blue_right_elims_auton();

void programming_skills_auton();

#endif // _PROS_AUTONS_H_