# **PHASE 2 — DETAILED SOFTWARE DESIGN** 

# **AstroMotion** 

**Two-Axis Telescope Mount Motion Planner and Calibration Simulator** 

**Roll no.:** 612507002 

**Course:** Automotive Embedded Minor **Engineering Domain:** Astronomy and Electromechanical Systems **Implementation Language:** C **Application Type:** Standalone Command-Line Application **Storage:** Local File-Based Storage **Testing Framework:** Google Test 

# **6. Module Design** 

# **6.1 Module Summary** 

AstroMotion will use a modular architecture in which each module performs a clearly defined task. The main application module will coordinate user interaction and invoke the appropriate functions from the remaining modules. 

|**Module Name**|**Source File**|**Header File**|**Responsibility**|
|---|---|---|---|
|Main Application|main.c|Not<br>applicable|Controls application flow and user interaction|
|Motor|motor.c|motor.h|Stores motor specifications and calculates<br>steps per degree and required motor steps|
|Mount|mount.c|mount.h|Maintains axis configurations, mechanical<br>limits and simulated positions|
|Planner|planner.c|planner.h|Creates movement plans and estimates<br>movement duration|
|Validation|validation.c|validation.h|Validates configurations, movement requests<br>and calibration inputs|
|Calibration|calibration.c|calibration.h|<sup>Stores calibration measurements and</sup><br>calculates positioning errors|
|Storage|storage.c|storage.h|Handles persistent configuration, movement<br>and calibration records|
|Report|report.c|report.h|Searches, sorts and generates movement and<br>calibration reports|



Shared Data Not astro_types.h<sup>Defines common structures, enumerations and</sup> Definitions applicable status codes 

# **6.2 Detailed Module Description** 

# **6.2.1 Module: Main Application** 

**Source file:** main.c 

**Header file:** Not applicable 

# **Purpose:** 

Acts as the entry point of AstroMotion and coordinates the interaction between the user and the functional modules. 

# **Responsibilities:** 

- Initialise application data structures. 

- Load saved configurations and records. 

- Display the main menu. 

- Accept user selections and coordinate the corresponding operations. 

- Invoke validation, calculation, simulation and storage functions. 

- Display results and error messages. 

- Handle application termination. 

# **Public functions:** 

- main() 

- Internal menu and user-interaction functions. 

# **Data used or owned:** 

- Current motor configuration. 

- Current mount configuration. 

- Current simulated mount position. 

- Movement and calibration records loaded from storage. 

# **Dependencies:** 

Motor, Mount, Planner, Validation, Calibration, Storage and Report. 

# **Possible errors:** 

- Configuration loading failure. 

- Invalid menu selection. 

- Invalid user input. 

- Failure to initialise application data. 

# **6.2.2 Module: Motor** 

**Source file:** motor.c 

**Header file:** motor.h 

# **Purpose:** 

Performs calculations related to stepper motor specifications and the relationship between motor steps and mount angular displacement. 

# **Responsibilities:** 

- Maintain motor step angle, microstepping factor and pulse frequency. 

- Calculate effective motor steps per degree of mount rotation. 

- Calculate the number of motor steps required for a requested angular displacement. 

- Determine movement direction separately from the step count. 

# **Public functions:** 

- motor_calculate_steps_per_degree() 

- motor_calculate_step_count() 

# **Data used or owned:** 

- MotorConfig_t 

- AxisConfig_t 

- MovementAxisPlan_t 

# **Dependencies:** 

Shared data definitions in astro_types.h. Input validation will be performed by the calling application layer before calculations are requested. 

# **Possible errors:** 

- Invalid motor step angle. 

- Zero or invalid microstepping factor. 

- Invalid gear reduction ratio. 

- Invalid angular displacement. 

- Step count exceeding the supported integer range. 

# **6.2.3 Module: Mount** 

**Source file:** mount.c **Header file:** mount.h 

# **Purpose:** 

Maintains the configuration and simulated angular position of the two telescope mount axes. 

# **Responsibilities:** 

- Initialise the two mount axes. 

- Maintain current angular positions. 

- Store minimum and maximum mechanical limits. 

- Check whether a requested movement is within mechanical limits. 

- Update simulated positions after a valid movement. 

- Prevent simulated positions from exceeding configured limits. 

# **Public functions:** 

- mount_initialize() 

- mount_check_target() 

- mount_apply_movement() 

# **Data used or owned:** 

- AxisConfig_t 

- MountState_t 

- MovementPlan_t 

# **Dependencies:** 

Shared data definitions in astro_types.h. 

# **Possible errors:** 

- Invalid axis configuration. 

- Target position outside mechanical limits. 

- Invalid movement plan. 

- Position update failure due to invalid state. 

# **6.2.4 Module: Planner** 

**Source file:** planner.c **Header file:** planner.h 

# **Purpose:** 

Combines motor calculations and mount positioning information to create a movement plan for both axes. 

# **Responsibilities:** 

- Accept requested angular displacements. 

- Calculate the required motor steps for each axis. 

- Determine movement direction. 

- Estimate movement duration using the configured pulse frequency. 

- Calculate total movement duration for simultaneous two-axis movement. 

- Produce a movement plan for simulation. 

# **Public functions:** 

- planner_create_plan() 

- planner_calculate_duration() 

- planner_execute_simulation() 

# **Data used or owned:** 

- MovementRequest_t 

- MovementAxisPlan_t 

- MovementPlan_t 

- MotorConfig_t 

- MountState_t 

# **Dependencies:** 

Motor and Mount calculation interfaces, along with shared data definitions. 

# **Possible errors:** 

- Invalid movement request. 

- Invalid motor configuration. 

- Movement outside mechanical limits. 

- Invalid pulse frequency. 

- Calculation overflow. 

# **6.2.5 Module: Validation** 

**Source file:** validation.c **Header file:** validation.h 

# **Purpose:** 

Provides common input-validation functions to ensure that user inputs and loaded data satisfy the application's requirements. 

# **Responsibilities:** 

- Validate motor configurations. 

- Validate axis configurations. 

- Validate movement requests. 

- Validate calibration measurements. 

- Check numeric values for valid ranges and finite values. 

- Prevent invalid data from reaching engineering calculations. 

# **Public functions:** 

- validation_validate_motor_config() 

- validation_validate_axis_config() 

- validation_validate_movement_request() 

- validation_validate_calibration() 

# **Data used or owned:** 

- MotorConfig_t 

- AxisConfig_t 

- MovementRequest_t 

- CalibrationRecord_t 

# **Dependencies:** 

Shared data definitions in astro_types.h. 

# **Possible errors:** 

- Null input pointer. 

- Negative or zero values where not permitted. 

- Non-finite floating-point values. 

- Invalid mechanical limits. 

- Invalid movement or calibration measurements. 

# **6.2.6 Module: Calibration** 

