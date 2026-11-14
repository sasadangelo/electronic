# PS-02 – Graetz Bridge

## Goal

Convert the 230 V AC, 50 Hz mains into a lower **pulsating DC** voltage with a step-down transformer
and a Graetz bridge (full-wave rectifier), and see how the diode voltage drop changes with the load current.

## Components

| Qty | Component | Notes |
|---|---|---|
| 1 | Transformer 230 V → 12 V AC | ⚠️ On the bench, use a ready-made 12 V AC wall adapter: never wire 230 V on a breadboard |
| 1 | Bridge rectifier (e.g. DB107, W04) or 4 × 1N4007 | 1 A, ≥ 100 V |
| 1 set | Load resistors: 100 Ω, 1 kΩ, 10 kΩ, 100 kΩ | 100 Ω dissipates ≈ 1.2 W: use a 2 W resistor |
| 1 | Multimeter (oscilloscope if available) | |

## Schema

[Open the Falstad simulation](https://www.falstad.com/circuit/circuitjs.html?cct=%24%201%200.000005%2010.20027730826997%2050%205%2050%205e-11%0Av%2080%20192%2080%20320%200%201%2050%20325%200%200%200.5%0AT%20176%20224%20272%20288%200%204%200.05217572785140353%20-0.6249299886175166%20-0.00006981577702840303%200.999%0Aw%20176%20192%20176%20224%200%0Aw%20176%20320%20176%20288%200%0Ad%20320%20240%20368%20192%202%20default%0Ad%20320%20240%20368%20288%202%20default%0Ad%20368%20192%20416%20240%202%20default%0Ad%20368%20288%20416%20240%202%20default%0Aw%20368%20192%20368%20160%200%0Aw%20368%20160%20296%20160%200%0Aw%20272%20160%20272%20224%200%0Aw%20272%20288%20272%20352%200%0Aw%20272%20352%20296%20352%200%0Aw%20368%20352%20368%20288%200%0Aw%20320%20240%20320%20320%200%0Aw%20320%20320%20480%20320%200%0A370%20416%20240%20480%20240%201%201%0Ar%20480%20240%20480%20320%200%20100000%0Ap%20144%20192%20144%20320%203%201%200%2010000000%0Aw%2080%20192%20144%20192%200%0Aw%20144%20192%20176%20192%200%0Aw%2080%20320%20144%20320%200%0Aw%20144%20320%20176%20320%200%0Ap%20544%20240%20544%20320%203%202%200%2010000000%0Aw%20480%20240%20544%20240%200%0Aw%20480%20320%20544%20320%200%0Aw%20296%20160%20272%20160%200%0Aw%20296%20352%20368%20352%200%0Ap%20296%20160%20296%20352%203%202%200%2010000000%0Ax%2040%20260%20128%20263%204%2016%20Primary%5Cs%28RMS%29%0Ax%20228%20400%20340%20403%204%2016%20Secondary%5Cs%28peak%29%0Ax%20420%20224%20476%20227%204%2016%20Ammeter%0Ax%20560%20284%20660%20287%204%2016%20Output%5Cs%28peak%29%0Ao%2023%2064%200%204098%2020%200.1%200%201%0A) · source: [sim/PS-02-graetz-bridge.txt](sim/PS-02-graetz-bridge.txt) (*File → Import From Text*)

<iframe src="https://www.falstad.com/circuit/circuitjs.html?cct=%24%201%200.000005%2010.20027730826997%2050%205%2050%205e-11%0Av%2080%20192%2080%20320%200%201%2050%20325%200%200%200.5%0AT%20176%20224%20272%20288%200%204%200.05217572785140353%20-0.6249299886175166%20-0.00006981577702840303%200.999%0Aw%20176%20192%20176%20224%200%0Aw%20176%20320%20176%20288%200%0Ad%20320%20240%20368%20192%202%20default%0Ad%20320%20240%20368%20288%202%20default%0Ad%20368%20192%20416%20240%202%20default%0Ad%20368%20288%20416%20240%202%20default%0Aw%20368%20192%20368%20160%200%0Aw%20368%20160%20296%20160%200%0Aw%20272%20160%20272%20224%200%0Aw%20272%20288%20272%20352%200%0Aw%20272%20352%20296%20352%200%0Aw%20368%20352%20368%20288%200%0Aw%20320%20240%20320%20320%200%0Aw%20320%20320%20480%20320%200%0A370%20416%20240%20480%20240%201%201%0Ar%20480%20240%20480%20320%200%20100000%0Ap%20144%20192%20144%20320%203%201%200%2010000000%0Aw%2080%20192%20144%20192%200%0Aw%20144%20192%20176%20192%200%0Aw%2080%20320%20144%20320%200%0Aw%20144%20320%20176%20320%200%0Ap%20544%20240%20544%20320%203%202%200%2010000000%0Aw%20480%20240%20544%20240%200%0Aw%20480%20320%20544%20320%200%0Aw%20296%20160%20272%20160%200%0Aw%20296%20352%20368%20352%200%0Ap%20296%20160%20296%20352%203%202%200%2010000000%0Ax%2040%20260%20128%20263%204%2016%20Primary%5Cs%28RMS%29%0Ax%20228%20400%20340%20403%204%2016%20Secondary%5Cs%28peak%29%0Ax%20420%20224%20476%20227%204%2016%20Ammeter%0Ax%20560%20284%20660%20287%204%2016%20Output%5Cs%28peak%29%0Ao%2023%2064%200%204098%2020%200.1%200%201%0A" width="100%" height="500" style="border:1px solid #ccc" title="Graetz Bridge – Falstad simulation"></iframe>

*Interactive on the [project site](https://sasadangelo.github.io/electronic/graetz-bridge); on github.com use the link above.*

The circuit contains:

* **AC source**: 230 V RMS, 50 Hz. Falstad wants the **peak** value: 230 × √2 ≈ **325 V**.
* **Transformer**: ratio 0.05218 (≈ 12/230), see [PS-01](simple-transformer.md).
* **Graetz bridge**: four diodes. In each half cycle two of them conduct and steer the current
  through the load always in the same direction: the negative half wave is flipped up.
* **Load resistor**: 100 kΩ by default; change it (double-click) to see how the output changes with current.
* **Meters**: a voltmeter (RMS) on the primary, peak voltmeters on the secondary and on the output,
  an ammeter (RMS) in series with the load, and a **scope** showing the output waveform.

## Theory & Calculation

The transformer gives 12 V RMS, so the secondary peak is:

```
Vpt = Vrms × √2 = 12 V × 1.414 ≈ 16.97 V
```

In each half cycle the current passes through **two diodes in series**. With the design value
of a silicon diode, **Vf ≈ 0.7 V**, the total drop is 1.4 V:

```
Vpout = Vpt − 2 × Vf = 16.97 V − 1.4 V ≈ 15.57 V
```

The output is a sine wave with the negative halves flipped up: it repeats **twice per cycle (100 Hz)**.
Three different "values" describe it, and different instruments show different ones:

| Value | Formula | Result | Who shows it |
|---|---|---|---|
| Peak | Vpout | ≈ 15.6 V | Scope, Falstad voltmeter in "peak" mode |
| RMS | Vpout / √2 | ≈ 11.0 V | True-RMS meter, Falstad voltmeter in "RMS" mode |
| Average (DC) | 2 × Vpout / π | ≈ 9.9 V | **A normal multimeter on DC** |

So on the bench your multimeter on V DC will read about **10 V, not 11 V**: it's not an error, it measures the average.

### Why the diode drop is not constant

0.7 V is a design value: the real forward voltage of a diode **grows with current** (exponential I-V curve).
At a few mA a silicon diode drops about 0.6 V, at 1 A it can reach 1 V.
A real bridge such as the one in datasheet [DS21219](https://www.diodes.com/assets/Datasheets/ds21219.pdf)
specifies up to **1.0–1.1 V per diode** at its rated current.
So with a heavy load (low resistance) the output peak is lower than with a light load.

## Simulation Results

### The drop depends on the load

A diode is not a fixed 0.7 V "battery": its forward voltage **depends on the current** flowing through it
(exponential I-V curve). Roughly, every time the current is **multiplied by 10**, the drop of a silicon diode
grows by **60–120 mV**. The load resistor sets the current, so:

- **high resistance → small current → small drop** (the output peak stays close to the secondary peak);
- **low resistance → large current → larger drop** (the output peak goes down).

That's why a rectifier's output voltage changes with the load, even before adding any capacitor or regulator.

### Measurements

The secondary peak in Falstad is 325 V × 0.05218 ≈ **16.96 V** (same as the calculated 16.97 V).
For each load, read the output peak (voltmeter in "peak/max" mode, or the scope); the bridge drop is
16.96 V minus the output peak, and each of the two conducting diodes takes half of it.

⚠️ A voltmeter in peak/max mode **holds the highest value** it has seen: after changing the resistor,
**reset the simulation** (*Reset* button) before reading, otherwise you keep reading the old value.

| Load R | Current RMS (Falstad) | Peak current (Vpout / R) | Vpout (calc., 2 × 0.7 V) | Vpout (Falstad) | Bridge drop | Per diode |
|---|---|---|---|---|---|---|
| 100 kΩ | 0.115 mA | 0.16 mA | 15.57 V | 16.23 V | 0.73 V | 0.36 V |
| 10 kΩ | 1.12 mA | 1.6 mA | 15.57 V | 15.99 V | 0.96 V | 0.48 V |
| 1 kΩ | 10.9 mA | 15.8 mA | 15.57 V | 15.76 V | 1.20 V | 0.60 V |
| 100 Ω | 107 mA | 155 mA | 15.57 V | 15.52 V | 1.44 V | 0.72 V |

What the numbers show:

- **Every time the current is multiplied by 10, the bridge drop grows by 0.236 V** (≈ 118 mV per diode):
  0.73 → 0.96 → 1.20 → 1.44 V. This is the logarithmic behaviour of the diode, measured cleanly.
- **The 0.7 V design value matches only around 150 mA.** At light loads the real drop is much smaller,
  so the output is higher than calculated; at heavy loads it would be even larger than 1.4 V.
- **Peak vs. RMS current.** For a perfect rectified sine, I_peak = I_rms × √2. Here I_rms × √2 is 1–2% lower
  than Vpout / R: near zero volts the diodes don't conduct yet, so the waveform has small gaps and is not a perfect sine.
- With this waveform the minimum is 0 V, so the **peak** and **peak-to-peak** readings coincide.

Notice also that Falstad's `default` diode model has a **lower forward voltage** than a real silicon rectifier:
a 1N4007 drops about 0.5 V at very small currents and 0.7–0.9 V at a few hundred mA.
The 0.7 V design value is closer to the real part. Double-click a diode to choose a different model.

## Real-World Measurements

⚠️ Use a **12 V AC wall adapter** (or an enclosed transformer) as the source: the 230 V side never goes on the breadboard.
With the multimeter: measure the adapter's AC voltage, then the output on V DC (average) and, if your meter has it, on V AC (RMS).

| Load R | Secondary (V AC) | Output (V DC, average) | Output peak (scope) | Notes |
|---|---|---|---|---|
| 100 Ω | | | | |
| 1 kΩ | | | | |
| 10 kΩ | | | | |
| 100 kΩ | | | | |

A cheap 12 V adapter often gives **more than 12 V without load** (14–15 V RMS) and drops under load:
it's the transformer's internal resistance, see [PS-01](simple-transformer.md).

## Variations to Try

- [ ] Remove one diode: the bridge becomes a **half-wave** rectifier. Watch the 50 Hz gaps on the scope.
- [ ] Add a capacitor (e.g. 1000 µF) across the load: the pulsating DC becomes almost flat, with a small **ripple**.
      This is the next experiment, PS-03.
- [ ] In Falstad, put an ammeter in series with one diode: it conducts only every other half cycle.

## Conclusion

The Graetz bridge turns AC into pulsating DC at 100 Hz, losing two diode drops on the way.
The drop is not a fixed 1.4 V: it depends on the current, so the output depends on the load.
Peak, RMS and average values differ a lot on this waveform, and each instrument shows a different one:
always know which value you are reading.

Next: PS-03 – Reservoir capacitor & ripple (see the [roadmap](roadmap.md)).
