# **PHASE 1 — PROJECT PROPOSAL** 

# **AstroMotion** 

# **Two-Axis Telescope Mount Motion Planner and Calibration Simulator** 

**Course:** Automotive Embedded Minor **Engineering Domain:** Astronomy and Electromechanical Systems 

# **1. Project Information** 

# **1.1 Project Title** 

# **AstroMotion: Two-Axis Telescope Mount Motion Planner and Calibration Simulator** 

# **1.2 Engineering Domain** 

Astronomy, Electromechanical Systems and Motion Control. 

# **1.3 Student Details** 

|**Field**|**Details**|
|---|---|
|Student Name|Aaditya Mahesh Narkhedkar|
|Roll Number|612507002|
|Division / Batch|Entc Div 1, Batch 1|
|Repository Name|astromotion|



GitHub Repository Link To be created 

# **1.4 Individual Project Declaration** 

I confirm that this project is my individual work. I understand the design, source code, unit tests, Makefile and documentation included in this repository, and I am prepared to explain or modify any part during evaluation. 

# **Student acknowledgement:** 



# **2. Engineering Scenario** 

# **2.1 Scenario Description** 

Astronomical telescopes use mechanical mounts to control their orientation and point towards celestial objects. Motorized telescope mounts commonly employ stepper motors coupled with mechanical transmission systems such as gears and worm drives to achieve controlled angular movement. 

The accuracy of such systems depends on several parameters, including the motor step angle, microstepping factor, gear reduction ratio and motor pulse frequency. 

In the context of telescope mount development, understanding the relationship between motor rotation and the resulting angular displacement of the telescope is essential. 

Determining the required motor rotations, calculating angular displacement and understanding the effect of mechanical transmission are important aspects of developing and operating such a system. Currently, these calculations may need to be performed manually, making it difficult to repeatedly evaluate different motor configurations and movement requirements. 

A dedicated software application can simplify these calculations, simulate the expected movements and help evaluate positioning accuracy through calibration records. The proposed application will provide a unified environment for configuring, planning and analysing telescope mount movements. 

# **2.2 Problem Statement** 

In astronomical telescope mount development, students and developers working with motorized telescope mounts face difficulties in calculating and managing the relationship between stepper motor movements and the resulting angular displacement of the telescope. 

Manual calculations involving motor step angle, microstepping and mechanical gear reduction can become repetitive and error-prone. Furthermore, theoretical movement calculations alone do not provide a convenient way to maintain movement records or evaluate positioning discrepancies through calibration measurements. 

The proposed software will provide configurable motor and mount parameters, automated movement calculations, two-axis positioning simulation, mechanical limit validation and calibration analysis so that users can plan telescope movements and evaluate their expected positioning performance efficiently. 

# **2.3 Proposed Solution** 

AstroMotion is a modular C-based application designed to calculate, plan and simulate the angular movement of a two-axis telescope mount driven by stepper motors. 

The application will allow users to configure motor specifications, microstepping factors, mechanical gear reduction ratios and axis movement limits. 

Based on these parameters, the application will calculate the motor steps required to achieve a specified angular displacement along either axis. 

The application will also estimate movement duration using the configured motor pulse frequency and simulate the resulting telescope mount position. 

In addition, AstroMotion will maintain movement and calibration records. Users will be able to enter calibration measurements, compare measured angular displacement with theoretical displacement and analyse positioning errors. 

The application will provide file-based storage, movement history, searchable records and performance reports. 

The initial implementation will be a standalone command-line application. Physical motor control and sensor integration will not be required. 

# **Major calculations and operations** 

1. Calculation of effective motor steps per degree. 

2. Calculation of required motor steps for a specified angular displacement. 

3. Estimation of movement duration. 

4. Validation of requested movements against mechanical limits. 

5. Simulation of current telescope mount position. 

6. Calculation of angular positioning error using calibration measurements. 

# **Expected outputs** 

- Required motor steps for each axis. 

- Estimated movement duration. 

- Updated simulated mount position. 

- Movement validation status. 

- Movement history. 

- Calibration error and positioning accuracy reports. 

# **2.4 Target Users** 

|**User Type**|**Responsibility**|**Application Usage**|
|---|---|---|
|Telescope Mount|Operate and develop telescope|Calculate and simulate telescope|
|Developers|mounts|movements|
|Astronomy Club|Design and evaluate motorized|<br>Configure motor parameters and|
|Members|mounts|analyse positioning requirements|



Engineering Study stepper motor-based Understand gear ratios, angular Students positioning systems displacement and calibration 

# **3. Project Scope** 

# **3.1 In-Scope Features** 

1. Configuration and management of stepper motor specifications, including step angle and pulse frequency. 