**Source file:** calibration.c **Header file:** calibration.h 

# **Purpose:** 

Evaluates positioning discrepancies by comparing commanded angular displacement with manually measured angular displacement. 

# **Responsibilities:** 

- Create calibration records. 

- Store commanded and measured angular displacement for each axis. 

- Calculate signed and absolute positioning errors. 

- Analyse a collection of calibration records. 

- Calculate average absolute error and maximum absolute error. 

# **Public functions:** 

- calibration_calculate_error() 

- calibration_create_record() 

- calibration_analyse_records() 

# **Data used or owned:** 

- CalibrationRecord_t 

- CalibrationSummary_t 

# **Dependencies:** 

Shared data definitions in astro_types.h. Persistent storage is handled by the Storage module and coordinated by main.c. 

# **Possible errors:** 

- Invalid calibration input. 

- Non-finite measurements. 

- Empty calibration dataset. 

- Invalid record count or null pointer. 

# **6.2.7 Module: Storage** 

**Source file:** storage.c 

**Header file:** storage.h 

# **Purpose:** 

Provides file-based storage and retrieval of application configurations, movement records and calibration records. 

# **Responsibilities:** 

- Load and save motor and mount configurations. 

- Append movement records. 

- Load previously stored movement records. 

- Append calibration records. 

- Load previously stored calibration records. 

- Detect malformed records and file-operation failures. 

# **Public functions:** 

- storage_load_config() 

- storage_save_config() 

- storage_append_movement() 

- storage_load_movements() 

- storage_append_calibration() 

- storage_load_calibrations() 

# **Data used or owned:** 

- MotorConfig_t 

- MountConfig_t 

- MovementRecord_t 

- CalibrationRecord_t 

# **Dependencies:** 

Shared data definitions in astro_types.h and the standard C file-handling library. 

# **Possible errors:** 

- File not found. 

- File permission failure. 

- Invalid file format. 

- File read or write failure. 

- Record capacity exceeded. 

# **6.2.8 Module: Report** 

**Source file:** report.c **Header file:** report.h 

# **Purpose:** 

Processes stored records and presents useful movement and calibration information to the user. 

# **Responsibilities:** 

- Generate movement history reports. 

- Generate calibration performance summaries. 

- Search movement records. 

- Sort movement records by selected criteria. 

- Display calculated statistics. 

# **Public functions:** 

- report_generate_movement_report() 

- report_generate_calibration_report() 

- report_search_movements() 

- report_sort_movements() 

# **Data used or owned:** 

- MovementRecord_t 

- CalibrationRecord_t 

- CalibrationSummary_t 

# **Dependencies:** 

Shared data definitions in astro_types.h. The application obtains records through the Storage module and passes them to Report. 

# **Possible errors:** 

- Empty record collection. 

- Invalid search criteria. 

- Invalid sorting criteria. 

- Null input pointer. 

# **7. Data Design** 

# **7.1 Structure Definitions** 

# **7.1.1 Structure: MotorConfig_t** 

# **Purpose:** 

Stores the specifications of a stepper motor used to drive a mount axis. 

# **Proposed definition:** 

typedef struct { 

double step_angle_deg; unsigned int microstep_factor; 

double pulse_frequency_hz; 

} MotorConfig_t; 

# **Member details:** 

|**Member**|**C Type**|**Valid Range or Size**|**Description**|
|---|---|---|---|
|step_angle_deg|double|Greater than 0 and at most<br>360|Full-step angle of the motor|
|microstep_factor|unsigned<br>int|Greater than or equal to 1|Number of microsteps per full<br>step|
|pulse_frequency_|hz double|Greater than 0|Configured pulse frequency|
|**7.1.2 Structure:**|**AxisConfig_t**|||



# **Purpose:** 

Stores the mechanical configuration and movement limits of an individual mount axis. 

# **Proposed definition:** 

typedef struct 

{ double gear_reduction_ratio; double min_angle_deg; 

double max_angle_deg; 

} AxisConfig_t; 

# **Member details:** 

**Member C Type**<sup>**Valid Range or**</sup> **Description Size** Motor revolutions required for one complete gear_reduction_ratio double Greater than 0 axis revolution min_angle_deg double<sup>Within -360 to</sup> Minimum allowed angular position 360 max_angle_deg double<sup>Within -360 to</sup> Maximum allowed angular position 360 

The minimum angle must be strictly less than the maximum angle. 

# **7.1.3 Structure: MountConfig_t** 

# **Purpose:** 

Groups the motor and mechanical configurations of the two independently controlled axes. 

# **Proposed definition:** 

typedef struct 

{ 

MotorConfig_t motor[AXIS_COUNT]; 

AxisConfig_t axis[AXIS_COUNT]; 

- } MountConfig_t; 

# **7.1.4 Structure: MountState_t** 

# **Purpose:** 

Maintains the current simulated angular position of both mount axes. 

# **Proposed definition:** 

typedef struct 

{ 

double current_angle_deg[AXIS_COUNT]; 

- } MountState_t; 

# **7.1.5 Structure: MovementRequest_t** 

# **Purpose:** 

Stores the angular displacement requested by the user for both axes. 

# **Proposed definition:** 

typedef struct 

{ 

double delta_angle_deg[AXIS_COUNT]; 

} MovementRequest_t; 

The displacement is relative to the current simulated position. Positive and negative values represent opposite movement directions. 

# **7.1.6 Structure: MovementAxisPlan_t** 

# **Purpose:** 

Stores the calculated movement details for one mount axis. 

# **Proposed definition:** 

typedef struct 

{ 

unsigned long step_count; 

Direction_t direction; 

double requested_angle_deg; double achievable_angle_deg; 

double estimated_duration_sec; 

} MovementAxisPlan_t; 

# **Member details:** 

|**Member**|**C Type**|**Description**|
|---|---|---|
|step_count|unsigned<br>long|Number of motor pulses required|
|direction|Direction_t|Direction of motor movement|
|requested_angle_deg|double|Requested angular displacement|
|achievable_angle_deg|double|Angular displacement represented by the rounded step<br>count|
|estimated_duration_sec|double|Estimated movement duration|
|**7.1.7 Structure: Move**|**mentPlan_t**||



# **Purpose:** 

Combines the movement plans of both axes into one complete movement operation. 

# **Proposed definition:** 

typedef struct 

{ 

MovementAxisPlan_t axis_plan[AXIS_COUNT]; 

double total_duration_sec; 

} MovementPlan_t; 

# **7.1.8 Structure: MovementRecord_t** 

# **Purpose:** 

Stores a completed simulated movement for history and report generation. 

# **Proposed definition:** 

typedef struct { 

unsigned long record_id; 

double start_angle_deg[AXIS_COUNT]; 

double requested_angle_deg[AXIS_COUNT]; 

double final_angle_deg[AXIS_COUNT]; unsigned long step_count[AXIS_COUNT]; 

double duration_sec; 

} MovementRecord_t; 

