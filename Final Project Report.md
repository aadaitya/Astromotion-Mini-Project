# **ASTROMOTION** 

**Two-Axis Telescope Mount Motion Planner and Calibration Simulator** 

# **C Programming and Software Engineering – Mini Project Report** 

**Submitted by:** Aaditya Mahesh Narkhedkar **Department:** Electronics and Telecommunication Engineering **Institution:** COEP Technological University, Pune **Academic Year:** 2026–27 **Roll Number:** 612507002 **Division:** Entc Div 1 **GitHub Repository:** [Insert Repository URL] 

# **1. Project Information** 

|**Particular**|**Details**|
|---|---|
|Project Title|AstroMotion|
|Project Description|Two-Axis Telescope Mount Motion Planner and Calibration<br>Simulator|
|Programming Langua|ge C|
|Testing Framework|Google Test (gTest)|
|Build System|GNU Make|
|Version Control|Git and GitHub|
|Application Type|Command-Line Application|
|Project Category|Engineering Application|
|Project Mode|Individual|



# **1.1 Abstract** 

AstroMotion is a C-based software application designed to calculate, plan and simulate the movement of a two-axis telescope mount using stepper motors. 

Telescope mounts require precise angular movement to position a telescope towards desired celestial objects. Stepper motors are commonly used in such systems because they provide controlled rotational movement through discrete steps. 

The relationship between motor rotation and telescope movement depends on parameters such as motor step angle, microstepping factor and gear reduction ratio. AstroMotion simplifies these calculations by converting requested angular displacement into the 

corresponding motor steps and estimating movement duration using the configured pulse frequency. 

The application also validates movement requests against predefined mechanical limits, simulates the resulting mount position, stores movement records and performs calibration analysis by comparing commanded and manually measured angular displacement. 

The project uses modular C programming, structures, enumerations, functions, file handling and error handling. Google Test is used for unit testing, while a Makefile automates compilation and testing. 

AstroMotion provides a software-based environment for understanding and analysing telescope mount movement without requiring physical hardware during initial development. 

**Keywords:** Telescope Mount, Stepper Motor, Motion Planning, Calibration, Simulation, C Programming. 

# **2. Engineering Scenario** 

# **2.1 Background** 

An astronomical telescope requires controlled positioning to observe objects in the sky. A telescope mount provides mechanical support and allows the telescope to rotate along specified axes. 

A two-axis mount generally provides two independent rotational degrees of freedom. Depending on the mount configuration, these axes may correspond to: 

- Altitude and Azimuth in an Alt-Azimuth mount. 

- Right Ascension and Declination in an Equatorial mount. 

Stepper motors are suitable for telescope positioning because they rotate through discrete angular increments in response to electrical pulses. 

However, the motor's angular displacement is not directly equal to the output angular displacement of the mount. Gear reduction and microstepping influence the number of motor steps required to achieve a particular mount movement. 

# **2.2 Problem Statement** 

Calculating the required motor steps for arbitrary angular displacement can become inconvenient when the system uses microstepping and gear reduction. 

Incorrect calculations or invalid movement commands may cause the telescope mount to move beyond its mechanical limits or produce inaccurate positioning. 

Therefore, a software system is required to: 

1. Calculate motor steps for a given angular displacement. 

2. Account for motor specifications and gear reduction. 

3. Estimate movement duration. 

4. Validate movement requests against mechanical limits. 

5. Simulate mount movement. 

6. Store movement and calibration records. 

7. Analyse positioning errors. 

AstroMotion addresses this problem through a modular C-based motion-planning and simulation application. 

# **2.3 Motivation** 

The project is motivated by the need to understand the relationship between stepper motor specifications and the actual angular movement of a telescope mount. 

It provides a practical application of electronics, mechanical motion concepts and C programming. 

# **2.4 Target Users** 

- Astronomy enthusiasts working with telescope mounts. 

- Students learning stepper motor control. 

- Developers designing telescope positioning systems. 

- Students working on embedded and automation projects. 

# **3. Project Scope** 

# **3.1 Features Included** 

- Motor configuration. 

- Gear reduction configuration. 

- Steps-per-degree calculation. 

- Angular displacement input. 

- Motor step calculation. 

- Direction determination. 

