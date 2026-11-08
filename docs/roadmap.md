# Electronics Lab Roadmap

A progressive path from basic circuits to understanding how today's devices work
(phone chargers, Bluetooth speakers, radios, computers, IoT gadgets).

Every experiment follows the same loop:

1. **Theory** – calculate what you expect.
2. **Simulate** – Falstad (link and embed the circuit); LTspice when precision matters.
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

Few tools, introduced one at a time, only when a track needs them. All free and available on macOS.

| Tool | Use it for | Tracks | When to start |
|---|---|---|---|
| **Falstad CircuitJS** (default) | Understanding how a circuit behaves: animated current, built-in scope and meters. Circuits are plain text, saved in the repo and embedded in the site | 0, 1, 2, 3, concepts of 4 | Now |
| **Wokwi** (wokwi.com) | Arduino / ESP32 **with your own code**, sensors, displays, WiFi. Embeddable like Falstad | 5, 6, 8 | Track 5 |
| **KiCad** (with built-in ngspice simulator) | Schematic → PCB, and accurate simulation of the same schematic: real models, Bode plots, FFT, switching efficiency | 9, then 1 (PS-10+), 2 (AN-05+) | Track 9 |
| LTspice (alternative to KiCad's simulator) | Same as above, with many manufacturer models | 1, 2, 4 | Only if needed |
| CircuitVerse (browser) / Logisim Evolution | Complex digital logic, up to building a CPU | 3, FPGA | If Track 3 hooks you |
| Qucs-S | RF: filters, impedance matching, S-parameters | 4 | If Track 4 hooks you |
| SDR++ + RTL-SDR | Not a simulator: the real radio spectrum on your PC | 4, 6 | RF-07 |

What Falstad **can't** do: microcontroller code, manufacturer SPICE models, AC sweep / precise distortion,
antennas and high-frequency parasitics, thermal behaviour, PCB layout. Tracks 7 (repair) need the bench, not a simulator.

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

## Track 6 – Real Devices: How They Work

👉 See also the **[Device Roadmap](devices.md)**: everyday devices ordered from simple to complex, with typical faults.

**Goal:** take everyday devices, find their blocks, measure their signals, then rebuild or emulate them.
Each experiment = **teardown + block diagram + measurements + a breadboard replica**.

| ID | Device | You learn | Experiment | Prereq | Status |
|---|---|---|---|---|---|
| DV-01 | Flashlight / LED bulb | Current regulation, LED drivers | Measure LED current; replicate with PS-08 | F-01, PS-08 | ⬜ |
| DV-02 | Infrared remote control | 38 kHz carrier, pulse coding (NEC, RC5) | See IR pulses with a photodiode + scope; decode with Arduino | DG-03, MC-03 | ⬜ |
| DV-03 | IR receiver (TV side) | Demodulator module (TSOP), filtering | Build a receiver that switches a relay | DV-02 | ⬜ |
| DV-04 | IR remote clone | Transmitting codes | Arduino that replays your TV remote | DV-02 | ⬜ |
| DV-05 | Electret microphone | JFET inside, bias resistor | Bias it, see the signal on the scope | AN-02 | ⬜ |
| DV-06 | Dynamic mic & speaker | Electromagnetic transducers, they're reversible | Use a speaker as a microphone | AN-07 | ⬜ |
| DV-07 | MEMS microphone (I²S) | Digital audio from a chip | Record with ESP32 | MC-08 | ⬜ |
| DV-08 | Headphones & wired earbuds | Impedance, sensitivity, inline mic/buttons | Measure impedance; decode button presses | AN-08 | ⬜ |
| DV-09 | Portable AM/FM radio | Superheterodyne in a real product | Trace signal stage by stage | RF-05, RF-08 | ⬜ |
| DV-10 | 433 MHz remote (gate, garage, doorbell) | OOK coding, rolling codes vs. fixed codes | Capture with RTL-SDR; ⚠️ only your own devices | RF-07, RF-10 | ⬜ |
| DV-11 | Smoke detector | Low-power sensing, piezo buzzer | Measure standby current, alarm circuit | MC-12 | ⬜ |
| DV-12 | Battery charger & power bank | Li-ion charging, boost, protection | Charge/discharge curves | PS-11, PS-12 | ⬜ |
| DV-13 | Toy RC car | RF link, H-bridge, servo | Map receiver → motor driver | MC-06, RF-10 | ⬜ |
| DV-14 | Computer ATX power supply | Standby rail, PFC, multiple outputs | ⚠️ unplugged & discharged only: identify blocks | PS-13 | ⬜ |

**Capstone DV-X:** pick a device you own, document its full block diagram and schematic (reverse-engineered).

---

## Track 7 – Troubleshooting & Repair

**Goal:** be able to diagnose and fix a large range of devices.
Start from battery-powered, low-voltage devices; mains-powered ones only at the end.

Extra tools for this track: desoldering pump and wick, flux, magnifier/USB microscope,
ESR meter (the component tester does it), hot-air station for SMD, and a **series-lamp limiter**
(a light bulb in series with the mains plug) before powering up any repaired mains device.

| ID | Skill / Repair | You learn | Practice on | Status |
|---|---|---|---|---|
| RP-01 | Soldering & desoldering THT | Good joints, removing parts without damage | Practice kit, old boards | ⬜ |
| RP-02 | SMD soldering | 0805 resistors, SOIC chips, hot air | SMD practice kit | ⬜ |
| RP-03 | Reading schematics & service manuals | Symbols, block diagrams, test points | Manuals of devices you own | ⬜ |
| RP-04 | The troubleshooting method | Symptom → hypothesis → measure → isolate | Any faulty device | ⬜ |
| RP-05 | Power first | Check fuse, rails, ripple: most faults are in the PSU | DV devices | ⬜ |
| RP-06 | Component testing in/out of circuit | Diodes, transistors, caps (ESR), shorts | Component tester + multimeter | ⬜ |
| RP-07 | Classic failures | Dried electrolytics, cold joints, broken cables/connectors, dirty pots | Old audio gear | ⬜ |
| RP-08 | Signal tracing | Inject a signal, follow it until it disappears | Radio, amplifier | ⬜ |
| RP-09 | Repair: remote control | Contacts, crystal/resonator, IR LED | A dead remote | ⬜ |
| RP-10 | Repair: headphones / cables | Broken wires, jacks | Faulty headphones | ⬜ |
| RP-11 | Repair: battery toys & gadgets | Battery contacts, motor drivers, switches | Broken toys | ⬜ |
| RP-12 | Repair: audio amplifier | Bias, output transistors, protection relay | Old Hi-Fi amp | ⬜ |
| RP-13 | Repair: switching power supply | Fuse, bridge, primary cap, controller | ⚠️ discharge primary cap; use series lamp | ⬜ |
| RP-14 | Repair log | Document each repair like an experiment | All of the above | ⬜ |

⚠️ **Never open:** microwave ovens (lethal capacitor and transformer), CRT TVs, and anything with
large mains capacitors you can't safely discharge.

**Capstone RP-X:** fix 10 different devices from friends/family and document them in `docs/repairs/`.

---

## Track 8 – Build Your Own Instruments

**Goal:** understand how measuring instruments work, and their limits, by building them.
Every instrument you build also upgrades your lab.

| ID | Instrument | You learn | Prereq | Status |
|---|---|---|---|---|
| IN-01 | Understanding your multimeter | Accuracy, resolution, burden voltage, input impedance | F-01, F-02 | ⬜ |
| IN-02 | Logic probe | Thresholds, high/low/pulse detection | DG-02 | ⬜ |
| IN-03 | Continuity tester with tone | 555 oscillator, low test current | DG-03 | ⬜ |
| IN-04 | Electronic DC load | Op-amp + MOSFET constant current, heat | F-10, PS-08 | ⬜ |
| IN-05 | Frequency counter (Arduino) | Gating, timers, input conditioning | MC-09 | ⬜ |
| IN-06 | LC meter | Oscillator frequency → L and C | RF-04, IN-05 | ⬜ |
| IN-07 | Transistor curve tracer | Ic vs. Vce, gain, using the scope in X-Y mode | F-07, AN-02 | ⬜ |
| IN-08 | Arduino/ESP32 oscilloscope & logic analyzer | Sampling, triggering, Nyquist | MC-10 | ⬜ |
| IN-09 | Signal injector / tracer | Square wave rich in harmonics, audio probe | RP-08 | ⬜ |
| IN-10 | Calibration & accuracy | Voltage references, comparing instruments | All of the above | ⬜ |

**Capstone IN-X:** a benchtop "lab box" combining electronic load, frequency counter and LC meter in one enclosure.

---

## Track 9 – PCB Design (KiCad)

**Goal:** turn breadboard experiments into finished boards, and work with SMD parts.

| ID | Step | You learn | Status |
|---|---|---|---|
| PCB-01 | Perfboard / stripboard layout | Planning a layout by hand | ⬜ |
| PCB-02 | KiCad schematic | Symbols, nets, ERC | ⬜ |
| PCB-03 | KiCad layout: first board (F-01 LED + battery) | Footprints, traces, DRC, Gerbers | ⬜ |
| PCB-04 | Ordering a PCB (JLCPCB / PCBWay) | Fab rules, cost, turnaround | ⬜ |
| PCB-05 | Trace width, current & heat | Copper thickness, power paths | ⬜ |
| PCB-06 | Ground planes & decoupling | Why every chip has a 100 nF cap next to it | ⬜ |
| PCB-07 | SMD board assembly | Stencil, solder paste, hot air (with RP-02) | ⬜ |
| PCB-08 | Board for a switching converter | Loop area, layout makes or breaks PS-10 | ⬜ |
| PCB-09 | Mixed analog/digital board | Separating noisy and quiet sections | ⬜ |
| PCB-10 | Enclosure & front panel | 3D-printed or drilled box, connectors | ⬜ |

**Capstone PCB-X:** your bench supply (PS-X) or amplifier (AN-X) on a custom PCB, in an enclosure.

---

## Suggested Order

The tracks are parallel, but this order keeps prerequisites satisfied:

| Phase | Do | Unlocks |
|---|---|---|
| 1 | F-01…F-06, PS-03…PS-04, MC-03…MC-04, RF-02, RP-01, DV-01, IN-01, PCB-01 | Basic measurement skills; first "wow" (radio without batteries) |
| 2 | F-07…F-10, PS-05…PS-08, DG-01…DG-05, AN-01…AN-03, RP-03…RP-06, DV-05, IN-02…IN-03 | Transistors & op-amps in real circuits |
| 3 | AN-04…AN-09, RF-01, RF-03…RF-07, DG-06…DG-09, MC-05…MC-09, DV-02…DV-08, RP-02, RP-07…RP-11, IN-04…IN-07, PCB-02…PCB-06 | Oscillators, amplifiers, logic |
| 4 | PS-09…PS-13, AN-10…AN-13, RF-08…RF-10, MC-10…MC-12, DV-09…DV-14, RP-12…RP-13, IN-08…IN-10, PCB-07…PCB-10 | Switching & modern techniques |
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
| TV remote & receiver | DG (555, coding) + MC + F (IR LED, photodiode) |
| Microphone (electret, dynamic, MEMS) | AN (preamp) + MC (I²S) |
| Garage / gate remote | RF (433 MHz, OOK) + DG |

And when one of them breaks, Track 7 gives you the method to fix it.

---

## Future Ideas

Areas to explore once the main tracks are well under way:

| Area | What's inside | Why |
|---|---|---|
| Motors & power electronics | DC, stepper, brushless (BLDC); ESCs, inverters | How drones, e-bikes, washing machines, PC fans work |
| Synthesizers & music electronics | VCO, VCF, ADSR, guitar effects (fuzz, overdrive, delay) | Fun projects mixing analog, audio and digital |
| Energy & solar | Panels, MPPT, BMS, UPS, home energy monitoring | Real-world power systems |
| Displays & optoelectronics | LCD, OLED, e-ink, LED matrices, photodiodes, fiber | How screens and optical links work |
| Automotive electronics | CAN bus, OBD-II, ECUs | Talk to your car with an ESP32 |
| Home automation | Home Assistant, ESPHome, Zigbee | Natural follow-up of Track 5 |
| Biosignals | ECG (AD8232), heart rate | ⚠️ Battery only, never with a mains-connected PC |
| FPGA & digital design | Verilog, build your own CPU | Follow-up of Track 3 |
| DSP | Digital filters, FFT | Noise-cancelling headphones, digital audio |
| Noise, grounding & EMC | Hum, interference, shielding | What separates "works" from "works well" |
| Amateur radio license | Legal transmitting, home-built transmitters | If the RF track hooks you (exam at MIMIT, Italy) |
| Vintage electronics | Tube radios and amplifiers restoration | ⚠️ 250–400 V: only with solid experience |