# **7.1.9 Structure: CalibrationRecord_t** 

# **Purpose:** 

Stores manually entered calibration measurements for both axes. 

# **Proposed definition:** 

typedef struct { 

unsigned long record_id; 

double commanded_angle_deg[AXIS_COUNT]; 

double measured_angle_deg[AXIS_COUNT]; 

double signed_error_deg[AXIS_COUNT]; 

double absolute_error_deg[AXIS_COUNT]; 

} CalibrationRecord_t; 

# **7.1.10 Structure: CalibrationSummary_t** 

# **Purpose:** 

Stores summary statistics calculated from multiple calibration records. 

# **Proposed definition:** 

typedef struct 

{ 

unsigned int record_count; 

double average_absolute_error_deg[AXIS_COUNT]; 

double maximum_absolute_error_deg[AXIS_COUNT]; 

} CalibrationSummary_t; 

# **7.2 Enumeration Definitions** 

# **7.2.1 Enumeration: Axis_t** 

**Purpose:** Identifies the two mount axes. 

typedef enum 

{ 

AXIS_FIRST = 0, 

AXIS_SECOND, 

AXIS_COUNT 

} Axis_t; 

The names AXIS_FIRST and AXIS_SECOND are intentionally generic. They can later be renamed to match the actual telescope mount configuration. 

# **7.2.2 Enumeration: Direction_t** 

**Purpose:** Represents the direction of motor movement. 

typedef enum 

{ 

DIRECTION_NEGATIVE = -1, DIRECTION_POSITIVE = 1, DIRECTION_NONE = 0 } Direction_t; 

# **7.2.3 Enumeration: Status_t** 

**Purpose:** Represents the result of operations performed by the application. 

typedef enum 

{ 

STATUS_SUCCESS = 0, STATUS_INVALID_ARGUMENT, 

STATUS_INVALID_CONFIGURATION, STATUS_LIMIT_EXCEEDED, STATUS_CALCULATION_ERROR, STATUS_FILE_NOT_FOUND, 

STATUS_FILE_ERROR, STATUS_INVALID_FILE_FORMAT, STATUS_CAPACITY_EXCEEDED, 

STATUS_EMPTY_DATASET, 

STATUS_NOT_FOUND 

} Status_t; 

# **7.2.4 Enumeration: SortCriteria_t** 

**Purpose:** Defines the available movement-record sorting criteria. 

typedef enum { 

SORT_BY_RECORD_ID = 0, 

SORT_BY_DURATION, SORT_BY_FIRST_AXIS_ANGLE, 

SORT_BY_SECOND_AXIS_ANGLE 

} SortCriteria_t; 

# **7.3 Constants** 

|**Constant**|**Proposed**<br>**Value**|**Purpose**|
|---|---|---|
|AXIS_COUNT|2|Number of independently controlled<br>mount axes|
|MAX_MOVEMENT_RECORDS|1000|Maximum movement records loaded into<br>memory|
|MAX_CALIBRATION_RECORDS|1000|Maximum calibration records loaded into<br>memory|
|MAX_LINE_LENGTH|256|Maximum expected input line length for<br>text records|
|MAX_FILENAME_LENGTH|128|Maximum supported filename length|
|FLOAT_TOLERANCE|1e-9|Tolerance for floating-point comparisons<br>where required|



These are initial software limits and may be adjusted during implementation. 

# **7.4 Data Dictionary** 

|**Data Item**|**C Type**|**Valid Range**|**Validation Rule**|**Description**|
|---|---|---|---|---|
|Step angle|double|Greater than 0|Must be finite|Motor full-step angle in<br>degrees|
|Microstep<br>factor|unsigned<br>int|1 or greater|Must not be zero|Microsteps per full step|
|Pulse<br>frequency|double|Greater than 0|Must be finite|Motor pulse frequency in<br>Hz|
|Gear ratio|double|Greater than 0|Must be finite|Motor revolutions per<br>axis revolution|
|Minimum<br>angle|double|-360 to 360|Must be less than<br>maximum|Lower mechanical limit|
|Maximum<br>angle|double|-360 to 360|Must be greater than<br>minimum|Upper mechanical limit|
|Current angl|e double|Configured|Must be finite and|Current simulated|



|||limits|within limits|position|
|---|---|---|---|---|
|Requested<br>angle|double|Finite numeric<br>value|Resulting target must<br>satisfy limits|Requested angular<br>displacement|
|Step count|unsigned<br>long|0 or greater|Must fit supported<br>range|Calculated motor pulse<br>count|
|Duration|double|0 or greater|Must be finite|Estimated movement<br>duration|
|Measured<br>angle|double|Finite numeric<br>value|Must be a valid<br>measurement|Manually measured<br>displacement|



# **8. Function Design** 

All public functions will return a Status_t unless a different return type is necessary. Functions that produce results will generally receive output pointers. This allows the caller to distinguish successful calculations from errors. 

# **8.1 Function: motor_calculate_steps_per_degree()** 

**Module:** Motor 

# **Prototype:** 

Status_t motor_calculate_steps_per_degree( 

const MotorConfig_t *motor, 

const AxisConfig_t *axis, 

double *steps_per_degree); 

# **Purpose:** 

Calculates the number of motor pulses required for one degree of mount-axis rotation. 

**Parameters:** 

|**Parameter**|**C Type**|**Direction**|**Description**|
|---|---|---|---|
|motor|const MotorConfig_t *|Input|Motor configuration|
|axis|const AxisConfig_t *|Input|Axis gear configuration|
|steps_per_degr|ee double *|Output|Calculated steps per degree|
|**Return type:**S|tatus_t|||



**Return values:** 

- STATUS_SUCCESS: Calculation completed. 

- STATUS_INVALID_ARGUMENT: Invalid pointer. 

- STATUS_INVALID_CONFIGURATION: Invalid motor or gear configuration. 

- STATUS_CALCULATION_ERROR: Invalid or non-finite result. 

# **Preconditions:** 

- All pointers must be valid. 

- Motor and axis configurations must be valid. 

# **Postconditions:** 

- The output contains a positive finite steps-per-degree value. 

# **Errors handled:** 

- Zero step angle. 

- Zero microstep factor. 

- Invalid gear ratio. 

- Non-finite calculation result. 

**Related requirements:** FR-01, FR-02, FR-03. 

**Planned unit tests:** UT-01, UT-02, UT-03. 

**8.2 Function: motor_calculate_step_count()** 

**Module:** Motor 

# **Prototype:** 

Status_t motor_calculate_step_count( 

double delta_angle_deg, 

double steps_per_degree, 

unsigned long *step_count, 

Direction_t *direction); 

# **Purpose:** 