- Movement duration estimation. 

- Mechanical-limit validation. 

- Two-axis movement simulation. 

- Virtual position tracking. 

- Movement history storage. 

- Calibration record storage. 

- Positioning error calculation. 

- Report generation. 

- Searching and sorting movement records. 

# **3.2 Features Excluded** 

- Direct physical motor control. 

- Microcontroller communication. 

- Automatic celestial object tracking. 

- Star catalogue integration. 

- GPS-based positioning. 

- Encoder-based automatic feedback. 

- Advanced backlash compensation. 

- Acceleration and deceleration profiles. 

- Graphical user interface. 

# **3.3 Assumptions** 

1. Each axis is driven by one stepper motor. 

2. Both axes operate independently. 

3. The motors execute the commanded number of steps without missing steps. 

4. Pulse frequency remains constant. 

5. Gear reduction ratios remain constant. 

6. Angular displacement is represented in degrees. 

7. Calibration measurements are entered manually. 

8. The simulator assumes ideal motor behaviour. 

# **3.4 Constraints** 

- The application is implemented in C. 

- The initial interface is command-line based. 

- Configuration and records are stored in text files. 

- The application uses standard C functionality wherever possible. 

- Unit testing is performed using Google Test. 

# **4. Requirements** 

# **4.1 Functional Requirements** 

# **ID Requirement** 

FR-01 Configure motor specifications for both axes. 

FR-02 Store gear reduction ratios. 

FR-03 Calculate effective steps per degree. 

FR-04 Accept angular displacement requests for both axes. 

FR-05 Calculate the required motor steps. 

FR-06 Estimate movement duration using pulse frequency. 

FR-07 Validate movement against mechanical limits. 

FR-08 Simulate movement and update virtual position. 

FR-09 Save and retrieve movement records. 

FR-10 Store calibration measurements. 

FR-11 Calculate positioning errors. 

FR-12 Generate movement and calibration reports. 

FR-13 Search and sort movement records. 

# **4.2 Non-Functional Requirements** 

**Modularity:** The application shall be divided into independent modules. 

**Reliability:** Invalid configurations and movement requests shall be rejected. 

**Maintainability:** Functions and modules shall follow consistent naming conventions. 

**Portability:** Standard C functionality shall be preferred. 

**Precision:** Floating-point calculations shall maintain adequate precision, with step counts rounded to integers. 

**Testability:** Important functions shall be independently testable. 

**Usability:** The command-line interface shall provide understandable prompts and error messages. 

|**4.3 Hardware and**|**Software Requirements**|
|---|---|
|**Component**|**Requirement**|
|Processor|Standard desktop/laptop processor|
|RAM|4 GB minimum recommended|
|Operating System|Linux or Windows|
|C Compiler|GCC|
|Build Tool|GNU Make|
|Testing Framework|Google Test|
|Version Control|Git|
|Editor|VS Code or equivalent|



# **5. High-Level Architecture** 

# **5.1 Architecture Overview** 

AstroMotion follows a modular architecture in which the main program coordinates the different modules. 

The user interacts with the application through a command-line interface. The main module accepts requests and invokes the appropriate functions. 

The motor module performs motor-related calculations. The planner module generates movement plans, while the mount module maintains the simulated position. 

The validation module checks inputs and mechanical limits. The calibration module calculates positioning errors. The storage module handles persistent data, and the report module displays the results. 

# **5.2 Architecture Diagram** 

+---------------------+ |        USER         | +----------+----------+ | v +---------------------+ |       main.c        | 



<!-- Start of picture text -->
                  |   User Interface    |<br>                  +----------+----------+<br>                             |<br>             +---------------+---------------+<br>             |               |               |<br>             v               v               v<br>       +-----------+   +-----------+   +-----------+<br>       |   Motor   |   |   Mount   |   |  Planner  |<br>       |   Module  |   |   Module  |   |  Module   |<br>       +-----------+   +-----------+   +-----------+<br>             |               |               |<br>             +---------------+---------------+<br>                             |<br>                             v<br>                  +---------------------+<br>                  | Validation Module  |<br>                  +----------+----------+<br>                             |<br>                 +-----------+-----------+<br>                 |                       |<br>                 v                       v<br>          +-------------+         +-------------+<br>          | Calibration |         |   Storage   |<br>          |   Module    |         |   Module    |<br>          +-------------+         +-------------+<br>                 |                       |<br>                 +-----------+-----------+<br>                             |<br>                             v<br><!-- End of picture text -->

