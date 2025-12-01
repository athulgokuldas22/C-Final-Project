#include <stdio.h>
#include <stdlib.h>
#include "core.h"
#include "menu.h"
#include "utils/random_gen.h"

int main(int argc, char *argv[])
{
    random_init();
    SmartHome home;
    smart_home_init(&home);
    smart_home_start(&home);
    menu_run(&home);
    smart_home_shutdown(&home);

    printf("Smart home simulation terminated.\n");
    return 0;
}