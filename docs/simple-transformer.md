# Simple Transformer Circuit

This is a simple project I created to test how transformers work in a simulator (Falstad) after a long break from electronics. The goal is to understand the basic behavior of a transformer and how it converts high AC voltage into a lower, safer value for use in circuits.

[Open the Falstad simulation](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgzCAMB0l3BWEBGGAmOaDsWyQBxoBsAnCViApJZdQgKYC0yyAUACor4AsKJa4NPhDYB1XjEgI0yfpCJF8UnggTIQjScjCoEYIvqzduabkW1RYiMDZI8SRNBkh3LZEqwBuKSL1kDUXlEoFFpBIhDqGARWACcQY2p-BO5qYKT4SFYAB0pjPgEEfOCIdQzMuFYAdy4-flqUfKya5B5BJLb06sFhZLAhRolu-t78xMGoYYGSgf6oqeE5lOol5uWJ8eS1zfyivybuvYmjre7xpaPVw-yL4qwxHI0iPzbGZ5EHcFDyiu63-d4-waayBSyBaE+a0CBR8AMmLV8InusPa8JRS1avCuCLhmIm21SqPGXRqQOQ+Wh5KGpPeGMRVyAA) · source: [sim/PS-01-simple-transformer.txt](sim/PS-01-simple-transformer.txt) (*File → Import From Text*)

## Schema

<iframe src="https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgzCAMB0l3BWEBGGAmOaDsWyQBxoBsAnCViApJZdQgKYC0yyAUACor4AsKJa4NPhDYB1XjEgI0yfpCJF8UnggTIQjScjCoEYIvqzduabkW1RYiMDZI8SRNBkh3LZEqwBuKSL1kDUXlEoFFpBIhDqGARWACcQY2p-BO5qYKT4SFYAB0pjPgEEfOCIdQzMuFYAdy4-flqUfKya5B5BJLb06sFhZLAhRolu-t78xMGoYYGSgf6oqeE5lOol5uWJ8eS1zfyivybuvYmjre7xpaPVw-yL4qwxHI0iPzbGZ5EHcFDyiu63-d4-waayBSyBaE+a0CBR8AMmLV8InusPa8JRS1avCuCLhmIm21SqPGXRqQOQ+Wh5KGpPeGMRVyAA" width="100%" height="500" style="border:1px solid #ccc" title="Simple Transformer – Falstad simulation"></iframe>

*Interactive on the [project site](https://sasadangelo.github.io/electronic/simple-transformer); on github.com use the link above.*

## Circuit Description

A transformer is a passive electrical device made of two inductively coupled coils: the primary and secondary. When alternating current (AC) flows through the primary coil, it generates a magnetic field that induces a voltage in the secondary coil. This allows us to change the voltage level without direct electrical connection.

- **Primary coil**: Connected directly to the AC mains (e.g., 230V in Italy).
- **Secondary coil**: Connected to the load or circuit.

Both coils are usually wrapped around a common iron core to enhance magnetic coupling.

## Circuit Calculation

If the primary has N = 1000 turns, then the voltage per turn is:

**Voltage per turn** = 230V / 1000 = 0.23V

To obtain an output of 12V, we need:

**Turns on secondary** = 12V / 0.23V ≈ 52.17 → ~53 turns

The turns ratio becomes:

**Turns ratio** = 53 / 1000 = 0.053

In AC circuits, voltages are often given in RMS (Root Mean Square), which is a measure of effective voltage. To understand the waveform fully, we need to calculate the **peak** (Vp) and **peak-to-peak** (Vpp) voltages. If the RMS voltage on the secondary is 12V, then:

**Peak voltage (Vp)** = RMS × √2 ≈ 12V × 1.414 ≈ 16.97V
**Peak-to-peak voltage (Vpp)** = 2 × Vp ≈ 2 × 16.97V ≈ 33.94V

So:

**Vp (peak)** ≈ 16.97V

**Vpp (peak-to-peak)** ≈ 33.94V

To see the waveform on the resistor in Falstad, right-click the resistor and choose *View in New Scope*:
the sine wave peaks at about ±17 V.

## Design Insights

- This simulation assumes ideal transformer behavior, with no power loss.
- Real transformers have additional characteristics like core losses, leakage inductance, and winding resistance, which are not modeled here.
- This is a step-down transformer, reducing voltage from a high level to a lower one.

## Simulating It in Falstad

**The AC source wants the peak voltage**, not RMS: 230 V RMS → 230 × √2 ≈ **326 V** peak.
The source is ideal (0 Ω internal resistance; real mains is about 0.1–1 Ω at the socket).
The two voltmeters are set to show **RMS** values (230 V and 12 V), so both views are on screen.

**The transformer has three parameters** (double-click it):

| Parameter | Value | Meaning |
|---|---|---|
| Primary Inductance | 4 H | Inductance of the primary winding (set by the real number of turns and the core) |
| Ratio | 0.0522 | Turns ratio N₂/N₁ = V₂/V₁ (≈ 12/230). Only the ratio matters, not the absolute turns |
| Coupling Coefficient | 0.999 | Magnetic coupling between windings (1 = perfect) |

Windings have zero resistance in this model; add a small resistor in series to simulate copper losses.

**Why the primary dots "race" in one direction while the secondary ones swing slowly.**
Frequency is the same (50 Hz) on both sides; dot speed is proportional to **current**:

```
Secondary:  12 V / 10 kΩ                       ≈ 1.2 mA
Primary:    magnetizing current = V / (2π·f·L)
            = 230 V / (2π · 50 Hz · 4 H)        ≈ 183 mA
```

The primary carries ~150× more current, mostly the **magnetizing current** needed to magnetize the core,
even with almost no load. Its dots move so far between frames that the eye sees them going one way
(the "wagon-wheel" effect, i.e. *aliasing*). Falstad also runs time much slower than reality,
so you see the 50 Hz alternation in slow motion.

Try it: raise Primary Inductance to 100 H (magnetizing current drops to ≈ 7 mA, the primary dots start swinging),
or lower the *Current Speed* slider.

Real lesson: a mains transformer **draws current even with no load** and gets slightly warm when idle.

**Colors** show voltage against ground: green = positive, red = negative, grey ≈ 0 V.
With AC they flip every half cycle; the 230 V primary is much brighter than the 12 V secondary.

**The dots are conventional current** (+ to −), not electrons: real electrons drift the other way,
at a few millimetres per second. What travels fast is the electric field, i.e. the energy.

## Real-World Testing

If you replicate this circuit with actual components, expect some variations:

- Real AC mains may fluctuate slightly above or below 230V.
- The output voltage will depend on load resistance and transformer quality.
- Cheap or small transformers may introduce voltage drops under load.

## Conclusion

This simple transformer model helps understand the principle of voltage conversion using magnetic induction. By adjusting the turn ratio, you can simulate different transformer behaviors in Falstad. It's a great starting point for more advanced power supply design or AC applications.