+---------------------+ 

- |    Report Module    | 

+---------------------+ 

# **5.3 Application Workflow** 

1. Start the application. 

2. Load saved configuration. 

3. Display the main menu. 

4. Accept a user operation. 

5. Read movement parameters. 

6. Calculate motor steps. 

7. Validate mechanical limits. 

8. Generate a movement plan. 

9. Simulate movement and update position. 

10. Save movement records. 

11. Allow calibration and report generation. 

12. Exit the application. 

# **6. Module Design** 

The application is divided into eight major modules. 

|**Module**|**Source File **|**Responsibility**|
|---|---|---|
|Main|main.c|User interface and application control|
|Motor|motor.c|Motor specifications and step calculations|
|Mount|mount.c|Position tracking and movement updates|
|Planner|planner.c|Movement plan generation and duration estimation|
|Validation|validation.c|Input and mechanical-limit validation|
|Calibration|calibration.c|Positioning error calculations|
|Storage|storage.c|File reading and writing|
|Report|report.c|Display, searching and report generation|



# **6.1 Main Module** 

Responsibilities: 

- Display menu. 

- Accept user selections. 

- Coordinate module execution. 

- Handle application startup and termination. 

- Display results. 

# **6.2 Motor Module** 

Responsibilities: 

- Store motor specifications. 

- Validate motor parameters. 

- Calculate steps per degree. 

- Calculate required motor steps. 

# **6.3 Mount Module** 

Responsibilities: 

- Maintain virtual mount position. 

- Store mechanical limits. 

- Initialize the mount. 

- Apply validated movement plans. 

- Prevent invalid position updates. 

# **6.4 Planner Module** 

Responsibilities: 

- Accept angular movement requests. 

- Calculate motor steps. 

- Determine direction. 

- Calculate achievable displacement. 

- Estimate movement duration. 

- Generate movement plans. 

# **6.5 Validation Module** 

Responsibilities: 

- Validate numerical inputs. 

- Check motor configuration. 

- Check mechanical limits. 

- Validate movement requests. 

- Prevent invalid operations. 

# **6.6 Calibration Module** 

Responsibilities: 

- Store commanded and measured displacement. 

- Calculate signed error. 

- Calculate absolute error. 

- Generate calibration summaries. 

# **6.7 Storage Module** 

Responsibilities: 

- Read configuration files. 

- Save movement records. 

- Load movement history. 

- Save calibration records. 

- Handle file errors. 

# **6.8 Report Module** 

Responsibilities: 

- Display movement plans. 

- Generate movement summaries. 

- Display calibration results. 

- Search and sort records. 

- Generate readable reports. 

# **7. Data Design** 

# **7.1 Axis Enumeration** 

typedef enum { 

AXIS_FIRST, 

AXIS_SECOND, 

AXIS_COUNT 

} Axis_t; 

Identifies the two independent mount axes. 

# **7.2 Direction Enumeration** 

typedef enum { 

DIRECTION_FORWARD, 

DIRECTION_REVERSE 

} Direction_t; 

Represents motor rotation direction. 

# **7.3 Status Enumeration** 

typedef enum { 

STATUS_SUCCESS, STATUS_INVALID_INPUT, STATUS_OUT_OF_RANGE, STATUS_FILE_ERROR, 

STATUS_INVALID_FILE_FORMAT, 

STATUS_CALCULATION_ERROR 

} Status_t; 

Provides consistent status reporting across modules. 

# **7.4 Motor Configuration** 

typedef struct { 

double step_angle_deg; 

unsigned int microstep_factor; 

double pulse_frequency_hz; 

} MotorConfig_t; 

# **7.5 Axis Configuration** 

