# PS-02 – Graetz Bridge

**Track:** Power Supplies
**Prerequisites:** [PS-01 – Simple Transformer](simple-transformer.md)
**Status:** 🔧 in progress (simulation done, bench measurements to do)

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

[Open the Falstad simulation](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWcMBMcUHYMGZIA4UA2ATmIxAUgoqoQFMBaMMAKADcQ8qxiVOrsaKOBohBSKpOgIWAFXAZCIFCgAsyjHxR48w9TEgIUYDAk0Y8CMKsjYE2EAxiE1vUjsImrhJU9jwSPDAzLEhtG1wHGFJiFgB3BSUePhMlFX14xLEhVOUdKBYAE2yqNQFCXWTlEEK6ADMAQwBXABsAFyKS5RsxCrzdPlrG1o7i7D6q1TA0nsH65vbO8YH8qZnSmvmRzOXwXl7KwkkdiaONFLPITMwL0s1lNQKEm-7zsSMnt7s+Xe-P34+u20uiuCUEpR64K6oK6UNUXGhmTW3So8IhxwATiA0SjsQiodx4HAWAAHcCqdRVazqKEOCCEonEhIIqkUvZ8GHU9lZKow-E5NkEzJcqG5IVkhBssoUQVCKLCMCMpl49Ey9TSmE4qGSmlCK4Ae2UDkI+mxkGIAyk9PALCAA) · source: [sim/PS-02-graetz-bridge.txt](sim/PS-02-graetz-bridge.txt) (*File → Import From Text*)

<iframe src="https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWcMBMcUHYMGZIA4UA2ATmIxAUgoqoQFMBaMMAKADcQ8qxiVOrsaKOBohBSKpOgIWAFXAZCIFCgAsyjHxR48w9TEgIUYDAk0Y8CMKsjYE2EAxiE1vUjsImrhJU9jwSPDAzLEhtG1wHGFJiFgB3BSUePhMlFX14xLEhVOUdKBYAE2yqNQFCXWTlEEK6ADMAQwBXABsAFyKS5RsxCrzdPlrG1o7i7D6q1TA0nsH65vbO8YH8qZnSmvmRzOXwXl7KwkkdiaONFLPITMwL0s1lNQKEm-7zsSMnt7s+Xe-P34+u20uiuCUEpR64K6oK6UNUXGhmTW3So8IhxwATiA0SjsQiodx4HAWAAHcCqdRVazqKEOCCEonEhIIqkUvZ8GHU9lZKow-E5NkEzJcqG5IVkhBssoUQVCKLCMCMpl49Ey9TSmE4qGSmlCK4Ae2UDkI+mxkGIAyk9PALCAA" width="100%" height="500" style="border:1px solid #ccc" title="Graetz Bridge – Falstad simulation"></iframe>

*Interactive on the [project site](https://sasadangelo.github.io/electronic/graetz-bridge); on github.com use the link above.*

The circuit contains:

* **AC source**: 230 V RMS, 50 Hz. Falstad wants the **peak** value: 230 × √2 ≈ **325 V**.
* **Transformer**: ratio 0.052 (≈ 12/230), see [PS-01](simple-transformer.md).
* **Graetz bridge**: four diodes. In each half cycle two of them conduct and steer the current
  through the load always in the same direction: the negative half wave is flipped up.
* **Load resistor**: 100 kΩ by default; change it (double-click) to see how the output changes with current.
* **Meters**: a voltmeter (RMS) on the primary, a voltmeter on the output, and a **scope** showing the output waveform.

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

Change the load resistor and read the output peak (voltmeter in "peak/max" mode, or the scope).
The expected peak current is Vpout / R; the drop is the secondary peak minus the output peak.

| Load R | Peak current (calc.) | Vpout (calc., 2 × 0.7 V) | Vpout (Falstad) | Bridge drop (Falstad) |
|---|---|---|---|---|
| 100 Ω | ≈ 156 mA | 15.57 V | | |
| 1 kΩ | ≈ 15.6 mA | 15.57 V | | |
| 10 kΩ | ≈ 1.6 mA | 15.57 V | | |
| 100 kΩ | ≈ 0.16 mA | 15.57 V | | |

*To fill in from the Falstad simulation.* Expected trend: the drop grows as the resistance decreases (more current).

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