Calculates the number of whole motor pulses needed for a requested angular displacement. 

# **Parameters:** 

|**Parameter**|**C Type**|**Direction**|**Description**|
|---|---|---|---|
|delta_angle_deg|double|Input|Requested angular displacement|



steps_per_degree double Input Effective motor pulses per degree step_count unsigned long * Output Rounded whole pulse count direction Direction_t * Output Movement direction 

**Return type:** Status_t 

# **Return values:** 

- STATUS_SUCCESS 

- STATUS_INVALID_ARGUMENT 

- STATUS_CALCULATION_ERROR 

# **Preconditions:** 

- Steps per degree must be positive and finite. 

- Angular displacement must be finite. 

- Output pointers must be valid. 

# **Postconditions:** 

- The step count is a non-negative whole number. 

- Direction is stored separately from the step count. 

- Zero displacement produces zero steps and DIRECTION_NONE. 

# **Errors handled:** 

- 

   - Invalid input. 

- 

   - Non-finite values. 

- Step count overflow. 

**Related requirements:** FR-04, FR-05. 

**Planned unit tests:** UT-04, UT-05, UT-06. 

**8.3 Function: mount_initialize()** 

**Module:** Mount 

# **Prototype:** 

Status_t mount_initialize( 

MountState_t *state, 

const MountConfig_t *config); 

# **Purpose:** 

Initialises the simulated position of both mount axes. 

# **Parameters:** 

- state: Output pointer to mount state. 

- config: Input pointer to mount configuration. 

**Return type:** Status_t 

**Return values:** STATUS_SUCCESS, STATUS_INVALID_ARGUMENT, STATUS_INVALID_CONFIGURATION. 

# **Preconditions:** 

- Both pointers must be valid. 

- Axis limits must be valid. 

# **Postconditions:** 

- Both axes are initialised to zero degrees, provided zero lies within both configured mechanical limits. 

# **Errors handled:** 

- Invalid pointers. 

- Invalid axis limits. 

- Zero position outside configured limits. 

**Related requirements:** FR-07, FR-08. 

# **8.4 Function: mount_check_target()** 

**Module:** Mount 

# **Prototype:** 

Status_t mount_check_target( 

const MountState_t *state, 

const MountConfig_t *config, 

const double target_angle_deg[AXIS_COUNT]); 

# **Purpose:** 

Checks whether the proposed final position of both axes is within their mechanical limits. 

# **Return values:** 

- STATUS_SUCCESS 

- STATUS_INVALID_ARGUMENT 

- STATUS_INVALID_CONFIGURATION 

- STATUS_LIMIT_EXCEEDED 

# **Preconditions:** 

- Mount state and configuration must be valid. 

- Both target angles must be finite. 

# **Postconditions:** 

- No mount position is modified. 

**Related requirements:** FR-07. 

# **8.5 Function: mount_apply_movement()** 

**Module:** Mount 

# **Prototype:** 

Status_t mount_apply_movement( 

MountState_t *state, 

const MovementPlan_t *plan); 

# **Purpose:** 

Updates the simulated mount position using the achievable angular displacement in a valid movement plan. 

# **Return values:** 

- STATUS_SUCCESS 

- STATUS_INVALID_ARGUMENT 

- STATUS_LIMIT_EXCEEDED 

- STATUS_CALCULATION_ERROR 

# **Preconditions:** 

- State and movement plan must be valid. 

- The resulting positions must remain within configured mechanical limits. The calling application must check the limits before applying the plan. 

# **Postconditions:** 

- The simulated position is updated using achievable displacement, not the unrounded requested displacement. 

**Related requirements:** FR-08. 

# **8.6 Function: planner_create_plan()** 

**Module:** Planner 

# **Prototype:** 

Status_t planner_create_plan( 

const MovementRequest_t *request, const MountConfig_t *config, 

const MountState_t *state, 

MovementPlan_t *plan); 

# **Purpose:** 

Creates a movement plan for both mount axes. 

# **Responsibilities:** 

- Calculate steps per degree for each axis. 

- Calculate step count and direction. 

- Calculate achievable angular displacement. 

- Determine proposed final positions. 

- Check mechanical limits. 

- Calculate estimated duration. 

# **Return values:** 

- STATUS_SUCCESS 

- STATUS_INVALID_ARGUMENT 

- STATUS_INVALID_CONFIGURATION 

- STATUS_LIMIT_EXCEEDED 

- STATUS_CALCULATION_ERROR 

# **Preconditions:** 

- Request, configuration, state and output pointers must be valid. 

- Motor and axis configurations must be valid. 

# **Postconditions:** 

- A complete movement plan is generated only if both axes can execute the requested movement within their limits. 

- The mount state remains unchanged. 

**Related requirements:** FR-03, FR-04, FR-05, FR-06, FR-07. 

# **8.7 Function: planner_calculate_duration()** 

**Module:** Planner 

# **Prototype:** 

Status_t planner_calculate_duration( 

unsigned long step_count, 

double pulse_frequency_hz, 

double *duration_sec); 

# **Purpose:** 

Calculates the estimated duration for a motor movement. 

# **Formula:** 

[ T = \frac{N}{f} ] 

Where: 

- (T) = movement duration in seconds. 

- (N) = number of motor pulses. 

- (f) = pulse frequency in pulses per second. 

# **Return values:** 

- STATUS_SUCCESS 

- STATUS_INVALID_ARGUMENT 

- STATUS_INVALID_CONFIGURATION 

- STATUS_CALCULATION_ERROR 

# **Postconditions:** 

- Duration is non-negative and finite. 

- Zero steps produce zero duration. 

# **Related requirements:** FR-06. 

# **8.8 Function: planner_execute_simulation()** 

**Module:** Planner 

# **Prototype:** 

Status_t planner_execute_simulation( 

const MovementPlan_t *plan, 

MountState_t *state); 

# **Purpose:** 

Applies a previously validated movement plan to the simulated mount state. 

# **Responsibilities:** 

- Verify the movement plan. 

- Update both axis positions using achievable displacement. 

- Preserve the previous state if the operation fails. 

**Return values:** STATUS_SUCCESS, STATUS_INVALID_ARGUMENT, STATUS_LIMIT_EXCEEDED. 

**Related requirements:** FR-08. 

# **8.9 Validation Functions** 

**validation_validate_motor_config()** 

Status_t validation_validate_motor_config( 

const MotorConfig_t *config); 

Checks that the step angle, microstep factor and pulse frequency are valid. 

# **validation_validate_axis_config()** 

Status_t validation_validate_axis_config( 

const AxisConfig_t *config); 

Checks that the gear ratio and mechanical limits are valid. 

# **validation_validate_movement_request()** 

Status_t validation_validate_movement_request( 

const MovementRequest_t *request); 

Checks that requested angular displacements are finite. 

# **validation_validate_calibration()** 

