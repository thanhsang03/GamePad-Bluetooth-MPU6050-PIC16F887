// Khai báo chân Arduino được sử dụng
const int motorA1 = 6;
const int motorA2 = 7;
const int motorB1 = 8;
const int motorB2 = 9;
const int speedPinA = 5; // Chân điều khiển tốc độ cho động cơ A
const int speedPinB = 10; // Chân điều khiển tốc độ cho động cơ B

#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(2, 3); // TX Bluetooth - RX 2, RX Bluetooth - TX 3

int value;

void setup() {
  // Khởi tạo cổng serial với baud rate 9600
  Serial.begin(9600);
  // Khởi tạo Bluetooth
  Bluetooth.begin(9600);
  // Khai báo chân là OUTPUT
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  pinMode(speedPinB, OUTPUT);
}

void loop() {
  // Kiểm tra xem có dữ liệu nào được nhận trên cổng serial không
  if (Bluetooth.available() > 0) {
    // Đọc dữ liệu từ cổng serial
    int receivedChar = Bluetooth.read();

    // In dữ liệu đã nhận lên cổng serial
    Serial.print("Received: ");
    Serial.println(receivedChar);

    // Điều khiển robot dựa trên dữ liệu nhận được
    switch(receivedChar) {
      case 3: // Move Forward
        moveForward(150);
        break;
      case 4: // Move Backward
        moveBackward(150);
        break;
      case 1: // Turn Left
        turnLeft(150);
        break;
      case 2: // Turn Right
        turnRight(150);
        break;
      default:
        stopMoving();
        break;
    }

    delay(10);
  }
}

// Hàm di chuyển tiến
void moveForward(int speed) {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);   
  digitalWrite(motorB2, LOW);
  analogWrite(speedPinA, speed); // Điều khiển tốc độ bằng PWM
  analogWrite(speedPinB, speed);
}

// Hàm di chuyển lùi
void moveBackward(int speed) {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(speedPinA, speed); // Điều khiển tốc độ bằng PWM
  analogWrite(speedPinB, speed);
}

// Hàm di chuyển sang trái
void turnLeft(int speed) {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(speedPinA, speed); // Điều khiển tốc độ bằng PWM
  analogWrite(speedPinB, speed);
}

// Hàm di chuyển sang phải
void turnRight(int speed) {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(speedPinA, speed); // Điều khiển tốc độ bằng PWM
  analogWrite(speedPinB, speed);
}

// Hàm dừng di chuyển
void stopMoving() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  analogWrite(speedPinA, 0);
  analogWrite(speedPinB, 0);
}