2. Configuration of mechanical gear reduction and microstepping factors. 

3. Calculation of effective steps per degree and required motor steps. 

4. Two-axis angular movement planning. 

5. Estimation of motor movement duration. 

6. Validation of requested movements against configurable mechanical limits. 

7. Simulation of telescope mount movement and current position tracking. 

8. Storage and retrieval of movement records. 

9. Calibration record management and positioning error calculation. 

10. Searching, sorting and generating movement and calibration reports. 

# **3.2 Out-of-Scope Features** 

1. Direct control of physical stepper motors and motor driver hardware. 

2. Real-time celestial object tracking and automatic star positioning. 

3. GPS-based positioning and astronomical coordinate conversion. 

4. Advanced acceleration and deceleration profiling. 

5. Automated backlash compensation. 

6. Graphical user interface and real-time hardware sensor integration. 

These features may be considered for future development. 

# **3.3 Assumptions** 

1. The telescope mount consists of two independently controlled rotational axes. 

2. Each axis is driven by a stepper motor through a mechanical transmission system. 

3. Motor specifications, microstepping factors and gear reduction ratios are known or can be configured by the user. 

4. Motor movement is initially assumed to be ideal, with no missed steps or mechanical slippage during simulation. 

5. Movement duration is estimated using a constant configured pulse frequency. 

6. Calibration measurements are entered manually by the user rather than obtained from physical sensors. 

7. Angular displacement is expressed in degrees, and motor pulse frequency is expressed in pulses per second. 

8. The gear reduction ratio is defined as the number of motor revolutions required for one complete revolution of the corresponding mount axis. 

# **3.4 Constraints** 

1. The application will be developed using the C programming language. 

2. The application will use a command-line interface. 

3. Data persistence will be implemented using local files rather than a database. 

4. The application will operate independently of physical telescope hardware. 

5. The implementation will use fixed, documented limits for record storage and input sizes wherever appropriate. 

6. The project must be completed within the available academic mini-project duration. 

7. Automated unit testing must be implemented using Google Test, with test files permitted to use C++. 

# **4. Requirements** 

# **4.1 Functional Requirements** 

|**ID**<br>**Functional Requirement**|**Priority**|<sup>**Verification**</sup><br>**Method**|
|---|---|---|
|FR-0<br>1<br>The system shall allow users to configure stepper motor<br>specifications.|High|Demonstration /<br>Test|
|FR-0<br>The system shall store the mechanical gear reduction ratio|Hih|Demonstration /|
|2<br>and microstepping factor for each axis.|g|Test|
|FR-0 The system shall calculate the effective motor steps|High|Unit Test|



|3<br>required per degree of mount rotation.||
|---|---|
|FR-0<br>The system shall accept desired angular displacement for|Hih<br>Demonstration /|
|4<br>both mount axes.|g<br>Test|
|FR-0<br>The system shall calculate the required motor steps for|Hih<br>Unit Test|
|5<br>each requested angular movement.|g<br>|
|FR-0<br>The system shall estimate movement duration using the|Medium Unit Test|
|6<br>configured pulse frequency.||
|FR-0<br>7<br>The system shall validate movement requests against<br>configured mechanical limits.|High<br>Unit Test|
|FR-0<br>The system shall simulate mount movement and update the|<br>Hih<br>Demonstration /|
|8<br>current simulated position.|g<br>Test|
|FR-0<br>The system shall store and retrieve movement records|Hih<br>Demonstration /|
|9<br>using local files.|g<br>Test|
|FR-1<br>The system shall allow users to enter and maintain|Mdi<sup>Demonstration /</sup>|
|0<br>calibration measurements.|eum<br>Test|
|FR-1<br>1<br>The system shall calculate positioning errors by comparing<br>theoretical and measured angular displacement.|Medium Unit Test|
|FR-1<br>The system shall generate movement and calibration|Mdi<sup>Demonstration /</sup>|
|2<br>performance reports.|eum<br>Test|
|FR-1<br>The system shall support searching and sorting of stored|L<br>Demonstration /|
|3<br>movement records.|ow<br>Test|
|**4.2 Non-Functional Requirements**||
|**ID**<br>**Non-Functional Requirement**|**Verification Method**|
|NFR-0<br>The source code shall compile without warnings using str|ict<br>Bild tt|
|1<br>compiler flags.|u oupu|
|NFR-0<br>2<br>The application shall use a modular multi-file architecture|.<br>Code review|
|NFR-0<br>3<br>Invalid user inputs shall be handled without crashing the<br>application.|Negative testing|
|NFR-0<br>Important functions shall be independently testable using|Ui i|
|4<br>Google Test.|nt-test executon|
|NFR-0<br>5<br>The project shall support automated compilation and testi<br>through a Makefile.|ng<br>Build demonstration|