Status_t validation_validate_calibration( 

const CalibrationRecord_t *record); 

Checks that commanded and measured calibration values are valid and finite. 

**Related requirements:** FR-01, FR-02, FR-04, FR-07, FR-10. 

# **8.10 Calibration Functions** 

# **calibration_calculate_error()** 

Status_t calibration_calculate_error( 

double commanded_angle_deg, double measured_angle_deg, double *signed_error_deg, 

double *absolute_error_deg); 

**Purpose:** Calculates the difference between commanded and measured angular displacement. [ E_s = \theta_{\text{measured}} - \theta_{\text{commanded}} ] [ E_a = |E_s| ] 

Where (E_s) is signed error and (E_a) is absolute error. 

# **calibration_create_record()** 

Status_t calibration_create_record( 

const double commanded_angle_deg[AXIS_COUNT], 

const double measured_angle_deg[AXIS_COUNT], 

CalibrationRecord_t *record); 

**Purpose:** Creates a calibration record for both axes and calculates the corresponding errors. 

# **calibration_analyse_records()** 

Status_t calibration_analyse_records( 

const CalibrationRecord_t records[], 

unsigned int record_count, 

CalibrationSummary_t *summary); 

**Purpose:** Calculates average absolute error and maximum absolute error for each axis. 

**Related requirements:** FR-10, FR-11, FR-12. 

# **8.11 Storage Functions** 

**storage_load_config()** 

Status_t storage_load_config( 

const char *filename, 

MountConfig_t *config); 

Loads the saved motor and mount configuration. 

# **storage_save_config()** 

Status_t storage_save_config( 

const char *filename, 

const MountConfig_t *config); 

Saves the current motor and mount configuration. 

# **storage_append_movement()** 

Status_t storage_append_movement( 

const char *filename, 

const MovementRecord_t *record); 

Appends a movement record to the movement history file. 

# **storage_load_movements()** 

Status_t storage_load_movements( 

const char *filename, 

MovementRecord_t records[], 

unsigned int capacity, 

unsigned int *record_count); 

Loads movement records up to the supplied capacity. 

# **storage_append_calibration()** 

Status_t storage_append_calibration( 

const char *filename, 

const CalibrationRecord_t *record); 

Appends a calibration record. 

# **storage_load_calibrations()** 

Status_t storage_load_calibrations( 

const char *filename, CalibrationRecord_t records[], 

unsigned int capacity, 

unsigned int *record_count); 

Loads calibration records up to the supplied capacity. 

**Related requirements:** FR-09, FR-10. 

# **8.12 Report Functions** 

**report_generate_movement_report()** 

Status_t report_generate_movement_report( 

const MovementRecord_t records[], unsigned int record_count); 

Displays movement history and relevant movement statistics. 

# **report_generate_calibration_report()** 

Status_t report_generate_calibration_report( 

const CalibrationSummary_t *summary); 

Displays calibration statistics for both axes. 

**report_search_movements()** 

Status_t report_search_movements( 

const MovementRecord_t records[], 

unsigned int record_count, 

unsigned long record_id, 

unsigned int *found_index); 

Searches for a movement record using its unique record ID. 

# **report_sort_movements()** 

Status_t report_sort_movements( 

MovementRecord_t records[], 

unsigned int record_count, SortCriteria_t criteria); Sorts movement records according to the selected criterion. 

**Related requirements:** FR-12, FR-13. 

# **9. Input-Validation Plan** 

|**Input**|**Source**|**Validation Rule**|**Invalid Example **|**Expected Behaviour**|
|---|---|---|---|---|
|Motor step angle|User / File|<sup>Must be finite and</sup><br>greater than zero|0 or -1|Reject configuration|
|Microstep factor|User / File|<sup>Must be an integer</sup><br>greater than zero|0|Reject configuration|
|Pulse frequency|User / File|<sup>Must be finite and</sup><br>greater than zero|-100|Reject configuration|
|Gear ratio|User / File|<sup>Must be finite and</sup><br>greater than zero|0|Reject configuration|
|Minimum angle|User / File|<sup>Must be less than</sup><br>maximum angle|180 when<br>maximum is 90|Reject axis<br>configuration|
|Maximum angle|User / File|<sup>Must be greater than</sup><br>minimum angle|-180 when<br>minimum is 0|Reject axis<br>configuration|
|Angular<br>displacement|User|Must be finite|NaN or infinity|Reject movement<br>request|
|Target position|Calculated|<sup>Must lie within</sup><br>mechanical limits|Target beyond<br>maximum angle|Reject movement plan|
|Measured angle|User|Must be finite|NaN|Reject calibration<br>record|
|Record ID|User|Must identify an<br>existing record|Unknown ID|Display not-found<br>message|
|Menu selection|User|Must correspond to an<br>available operation|<br>99|Display error and<br>request input again|



# **Common Validation Strategy** 

All user inputs will first be read as text and then converted into the required numeric type. Conversion functions such as strtod() and strtoul() will be used where appropriate, with checks for conversion errors, trailing characters and out-of-range values. 

The application will reject invalid input before passing it to engineering calculation functions. 

Validation will be performed at two levels: 

1. **Input validation:** Checks user-entered values and file-loaded data. 

2. **Engineering validation:** Checks calculated target positions and other results before a movement is simulated. 

Invalid input will not cause the application to terminate unexpectedly. The user will receive a meaningful error message and be allowed to retry where recovery is possible. 

# **10. File-Handling Design** 

# **10.1 File Summary** 

|**File**<br>**Purpose**|**Forma**|**t Created By**|**Read By**|**Updated**<br>**By**|
|---|---|---|---|---|
|config.txt<br>Stores motor and mount<br>configurations|Text|Application /<br>User setup|Storage|Storage|
|movements.txt Stores movement history|Text|Storage|Storage /<br>Report|Storage|
|calibrations.txt Stores calibration records|Text|Storage|Storage /<br>Report|Storage|



All files will be stored in the project's data/ directory during normal operation. 

# **10.2 Record Format** 

A comma-separated text format will be used initially to keep records readable and easy to inspect. 

# **Configuration file: config.txt** 

The configuration file will contain the motor and axis parameters for both axes. 

Example: 

# axis,step_angle,microstep,pulse_frequency,gear_ratio,min_angle,max_angle 

- 0,1.8,16,1000,100,0,360 

1,1.8,16,1000,100,-90,90 

The values above are illustrative examples only and are not confirmed specifications of the actual telescope mount. 

# **Movement file: movements.txt** 

Each record will contain: 

# # 

id,start_axis1,start_axis2,requested_axis1,requested_axis2,final_axis1,final_axis2,steps_axis1 ,steps_axis2,duration 

1,0,0,10,5,10.00125,5.000625,64001,32001,64.001 

The values are illustrative. 

# **Calibration file: calibrations.txt** 

