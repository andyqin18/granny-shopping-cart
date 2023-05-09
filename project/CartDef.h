// Blynk Auth
char auth[] = "KcYzmEOHinr5Hmq0-90VSWcYxmUEVORP";

// Pin variables
// #define SERVO_PIN 3

#define GPS_TX_PIN 7
#define GPS_RX_PIN 6

#define BLUETOOTH_TX_PIN 10
#define BLUETOOTH_RX_PIN 11

#define MOTOR_A_EN_PIN 5
#define MOTOR_B_EN_PIN 9
#define MOTOR_A_IN_1_PIN 2
#define MOTOR_A_IN_2_PIN 3
#define MOTOR_B_IN_1_PIN 13
#define MOTOR_B_IN_2_PIN 12

// If one motor tends to spin faster than the other, add offset
#define MOTOR_A_OFFSET 0
#define MOTOR_B_OFFSET 0

// Add  'Declination Angle' to the compass, which is the 'Error' of the magnetic field here
#define DECLINATION_ANGLE -0.218f

// The offset of the mounting position to true north
#define COMPASS_OFFSET 0.0f

// How often the GPS should update in MS
#define GPS_UPDATE_INTERVAL 5000

// Number of changes in movement to timeout for GPS streaming
#define GPS_STREAM_TIMEOUT 1000

// Definitions (don't edit these)
struct GeoLoc {
  float lat;
  float lon;
};

