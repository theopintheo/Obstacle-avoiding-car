# 🚗✨ Obstacle Avoiding Car ✨🚗

Welcome to the **Obstacle Avoiding Car** project!  
This Arduino-powered robot car uses an ultrasonic sensor mounted on a servo to scan its environment, detecting and dodging obstacles all on its own.  
Perfect for robotics beginners and tinkerers!

---

## 🛠️ Features

- **Automatic Obstacle Avoidance**  
  Moves forward, senses obstacles, and turns toward the safer direction—completely hands-free!
- **Ultrasonic Distance Sensing**  
  Uses the HC-SR04 to spot obstacles up to 2 meters away.
- **Servo Scanning**  
  Rotates the sensor left and right to "look" for open paths.
- **Simple Motor Controls**  
  Basic two-wheel drive (forward, stop, left, right).

---

## 🔌 Hardware You’ll Need

| Component                | Arduino Pin      |
|--------------------------|:---------------:|
| **Servo Signal**         | D3              |
| **Ultrasonic Trigger**   | D12             |
| **Ultrasonic Echo**      | D11             |
| **Left Motor Forward**   | D6              |
| **Left Motor Backward**  | D5              |
| **Right Motor Forward**  | D10             |
| **Right Motor Backward** | D9              |

**Other parts:**  
- Arduino Uno (or compatible board)  
- 2x DC Motors + Motor Driver  
- HC-SR04 Ultrasonic Sensor  
- SG90 Servo (or similar)  
- Power supply, wires, and chassis

---

## 📦 Libraries Required

- [`Servo`](https://www.arduino.cc/en/Reference/Servo) (standard Arduino library)
- [`NewPing`](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home)

_Install via Arduino IDE Library Manager or download manually._

---

## 🚦 How It Works

1. **Go, Go, Go!**  
   The car moves forward by default.
2. **Obstacle Detected!**  
   If something is closer than 20 cm, the car stops.
3. **Scan Left & Right**  
   The servo rotates to check distances on both sides.
4. **Decision Time**  
   The car turns toward the direction with more space and resumes driving.

---

## ⚡ Quick Start

1. **Wire up** everything according to the pinout above.
2. **Install** the required libraries in your Arduino IDE.
3. **Upload** `Code.ino` to your Arduino.
4. **Power up** the car and watch it dodge obstacles!

---

## 🧑‍🔬 Customization Tips

- **Change detection distance:**  
  Edit `if (distance > 0 && distance < 20)` in the code to your preferred avoidance distance.
- **Turn time:**  
  Adjust the `delay(500);` in `turnLeft()` and `turnRight()` for sharper or wider turns.

---

## 🖼️ Demo

![Obstacle Avoiding Car GIF](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExY2N5d3M2eHc2N2dwcnppZ3ZzMG5nOWd0d2FveXFkN2JodWQyM2Q2ZCZlcD12MV9naWZzX3NlYXJjaCZjdD1n/H4w1Fh7iJ8y4Y/giphy.gif)

---

## 📜 License

Open source and open to all!  
Feel free to use, modify, or share.

---

**Made with ❤️ by [theopintheo](https://github.com/theopintheo)**
