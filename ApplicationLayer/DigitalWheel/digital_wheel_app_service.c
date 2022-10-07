#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "digital_wheel_app_service.h"

static digital_wheel dw1;
static digital_wheel dw2;
static int speed1;
static int speed2;

static digital_wheel create(int size)
{

    digital_wheel dw = digital_wheel_construct(1, size);
    return dw;
}


void digitalWheelAppService_run_use_case(int c, int *param)
{
    switch (c)
    {
    case DESTROY_DIGITAL_WHEEL:
        digital_wheel_collect(dw1);
        digital_wheel_collect(dw2);
        break;

    case NEW_DIGITAL_WHEEL:
        dw1 = create(param[0]);
        dw2 = create(param[0]);
        speed1 = param[1];
        speed1 = param[2];
        break;

    case '\n':
        for (int i=0; i<speed1; i++) {
            digital_wheel_move_to_next_position(dw1);
            printf("%d", digital_wheel_get_current_position(dw1));
        }
        for (int i=0; i<speed2; i++) {
            digital_wheel_move_to_next_position(dw2);
            printf("%d", digital_wheel_get_current_position(dw2));
        }
        break;
    default:
        break;
    }
}
