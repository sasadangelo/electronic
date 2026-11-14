# PS-03 – Reservoir Capacitor & Ripple

The [Graetz bridge](graetz-bridge.md) gives a pulsating voltage that drops to 0 V a hundred times per second:
useless for almost any circuit. Adding one large capacitor turns it into an almost flat DC voltage.
This experiment is about **how to size that capacitor**, when this simple supply is good enough,
and why real devices need something more.

## Goal

- Calculate the capacitor needed for a given load current and a desired ripple.
- See how ripple changes with capacitance and with load.
- Understand which ripple is acceptable for which application, and the limits of this kind of supply.

## Components

| Qty | Component | Notes |
|---|---|---|
| 1 | 12 V AC wall adapter (or enclosed transformer) | ⚠️ Never wire 230 V on a breadboard |
| 1 | Bridge rectifier or 4 × 1N4007 | From [PS-02](graetz-bridge.md) |
| 1 each | Electrolytic capacitors 100 µF, 470 µF, 1000 µF, 2200 µF | **≥ 25 V**, 105 °C. ⚠️ Respect polarity: a reversed electrolytic can burst |
| 1 each | Load resistors 1 kΩ, 150 Ω, 47 Ω | 150 Ω dissipates ≈ 1.5 W → use 3 W; 47 Ω ≈ 4.2 W → use 10 W. They get hot |
| 1 | Resistor 4.7 kΩ ½ W | Bleeder: discharges the capacitor when the supply is off |
| 1 | Multimeter (oscilloscope if available) | |

## Schema