Each record will contain: 

# id,commanded_axis1,measured_axis1,commanded_axis2,measured_axis2 

1,10.0,9.98,5.0,5.02 

The application will calculate the signed and absolute errors when records are loaded or processed. 

# **10.3 File Operations** 

|**Operation **|<sup>**Function or**</sup><br>**Module**|**C Library Function**|**Failure Handling**|
|---|---|---|---|
|Open|Storage|fopen()|Return file error|
|Read|Storage|fgets() / fscanf() as<br>appropriate|Detect invalid or incomplete<br>records|
|Write|Storage|fprintf()|Detect write failure|
|Append|Storage|fopen() with append mode|Preserve existing records|
|Close|Storage|fclose()|Report close failure where<br>relevant|



The implementation will prefer line-based reading with fgets() followed by explicit parsing, allowing malformed records to be detected and rejected. 

# **10.4 File Error Conditions** 

|**Error Condition**|**Detection Method**|**Expected Behaviour**|
|---|---|---|
|File does not<br>exist|fopen() returns NULL|Use documented defaults for an optional first-run<br>configuration, or report the missing file|
|File cannot be<br>opened|fopen() returns NULL|Display an error and avoid using uninitialised<br>data|
|File is empty|No records read|Treat as an empty dataset or invalid required|



|||configuration|
|---|---|---|
|File contains|Parsing or validation|Reject the malformed record and report the|
|invalid data|fails|problem|
|Read failure|Check read result and<br>ferror()|Stop reading and report failure|
|Write failure|Check output operation<br>and ferror()|Report failure; do not claim that the record was<br>saved|
|Capacity<br>exceeded|Record count reaches<br>configured capacity|Stop loading and report that the supported<br>capacity was exceeded|



Configuration updates will be validated before being saved. Where practical, the application will write a new configuration to a temporary file and replace the old configuration only after a successful write. 

# **11. Error-Handling Strategy** 

# **11.1 Status Representation** 

The Status_t enumeration defined in Section 7 will be used to communicate operation results between modules. 

Successful operations return STATUS_SUCCESS. Failed operations return a specific error status. 

# **11.2 Error Catalogue** 

|**Error**<br>**ID**|<br>**Error**<br>**Condition**|**Detection**<br>**Location**|**Returned Status**|**User-Facing**<br>**Behaviour**|
|---|---|---|---|---|
|ERR-<br>01|Invalid motor<br>configuration|<sup>Validation </sup>|<sup>STATUS_INVALID_CONFIGURATION</sup>|Ask user to<br>correct motor<br>parameters|
|ERR-<br>02|Invalid axis<br>limits|Validation|STATUS_INVALID_CONFIGURATION|Display invalid<br>mechanical<br>limits|
|ERR-<br>03|Target exceeds<br>mechanical<br>limits|<br>Mount /<br>Planner|STATUS_LIMIT_EXCEEDED|Reject<br>movement|
|ERR-<br>04|Invalid<br>movement<br>request|Validation|STATUS_INVALID_ARGUMENT|Request valid<br>angular<br>displacement|



|ERR-<br>05|Invalid<br>calculation<br>result|Motor /<br>Planner|STATUS_CALCULATION_ERROR|Abort the<br>current<br>calculation|
|---|---|---|---|---|
|ERR-<br>06|Configuration<br>file<br>unavailable|Storage|STATUS_FILE_NOT_FOUND or<br>STATUS_FILE_ERROR|Load<br>documented<br>defaults only<br>when<br>appropriate,<br>otherwise<br>report failure|
|ERR-<br>07|Invalid file<br>record|Storage|STATUS_INVALID_FILE_FORMAT|Reject the<br>malformed<br>record|
|ERR-<br>08|Record<br>capacity<br>exceeded|Storage|STATUS_CAPACITY_EXCEEDED|Inform the user<br>that the<br>supported<br>capacity is<br>reached|
|ERR-<br>09|Empty<br>calibration<br>dataset|Calibration|STATUS_EMPTY_DATASET|Inform the user<br>that analysis<br>requires<br>records|
|ERR-<br>10|Movement<br>record not<br>found|Report|STATUS_NOT_FOUND|Display a not-<br>found message|



# **11.3 Recovery Strategy** 

The application will use controlled error handling to prevent invalid operations from affecting the simulated mount state or stored records. 

- Invalid menu selections will return the user to the main menu. 

- Invalid numeric inputs will be rejected and requested again. 

- Invalid configurations will not be used in calculations. 

- Movement plans that violate mechanical limits will be rejected without changing the mount position. 

- File failures will be reported without assuming that data has been saved. 

- Malformed records will not be passed to calculation or report functions. 

- If a required configuration cannot be loaded and no valid default configuration is available, the application will prevent movement planning until a valid configuration is supplied. 

- The application will close open files and release allocated resources before termination. 

# **12. Coding Standards Plan** 

# **12.1 Naming Conventions** 

|**Item**|**Convention**|**Example**|
|---|---|---|
|Source files|Lowercase with underscores|motor.c|
|Header files|Lowercase with underscores|motor.h|
|Functions|Lowercase with module prefix|motor_calculate_step_count()|
|Local variables|Lowercase with underscores|step_count|
|Structures|PascalCase with _t suffix|MotorConfig_t|
|Enumerations|PascalCase with _t suffix|Status_t|
|Enumeration constants|Uppercase with underscores|STATUS_SUCCESS|
|Constants|Uppercase with underscores|MAX_MOVEMENT_RECORDS|
|Macros|Uppercase with underscores|AXIS_COUNT|



# **12.2 Formatting Rules** 

- **Indentation:** Four spaces. 

- **Brace style:** K&R style. 

- **Maximum line length:** Approximately 100 characters where practical. 

- **Compiler warning flags:** -Wall -Wextra -Wpedantic. 

- **Comment style:** Use /* ... */ for explanations and // for short inline comments. 

- **Header protection:** Use include guards in every header file. 

- **Floating-point calculations:** Use double for angular and timing calculations. 

- **Constants:** Define shared constants in a common header or appropriate module header. 

# **12.3 Function Rules** 

- Each function should perform one clearly defined task. 

- Function names should indicate their responsibilities. 

- Parameters should be used instead of unnecessary global variables. 

- Input-only pointers should use const wherever possible. 

- Output parameters must be checked for valid pointers. 

- Functions should return meaningful status values. 

- Functions should validate their own critical preconditions where necessary. 

- Large functions should be divided into smaller functions. 

# **12.4 Prohibited Practices** 

- Unnecessary use of global variables. 

- Hard-coded motor specifications within calculation functions. 

- Unchecked file operations. 

- Unchecked input conversions. 

- Use of uninitialised variables. 

- Functions with multiple unrelated responsibilities. 

- Duplicating the same engineering calculation across multiple modules. 

