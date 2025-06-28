#define left 6
#define center 7
#define right 8

// Motor one
#define IN1 11  // PWM capable
#define IN2 10

// Motor two
#define IN3 9  // PWM capable
#define IN4 3

int speed = 170;  // Speed value from 0 (stopped) to 255 (full speed)

bool isRunning = false;  // Bluetooth control flag

void setup() {
  Serial.begin(9600); // initialize communication with bluetooth
  pinMode(left, INPUT);
  pinMode(center, INPUT);
  pinMode(right, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Read Bluetooth commands
  if (Serial.available()) {
    char command = Serial.read();
    if (command == '1' && isRunning == false) {
      isRunning = true;
      Serial.println("Start command received");
    } else if (command == '0' && isRunning == true) {
      isRunning = false;
      carStop();
      Serial.println("Stop command received");
    }
  }

  // Only follow line if running
  if (isRunning) {
    bool leftV = digitalRead(left);
    bool centerV = digitalRead(center);
    bool rightV = digitalRead(right);

    if (leftV == 1 && centerV == 0 && rightV == 1) {
      carForward();
      Serial.println("forward");
    } else if (leftV == 1 && centerV == 1 && rightV == 1) {
      carStop();
      Serial.println("stop (all sensors 1)");
    } else if (leftV == 1 && rightV == 0) {
      carTurnLeft();
      Serial.println("left");
    } else if (leftV == 0 && rightV == 1) {
      carTurnRight();
      Serial.println("right");
    } else if (leftV == 0 && centerV == 0 && rightV == 0) {
      carForward();
      Serial.println("forward (all sensors 0)");
    }
  } else {
    carStop();  // Make sure it stops if not running
  }
}

// Motor control functions using PWM
void carForward() {
  analogWrite(IN1, speed);  // Motor A forward
  digitalWrite(IN2, LOW);
  analogWrite(IN3, speed);  // Motor B forward
  digitalWrite(IN4, LOW);
}

void carTurnLeft() {
  digitalWrite(IN1, LOW);       // Motor A reverse
  analogWrite(IN2, speed);
  analogWrite(IN3, speed);      // Motor B forward
  digitalWrite(IN4, LOW);
}

void carTurnRight() {
  analogWrite(IN1, speed);      // Motor A forward
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);       // Motor B reverse
  analogWrite(IN4, speed);
}

void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}