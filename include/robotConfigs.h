#ifndef _PROS_ROBOT_CONFIG_H_
#define _PROS_ROBOT_CONFIG_H_

#include "lemlib/chassis/chassis.hpp"

#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/optical.hpp"
#include "pros/rotation.hpp"
#include "pros/motors.hpp"
#include "pros/motor_group.hpp"

extern pros::Controller controller;

extern pros::Motor left_front_motor;
extern pros::Motor left_middle_motor;
extern pros::Motor left_back_motor;

extern pros::Motor right_front_motor;
extern pros::Motor right_middle_motor;
extern pros::Motor right_back_motor;

extern pros::MotorGroup left_drive_motors;
extern pros::MotorGroup right_drive_motors;

extern lemlib::Drivetrain drivetrain;

extern pros::Motor left_lift_motor;
extern pros::Motor right_lift_motor;

extern pros::MotorGroup lift_motors;

extern pros::Motor intake_motor;

extern pros::Imu imu;
extern pros::Rotation vertical_encoder;
extern pros::Optical toggle_optical;
extern pros::Rotation lift_encoder;

extern lemlib::TrackingWheel vertical_tracking_wheel;

extern lemlib::OdomSensors odom_sensors;

extern lemlib::ExpoDriveCurve throttleCurve;
extern lemlib::ExpoDriveCurve steerCurve;

extern lemlib::Chassis chassis;

#endif // _PROS_ROBOT_CONFIG_H_