typedef struct { 

double gear_reduction_ratio; 

double minimum_angle_deg; 

double maximum_angle_deg; 

# } AxisConfig_t; 

The gear reduction ratio is defined as motor revolutions per output-axis revolution. 

# **7.6 Mount Configuration** 

typedef struct { 

MotorConfig_t motor[AXIS_COUNT]; 

AxisConfig_t axis[AXIS_COUNT]; 

} MountConfig_t; 

# **7.7 Mount State** 

typedef struct { 

double current_position_deg[AXIS_COUNT]; 

} MountState_t; 

# **7.8 Movement Request** 

typedef struct { 

double displacement_deg[AXIS_COUNT]; 

} MovementRequest_t; 

# **7.9 Movement Axis Plan** 

typedef struct { 

unsigned long step_count; 

Direction_t direction; 

double requested_angle_deg; 

double achievable_angle_deg; 

double duration_seconds; 

} MovementAxisPlan_t; 

# **7.10 Movement Plan** 

typedef struct { 

MovementAxisPlan_t axis[AXIS_COUNT]; 

double total_duration_seconds; 

} MovementPlan_t; 

**7.11 Calibration Record** 

typedef struct { unsigned int record_id; Axis_t axis; double commanded_angle_deg; double measured_angle_deg; double signed_error_deg; double absolute_error_deg; } CalibrationRecord_t; 

# **8. Function Design** 

The following functions form the proposed public interfaces of the modules. 

# **8.1 Motor Functions** 

Status_t motor_validate_config(const MotorConfig_t *config); 

double motor_calculate_steps_per_degree( 

const MotorConfig_t *motor, 

const AxisConfig_t *axis 

); 

Status_t motor_calculate_steps( 

double displacement_deg, double steps_per_degree, unsigned long *steps, 

Direction_t *direction 

); 

# **8.2 Mount Functions** 

Status_t mount_initialize( 

MountState_t *state, 

const MountConfig_t *config 

); 

Status_t mount_apply_movement( MountState_t *state, const MountConfig_t *config, 

const MovementPlan_t *plan 

); 

# **8.3 Planner Functions** 

Status_t planner_create_plan( 

const MountConfig_t *config, 

const MountState_t *state, 

const MovementRequest_t *request, 

MovementPlan_t *plan 

); 

# **8.4 Validation Functions** 

Status_t validation_check_position( 

double final_position, 

const AxisConfig_t *axis 

); 

Status_t validation_check_request( 

const MovementRequest_t *request ); 

# **8.5 Calibration Functions** 

Status_t calibration_calculate_error( 

double commanded, 

double measured, double *signed_error, 

double *absolute_error 

); 

# **8.6 Storage Functions** 

Status_t storage_load_config( 

const char *filename, 

MountConfig_t *config 

# ); 

Status_t storage_save_movement( 

const char *filename, 

const MovementRecord_t *record 

# ); 

Status_t storage_save_calibration( 

const char *filename, 

const CalibrationRecord_t *record 

); 

# **8.7 Report Functions** 

void report_display_plan(const MovementPlan_t *plan); 

void report_display_calibration( 

const CalibrationRecord_t *record 

# ); 

Each function has a specific responsibility and communicates errors through the Status_t enumeration where appropriate. 

# **9. Input Validation Plan** 

Input validation prevents invalid configurations and movement requests from affecting the simulation. 

# **9.1 Motor Configuration** 

**Parameter Validation** 

Step angle Must be greater than zero 

Microstepping factor Must be a positive integer Gear reduction ratio Must be greater than zero Pulse frequency Must be greater than zero 

# **9.2 Movement Requests** 

- Inputs must be numeric. 

- Inputs must be finite values. 

- Requested movement must be representable. 

- Calculated step count must not overflow. 

- Final simulated position must remain within mechanical limits. 

# **9.3 Mechanical Limits** 

The final position is calculated as: 

[ \theta_f=\theta_c+\Delta\theta_{\text{actual}} ] 

A movement is accepted only when: 

[ \theta_{\min}\leq\theta_f\leq\theta_{\max} ] 

Both axes are checked independently. 

# **10. File Handling Design** 

AstroMotion uses text files to maintain configuration and records. 

# **10.1 Configuration File** 

**Filename:** config.txt 

Stores: 

- Motor step angle. 

- Microstepping factor. 

- Pulse frequency. 

- Gear reduction ratio. 

- Minimum angle. 

- Maximum angle. 

# **10.2 Movement History** 

**Filename:** movements.txt 

Stores: 

- Record ID. 

- Requested displacement. 

- Motor steps. 

- Direction. 

- Achievable displacement. 

- Estimated duration. 

# **10.3 Calibration Records** 

**Filename:** calibrations.txt 

Stores: 

- Record ID. 

- Axis. 

- Commanded displacement. 

- Measured displacement. 

- Signed error. 

- Absolute error. 

# **10.4 File Handling Strategy** 

The storage module will: 

1. Check file opening success. 

2. Validate file contents. 

3. Check read and write return values. 

4. Handle missing files. 

5. Close files after use. 

6. Detect malformed records. 

7. Avoid silently accepting invalid configuration data. 

# **11. Error Handling Strategy** 

|**Error Condition**|**Handling**|
|---|---|
|Invalid numerical input|Request input again|
|Invalid step angle|Reject configuration|
|Invalid gear ratio|Reject configuration|
|Invalid pulse frequency|Reject configuration|
|Movement outside limits|Reject movement|
|Missing configuration file|Display error or initialise default configuration|
|Malformed file|Report invalid file format|
|File write failure|Report storage error|
|Invalid menu selection|Display error and return to menu|
|Invalid movement plan|Reject position update|
|All modules use consistent|status values to report success or failure.|



# **12. Coding Standards Plan** 

The following standards are followed: 

1. Use descriptive variable and function names. 

2. Use snake_case for functions and variables. 

3. Use PascalCase_t for structure and enumeration typedefs. 

4. Use uppercase names for macros and constants. 

5. Keep functions focused on one responsibility. 

6. Use header guards in every header file. 

7. Pass structures by pointer where appropriate. 

8. Use const for read-only parameters. 

9. Avoid unnecessary global variables. 

10. Check file operations and input conversions. 

11. Free dynamically allocated memory where applicable. 

12. Compile using strict warning flags. 

Compiler flags: 

-Wall -Wextra -Wpedantic 

The objective is to maintain a warning-free build. 

# **13. Application Flow** 

# **13.1 Main Application Flow** 

+----------------+ | Start Program  | +-------+--------+ | v +----------------+ | Load Config    | +-------+--------+ | v +----------------+ | Display Menu   | +-------+--------+ | v +----------------+ | Read Selection | 

+-------+--------+ | +----------+----------+ |          |          | v          v          v Movement   Calibration  Reports |          |          | v          v          v Calculate   Calculate   Generate Plan        Error      Report |          |          | v          v          v Validate     Save       Display | v Simulate | v Save Record | +----------+ | v Return to Menu | v Exit? 

# **13.2 Movement Planning Algorithm** 

1. Read requested displacement for both axes. 

2. Retrieve motor and axis configuration. 

3. Calculate steps per degree. 

4. Calculate required motor steps. 

5. Determine movement direction. 

6. Calculate achievable displacement. 

7. Calculate estimated duration. 

8. Calculate final simulated position. 

9. Validate both final positions. 

10. If valid, generate and apply the movement plan. 

11. Save the movement record. 

12. Display the result. 

# **14. Unit Test Plan** 

Google Test is used for unit testing. 

The tests cover the important functions of the application. 

# **14.1 Planned Test Cases** 

|**Test ID **|**Module**|**Test**|
|---|---|---|
|UT-01|Motor|Calculate steps per degree|
|UT-02|Motor|Calculate steps for positive displacement|
|UT-03|Motor|Calculate steps for negative displacement|
|UT-04|Planner|Estimate movement duration|
|UT-05|Validation|Accept valid movement|
|UT-06|Validation|Reject movement beyond maximum limit|
|UT-07|Validation|Reject movement beyond minimum limit|
|UT-08|Mount|Update position after valid movement|
|UT-09|Mount|Reject invalid movement plan|
|UT-10|Calibration|Calculate signed and absolute error|
|UT-11|Storage|Load valid configuration|



UT-12 Storage Handle missing configuration file UT-13 Motor Reject zero step angle 

UT-14 Motor Reject zero pulse frequency 

UT-15 Planner Handle zero displacement 

# **14.2 Test Categories** 

- Positive tests. 

- Negative tests. 

- Boundary tests. 

- File handling tests. 

- Integration tests. 

At least ten meaningful test cases are planned, covering the main calculations and validation functions. 

# **15. Makefile Design** 

A Makefile is used to automate compilation, linking and testing. 

# **15.1 Required Targets** 

# **Target Purpose** 

make all Compile the main application 

make run Execute the application 

make test Build and execute Google Test cases 

make clean Remove generated files 

# **15.2 Compilation** 

The application is compiled using GCC with strict compiler warnings. 

Example: 

gcc -Wall -Wextra -Wpedantic \ 

-Iinclude -c src/motor.c -o build/motor.o 

Object files are linked to produce the executable. 

The Google Test executable is built separately using a C++ compiler and linked against the C object files. 

# **16. Repository Structure** 

The proposed GitHub repository follows this structure: 

AstroMotion/ │ ├── src/ │   ├── main.c │   ├── motor.c │   ├── mount.c │   ├── planner.c │   ├── validation.c │   ├── calibration.c │   ├── storage.c │   └── report.c │ 

├── include/ 

- │   ├── astro_types.h 

- │   ├── motor.h │   ├── mount.h │   ├── planner.h │   ├── validation.h 

- │   ├── calibration.h │   ├── storage.h │   └── report.h │ 

├── tests/ 

- │   ├── test_motor.cpp 

- │   ├── test_mount.cpp 

- │   ├── test_planner.cpp 

│   ├── test_validation.cpp 

│   └── test_calibration.cpp │ ├── data/ │   ├── config.txt │   ├── movements.txt │   └── calibrations.txt │ ├── docs/ │   ├── project_proposal.md │   ├── detailed_design.md │   └── architecture.png │ ├── Makefile ├── README.md └── .gitignore 

# **17. Git/GitHub Plan** 

Git is used for source-code version control and GitHub is used for repository hosting. 

# **17.1 Planned Commit Sequence** 

# **Commit Description** 

- 1 Initial repository setup 

- 2 Add project proposal and documentation 

- 3 Add shared data structures and enums 

- 4 Implement motor calculation module 

- 5 Implement mount and position tracking 

- 6 Implement movement planner 

- 7 Add validation and error handling 

- 8 Add storage and calibration modules 

- 9 Add report generation 

- 10 Add Google Test cases 

- 11 Add Makefile automation 

- 12 Complete README and final documentation 

# **17.2 Repository Requirements** 

The repository will include: 

- Source files. 

- Header files. 

- Test files. 

- Makefile. 

- README. 

- Project proposal. 

- Detailed design. 

- Architecture diagrams. 

- Sample configuration files. 

- .gitignore. 

Generated object files and executables will not be committed. 

# **18. Implementation Status** 

The following is an illustrative completion plan for the project. 

|**Component**|**Estimated Status**|
|---|---|
|Requirement analysis|Complete|
|High-level architecture|Complete|
|Data structure design|Complete|
|Function design|Complete|
|Motor module|Pending implementation|
|Mount module|Pending implementation|



|Planner module|Pending|implementation|
|---|---|---|
|Validation module|Pending|implementation|
|Calibration module|Pending|implementation|
|Storage module|Pending|implementation|
|Report module|Pending|implementation|
|Google Test integration|Pending|implementation|
|Makefile|Pending|implementation|
|README and GitHub|Pending||



The implementation status must be updated according to actual development progress. 

# **19. Test Execution Results** 

# **19.1 Testing Environment** 

The proposed testing environment is: 

|**Component**|**Configuration**|
|---|---|
|Operating System|Ubuntu Linux|
|Compiler|GCC|
|Language|C|



Testing Framework Google Test 

|Build Tool|GNU Make|
|---|---|
|Compiler Flags|-Wall -Wextra -Wpedantic|



# **19.2 Illustrative Test Execution Results** 

The following table presents an estimated successful test outcome for the planned test suite. 

|**Test ID **|**Description**|**Estimated Result**|
|---|---|---|
|UT-01|Steps per degree calculation|PASS|
|UT-02|Positive displacement calculation|PASS|
|UT-03|Negative displacement calculation|PASS|
|UT-04|Movement duration calculation|PASS|
|UT-05|Valid movement acceptance|PASS|



- UT-06 Maximum limit validation PASS UT-07 Minimum limit validation PASS UT-08 Mount position update PASS UT-09 Invalid plan rejection PASS UT-10 Calibration error calculation PASS UT-11 Valid configuration loading PASS UT-12 Missing configuration handling PASS UT-13 Zero step angle rejection PASS UT-14 Zero pulse frequency rejection PASS UT-15 Zero displacement handling PASS 

# **19.3 Estimated Test Summary** 

|**Parameter**|**Estimated Result**|
|---|---|
|Total test cases|15|
|Passed|15|
|Failed|0|
|Pass percentage|100%|
|Compiler warnings|0 target|
|Build status|Successful target|



These values represent an estimated target outcome and must be replaced with actual compiler and test output. 

# **19.4 Sample Test Calculation** 

For a motor with: 

- 

   - Step angle = 1.8°. 

- 

   - Microstepping = 16. 

- 

   - Gear reduction = 100:1. 

- Pulse frequency = 2000 Hz. 

The steps per degree are: 

[ S=\frac{16\times100}{1.8} =888.8889 ] 

For a movement of 1°: 

[ N=\operatorname{round}(888.8889)=889 ] 

Estimated movement duration: [ T=\frac{889}{2000}=0.4445\text{ seconds} ] 

The expected result is therefore 889 motor steps and an estimated duration of 0.4445 seconds. 

# **19.5 Build Verification** 

The following commands are used to verify the application: 

make clean 

make all 

make test 

make run 

The expected outcome is a successful build, successful unit-test execution and correct application startup. 

# **20. README Documentation** 

The README file serves as the primary documentation for users and evaluators. 

It includes the following information: 

**Item Description** Project Title AstroMotion Problem Statement Two-axis telescope mount motion planning Proposed Solution C-based motion planner and simulator Features Motor calculations, validation, simulation, calibration Architecture Module diagram and descriptions 

Repository Structure Source, include, tests, data and docs 

|C Concepts|Structures, enums, pointers, functions and file handling|
|---|---|
|Coding Standards|Naming conventions and compiler flags|
|Prerequisites|GCC, Make and Google Test|
|Build Instructions|make all|
|Run Instructions|make run|
|Test Instructions|make test|
|Clean Instructions|make clean|
|Sample Output|Example movement plan|
|Error Handling|Input, configuration and file errors|
|Limitations|Idealised simulation and manual calibration|
|Future Scope|Hardware integration and celestial tracking|



# **20.1 Sample README Description** 

AstroMotion is a C-based application that calculates and simulates the movement of a twoaxis telescope mount using stepper motors. 

It calculates motor steps for requested angular displacement using motor step angle, microstepping and gear reduction. It also estimates movement duration, validates mechanical limits, tracks simulated mount position and performs calibration analysis. 

The project demonstrates modular C programming, file handling, Google Test and Makefile automation. 

# **21. Demonstration Plan** 

The project demonstration will explain the engineering problem, software architecture, implementation and testing. 

# **21.1 Demonstration Sequence** 

# **Step Activity** 

- 1 Introduce the telescope mount motion-planning problem 

- 2 Explain stepper motor operation and gear reduction 

- 3 Present project objectives and requirements 

- 4 Explain the software architecture 

- 5 Demonstrate motor and mount configuration 

- 6 Enter angular displacement for both axes 

- 7 Display calculated motor steps and duration 

- 8 Demonstrate mechanical-limit validation 

- 9 Simulate movement and display updated position 

- 10 Enter calibration measurements 

- 11 Display positioning error 

- 12 Demonstrate saving and retrieving movement records 

- 13 Execute Google Test using make test 

- 14 Explain Makefile automation 

- 15 Present GitHub repository and commit history 

# **21.2 Expected Demonstration Output** 

An illustrative movement request: 

ASTROMOTION - MOVEMENT PLANNER 

Enter displacement for Axis 1: 1.0 Enter displacement for Axis 2: 0.5 

MOVEMENT PLAN 

Axis 1: 

Requested displacement: 1.000 degrees Motor steps: 889 Direction: Forward Achievable displacement: 1.000125 degrees Estimated duration: 0.4445 seconds 

Axis 2: 

Requested displacement: 0.500 degrees Motor steps: 444 Direction: Forward Achievable displacement: 0.4995 degrees Estimated duration: 0.2220 seconds 

Estimated total duration: 0.4445 seconds 

Movement validation: Successful 

Simulation: Completed 

The demonstration will also include an invalid movement request to show mechanical-limit validation. 

Screenshots of the implemented application and actual test output will be added to the final submission. 

# **22. Project Reflection** 

# **22.1 Learning Outcomes** 

The project provides experience in applying C programming concepts to an engineering problem. 

The major learning outcomes include: 

1. Understanding stepper motor specifications and their relationship with angular movement. 

2. Applying mathematical calculations to convert angular displacement into motor steps. 

3. Designing modular software using multiple source and header files. 

4. Using structures and enumerations to represent engineering data. 

5. Implementing input validation and error handling. 

6. Performing file operations to store configuration and movement records. 

7. Writing unit tests using Google Test. 

8. Automating compilation and testing using a Makefile. 

9. Managing project development using Git and GitHub. 

10. Understanding the importance of separating engineering calculations from application logic. 

# **22.2 Challenges Encountered and Engineering Considerations** 

**Motor step calculations:** The conversion between motor rotation and output angular displacement requires careful consideration of microstepping and gear reduction. 

**Floating-point precision:** Calculated step counts are rounded to integers, which introduces a small difference between requested and achievable angular displacement. 

**Mechanical-limit validation:** The system must validate the final simulated position rather than merely checking the requested displacement. 

**Modular design:** The different modules must communicate through clearly defined interfaces without duplicating responsibilities. 

**File handling:** Configuration and movement records must be stored reliably, and malformed files must be handled appropriately. 

**C and C++ integration:** Google Test uses C++, while the application is written in C. The interface must therefore use appropriate C linkage. 

# **22.3 Limitations** 

The initial system assumes ideal motor behaviour and does not account for missed steps, vibration, mechanical backlash or structural deformation. 

It does not directly measure the physical mount position. Calibration measurements are entered manually. 

The movement duration is calculated using constant pulse frequency and does not include acceleration or deceleration. 

# **22.4 Future Enhancements** 

The system could be extended through: 

- Physical stepper motor driver integration. 

- Microcontroller-based motor control. 

- Encoder-based position feedback. 

- Acceleration and deceleration profiles. 

- Backlash compensation. 

- Automatic calibration. 

- Celestial coordinate conversion. 

- Automatic telescope tracking. 

- Graphical user interface development. 

# **22.5 Overall Reflection** 

AstroMotion demonstrates how software engineering techniques can be applied to a practical engineering problem. It combines mathematical modelling, modular programming, data management and testing into a single application. 

The project also provides a foundation for understanding how a software motion planner can eventually be extended into a hardware-based telescope mount controller. 

# **23. Final Project Checklist** 

|**Requirement**|**Status**|
|---|---|
|Problem identification|Completed in design|
|Project proposal|Prepared|
|Detailed software design|Prepared|
|High-level architecture|Prepared|
|Modular C source files|Pending implementation|
|Header files|Pending implementation|
|Structures and enumerations|Designed|
|Input validation|Designed|
|Error handling|Designed|
|File handling|Designed|
|At least three meaningful implementation modules|Pending implementation|
|Google Test integration|Pending implementation|
|At least ten meaningful test cases|Planned|
|Makefile with required targets|Pending implementation|
|Warning-free compilation|To be verified|
|README documentation|Drafted|
|GitHub repository|To be finalised|
|Meaningful Git commits|To be completed|



Actual test evidence Pending Demonstration screenshots Pending Final report Prepared as a draft 

# **23.1 Final Verification Commands** 

The following commands will be used for final verification: 

make clean 

make all 

make test 

make run 

The repository will also be cloned into a separate directory to verify that the project builds and runs independently. 

# **Final Conclusion** 

AstroMotion is an engineering-oriented software application that provides a structured approach to planning and simulating the movement of a two-axis telescope mount. 

By combining stepper motor calculations, gear reduction, microstepping, mechanical-limit validation, movement simulation and calibration analysis, the application demonstrates how software can simplify the design and evaluation of a telescope positioning system. 

The project also demonstrates the practical application of C programming and software engineering principles, including modularity, data structures, file handling, error management, automated builds, unit testing and version control. 

The proposed system provides a foundation for future hardware integration and more advanced telescope tracking capabilities. 

