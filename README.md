# SPI Communication Project with ATmega32

This project involves communication between three ATmega32 microcontrollers using the Serial Peripheral Interface (SPI) protocol. The master controller is connected to two slave controllers, and based on button presses on the master, corresponding LEDs are illuminated on the slaves.

## Components Used

- **ATmega32 Microcontrollers**: Three microcontrollers are used for master and two slave devices.
- **Push Buttons**: Connected to the master controller to trigger actions.
- **LEDs**: Indicate the state of each slave device.
- **SPI Protocol**: Utilized for communication between the master and slave controllers.

## Project Structure

- **Master Controller (master.c)**
  - Monitors two push buttons.
  - Sends '0' to Slave 1 if Button 1 is pressed.
  - Sends '0' to Slave 2 if Button 2 is pressed.
  - Sends '1' if no button is pressed.
  - Sends '0' if both buttons are pressed simultaneously.

- **Slave 1 (slave1.c)**
  - Listens for data from the master through SPI.
  - Illuminates an LED if the received data is '0'.
  - Turns off the LED if the received data is '1'.

- **Slave 2 (slave2.c)**
  - Listens for data from the master through SPI.
  - Illuminates an LED if the received data is '0'.
  - Turns off the LED if the received data is '1'.

## Wiring Configuration

- **Master Controller**
  - Button 1 -> Pin A0
  - Button 2 -> Pin A1
  - Slave 1 LED -> Pin B3
  - Slave 2 LED -> Pin B4

- **Slave 1**
  - LED -> Pin B0

- **Slave 2**
  - LED -> Pin B0

## How to Use

1. Connect the microcontrollers according to the wiring configuration , (Protues Simulation is included).
2. Upload the provided code to each microcontroller.
3. Power on the circuit.
4. Press Button 1 on the master to control Slave 1 LED.
5. Press Button 2 on the master to control Slave 2 LED.
6. Press both buttons simultaneously to control both Slave 1 and Slave 2 LEDs.

## Repository Structure

- `master.c`: Code for the master controller.
- `slave1.c`: Code for Slave 1.
- `slave2.c`: Code for Slave 2.
- `MCAL/`, `HAL/`, `LIB/`: Folders containing microcontroller abstraction layers, hardware abstraction layers, and utility libraries.
- `README.md`: This file.


