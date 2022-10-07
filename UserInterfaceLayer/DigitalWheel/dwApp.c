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
    puts("************************************");
    puts("*************************************************************************");
    puts(" The digital wheel is actually a 10 bound wheel");
    puts("*************************************************************************");
    puts("********************************************************************************************************");
    puts("* Menu [ n : New instance , > : Next, ! : destroy instance , Ctr-D: Quit] *");
    puts("********************************************************************************************************");
}

int main()
{
    prompt();
    digitalWheelAppService_run_use_case('n'); //create the first instance for free -cadeau!

    while (true)
    {

        int c = getchar();
        if (c == EOF)
            break;

        circularBufferAppService_run_use_case(c);
    }

    printf("\n");
    return EXIT_SUCCESS;
}