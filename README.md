# Arduino Temperature Controller

A simple yet practical project that uses an Arduino UNO to automatically control the ambient temperature. This system reads the temperature from a sensor, displays it on a 7-segment display, and controls a cooling fan and a heater based on predefined thresholds.

## Features

-   **Live Temperature Display:** Shows the current ambient temperature in Celsius on two 7-segment displays.
-   **Automatic Fan Control:** If the temperature rises above 30°C, the cooling fan turns on automatically and stays on until the temperature drops back to 25°C.
-   **Automatic Heater Control:** If the temperature falls below 20°C, the heater turns on automatically and stays on until the temperature rises back to 25°C.
-   **LED Simulation:** The fan and heater operations are simulated using two distinct LEDs.
-   **Serial Data Output:** Continuously sends temperature data to the computer, which can be visualized using the Arduino Serial Plotter.

---

## Components Required

| Component                  | Quantity |
| :------------------------- | :------: |
| Arduino Uno Board          |    1     |
| LM35 (or TMP36) Sensor     |    1     |
| 7-Segment Display (Common Cathode) |    2     |
| LEDs (any color)           |    2     |
| 220 Ohm Resistor           |    2     |
| Breadboard                 |    1     |
| Jumper Wires               | Several  |

---

## Tools and Software

This project was developed and tested using the following tools:

-   **Programming Language:** C++ (in the Arduino environment)
-   **IDE:** Arduino IDE
-   **Simulation Environment:** Autodesk Tinkercad (Web-based)
-   **Hardware:** Arduino Uno

---

## Wiring Diagram

You can find the complete circuit diagram for this project below:

*(Here you can add a screenshot of your circuit or simulation)*
``

---

## Getting Started

1.  **Hardware Setup:** Assemble the circuit on a breadboard according to the wiring diagram.
2.  **Software Setup:**
    * Open the project's `.ino` file in the **Arduino IDE**.
    * Connect your Arduino Uno board to your computer.
    * Select the correct Board and Port from the `Tools` menu.
3.  **Upload:** Click the **Upload** button to flash the program onto your board.

The system will start working automatically after the upload is complete. You can test its functionality by heating or cooling the temperature sensor and observing the LEDs and the 7-segment display.

---

## Programmer

**Shady Nikooei**