# Simple LED Circuit

This is my first project after years of not creating electronics projects. The project is a simple circuit that consists of a LED, a 390-ohm resistor, and a 9V battery. Below is an overview of the circuit, the design process, and my real-world testing results.

## Circuit Description

The circuit is made up of:

- **LED**: A light-emitting diode (LED) that lights up when current flows through it.
- **390-ohm Resistor**: Limits the current flowing through the LED to prevent it from burning out.
- **9V Battery**: The power source for the circuit.

### Circuit Calculation

To calculate the value of the resistor (R), I used the formula:

**R** = (**Vcc** -**Vd**)/**I**

Where:
- Vcc is the supply voltage (9V)
- Vd is the LED's forward voltage drop (1.7V for this case)
- I is the desired current (20mA)

Substituting the values:

R = (9V - 1.7V)}/0.020A = 365 Ohms

The closest commercially available resistor is **390 ohms**, so that’s what I used.

## Design Insights

Here are some key points I considered while designing this circuit:

1. **LED Current**: I assumed that the LED would draw approximately 20mA of current.
2. **LED Voltage Drop**: The voltage drop across the LED terminals is around 1.7V.
3. **Series Resistor**: A resistor is always necessary when using an LED to limit the current and prevent damage to the LED.
4. **Resistor Calculation**: The resistor value can be calculated using the formula above to ensure the right amount of current flows through the LED.

### LED Color and Forward Voltage

The forward voltage drop of the LED varies based on its color. According to common specifications:

- **Red LED**: 1.8V
- **Yellow LED**: 1.9V
- **Green LED**: 2.0V
- **Blue LED**: 3.5V

For more details on LED characteristics, visit the [LED Wikipedia page](https://it.wikipedia.org/wiki/LED).

## Real-World Testing

When I tested the circuit with real components, I observed some differences from the theoretical calculations:

- **Current Draw**: The LED actually absorbed around 16mA, which was slightly lower than the 20mA I expected.
- **Junction Voltage**: The voltage drop across the LED terminals was around **2.12V**, which was higher than the assumed 1.7V.
- **Battery Voltage**: My 9V battery measured **9.76V**, not the standard 9V. This is normal, as real battery voltages can differ slightly from the nominal value.

## Simulation Results

When simulating the circuit in EasyEDA, I found the following results:

- The LED’s junction voltage in the simulation was **1.843V**.
- The LED current in the simulation was **18mA**.

### Conclusion

This project demonstrates how theoretical calculations may differ from real-world results. Always consider potential variations in real-world components, and use simulations as a starting point for design, but expect minor differences when testing physically.

---
*Note: This project is an excellent starting point for understanding basic electronic components and how to safely design circuits with LEDs.*
