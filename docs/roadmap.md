# Electronics Lab Roadmap

A progressive path from basic circuits to understanding how today's devices work
(phone chargers, Bluetooth speakers, radios, computers, IoT gadgets).

Every experiment follows the same loop:

1. **Theory** – calculate what you expect.
2. **Simulate** – EasyEDA / Falstad (link the circuit).
3. **Build** – breadboard first, perfboard/PCB for the ones worth keeping.
4. **Measure** – compare with the calculation in a table.
5. **Explain the gap** – why reality differs (tolerances, parasitics, datasheet limits).

Use [the template](https://github.com/sasadangelo/electronic/blob/main/docs/_template.md) for each new experiment.

Legend: ✅ done · 🔧 in progress · ⬜ to do · ⚠️ safety note

---

## Lab Setup

What you have: bench power supply, multimeter, soldering iron, hand tools.

Recommended additions, in order of priority:

| Priority | Instrument | Why |
|---|---|---|
| 1 | Breadboards, jumper wires, assorted component kit (R, C, diodes, LEDs, BC547/BC557, 2N2222, IRLZ44N, LM358, NE555, LM317, 78xx) | Raw material for everything below |
| 2 | **Oscilloscope** (2 channels, ≥ 50 MHz) | Biggest leap: without it you can't *see* ripple, distortion, oscillations, PWM, RF. Single most important purchase |
| 3 | Function generator | Needed for audio and filter experiments. You can **build** one (XR2206 kit) – it's itself an experiment (AN-04) |
| 4 | Component tester (LCR-T4 type) | Identifies transistors, measures C, L, ESR |
| 5 | RTL-SDR USB dongle | Opens the whole RF track: see the radio spectrum on your PC |
| 6 | Isolation transformer / ready-made AC wall adapter | ⚠️ Avoid wiring 230 V on a breadboard. Use a 12 V AC adapter or an enclosed transformer |

⚠️ **Safety rules:** never breadboard mains voltage; discharge big capacitors before touching;
the oscilloscope ground clip is connected to earth – never clip it on a mains-referenced node.

---

## Simulation Tools

| Tool | Use it for | Why |
|---|---|---|
| **Falstad CircuitJS** (default) | Tracks 0–3, quick experiments | Runs in the browser, animated current flow, built-in scope. A circuit is plain text: save it in the repo, share it as a link |
| **LTspice** (or ngspice) | Accurate numbers: switching converters (PS-10+), audio distortion (AN-05+), RF (RF-04+) | Real manufacturer models, AC sweep / Bode plots, FFT |
| EasyEDA | Schematic → PCB for the experiments worth keeping | Simulation is heavier, but goes straight to PCB |

Workflow: in Falstad use *File → Export As Text*, save it as `docs/sim/<ID>-<name>.txt`,
and put the share link (*File → Export As Link*) in the experiment doc, both as a link and as an embedded `<iframe>`
(the iframe is interactive on the [project site](https://sasadangelo.github.io/electronic/); github.com hides it). Text files are versioned in git and can be
generated or edited by hand (or with an AI assistant) and re-imported with *File → Import From Text*.

---

## Track 0 – Foundations

Everything else builds on this. Short experiments, mostly multimeter work.

| ID | Experiment | You learn | Key measurement | Status |
|---|---|---|---|---|
| F-01 | [Simple LED](simple-led.md) | Ohm's law, LED forward voltage | I vs. R | ✅ |
| F-02 | Voltage divider & loading effect | Thevenin equivalent, output impedance | Vout with/without load | ⬜ |
| F-03 | Kirchhoff on a resistor network | KVL/KCL, series/parallel | Node voltages vs. calc | ⬜ |
| F-04 | RC charge/discharge | Time constant τ = RC | Time to 63% (stopwatch, then scope) | ⬜ |
| F-05 | Diode I-V curve | Exponential behaviour, Vf vs. current | Table I/V, plot | ⬜ |
| F-06 | Zener diode | Breakdown, voltage reference | Vz vs. input | ⬜ |
| F-07 | Transistor as a switch (BJT) | Saturation, base resistor sizing | Vce(sat), Ib, Ic | ⬜ |
| F-08 | MOSFET as a switch | Logic-level gate, Rds(on) | Heat & drop vs. BJT | ⬜ |
| F-09 | Relay driver with flyback diode | Inductive kickback | Spike with/without diode (scope) | ⬜ |
| F-10 | Op-amp basics (LM358) | Comparator, inverting/non-inverting gain | Gain vs. resistor ratio | ⬜ |

**Milestone:** you can read a datasheet and size a resistor, transistor, or op-amp gain yourself.

---

## Track 1 – Power Supplies

**Goal:** understand how a phone charger / laptop brick works.

| ID | Experiment | You learn | Key measurement | Status |
|---|---|---|---|---|
| PS-01 | [Simple Transformer](simple-transformer.md) | Turns ratio, RMS/peak | Vrms, Vp | ✅ |
| PS-02 | [Graetz Bridge](graetz-bridge.md) | Full-wave rectification, diode drop | Vdrop vs. load | ✅ |
| PS-03 | Reservoir capacitor & ripple | Vripple ≈ I / (2·f·C) | Ripple vs. C and load | ⬜ |
| PS-04 | Zener shunt regulator | Simplest regulation, its inefficiency | Line/load regulation | ⬜ |
| PS-05 | Series-pass regulator (zener + transistor) | How a linear regulator works inside | Regulation vs. PS-04 | ⬜ |
| PS-06 | 78xx fixed regulator | Dropout, heat dissipation P = (Vin−Vout)·I | Heatsink temperature | ⬜ |
| PS-07 | LM317 variable regulator | Feedback, reference voltage | Vout = 1.25·(1+R2/R1) | ⬜ |
| PS-08 | Current limiter / constant-current source (LM317) | CC mode, LED drivers | I vs. load | ⬜ |
| PS-09 | Joule thief | Inductors store energy, blocking oscillator | Light an LED from 0.8 V | ⬜ |
| PS-10 | Buck converter (MC34063 or 555 + MOSFET) | Switching, PWM, LC filter, efficiency | η = Pout/Pin vs. linear | ⬜ |
| PS-11 | Boost converter | Stepping voltage *up* | 5 V → 12 V, efficiency | ⬜ |
| PS-12 | Li-ion charger (TP4056) + protection | CC/CV charging | Charge curve | ⬜ |
| PS-13 | Teardown: USB phone charger | Flyback, optocoupler feedback, isolation | ⚠️ unplugged only, identify blocks | ⬜ |

**Capstone PS-X:** build your own dual-rail bench supply (±12 V, current limit, display).

---

## Track 2 – Analog Audio / Hi-Fi

**Goal:** understand how an amplifier and a Bluetooth speaker work.

| ID | Experiment | You learn | Key measurement | Status |
|---|---|---|---|---|
| AN-01 | Passive RC filters (low/high-pass) | Cutoff frequency f = 1/(2πRC) | Bode plot by hand | ⬜ |
| AN-02 | Common-emitter amplifier | Biasing, gain, clipping | Gain, max swing | ⬜ |
| AN-03 | Emitter follower | Impedance buffering | Drive a speaker: with/without | ⬜ |
| AN-04 | Function generator (XR2206) | Oscillators; also a lab tool | Frequency range | ⬜ |
| AN-05 | Class B push-pull | Crossover distortion | See it on the scope | ⬜ |
| AN-06 | Class AB (diode bias) | Fixing crossover, quiescent current | Distortion gone | ⬜ |
| AN-07 | Microphone preamp (op-amp) | Single-supply biasing, noise | Gain, noise floor | ⬜ |
| AN-08 | LM386 mini amplifier | Integrated power amp | Output power, heat | ⬜ |
| AN-09 | Baxandall tone control | Active filters with feedback | Bass/treble response | ⬜ |
| AN-10 | TDA2030 / TDA7294 power amp | Real Hi-Fi amp, PSU requirements, stability | Power, THD by ear/scope | ⬜ |
| AN-11 | Passive speaker crossover | LC filters, speaker impedance | Response per driver | ⬜ |
| AN-12 | Class D concept (comparator + triangle + MOSFET + LC) | PWM audio, why modern amps are efficient | η vs. AN-10 | ⬜ |
| AN-13 | LED VU meter (LM3915) | Log scale, dB | Response to signal | ⬜ |

**Capstone AN-X:** stereo amplifier with tone control and its own power supply (reuses Track 1).

---

## Track 3 – Digital Logic

**Goal:** understand how a computer computes, from gates up.

| ID | Experiment | You learn | Key measurement | Status |
|---|---|---|---|---|
| DG-01 | Logic gates with transistors (RTL) | What a gate *is* | Truth table | ⬜ |
| DG-02 | CMOS gates (CD4011) | NAND as universal gate | Build NOT/AND/OR from NAND | ⬜ |
| DG-03 | 555 astable & monostable | Timing, the most famous IC | f vs. R, C | ⬜ |
| DG-04 | SR latch & D flip-flop | Memory: 1 bit | State retention | ⬜ |
| DG-05 | Button debouncing (RC + Schmitt) | Bounce is real | See bounces on scope | ⬜ |
| DG-06 | Counter (CD4017 / CD4026 + 7-seg) | Sequential logic | Count clock pulses | ⬜ |
| DG-07 | Half/full adder | Binary arithmetic in hardware | 2-bit adder works | ⬜ |
| DG-08 | Shift register (74HC595) | Serial → parallel, how displays are driven | 8 LEDs from 3 pins | ⬜ |
| DG-09 | R-2R DAC & simple ADC | Analog ↔ digital bridge | Linearity | ⬜ |

**Capstone DG-X:** digital clock or dice built only with logic ICs (no microcontroller).

---

## Track 4 – Radio Frequency

**Goal:** understand how radio, WiFi and phones transmit information.
⚠️ Transmitting is regulated: keep transmitters at very low power, short range, legal bands.

| ID | Experiment | You learn | Key measurement | Status |
|---|---|---|---|---|
| RF-01 | LC resonance | f = 1/(2π√LC) | Resonant peak with generator | ⬜ |
| RF-02 | Crystal radio (no battery!) | Tuning, AM detection, antennas | Stations received | ⬜ |
| RF-03 | Crystal radio + transistor amp | Adding gain | Volume improvement | ⬜ |
| RF-04 | Colpitts / Hartley oscillator | Positive feedback | Frequency vs. LC (scope) | ⬜ |
| RF-05 | AM receiver IC (TA7642 / MK484) | TRF receiver | Sensitivity | ⬜ |
| RF-06 | Low-power FM transmitter | Frequency modulation | Hear it on an FM radio | ⬜ |
| RF-07 | RTL-SDR: exploring the spectrum | FM, ADS-B, weather sats, 433 MHz | Waterfall screenshots | ⬜ |
| RF-08 | Superheterodyne concept (mixer + IF) | Why every radio is a superhet | Mixing products | ⬜ |
| RF-09 | Dipole antenna for a chosen band | λ/2, impedance | SDR signal improvement | ⬜ |
| RF-10 | 433 MHz modules + Arduino | Digital modulation (OOK/ASK) | Range test | ⬜ |

**Capstone RF-X:** superheterodyne AM/shortwave receiver kit, then explain each stage.

---

## Track 5 – Microcontrollers & Sensors

**Goal:** understand IoT devices, smart home gadgets, embedded systems.

| ID | Experiment | You learn | Key measurement | Status |
|---|---|---|---|---|
| MC-01 | [Blink](https://github.com/sasadangelo/electronic/tree/main/arduino/blink/) / [MyBlink](https://github.com/sasadangelo/electronic/tree/main/arduino/myblink/) | GPIO output | — | ✅ |
| MC-02 | [RGB LED](https://github.com/sasadangelo/electronic/tree/main/arduino/rgb/) | PWM, color mixing | PWM on scope | ✅ |
| MC-03 | [Digital inputs](https://github.com/sasadangelo/electronic/tree/main/arduino/digital-inputs/) | Pull-up, buttons | — | 🔧 |
| MC-04 | Analog read: potentiometer, LDR, NTC | ADC, resolution, voltage dividers (F-02) | ADC counts vs. multimeter | ⬜ |
| MC-05 | Driving loads with MOSFET (F-08) | MCU pins can't drive motors | Current from pin vs. load | ⬜ |
| MC-06 | DC motor with H-bridge | Direction, PWM speed | Current vs. speed | ⬜ |
| MC-07 | Servo & stepper | Position control | Steps/rev | ⬜ |
| MC-08 | I²C and SPI sensors (BME280, OLED) | Serial buses | Decode on scope | ⬜ |
| MC-09 | UART & serial protocols | How devices talk | Baud rate on scope | ⬜ |
| MC-10 | Arduino oscilloscope / data logger | Sampling, Nyquist | Max frequency | ⬜ |
| MC-11 | ESP32 + WiFi + MQTT | IoT: device → cloud | Live dashboard | ⬜ |
| MC-12 | Low-power design (sleep modes) | Battery life | µA in sleep | ⬜ |

**Capstone MC-X:** battery-powered WiFi weather station (Tracks 0, 1, 5 together).

---

## Suggested Order

The tracks are parallel, but this order keeps prerequisites satisfied:

| Phase | Do | Unlocks |
|---|---|---|
| 1 | F-01…F-06, PS-03…PS-04, MC-03…MC-04, RF-02 | Basic measurement skills; first "wow" (radio without batteries) |
| 2 | F-07…F-10, PS-05…PS-08, DG-01…DG-05, AN-01…AN-03 | Transistors & op-amps in real circuits |
| 3 | AN-04…AN-09, RF-01, RF-03…RF-07, DG-06…DG-09, MC-05…MC-09 | Oscillators, amplifiers, logic |
| 4 | PS-09…PS-13, AN-10…AN-13, RF-08…RF-10, MC-10…MC-12 | Switching & modern techniques |
| 5 | Capstones | Full devices you designed and understand |

---

## Final Goal: "How does it work?"

When the tracks are done, you should be able to open these and name every block:

| Device | Tracks involved |
|---|---|
| USB phone charger | PS (flyback, feedback) |
| Bluetooth speaker | PS (Li-ion, boost) + AN (class D) + RF (2.4 GHz) + MC |
| FM/DAB radio | RF (superhet/SDR) + AN + PS |
| Smart plug | PS (non-isolated buck) + MC (ESP32) + F (relay) |
| Computer | DG + MC + PS (buck converters on the motherboard) |
