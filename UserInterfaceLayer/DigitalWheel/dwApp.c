#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "digital_wheel_app_service.h"

#define DESTROY_DIGITAL_WHEEL '!'
#define NEW_DIGITAL_WHEEL 'n'

//static circular_buffer cb;

static void prompt()
{
    puts("************************************");
    puts("* Instance Digital wheel created *");
    puts("********************************************************************************************************");
    puts("* Menu [> : Make it rool, ! : destroy instance , Ctr-D: Quit] *");
    puts("********************************************************************************************************");
}

int main(int argc, char** argv)
{
    if (argc != 4) {
        exit(1);
    }
    int *param;
    for (int i = 1; i<4; i++) {
        param[i-1] = (int)argv[i];
    }
    prompt();
    digitalWheelAppService_run_use_case('n', param); //create the first instance for free -cadeau!

    while (true)
    {

        int c = getchar();
        if (c == EOF)
            break;

        digitalWheelAppService_run_use_case(c, NULL);
    }

    printf("\n");
    return EXIT_SUCCESS;
}