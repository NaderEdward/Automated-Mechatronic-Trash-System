// Direct Pin Mapping based on physical wiring
const int IN1 = 2;       // L298N Motor A Direction 1
const int IN2 = 3;       // L298N Motor A Direction 2
const int IN3 = 4;       // L298N Motor B Direction 1
const int IN4 = 5;       // L298N Motor B Direction 2
const int ENA = 6;       // L298N Motor A PWM Speed Enable
const int ENB = 7;       // L298N Motor B PWM Speed Enable

const int TRIG_PIN = 11; // HC-SR04 Ultrasonic Trigger
const int ECHO_PIN = 12; // HC-SR04 Ultrasonic Echo

// Operational Parameters
const float SENSOR_THRESHOLD_CM = 15.0; // Detection threshold (cm)
const unsigned long EXTEND_TIME_MS = 1200;  // Time needed to push QR code out
const unsigned long DISPLAY_HOLD_MS = 5000; // Time QR code stays exposed for scanning
const unsigned long RETRACT_TIME_MS = 1200; // Time needed to pull QR code back in
const unsigned long REARM_LOCKOUT_MS = 2000;// Debounce/reset delay
const int PWM_SPEED = 220;                // Motor speed profile (0–255)

float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return 999.0;

  return (duration * 0.0343) / 2.0;
}

// Motor State Handlers
void extendQRCode() {
  analogWrite(ENA, PWM_SPEED);
  analogWrite(ENB, PWM_SPEED);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void retractQRCode() {
  analogWrite(ENA, PWM_SPEED);
  analogWrite(ENB, PWM_SPEED);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  stopMotors();
  Serial.begin(9600);
}

void loop() {
  float distance = measureDistance();

  if (distance > 0.0 && distance <= SENSOR_THRESHOLD_CM) {
    Serial.print("Basket Made! Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Phase 1: Extend QR Code display
    extendQRCode();
    delay(EXTEND_TIME_MS);
    stopMotors();

    // Phase 2: Hold exposed for scanning
    delay(DISPLAY_HOLD_MS);

    // Phase 3: Retract QR Code display
    retractQRCode();
    delay(RETRACT_TIME_MS);
    stopMotors();

    // Phase 4: Lockout before re-arming
    delay(REARM_LOCKOUT_MS);
  }

  delay(60);
}