#ifndef MENU_H
#define MENU_H

#include "core.h"

/*

    Displays main menu and what the user can choose from:

    - view current sensor readings
    - view recent readings from temporary memory
    - view historical readinsg from CSV files
    - display graphs (is the form of ASCII lines)
    - control devices (on/off for lights and open/close for door)
    - exit the system

*/

void menu_run(SmartHome *home);

#endif