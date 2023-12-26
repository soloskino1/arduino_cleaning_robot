**DEVELOPMENT OF A CLEANING ROBOT**

**Introduction:**

In recent years, the use of robots has increased, and many fields have been affected by the automation revolution. The cleaning industry is no exception. Cleaning robots have become a popular alternative to traditional cleaning methods. This report outlines the development of a cleaning robot. The robot consists of various components, including motors, sensors, and a microcontroller which the code is uploaded to. The report will focus on the scenario in which the system can be used, the motor characteristics and control, ways to control the motor, the capabilities of the microcontroller, a list of the sensors and their connections to the microcontroller, and the circuits.

<a name="_heading=h.gjdgxs"></a>**Scenario:** 

This cleaning robot is designed to be used in an enclosed space or room that may or may not have obstacles although it is designed for obstacle avoidance. The robot will be used in cleaning a room whose floor is considerably smooth and the dirt on it are little particles or dirt that can be easily swept underneath the robot. It is not to be used on a wet floor as the liquid may cause slips and also damage the electrical components of the robot. The system is semi-autonomous as it may require the help of an individual to redirect it using a remote controller whenever it gets stuck and is unable to navigate properly.

<a name="_heading=h.bqoujgpeshi"></a>**Skills of the Cleaning robot**

<a name="_heading=h.ozjmcd3jp8pf"></a>The following are the skills this robot would have 

- <a name="_heading=h.5bj8hub4pn4m"></a>The ability to navigate around obstacles, avoid collisions, and efficiently move throughout the space.
- <a name="_heading=h.l7e2t1eyk0ly"></a>The ability to detect dirt, dust, and other debris that needs to be cleaned, as well as the ability to sense walls and other boundaries.
- <a name="_heading=h.xi65n4va3voc"></a>The ability to effectively clean surfaces, such as floors, carpets, and countertops, using its cleaning brushes.
- <a name="_heading=h.4hh25xsbf974"></a>The ability to communicate with users
- <a name="_heading=h.lwbtzkd0ya6b"></a>The ability to operate efficiently and easily

**Motor Characteristics and Control:**

The robot uses three types of motors, namely:

2 x Adafruit TT DC BO Gearbox Motor with wheels to move the robot

2 x  DC motors to drive the cleaning bushes

1 BLDC motor to drive the cleaning vacuum fan

**Adafruit TT DC BO Gearbox Motor**: These DC motors have a gear ratio of 1:48 which can be powered with 3VDC - 6VDC. But for our application, we would be using 5V. At 4.5V they have about 155mA @ 185 RPM with no load and 1.2A when stalled. These motors give good torque at low operating voltages which makes them desirable for our application. These motors are connected to a motor driver (L298N) which is controlled by the microcontroller.  More information on the motors can be found at <https://www.adafruit.com/product/3777>.

**DC motor:** These motors are being used to drive the cleaning brushes which sweep the floor. Their connection is controlled using a MOSFET (IRT Z44 motor speed controller) and a potentiometer. They are not connected to the microcontroller since their directions and speed will be constant throughout the whole cleaning operation.

**BLDC motor**: the BLDC (Brushless DC) Motor is used to create a vacuum effect by sucking the air which in turn sucks the dirt that is being collected by the cleaning brushes. This motor which is also known as an electronically commutated motor, is a synchronous motor powered by direct current. It employs an electronic controller to switch DC currents to the motor windings, thereby generating magnetic fields that revolve in space and are followed by the permanent magnet rotor. The controller modifies the phase and amplitude of the DC current pulses in order to regulate the motor's speed and torque. A2212 Brushless Motor 2200KV Out runner Brushless is considered in our application. The brushless motor is being connected to an ESC (Electronic Speed Controller) which is controlled by the microcontroller.  The BLDC used is [on this site](https://www.amazon.co.uk/Kyrio-Accessories-Quadcopter-Helicopter-Multi-Copter/dp/B08N9YXF8R/ref=asc_df_B08N9YXF8R/?tag=googshopuk-21&linkCode=df0&hvadid=499390140884&hvpos=&hvnetw=g&hvrand=13036817868340196189&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=1006897&hvtargid=pla-1249141758877&psc=1)

**Other Components of the Robot**

