#ifndef _PROS_LIFT_H
#define _PROS_LIFT_H

#include "api.h"

extern double target_position;

extern pros::Task* lift_task;

void lift_logic();

void set_lift_target(double degrees, double speed);

#endif 