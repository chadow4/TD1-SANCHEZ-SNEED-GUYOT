#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "digital_wheel_app_service.h"

static digital_wheel dw;

static void generate_next_int()
{
    // Check later
    printf("\n[%d]: ", generator_get_next());
}

static digital_wheel create(int start, int end)
{
    digital_wheel dw = digital_wheel_construct(start, end);

    return dw;
}

void circularBufferAppService_run_use_case(int c)
{
    if (dw == NULL)
        generate_next_int();

    switch (c)
    {
    case NEXT:
        digital_wheel_move_to_next_position(dw);
        break;

    case DESTROY_DIGITAL_WHEEL:
        digital_wheel_collect(dw);
        break;

    case NEW_DIGITAL_WHEEL:
        dw = create(1, DIGITAL_WHEEL_LENGTH);
        break;

    case '\n':
        generate_next_int();
    case ' ':
    case '\t':
        break;

    default:7
        // TODO
        circularBuffer_append_char_at_head(dw, c);
        break;
    }
}
