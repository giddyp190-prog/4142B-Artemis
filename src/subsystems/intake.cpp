#include "intake.h"
#include "robotConfigs.h"

void intake(int pow) {
    intake_motor.move(pow);
}