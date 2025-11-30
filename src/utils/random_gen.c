#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "graph.h"
#include "utils/csv_reader.h"
#include "utils/logger.h"

static void wait_for_enter(void)
{
    printf("\nPress ENTER to continue...");
    getchar();
}

static void show_memory_graph(const float *history, size_t count, const char *title)
{
    if (count == 0) {
        printf("No data available for %s yet.\n", title);
        return;
    }
    graph_draw(history, count, title);
}

static void show_csv_graph(const char *path, const char *title)
{
    float values[200];
    size_t count = csv_read_floats(path, values, 200);

    if (count == 0) {
        printf("The CSV file is empty or could not be read.\n");
        return;
    }

    graph_draw(values, count, title);
}

void menu_run(SmartHome *home)
{
    if (!home) return;

    int choice = 0;
    char buffer[16];

    while (1) {
        printf("\n=====================\n");
        printf("   SMART HOME MENU   \n");
        printf("=====================\n");
        printf("1. View current sensor readings\n");
        printf("2. Show memory-based graphs\n");
        printf("3. Show CSV-based graphs\n");
        printf("4. Control door lock\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        fgets(buffer, sizeof(buffer), stdin);
        choice = atoi(buffer);

        switch (choice) {

            case 1:
                printf("\n--- Current Readings ---\n");
                temperature_print(&home->temperature);
                humidity_print(&home->humidity);
                light_sensor_print(&home->light);
                motion_print(&home->motion);
                door_print(&home->door);
                wait_for_enter();
                break;


            case 2:
                printf("\n--- Memory Graphs ---\n");
                show_memory_graph(home->temperature.history, home->temperature.count, "Temperature (°C)");
                show_memory_graph(home->humidity.history, home->humidity.count, "Humidity (%)");
                show_memory_graph(home->light.history, home->light.count, "Light Level");
                wait_for_enter();
                break;


            case 3:
                printf("\n--- CSV Graphs ---\n");
                show_csv_graph(DATA_DIR "/temperature.csv", "Temperature (°C)");
                show_csv_graph(DATA_DIR "/humidity.csv", "Humidity (%)");
                show_csv_graph(DATA_DIR "/light.csv", "Light Level");
                wait_for_enter();
                break;


            case 4: {
                printf("\n--- Door Control ---\n");
                printf("1. Lock door\n");
                printf("2. Unlock door\n");
                printf("Choose: ");

                fgets(buffer, sizeof(buffer), stdin);
                int d = atoi(buffer);

                if (d == 1) {
                    home->door.locked = 1;
                    printf("Door locked.\n");
                } else if (d == 2) {
                    home->door.locked = 0;
                    printf("Door unlocked.\n");
                } else {
                    printf("Invalid choice.\n");
                }
                wait_for_enter();
                break;
            }

            case 5:
                printf("Exiting...\n");
                return;

            default:
                printf("Invalid option.\n");
                wait_for_enter();
                break;
        }
    }
}
