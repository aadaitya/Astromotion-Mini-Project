# AstroMotion
Software-only C simulation of a two-axis telescope mount motion planner and calibration system.

## Features
- Virtual stepper motor configuration and angular limits
- Angular displacement to step conversion
- Two-axis movement planning and duration estimation
- Mechanical limit validation and virtual position updates
- Calibration error calculations
- Text-file persistence
- Google Test unit tests

## Requirements
GCC, GNU Make, and Google Test development libraries.
On Debian/Ubuntu: `sudo apt install build-essential libgtest-dev`

## Build and run
`make all` then `make run`

## Tests
`make test`

## Clean
`make clean`

## Scope
No physical hardware is controlled. The simulator assumes ideal movement, no missed steps, and constant pulse frequency. Acceleration, backlash, torque limits, and sensor feedback are outside scope.
