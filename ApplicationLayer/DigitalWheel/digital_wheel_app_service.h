#ifndef DW_APP_SERVICE_H
#define DW_APP_SERVICE_H
#include "generator.h"
#include "digital_wheel.h"

#define DESTROY_DIGITAL_WHEEL '!'
#define NEXT '>'
#define NEW_DIGITAL_WHEEL 'n'

#define DIGITAL_WHEEL_LENGTH 10

void digitalWheelAppService_run_use_case(int c);

#endif