#include <stdio.h>
#include <stdlib.h>
#include "core.h"
#include "menu.h"
#include "utils/random_gen.h"

int main(void)
{
    // Initialize random number generator
    random_init();

    // Create SmartHome instance
    SmartHome home;

    // Initialize the system (sensors, state, etc.)
    smart_home_init(&home);

    // Start all sensor threads
    smart_home_start(&home);

    // Run the user interface
    menu_run(&home);

    // Shut down threads and clean up
    smart_home_shutdown(&home);

    printf("Smart home simulation terminated.\n");
    return 0;
}