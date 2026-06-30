#include "robotConfigs.h"
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "autons.h"
#include "pros/optical.hpp"
#include "pros/rotation.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor left_front_motor(1, pros::MotorGears::blue);
pros::Motor left_middle_motor(2, pros::MotorGears::blue);
pros::Motor left_back_motor(3, pros::MotorGears::green);

pros::Motor right_front_motor(4, pros::MotorGears::blue);
pros::Motor right_middle_motor(5, pros::MotorGears::blue);
pros::Motor right_back_motor(6, pros::MotorGears::green);

// left motor group
pros::MotorGroup left_motor_group({1, 2, 3}, pros::MotorGears::blue);
// right motor group
pros::MotorGroup right_motor_group({4, 5, 6}, pros::MotorGears::blue);

// drivetrain settings
lemlib::Drivetrain drivetrain(&left_motor_group, // left motor group
                              &right_motor_group, // right motor group
                              11.5, // 10 inch track width
                              lemlib::Omniwheel::NEW_275, // using new 4" omnis
                              450, // drivetrain rpm is 360
                              8 // horizontal drift is 2 (for now)
);

pros::Motor left_lift_motor(1);
pros::Motor right_lift_motor(2);

pros::MotorGroup lift_motors({1,1}, pros::MotorGears::red);

pros::Motor intake_motor(19);

// imu
pros::Imu imu(10); 
// vertical tracking wheel encoder
pros::Rotation vertical_encoder(0); 
// optical sensor (toggle)
pros::Optical toggle_optical(20);
// lift rotation sensor
pros::Rotation lift_encoder(21);

// vertical tracking wheel encoder
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_2, -2.5);

// odometry settings
lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we dont use one
                            nullptr, // horizontal tracking wheel 1, set to nullptr as we dont use one
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we dont use one
                            &imu // inertial sensor
);

lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller_settings, // lateral PID settings
                        angular_controller_settings, // angular PID settings
                        sensors, // odometry sensors
                        &throttleCurve,
                        &steerCurve
);