- Ignoring compiler warnings. 

- Using unexplained numerical constants throughout the source code. 

- Updating simulated positions before movement validation succeeds. 

# **13. Application Flow** 

# **13.1 Main Application Flowchart** 

The main application will follow this sequence: 

1. Start the application. 

2. Initialise data structures. 

3. Load the saved motor and mount configuration. 

4. Load movement and calibration records. 

5. Display the main menu. 

6. Accept the user's selection. 

7. Execute the selected operation. 

8. Display the result or error message. 

9. Return to the main menu. 

10. Save necessary changes and exit when requested. 

# **Main application flow:** 

START 

| v 

Initialise Data 

| v 

Load Configuration 

| v 

Load Stored Records 

| v 

Display Menu 

| v 

Read Selection 

| v 

Validate Choice 

| v 

Execute Operation 

| v 

Display Result 

| v 

Exit Selected? 

/       \ No         Yes |           | v           v Display Menu  Save Changes | v 

END 

# **13.2 Operation Flow: Movement Planning** 

1. Accept angular displacement for both axes. 

2. Validate the input values. 

3. Calculate steps per degree for each axis. 

4. Calculate required motor steps and direction. 

5. Calculate achievable angular displacement from the rounded step count. 

6. Determine the proposed final position. 

7. Check the final position against mechanical limits. 

8. Calculate movement duration for each axis. 

9. Calculate total duration for simultaneous movement. 

10. Display the movement plan. 

11. Ask the user whether to execute the simulation. 

12. If confirmed, update the simulated position. 

13. Create and save a movement record. 

Movement Request 

| 

v 

Validate Input 

| v Calculate Motor Steps | v Calculate Achievable Angle | v Check Mechanical Limits | Valid? /     \ No       Yes |         | v         v Show Error  Estimate Duration | v Display Movement Plan | v User Confirms? /      \ No        Yes |          | v          v Cancel   Update Position | v 

Save Movement Record 

| 

v 

END 

# **13.3 Operation Flow: Calibration** 

1. Select calibration operation. 

2. Enter commanded angular displacement for both axes. 

3. Enter manually measured angular displacement for both axes. 

4. Validate the entered values. 

5. Calculate signed and absolute errors. 

6. Create a calibration record. 

7. Save the record. 

8. Load calibration records for analysis. 

9. Calculate average and maximum absolute error for each axis. 

10. Display the calibration report. 

Calibration Input 

| v 

Validate Values 

| 

v 

Calculate Errors 

| v 

Create Record 

| v 

Save Record 

| 

v 

Load All Records 

| v 

Analyse Records 

| v Display Report | v 

END 

# **13.4 Operation Flow: Configuration Management** 

1. Select configuration operation. 

2. Display current motor and axis parameters. 

3. Accept updated parameters. 

4. Validate the motor and axis configurations. 

5. Check that the current simulated position remains within the updated limits. 

6. Save the updated configuration. 

7. Apply the configuration only after successful validation and saving. 

8. Display success or error information. 

# **14. Unit-Test Plan** 

# **14.1 Functions Selected for Testing** 

|**Function**|**Module**|**Reason for Testing**|
|---|---|---|
|motor_calculate_steps_per_degree()|Motor|Verifies the core motor-to-mount conversion|
|motor_calculate_step_count()|Motor|Verifies step rounding and direction|
|mount_check_target()|Mount|Verifies mechanical limit enforcement|
|planner_calculate_duration()|Planner|Verifies movement timing|
|calibration_calculate_error()|Calibration|Verifies positioning error calculations|



validation_validate_motor_config() Validation Verifies rejection of invalid configurations 

storage_append_movement() Storage Verifies movement record persistence storage_load_movements() Storage Verifies record retrieval and parsing 

# **14.2 Test Cases** 

The following test cases are proposed. Actual results will be recorded after implementation. 

|**Test**<br>**ID**|<br>**Function**|**Category**|<sup>**Input or**</sup><br>**Condition**|**Expected**<br>**Result**|**Requirement**|
|---|---|---|---|---|---|
|UT-<br>01|motor_calculate_steps_per_degree(<br>)|Positive|Step angle<br>1.8°,<br>microstep<br>16, gear<br>ratio 100|888.8889<br>steps/degree<br>approximatel<br>y|FR-03|
|UT-<br>02|motor_calculate_steps_per_degree(<br>)|Negative|<sup>Step angle</sup><br>equals zero|Invalid<br>configuration<br>status|<br>FR-03|
|UT-<br>03|motor_calculate_steps_per_degree(<br>)|Boundary|Microstep<br>factor equals<br>1|<br>Valid<br>calculation|FR-03|
|UT-<br>04|motor_calculate_step_count()|Positive|10° at 100<br>steps/degree|1000 steps,<br>positive<br>direction|FR-05|
|UT-<br>05|motor_calculate_step_count()|Negative|<sup>-10° at 100</sup><br>steps/degree|1000 steps,<br>negative<br>direction|FR-05|
|UT-<br>06|motor_calculate_step_count()|Boundary|Zero angular<br>displacemen<br>t|<br>Zero steps<br>and no<br>direction|FR-05|
|UT-<br>07|planner_calculate_duration()|Positive|1000 steps at<br>500 Hz|<br>2 seconds|FR-06|
|UT-<br>08|planner_calculate_duration()|Negative|Pulse<br>frequency<br>equals zero|Invalid<br>configuration<br>status|<br>FR-06|
|UT-|<sup>mount_check_target()</sup>|Boundary|Target|Valid target|FR-07|



|09<br>UT-<br>10<br>|mount_check_target()|Negative|equals<br>maximum<br>permitted<br>angle<br>Target<br>exceeds<br>maximum<br>permitted<br>angle<br>Commanded<br>°|Limit<br>exceeded<br>status<br> <br>Signed error<br>°|FR-07|
|---|---|---|---|---|---|
|UT-<br>11<br>UT-|calibration_calculate_error()|Positive|10,<br>measured<br>9.8°<br>Commanded<br>and|-0.2,<br>absolute error<br>0.2°<br>|<br>FR-11|
|12|calibration_calculate_error()|Boundary|<br>measured|Zero error|FR-11|
||||<br>values equal|||
|UT-<br>13|validation_validate_motor_confi|g() Negative|Negative<br>pulse<br>frequency|Invalid<br>configuration<br>status|<br>FR-01|
||||Valid|||
||||movement|||
|UT-<br>14|storage_append_movement()|Positive|record and<br>writable<br>temporary<br>file|Record saved<br>successfully|<br>FR-09|
|||||Invalid file<br>format status||
|UT-<br>15|storage_load_movements()|Negative|Malformed<br>movement<br>record|or<br>documented<br>malformed-<br>record|FR-09|
|||||handling||



The first ten tests satisfy the minimum planned test count; additional tests will improve coverage. 

