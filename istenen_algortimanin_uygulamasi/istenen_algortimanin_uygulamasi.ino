const int motorPin = 12;  // PWM pin for motor speed control (e.g. D14)
const int pwmFrequency = 5000;  // Determine PWM frequency (e.g. 1000 Hz)
const int pwmChannel = 1;  // Set PWM channel
const int resolution = 8;  // Set PWM resolution (8 bit)

void setup() {
  Serial.begin(115200); // Configure baud rate

  pinMode(motorPin, OUTPUT); // Set pin mode
  ledcSetup(pwmChannel, pwmFrequency, resolution);  // Set PWM channel
  ledcAttachPin(motorPin, pwmChannel);  // Connect PWM channel to motor
  ledcWrite(pwmChannel, 0);  // Set speed to zero at startup
}

void loop() {
  // You can adjust the engine speed as you wish, for example:
  ledcWrite(pwmChannel,0); // Determine motor channel and speed
  Serial.println("hız:0"); // print to serial monitor
  delay(2000);  // Allows the engine to run at this speed for 2 seconds

  for(int speed=0; speed <= 200; speed += 10) { // max engine speed is 230 rpm, so 200 rpm was chosen to avoid stressing the engine

    ledcWrite(pwmChannel, speed); // Determine motor channel and speed
    delay(500); // Allows the engine to run at this speed for 0.5 seconds
    Serial.println(speed); // print to serial monitor
  }

  delay(5000); // wait 5 seconds

  for(int speed = 200; speed >= 0; speed -=10) { // Decrease 10 rpm from the motor's max speed to zero

    ledcWrite(pwmChannel, speed); // Determine motor channel and speed
    delay(500); // Allows the engine to run at this speed for 0.5 seconds
    Serial.println(speed); // print to serial monitor
  }
}
