# F-01 – Simple LED

**Track:** Foundations
**Prerequisites:** none
**Status:** ✅ done

This is my first project after years away from electronics: an LED, a resistor and a 9 V battery.
It looks trivial, but it already shows the most important lesson of the whole lab:
**components are not the numbers written on them**.

## Goal

How do you choose the series resistor for an LED, and how much can you trust the calculation
when LED voltage, battery voltage and resistor value all differ from their nominal values?

## Components

| Qty | Component | Notes |
|---|---|---|
| 1 | Red LED, 5 mm | |
| 1 | Resistor 390 Ω, ¼ W | ±5% tolerance |
| 1 | 9 V battery | Alkaline |
| 1 | Multimeter | Voltage and current |

## Schema

[Open the Falstad simulation](https://www.falstad.com/circuit/circuitjs.html?ctz=DwYwlgTgBAZgvAIgIwKgFwM6IAwDpsEECsqYIiSeATAVQOx0DM2AHFQGwCcndqIARoiLZUAB0EJhqAG4QhqALaYhAUwC0SFAD4AUFCjBpUAB4U67KIyJUoSc7fOp4CEVADuz1woCGx6Yk4EAHpdfWA3EzMLOwtmABYHdiccYNCDaFMEeMSoOMYbGOSXVDkszhEQvQMAGQBRABFIhDyC+xbLayKqRQB7RAATFRhvAFcAGzQ1MZV+vlKUKBAAcxTFiS9+chd8FEqwiMz2q1bYztgUvYMlppiOk8sWOKKKtOBjJroWKA4vpGFvugLZxPKAYMAUJLoFQBABqUH43jQaBUEAAnqkqm8mlZsLY4pxLJxGLYzsDUGCIahkYhGOUoIBK4AxYXeh2sAJscRYxPoJHOzXJ4OQkOpCDq9QxwCC4AguiAA) · source: [sim/F-01-simple-led.txt](sim/F-01-simple-led.txt) (*File → Import From Text*)

<iframe src="https://www.falstad.com/circuit/circuitjs.html?ctz=DwYwlgTgBAZgvAIgIwKgFwM6IAwDpsEECsqYIiSeATAVQOx0DM2AHFQGwCcndqIARoiLZUAB0EJhqAG4QhqALaYhAUwC0SFAD4AUFCjBpUAB4U67KIyJUoSc7fOp4CEVADuz1woCGx6Yk4EAHpdfWA3EzMLOwtmABYHdiccYNCDaFMEeMSoOMYbGOSXVDkszhEQvQMAGQBRABFIhDyC+xbLayKqRQB7RAATFRhvAFcAGzQ1MZV+vlKUKBAAcxTFiS9+chd8FEqwiMz2q1bYztgUvYMlppiOk8sWOKKKtOBjJroWKA4vpGFvugLZxPKAYMAUJLoFQBABqUH43jQaBUEAAnqkqm8mlZsLY4pxLJxGLYzsDUGCIahkYhGOUoIBK4AxYXeh2sAJscRYxPoJHOzXJ4OQkOpCDq9QxwCC4AguiAA" width="100%" height="500" style="border:1px solid #ccc" title="Simple LED – Falstad simulation"></iframe>

*Interactive on the [project site](https://sasadangelo.github.io/electronic/simple-led); on github.com use the link above.*

## Theory & Calculation

The resistor drops the difference between the supply and the LED voltage, and **sets the current**:

```
R = (Vcc − Vf) / I
```

**Which Vf?** Loose LEDs from component kits come without a datasheet, so pick the
**design value for the LED's color**:

| Color | Typical range (5–20 mA) | Design value |
|---|---|---|
| Red | 1.8–2.1 V | **2.0 V** |
| Yellow / orange | 2.0–2.2 V | **2.1 V** |
| Green (classic, yellowish) | 2.1–2.3 V | **2.2 V** |
| Pure green, blue, white | 2.9–3.3 V | **3.0 V** |

Want the real value of your LED? Use the multimeter's **diode test mode**: the LED glows faintly
and the meter shows its Vf at about 1 mA, so add 0.1–0.2 V to estimate it at 10–20 mA.

For this circuit:

- Vcc = 9 V (nominal battery voltage)
- Vf = 2.0 V (design value for a red LED)
- I = 20 mA (target; see *Design Guidelines* for why lower is better)

```
R = (9 V − 2.0 V) / 0.020 A = 350 Ω  →  390 Ω (next standard value up, so the current stays below target)
I = (9 V − 2.0 V) / 390 Ω ≈ 17.9 mA
```

Note: the LED does not "draw" a current of its own. The LED holds its voltage roughly constant;
**the resistor decides the current**. Without the resistor, a tiny change in voltage across the
LED would cause a huge change in current, and the LED would burn.

See also the [LED Wikipedia page](https://it.wikipedia.org/wiki/LED).

## Simulation Results

Falstad uses its `default-led` model (a red LED) with an ideal 9 V source.
Hover over each component to read voltage and current.

| Quantity | Value |
|---|---|
| LED voltage | ≈ 2.0 V |
| LED current | ≈ 18 mA |

The simulator confirms the 2.0 V design value for a red LED at this current.

## Real-World Measurements

| Quantity | Calculated (design) | Simulated (Falstad) | Measured | Δ vs. design |
|---|---|---|---|---|
| Battery voltage | 9 V | 9 V | 9.76 V (no load) | +8% |
| LED voltage | 2.0 V | ≈ 2.0 V | 2.12 V | +6% |
| Current | 17.9 mA | ≈ 18 mA | 16 mA (ammeter) | −11% |

Now recalculate using **my measured values**:

```
I = (9.76 V − 2.12 V) / 390 Ω = 19.6 mA
```

The formula with real values predicts almost exactly 20 mA, yet the ammeter read 16 mA.
The formula is right; the gap comes from **how the current was measured** (see below).

## Why Reality Differs

**1. The ammeter changes the circuit.** A multimeter on a mA range adds its internal shunt
(plus fuse) in series: from a few ohms to tens of ohms, often more on the lowest ranges.
To get 16 mA, the total resistance would have to be:

```
R_total = (9.76 V − 2.12 V) / 0.016 A ≈ 477 Ω  →  ≈ 87 Ω more than the 390 Ω resistor
```

High, but possible on some meters' low ranges. Together with points 2–4, it explains the gap.

**2. The battery was measured without load.** Under load the voltage drops a little
on a fresh battery, much more on a used one.

**3. Resistor tolerance.** A ±5% 390 Ω resistor can be anywhere from 370 to 410 Ω.

**4. Measurements were not simultaneous.** Inserting and removing the meter changes the conditions.

**Better method:** don't use the ammeter. Measure the resistor with the ohmmeter (circuit off),
then the **voltage across the resistor** with the circuit on:

```
I = V_R / R
```

The voltmeter barely disturbs the circuit, and every value is taken in the same conditions.

## Design Guidelines

**Which LED voltage should I use?** The design value from the color table above: **2.0 V for red**.
A real LED can be about ±0.2 V off. How much that matters depends on
**how much headroom the supply has over the LED**:

| Supply | R (designed for 20 mA, Vf = 2.0 V) | I if Vf = 1.8 V | I if Vf = 2.2 V | Spread |
|---|---|---|---|---|
| 9 V | 390 Ω | 18.5 mA | 17.4 mA | ≈ ±3% |
| 3.3 V | 68 Ω | 22.1 mA | 16.2 mA | ≈ ±15% |

At 9 V the Vf uncertainty barely matters; at 3.3 V (microcontrollers) it matters a lot,
and the current can even exceed the 20 mA target: one more reason to design for less.

**Which current?** Don't design for 20 mA. For classic 5 mm LEDs, 20 mA is the datasheet *test* current,
and the absolute maximum is often only 25–30 mA. Designing lower gives you:

- **Safety margin** against a fresh battery, a lower-than-expected Vf, resistor tolerance.
- **Enough light anyway**: modern LEDs are already bright at 5–10 mA, and the eye's response is not linear
  (going from 10 to 20 mA looks only slightly brighter).
- **Less heat, longer life**, and **double battery life** at 10 mA vs. 20 mA.
- **Microcontroller-friendly**: an Arduino pin is rated about 20 mA recommended, 40 mA absolute max,
  with a total limit for the whole chip.

| Use | Current |
|---|---|
| Indicator (indoors) | 2–5 mA |
| Normal use | 5–10 mA |
| Maximum brightness (outdoors, old low-efficiency LEDs) | 15–20 mA |

This circuit redesigned for 10 mA:

```
R = (9 V − 2.0 V) / 0.010 A = 700 Ω  →  680 Ω (standard value)
I = (9 V − 2.0 V) / 680 Ω ≈ 10.3 mA
```

**Check the worst case:** maximum supply + minimum Vf must stay below the LED's maximum current.

**The battery is not a constant.** A 9 V alkaline starts at about 9.5–9.7 V and ends at about 6.5–7 V.
With 390 Ω and Vf ≈ 2.1 V:

| Battery | Current |
|---|---|
| 9.7 V (fresh) | ≈ 19.5 mA |
| 9.0 V (nominal) | ≈ 17.7 mA |
| 7.0 V (nearly empty) | ≈ 12.6 mA |

Design over the whole range: below the LED maximum with a fresh battery, still bright enough with an empty one.
If brightness must stay constant, a resistor is not enough: use a **constant-current source**
(see PS-08 in the [roadmap](roadmap.md)). That's how LED flashlights and bulbs work.

## Variations to Try

- [ ] Measure the current via the voltage across the resistor and compare it with the ammeter reading.
      If they differ, the ammeter's internal resistance is the culprit.
- [ ] Measure the actual resistor value with the ohmmeter.
- [ ] Measure the battery voltage **with the LED on**.
- [ ] Compare 390 Ω (≈ 18 mA) and 680 Ω (≈ 10 mA) side by side: can you really see the difference?
- [ ] Swap 390 Ω for 1 kΩ and 220 Ω: how do current, Vf and brightness change?
- [ ] Try different colors and record Vf for each.
- [ ] Plot the full I-V curve of the LED (next: F-05, diode I-V curve).

## Conclusion

The calculation is reliable if you feed it sensible values: 2.0 V for a red LED, a current well below
the maximum. Real batteries are not 9 V, and an ammeter is not invisible. With measured values the formula predicts the current within
a few percent. The lesson for every future experiment: **know what your instrument does to the circuit**,
and design for the full range of your components, not for their nominal values.

Next: F-02 – Voltage divider & loading effect (see the [roadmap](roadmap.md)).