**HC-SR04 Ultrasonic Sensor**: It is required that the robot is able to detect obstacles, walls and other boundaries. Three ultrasonic sensors are used in this application to detect obstacles which may be in front or by the side of the robot. This economical sensor provides 2cm to 400cm of non-contact measurement functionality with a ranging accuracy that can reach up to 3mm. Each ultrasonic sensor has four pins which are the VCC (Power), Trig(Trigger), Echo(Receive) and the GND ground. The three ultrasonic sensors will need 6 digital pins on the microcontroller. The sensor can be found [here](https://www.sparkfun.com/products/15569)

**IR Obstacle Avoidance Sensor**: This is used to prevent the robot from falling off stairs or any other steep surface. The detection distance of the infrared module is 2 to 30 cm which is very suitable for our use as we would tell the robot to stop only when the distance between the robot base and the floor is 5 cm. So the IR sensor would be placed at a 1cm distance from the floor to avoid false signals. The ir sensor is [here](https://www.amazon.co.uk/Avoidance-Reflective-Photoelectric-Compatible-Raspberry/dp/B08DR1W3BK/ref=asc_df_B08DR1W3BK/?tag=googshopuk-21&linkCode=df0&hvadid=463011051724&hvpos=&hvnetw=g&hvrand=17082117727449330047&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=1006897&hvtargid=pla-960333098377&psc=1)

**HC-05 Bluetooth module:** The HC-05 Bluetooth module is used to enable remote control of the robot using a smartphone or any other Bluetooth-enabled device. In this application, we assume that the Bluetooth device is sending characters F - to move front, L - to turn left, R- to turn right, B - to move back. More information on the bluetooth mode is [here](https://components101.com/sites/default/files/component_datasheet/HC-05%20Datasheet.pdf)

**L298N Motor Driver Module:** This module is an H-bridge two-channel type driver that drives the two TT dc motors of the robot. Driver voltage is 5V to 35V, and the drive current is 2A. It is perfect for our application as the operating voltages are within the range of the motor driver. The L298N also has built-in protection features, such as over-current and over-temperature protection, which help to ensure safe and reliable operation. They are also easy to use with Arduino microcontroller which is used for this project. More information is [here](https://components101.com/modules/l293n-motor-driver-module)

**RS pro 11.1V Li-ion Battery:** This batter is used to power the Arduino while other components get their power form the Arduino. The battery provides enough power for the system to operate for a considerable time without having to recharge. The battery is also rechargeable battery which is desirable for our application.

**Arduino Mega Microcontroller:**

Arduino Mega is suitable for this application mainly due to its higher processing power and increased number of input/output (I/O) pins compared to the Arduino Uno.

The Arduino Mega has 54 digital I/O pins and 16 analog input pins, which is significantly more than the 14 digital I/O pins and 6 analog input pins of the Arduino Uno. This provides greater flexibility for connecting sensors and other peripherals, as well as for controlling multiple motors and servos.

Additionally, the Arduino Mega is equipped with a more powerful microcontroller, the ATmega2560, which has 256 KB of flash memory and 8 KB of SRAM. This allows for larger and more complex programs to be written and executed, which is necessary for the autonomous navigation and obstacle avoidance functions required in the application.

Overall, the increased processing power and I/O capabilities of the Arduino Mega make it a suitable choice for this application, particularly when dealing with multiple sensors, motors, and control functions.

**Connections**

![](Aspose.Words.b00b257d-a6a4-4f49-9b98-9f1eb1cb378d.001.png)

*Schematic of the connections to the microcontroller*

The figure above is a rough diagram showing how the components can be connected together. It was designed on circuito.io

The connection to the microcontroller is as follows:

- Three HC-SR04 Ultrasonic Sensors:
  - Trigger pin for front sensor - Digital pin 2
  - Echo pin for front sensor - Digital pin 3
  - Trigger pin for left sensor - Digital pin 4
  - Echo pin for left sensor - Digital pin 5
  - Trigger pin for right sensor - Digital pin 6
  - Echo pin for right sensor - Digital pin 7
- IR Sensor:
  - Signal pin - Analog pin A0
- L298N Motor Driver Module:
  - IN1 pin - Digital pin 8
  - IN2 pin - Digital pin 9
  - IN3 pin - Digital pin 10
  - IN4 pin - Digital pin 11
- ESC and 10k Potentiometer:
  - Signal pin for ESC - Digital pin 12
  - Potentiometer pin - Analog pin A1
  - The ESC and potentiometer are used to control the speed of a BLDC motor that drives the vacuum of the cleaning robot.
- HC-05 Bluetooth Module:
  - RX pin - Digital pin 13
  - TX pin - Digital pin 14
  - The HC-05 Bluetooth module is used to provide an alternative way to control the robot using a Bluetooth controller.

These pins were chosen based on their availability on the Arduino Mega and their suitability for the respective components. For example, ultrasonic sensors require both digital input and output pins for triggering and reading echoes, while the IR sensor uses an analog input pin to measure the intensity of reflected infrared light. The L298N motor driver module requires four digital output pins to control the two motors, and the HC-05 Bluetooth module communicates with the Arduino Mega through digital RX and TX pins. An Arduino Uno would have been just sufficient for this usage however an Arduino mega creates room for more sensors or components that may be added for future development.

The cleaning motor circuit: The cleaning dc motors are not connected to the microcontroller as they are expected to keep working as long as the robot is switched on. They are connected to a potentiometer (powered by the batter) which is interfaced with the MOSFET.
