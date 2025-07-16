# 🚗 Line Follower Robot

As part of university's CSCI205 course, my team and I developed a Line Follower Robot which is an autonomous robot that follows a path drawn with a black line on a white surface (or vice versa). This project uses infrared (IR) sensors to detect the line and control the robot's movement accordingly.

## Components Used

- Arduino Uno
- Line Tracker Module (3 Channels)
- L298N Motor Driver
- DC Motors with wheels
- Chassis
- Two batteries with 3.7 volt each.
- Jumper wires
- Breadboard
- HC-05 Bluetooth module

## How It Works

1. IR Sensors: Detect whether they are over a black or white surface.
2. Arduino: Reads the sensor values and makes decisions.
3. Motor Driver: Drives the motors based on Arduino's commands.
4. The robot adjusts the motor speeds to stay on the line.
5. The Bluetooth module receives 0 or 1 from a mobile app.The Arduino interprets the commands, if it's 0 the robot stops and if 1, it moves.

## Logic

- Black surface absorbs IR light → Sensor gives LOW signal
- White surface reflects IR light → Sensor gives HIGH signal

**The arduino code and a circuit diagram are attached as well as a Demo video.**