|NFR-0<br>6|The application shall maintain persistent records through file<br>handling.|<br>File-operation testing|
|---|---|---|
|NFR-0<br>7|The application shall use consistent naming conventions and<br>coding standards.|Code review|
|NFR-0<br>8|The application shall use appropriate floating-point precision<br>for angular and motor calculations.|<br>Calculation verification|
|NFR-0|The application shall provide meaningful error messages for|Error-handling|
|9|invalid operations and file failures.|demonstration|
|NFR-1<br>0|The application shall be documented sufficiently for another<br>developer to build, run and test it.|Documentation review|



# **4.3 Initial Requirement Traceability** 

The following is a preliminary mapping. Function names and test identifiers will be finalized during Phase 2. 

**Requirement ID Planned Module Planned Function / Feature** 

|**Requirement ID Planned Modu**|**le Planned Function / Feature**|**Test ID**|
|---|---|---|
|FR-01<br>Motor|Motor configuration|UT-01|
|FR-02<br>Mount|Axis configuration|UT-02|
|FR-03<br>Motor|Steps-per-degree calculation|UT-03|
|FR-04<br>Planner|Angular movement input|—|
|FR-05<br>Planner|Motor step calculation|UT-04|
|FR-06<br>Planner|Movement duration estimation|UT-05|
|FR-07<br>Validation|Mechanical limit validation|UT-06|
|FR-08<br>Mount|Position simulation|UT-07|
|FR-09<br>File Handler|Save and load movement records|—|
|FR-10<br>Calibration|Calibration record management|—|
|FR-11<br>Calibration|Positioning error calculation|UT-08|
|FR-12<br>Report|Performance report generation|—|
|FR-13<br>Report|Movement record searching and sorting|—|



The traceability mapping will be expanded after the detailed function design and unit-test plan are prepared. 

# **5. High-Level Architecture** 

# **5.1 Architecture Description** 

AstroMotion will follow a modular software architecture consisting of an application interface, configuration and validation modules, motion-planning logic, positioning simulation, calibration management and file-based storage. 

The main application module will coordinate user interactions and invoke the required functions from other modules. 

The motor module will handle motor specifications and motor-step calculations. The mount module will maintain axis configurations, movement limits and simulated positions. 

The planner module will calculate the motor steps and estimated duration for requested movements. The validation module will verify that the input parameters and movement requests are valid. 

The calibration module will maintain calibration measurements and calculate positioning errors. The report module will process stored records and generate useful performance summaries. 

The file-handling module will provide persistent storage and retrieval of application data. 

The architecture will separate application control, engineering calculations, data management and file operations to improve maintainability and testability. 

# **5.2 Initial Architecture Diagram** 



<!-- Start of picture text -->
Software Architecture Diagram: fe)<br>Control and Simulation System a<br>INPUTS:<br>COMMAND-LINE INTERFACE<br>—_— = (curcanes comnts, Pete)<br>——<br>ee)<br>Or Actes md | | (vk: hess wp ses)<br>Votinslan pete PATH PLANNER:<br>POSITION SIMULATION<br>(eg. Virwal Arm,Movement)<br>censor REGAN)[ ENTREE] rns<br>LOCAL STORAGE<br>Bae Sree<br><!-- End of picture text -->

# **5.3 High-Level Workflow** 

The application will follow the workflow below: 

1. **Application Start:** Initialise the application and required data structures. 

2. **Load Configuration:** Retrieve previously saved motor, mount and calibration information. 

3. **Display Main Menu:** Present the available operations to the user. 

4. **Configuration:** Allow the user to configure motor and mount parameters. 

5. **Movement Input:** Accept the desired angular displacement for the two axes. 

6. **Input Validation:** Validate motor parameters, angular displacement and mechanical limits. 

7. **Movement Calculation:** Calculate the required motor steps and estimated movement duration. 

8. **Position Simulation:** Simulate the movement and update the current mount position. 

9. **Record Management:** Save the movement information and update stored records. 

10. **Calibration:** Allow the user to enter calibration measurements and evaluate positioning errors. 

11. **Report Generation:** Display movement history and calibration reports. 

12. **Application Exit:** Save necessary data, release resources and terminate the application. 

# **End of Phase 1 — Project Proposal** 

**Project:** AstroMotion **Engineering Domain:** Astronomy and Electromechanical Systems **Implementation Language:** C **Application Type:** Standalone Command-Line Application **Storage:** Local File-Based Storage **Testing Framework:** Google Test 

The proposed application aims to demonstrate the practical application of C programming and software engineering principles to the engineering problem of stepper motor-based telescope positioning. 

The project will be developed through requirements analysis, detailed software design, modular implementation, automated testing and documentation. 