# **14.3 Test Data and Setup** 

- Unit tests will use known motor and mount configurations. 

- Expected results will be calculated independently from the function under test. 

- File-handling tests will use temporary test files. 

- Each test will initialise its own data structures. 

- Temporary files will be removed after the relevant tests. 

- Tests will not depend on the order in which other tests execute. 

- Invalid and boundary values will be included. 

- Floating-point results will be compared using an appropriate tolerance. 

The C++ Google Test files will call the C functions through headers that provide extern "C" linkage guards when compiled as C++. 

# **14.4 Expected Test Command** 

make test 

The test executable will run all registered Google Test cases and display the pass/fail summary. 

# **15. Makefile Design** 

# **15.1 Required Targets** 

**Target Purpose Expected Output** all Compile the complete application Application executable run Execute the application Running AstroMotion CLI test Compile and execute unit tests Google Test results clean Remove generated files Clean source repository 

# **15.2 Build Configuration** 

|**Item**|**Planned Value**|
|---|---|
|C compiler|gcc|
|C++ compiler|g++|
|C standard|C11|
|C++ standard|C++17|
|C compiler flags|-Wall -Wextra -Wpedantic -std=c11|
|C++ compiler flags|-Wall -Wextra -Wpedantic -std=c++17|
|Include path|-Iinclude|



Google Test libraries -lgtest -lgtest_main -pthread 

Application executable build/astromotion 

Test executable build/test_astromotion Object files build/obj/ 

The Makefile will compile C source files separately into object files and link them into the application executable. 

The test executable will link the required C object files with the C++ Google Test framework. 

# **16. Repository Structure** 

The proposed GitHub repository structure is: 

astromotion/ 

| 

- |-- src/ 

- |   |-- main.c 

- |   |-- motor.c 

- |   |-- mount.c 

- |   |-- planner.c 

- |   |-- validation.c 

- |   |-- calibration.c 

- |   |-- storage.c 

- |   `-- report.c 

| 

- |-- include/ 

- |   |-- astro_types.h 

- |   |-- motor.h 

- |   |-- mount.h 

- |   |-- planner.h 

- |   |-- validation.h 

- |   |-- calibration.h 

- |   |-- storage.h 

- |   `-- report.h 

- | 

- |-- tests/ 

- |   |-- test_motor.cpp 

- |   |-- test_mount.cpp 

- |   |-- test_planner.cpp 

- |   |-- test_validation.cpp 

- |   |-- test_calibration.cpp 

- |   `-- test_storage.cpp | 

- |-- data/ 

- |   |-- config.txt 

- |   |-- movements.txt 

- |   `-- calibrations.txt 

| 

- |-- docs/ 

- |   |-- project_proposal.docx 

- |   |-- project_proposal.md 

- |   |-- detailed_design.docx 

- |   |-- detailed_design.md 

- |   |-- architecture.png 

- |   `-- flowcharts.png 

| 

- |-- Makefile 

- |-- README.md 

- `-- .gitignore 

Generated executables, object files and temporary test files will be placed in the build/ directory and excluded from GitHub. 

The final project report may be added to docs/ if required by the course submission instructions. 

# **17. Git and GitHub Plan** 

# **17.1 Repository Information** 

|**Field**|**Value**||
|---|---|---|
|Repository name|astromotion||
|Repository visibility|Public, unless instructed otherwise||
|Main branch|main||
|GitHub link|To be added after repository creation||
|**17.2 Planned Com**|**mit Milestones**||
|**Milestone**|**Planned Commit Message**|**Status**|
|Repository creation|Initialize AstroMotion repository|Planned|
|Data design|Add shared data structures and enums|Planned|
|Core motor module|Implement motor step calculations|Planned|
|Mount and planner|Implement mount positioning and movement plann|ing Planned|
|Validation|Add input and configuration validation|Planned|
|Calibration|Implement calibration error analysis|Planned|
|File handling|Add persistent configuration and record storage|Planned|
|Reports|Implement movement and calibration reports|Planned|
|Unit testing|Add Google Test coverage|Planned|
|Makefile|Add automated build and test targets|Planned|
|Documentation|Complete project documentation and README|Planned|



Commits will be made after meaningful development milestones rather than submitting the entire project in one commit. 

# **17.3 Files to Ignore** 

The .gitignore file will initially contain: 

build/ 

*.o *.out *.exe *.log 

core 

Generated files and temporary test outputs will not be committed. 

# **Design Decisions and Engineering Assumptions** 

# **A. Motor-to-Axis Conversion** 

The gear reduction ratio is defined as: 

# **Gear reduction ratio = Motor revolutions required for one complete mount-axis revolution.** 

The effective motor pulses per degree are: 

[ S = \frac{360}{\theta_s} \times \mu \times \frac{G}{360} ] 

Therefore: 

[ \boxed{S = \frac{\mu G}{\theta_s}} ] 

Where: 

- (S) = effective motor pulses per degree. 

- (\theta_s) = full-step angle in degrees. 

- (\mu) = microstepping factor. 

- (G) = gear reduction ratio. 

For a requested angular displacement: 

[ 

N = \operatorname{round}(|\Delta\theta| \times S) ] 

The direction is stored separately. 

The achievable angular displacement is: 

[ \Delta\theta_{\text{actual,sim}} = \frac{N}{S} ] 

The simulated position is updated using this achievable displacement rather than the original requested value. 

# **B. Movement Duration** 

For each axis: 

[ T_i = \frac{N_i}{f_i} ] 

For simultaneous movement of two independent axes: 

[ 

\boxed{T_{\text{total}} = \max(T_1,T_2)} ] 

This assumes both axes begin moving at the same time and operate at their configured constant pulse frequencies. 

# **C. Calibration Error** 

For each axis: 

[ E_s = \theta_{\text{measured}} - \theta_{\text{commanded}} ] [ E_a = |E_s| ] 

The calibration report will calculate average and maximum absolute error across available records. 

Calibration values are manually entered by the user. The application does not directly measure the telescope's physical position. 

# **D. Simulation Limitations** 

The initial version assumes: 

- Ideal motor movement without missed steps. 

- No mechanical slippage. 

- Constant pulse frequency. 

- No acceleration or deceleration profile. 

- No automatic backlash compensation. 

- Independent two-axis motion. 

- Manually entered calibration measurements. 

The calculated duration is an estimate, not a guarantee of actual hardware performance. 

**End of Phase 2 — Detailed Software Design** 

**Project:** AstroMotion **Engineering Domain:** Astronomy and Electromechanical Systems **Implementation Language:** C **Application Type:** Standalone Command-Line Application 

This design establishes the proposed software modules, data structures, interfaces, validation methods, file formats, testing approach and development workflow for AstroMotion. 

Implementation will begin after reviewing and finalising this design against the actual telescope mount specifications. 