[Open the Falstad simulation](https://www.falstad.com/circuit/circuitjs.html?cct=%24%201%200.000005%2010.20027730826997%2050%205%2050%205e-11%0Av%2080%20192%2080%20320%200%201%2050%20325%200%200%200.5%0AT%20176%20224%20272%20288%200%204%200.05217572785140353%200%200%200.999%0Aw%20176%20192%20176%20224%200%0Aw%20176%20320%20176%20288%200%0Ad%20320%20240%20368%20192%202%20default%0Ad%20320%20240%20368%20288%202%20default%0Ad%20368%20192%20416%20240%202%20default%0Ad%20368%20288%20416%20240%202%20default%0Aw%20368%20192%20368%20160%200%0A370%20296%20160%20368%20160%201%201%0Aw%20272%20160%20272%20224%200%0Ar%20272%20288%20272%20352%200%201%0Aw%20272%20352%20296%20352%200%0Aw%20368%20352%20368%20288%200%0Aw%20320%20240%20320%20320%200%0Aw%20320%20320%20480%20320%200%0A370%20416%20240%20480%20240%201%201%0Ac%20480%20240%20480%20320%200%200.001%200%0Ar%20528%20240%20528%20320%200%20150%0Ap%20144%20192%20144%20320%203%201%200%2010000000%0Aw%2080%20192%20144%20192%200%0Aw%20144%20192%20176%20192%200%0Aw%2080%20320%20144%20320%200%0Aw%20144%20320%20176%20320%200%0Ap%20592%20240%20592%20320%203%202%200%2010000000%0Aw%20480%20240%20528%20240%200%0Aw%20528%20240%20592%20240%200%0Aw%20480%20320%20528%20320%200%0Aw%20528%20320%20592%20320%200%0Aw%20296%20160%20272%20160%200%0Aw%20296%20352%20368%20352%200%0Ap%20296%20160%20296%20352%203%202%200%2010000000%0Aw%20592%20240%20656%20240%200%0Aw%20592%20320%20656%20320%200%0Ap%20656%20240%20656%20320%203%204%200%2010000000%0Ax%2040%20260%20128%20263%204%2016%20Primary%5Cs%28RMS%29%0Ax%20228%20400%20340%20403%204%2016%20Secondary%5Cs%28peak%29%0Ax%20300%20140%20380%20143%204%2016%20I%5Cssecondary%5Cs%28RMS%29%0Ax%20210%20330%20260%20333%204%2016%20Winding%5Cs1%CE%A9%0Ax%20412%20224%20490%20227%204%2016%20I%5Csload%5Cs%28RMS%29%0Ax%20440%20350%20520%20353%204%2016%20C%5Cs1000%C2%B5F%0Ax%20500%20350%20560%20353%204%2016%20R%5Cs150%CE%A9%0Ax%20560%20370%20640%20373%204%2016%20Output%5Cs%28peak%29%0Ax%20630%20220%20720%20223%204%2016%20Ripple%5Cs%28p-p%29%0Ao%2024%2064%200%204098%2020%200.1%200%201%0A) · source: [sim/PS-03-reservoir-capacitor.txt](sim/PS-03-reservoir-capacitor.txt) (*File → Import From Text*)

<iframe src="https://www.falstad.com/circuit/circuitjs.html?cct=%24%201%200.000005%2010.20027730826997%2050%205%2050%205e-11%0Av%2080%20192%2080%20320%200%201%2050%20325%200%200%200.5%0AT%20176%20224%20272%20288%200%204%200.05217572785140353%200%200%200.999%0Aw%20176%20192%20176%20224%200%0Aw%20176%20320%20176%20288%200%0Ad%20320%20240%20368%20192%202%20default%0Ad%20320%20240%20368%20288%202%20default%0Ad%20368%20192%20416%20240%202%20default%0Ad%20368%20288%20416%20240%202%20default%0Aw%20368%20192%20368%20160%200%0A370%20296%20160%20368%20160%201%201%0Aw%20272%20160%20272%20224%200%0Ar%20272%20288%20272%20352%200%201%0Aw%20272%20352%20296%20352%200%0Aw%20368%20352%20368%20288%200%0Aw%20320%20240%20320%20320%200%0Aw%20320%20320%20480%20320%200%0A370%20416%20240%20480%20240%201%201%0Ac%20480%20240%20480%20320%200%200.001%200%0Ar%20528%20240%20528%20320%200%20150%0Ap%20144%20192%20144%20320%203%201%200%2010000000%0Aw%2080%20192%20144%20192%200%0Aw%20144%20192%20176%20192%200%0Aw%2080%20320%20144%20320%200%0Aw%20144%20320%20176%20320%200%0Ap%20592%20240%20592%20320%203%202%200%2010000000%0Aw%20480%20240%20528%20240%200%0Aw%20528%20240%20592%20240%200%0Aw%20480%20320%20528%20320%200%0Aw%20528%20320%20592%20320%200%0Aw%20296%20160%20272%20160%200%0Aw%20296%20352%20368%20352%200%0Ap%20296%20160%20296%20352%203%202%200%2010000000%0Aw%20592%20240%20656%20240%200%0Aw%20592%20320%20656%20320%200%0Ap%20656%20240%20656%20320%203%204%200%2010000000%0Ax%2040%20260%20128%20263%204%2016%20Primary%5Cs%28RMS%29%0Ax%20228%20400%20340%20403%204%2016%20Secondary%5Cs%28peak%29%0Ax%20300%20140%20380%20143%204%2016%20I%5Cssecondary%5Cs%28RMS%29%0Ax%20210%20330%20260%20333%204%2016%20Winding%5Cs1%CE%A9%0Ax%20412%20224%20490%20227%204%2016%20I%5Csload%5Cs%28RMS%29%0Ax%20440%20350%20520%20353%204%2016%20C%5Cs1000%C2%B5F%0Ax%20500%20350%20560%20353%204%2016%20R%5Cs150%CE%A9%0Ax%20560%20370%20640%20373%204%2016%20Output%5Cs%28peak%29%0Ax%20630%20220%20720%20223%204%2016%20Ripple%5Cs%28p-p%29%0Ao%2024%2064%200%204098%2020%200.1%200%201%0A" width="100%" height="500" style="border:1px solid #ccc" title="Reservoir Capacitor – Falstad simulation"></iframe>

*Interactive on the [project site](https://sasadangelo.github.io/electronic/reservoir-capacitor); on github.com use the link above.*

The circuit is the [Graetz bridge](graetz-bridge.md) plus:

* **C 1000 µF** across the output: the reservoir capacitor.
* **R 150 Ω** load: about 100 mA.
* **Winding 1 Ω**: a real small transformer has about 1–3 Ω of copper resistance; it matters here, see *Limits*.
* **Meters**: primary voltage (RMS), secondary voltage (peak), secondary and load current (RMS),
  output peak, and **Ripple (p-p)**, which measures the ripple directly. The scope shows the output waveform.

## Theory & Calculation

### How it works

1. Near the peak of each half wave the diodes conduct and **charge the capacitor** up to the peak voltage.
2. When the input voltage falls below the capacitor voltage, the diodes stop conducting.
   Now **the capacitor alone feeds the load** and slowly discharges.
3. At the next peak (10 ms later, the bridge gives 100 peaks per second) the diodes recharge it.

The output is a DC voltage with a small **sawtooth** on top: the **ripple**.

### The ripple formula

While the capacitor feeds the load, it loses charge Q = I × t, so its voltage drops by:

```
ΔV = I × t / C
```

The discharge lasts at most one ripple period, t ≈ 1 / f_ripple, where f_ripple = **2 × 50 Hz = 100 Hz** for a full-wave bridge:

```
Vripple ≈ I / (f_ripple × C) = I / (2 × f × C)
```

The formula slightly **overestimates** the ripple (the capacitor actually recharges a bit before the 10 ms are over),
so a design based on it is on the safe side. It is accurate when the ripple is small compared to the voltage (below ~15%).

### Designing the capacitor

Turn the formula around: **choose the ripple you can accept, then compute C**.

```
C = I / (2 × f × Vripple)
```

Example: 100 mA load, 1 V ripple accepted:

```
C = 0.1 A / (2 × 50 Hz × 1 V) = 0.001 F = 1000 µF
```

**Rule of thumb** (full-wave, 50 Hz): **1000 µF for every 100 mA gives about 1 V of ripple**.

| Load current | 1 V ripple | 2 V ripple |
|---|---|---|
| 100 mA | 1000 µF | 470 µF |
| 500 mA | 4700 µF | 2200 µF |
| 1 A | 10 000 µF | 4700 µF |

With a **half-wave** rectifier (one diode) f_ripple is 50 Hz: you need **twice** the capacitance for the same ripple.

### Choosing the real component

1. **Capacitance**: from the formula, rounded **up** to the next standard value (100, 220, 470, 1000, 2200, 4700 µF…).
   Electrolytics have a −20% tolerance: add margin.
2. **Voltage rating**: the capacitor sees the **no-load peak**, with mains up to +10% and an unloaded transformer
   giving more than its nominal voltage. Rule: **at least 1.5 × the peak**. Here 17 V peak → **25 V**, better 35 V.
3. **Ripple current rating**: the capacitor is charged by short, strong pulses. Its RMS current is
   **1.5–2 × the load current**; check the datasheet's *ripple current*, otherwise it heats and dries out
   (the most common fault in old devices, see the [Device Roadmap](devices.md)).
4. **Temperature**: prefer **105 °C** types: their life is several times longer than 85 °C ones.

### Expected values

Secondary peak 16.97 V, minus two diodes (2 × 0.7 V) = **15.57 V** output peak (winding resistance ignored).
Average output ≈ peak − ripple / 2.

## Simulation Results

For each combination: change C or R (double-click), press **Reset**, wait until the capacitor is charged
(the scope trace is flat), then read the meters.
⚠️ At reset the capacitor starts empty: if *Ripple (p-p)* shows ~15 V it is still counting the start-up.
Wait a few cycles or read the ripple on the scope.

### Ripple vs. capacitance (load 150 Ω)

| C | Current (calc.) | Ripple (calc.) | V min (calc.) | Output peak (Falstad) | Ripple p-p (Falstad) | I load RMS (Falstad) |
|---|---|---|---|---|---|---|
| 100 µF | ≈ 78 mA | ≈ 7.8 V (formula unreliable) | ≈ 7.8 V | | | |
| 470 µF | ≈ 97 mA | ≈ 2.1 V | ≈ 13.5 V | | | |
| 1000 µF | ≈ 100 mA | ≈ 1.0 V | ≈ 14.6 V | | | |
| 2200 µF | ≈ 102 mA | ≈ 0.46 V | ≈ 15.1 V | | | |

### Ripple vs. load (C = 1000 µF)

| Load R | Current (calc.) | Ripple (calc.) | V average (calc.) | Output peak (Falstad) | Ripple p-p (Falstad) | I load RMS (Falstad) | I secondary RMS (Falstad) |
|---|---|---|---|---|---|---|---|
| 1 kΩ | ≈ 15 mA | ≈ 0.15 V | ≈ 15.5 V | | | | |
| 150 Ω | ≈ 100 mA | ≈ 1.0 V | ≈ 15.1 V | | | | |
| 47 Ω | ≈ 300 mA | ≈ 3.0 V | ≈ 14.1 V | | | | |

*To fill in from the Falstad simulation.* Expected: ripple halves when C doubles, and doubles when the current doubles.
The secondary RMS current should be clearly **higher** than the load current: see *Limits*.

## Real-World Measurements

⚠️ 12 V AC adapter only. Check capacitor polarity before powering. After switching off, the capacitor stays charged:
wait for the bleeder or short it through a resistor, never with a screwdriver.

**Measuring ripple without an oscilloscope**: most multimeters in **V AC** mode block the DC part and read the ripple's RMS.
For a sawtooth, **Vripple p-p ≈ V AC reading × 3.5** (= 2√3). It's an estimate: cheap meters are not accurate on non-sine waves.

| C | Load R | Adapter (V AC, no load) | Output (V DC) | Ripple (V AC reading) | Ripple p-p (≈ × 3.5, or scope) | Capacitor warm? |
|---|---|---|---|---|---|---|
| 1000 µF | none | | | | | |
| 1000 µF | 1 kΩ | | | | | |
| 1000 µF | 150 Ω | | | | | |
| 1000 µF | 47 Ω | | | | | |
| 100 µF | 150 Ω | | | | | |
| 470 µF | 150 Ω | | | | | |
| 2200 µF | 150 Ω | | | | | |

## How Much Ripple Is Acceptable?

| Application | Acceptable ripple | Is this supply enough? |
|---|---|---|
| Incandescent lamps, heaters, DC motors, relays, buzzers | 10–20% of the voltage | ✅ Yes, even with small C |
| LEDs with resistor | 5–10% (more causes visible flicker on camera, and current varies) | ✅ Yes, with adequate C |
| Simple lead-acid battery charger | Large ripple is fine | ✅ Yes (with current limiting) |
| **Input of a linear regulator** (78xx, LM317) | Any, as long as **V min stays ≥ Vout + dropout** (≈ 2 V for 7805, ≈ 1.5–2 V for LM317) | ✅ **The main real use**: this supply is the first stage of every linear power supply |
| Audio power amplifier (power stage) | 1–3 V p-p with very large C (10 000 µF and more) | 🟡 Often yes: the amplifier rejects much of it, but hum may be audible |
| Audio preamplifier, microphone, sensors | < 1 mV | ❌ Needs regulation and filtering |
| Digital logic, microcontrollers | < 1–2% (e.g. 5 V ± 0.1 V) | ❌ Needs a regulator |
| Measurement, ADC references, RF oscillators | µV – mV | ❌ Needs a regulator plus extra filtering |

**Practical rule**: design the capacitor for **1–2 V of ripple** when a regulator follows (and check V min),
**10% or less** when the load is fed directly.

## Limits of This Supply

1. **The voltage depends on the load.** Diode drop (see [PS-02](graetz-bridge.md)), winding resistance and ripple all grow with current:
   a 12 V unregulated wall adapter gives **≈ 16–17 V without load** and much less at full load.
2. **The voltage depends on the mains.** ±10% on the 230 V means ±10% on the output.
3. **Ripple grows with current.** For 1 A with 1 V ripple you need 10 000 µF: large, heavy, expensive capacitors.
4. **Current pulses.** Diodes conduct only for a short time near each peak, so they deliver the whole charge in short,
   strong pulses (**peak currents 5–10 × the load current**). Consequences:
   - the transformer's RMS current is **1.6–1.8 × the DC current**: it must be oversized (VA rating), and it heats;
   - the capacitor heats (ripple current) and ages;
   - the current drawn from the mains is distorted (harmonics, poor *power factor*).
5. **Inrush current at power-on.** An empty capacitor is a short circuit: big supplies need a slow-blow fuse or an NTC.
6. **Stored energy.** The capacitor stays charged after switching off: always add a **bleeder resistor**.
7. **Size and weight.** A 50 Hz transformer plus big capacitors is bulky: compare an old heavy wall adapter with a phone charger.

**This is why other supplies exist:**

- **Linear regulators** ([PS-04…PS-08](roadmap.md)) fix limits 1, 2 and 3: they cut the ripple and keep the voltage constant,
  at the cost of wasting power as heat.
- **Switching supplies** ([PS-10…PS-13](roadmap.md)) fix limit 7 and efficiency: they work at tens of kHz,
  where transformers and capacitors are tiny. That's how a phone charger is so small.

## Variations to Try

- [ ] Remove two diodes and use a single diode (half-wave): with the same C the ripple doubles.
- [ ] In Falstad, put the scope on the **secondary current**: see the narrow charging pulses.
- [ ] Set the winding resistance to 0 Ω, then 5 Ω: watch the output voltage and the current pulses change.
- [ ] Remove the load and press Reset: see the inrush current on the secondary ammeter.
- [ ] Add an LED with resistor across the output and switch the supply off: the capacitor keeps it lit for a while.

## Conclusion

*To write after the measurements.*

Next: PS-04 – Zener shunt regulator (see the [roadmap](roadmap.md)).
