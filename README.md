# C-Final-Project
# Smart Home Simulation

A simple smart home simulation written in C.
This program simulates multiple sensors (temperature, humidity, ambient lighting, motion and the state of the door), updates them using threads, logs the readings onto CSV files and allows the user to view data or display them in the form of ASCII line graphs, depending on what they want.

# Requirements

- C-compiler
- CMake
- Make
- Conda

## Building and running the Project

```bash
conda env create -f environment.yml
conda activate smart_home_env
cmake -B build
cmake --build build
./build/smart_home
```
If something breaks or you need to compile it again, go back to the root directory, and:

```bash
rm -rf build
cmake -B build
cmake --build build
./build/smart_home
```
Be sure to run the executable from the root directory, else the data paths will break and it won't run.

## Usage Instructions

1. **View current sensor readings**
    Displays the latest sensor values
2. **Show memory-based graphs**
    Displays ASCII graphs from recent readings
3. **Show CSV-based graphs**
    Plots historical data from CSV files
4. **Control door lock**
    Manually lock or unlock the door
5. **Exit**
    Exits the program
---
## Limitations

- The program can only run from the root directory, otherwise it won't recognize the paths and will crash
- The ASCII graphs can be a bit hard to read with really long histories, so it is only limited to the last N readings
- CSV logs keep growinf during the session and nothing is done to keep it in control

## Future Improvements

- Add mutexes to handle threads more effectively
- Add more sensors such as Smoke detectors, CO2 readings
- Implement CSV archiving for data older than a certain period

## Authors

- **Athul Gokuldas** - Core system logic, threading, graphing system, documentation and header files
- **Edard Hala** - Menu system, random number generator, and logging utilities
- **Ana-Maria Pintilie** - Sensor module implementations (light, motion and door)
- **Khadeja Nehad** - CSV reader, main program setup and documentation 
