# Device Roadmap

Everyday devices, from the simplest to the most complex: how they work and how to repair them.
Each device becomes an article (teardown → block diagram → measurements → typical faults → repair log).

The **Learn first** column points to experiments in the [main roadmap](roadmap.md).
The repair method (power first, then signal tracing) is in Track 7 of the roadmap.

**Risk legend**

| | Meaning |
|---|---|
| 🟢 | Battery or low voltage: safe to work on while powered |
| 🟡 | Low voltage, but Li-ion batteries or high currents: no short circuits, no punctured cells |
| 🟠 | Mains-powered: open and repair **unplugged only**; discharge capacitors first |
| 🔴 | Mains-powered with high-voltage sections: measure only with series lamp / isolation transformer, after experience with 🟠 |
| ⛔ | Don't open |

---

## Level 1 – Simple Circuits (no electronics, or almost)

Learn: continuity tests, switches, contacts, soldering wires.

| Device | Main blocks | Typical faults | Learn first | Risk | Status |
|---|---|---|---|---|---|
| Flashlight (incandescent / LED) | Battery, switch, bulb or LED + resistor | Corroded contacts, broken switch, dead LED | F-01 | 🟢 | ⬜ |
| USB / audio cables | Wires, shield, connectors | Broken wire near the connector | RP-01 | 🟢 | ⬜ |
| Wired headphones | Drivers (small speakers), cable, jack | Wire broken at jack or earpiece, open driver | RP-01, DV-08 | 🟢 | ⬜ |
| Battery toys with a motor | Battery, switch, DC motor, gears | Battery contacts, worn brushes, stuck gears | F-07 | 🟢 | ⬜ |
| Christmas lights | Series/parallel LED strings, controller | One open LED kills a series string, broken wire | F-01, F-03 | 🟢 | ⬜ |
| Wired doorbell / buzzer | Transformer or battery, button, electromagnet or piezo | Button contacts, coil open | PS-01 | 🟢 | ⬜ |

## Level 2 – Small Electronics, Low Voltage

Learn: reading a simple PCB, identifying chips, oscillators, keypads.

| Device | Main blocks | Typical faults | Learn first | Risk | Status |
|---|---|---|---|---|---|
| IR remote control | Key matrix, microcontroller, ceramic resonator, IR LED | Worn rubber keys, cracked resonator, battery contacts. Tip: phone camera sees IR | DV-02 | 🟢 | ⬜ |
| Quartz wall clock | 32,768 Hz crystal, divider, stepper (Lavet) motor | Dry gears, open coil, battery contacts | DG-03, DG-06 | 🟢 | ⬜ |
| Calculator / digital thermometer | MCU, LCD, sensor (NTC) | Battery leak corrosion, LCD zebra strip | MC-04 | 🟢 | ⬜ |
| Kitchen / bathroom scale | Load cells (strain gauges), amplifier (HX711-like), LCD | Broken load-cell wire, battery contacts | F-02, AN-07 | 🟢 | ⬜ |
| Mouse & keyboard | Microswitches, optical sensor, USB controller | **Double-click** (worn microswitch), broken cable | DG-05, RP-01 | 🟢 | ⬜ |
| USB computer speakers | Class D amp chip, volume pot, drivers | Scratchy pot, broken cable, blown amp chip | AN-08, AN-12 | 🟢 | ⬜ |
| Smoke detector | Optical chamber, low-power MCU, piezo | Dirty chamber, battery | DV-11 | 🟢 | ⬜ |

## Level 3 – Rechargeable Devices & Power Conversion

Learn: Li-ion charging, protection circuits, boost/buck converters, wireless links.

| Device | Main blocks | Typical faults | Learn first | Risk | Status |
|---|---|---|---|---|---|
| Old linear wall adapter (heavy type) | Transformer, bridge, capacitor, maybe regulator | Open thermal fuse in transformer, dried capacitor, broken cable | PS-01…PS-06 | 🟠 | ⬜ |
| Power bank | Li-ion cells, protection (BMS), charger IC, boost | Worn cells, broken USB connector, dead boost | PS-11, PS-12 | 🟡 | ⬜ |
| Electric toothbrush / shaver | Inductive charging coil, NiMH/Li-ion cell, motor | Worn battery, water ingress | PS-12, F-08 | 🟡 | ⬜ |
| Bluetooth speaker | Li-ion, charger, BT module, class D amp, drivers | Battery, charging connector, torn speaker cone | DV-12, AN-12 | 🟡 | ⬜ |
| Walkie-talkie / cordless phone | Transceiver, audio amp, battery pack | Battery pack, antenna, keypad | RF-06, RF-08 | 🟡 | ⬜ |
| Cordless drill / power tools | Battery pack + BMS, brushed motor, speed trigger (PWM MOSFET) | Dead cell in pack, worn brushes, burnt trigger | MC-05, MC-06 | 🟡 | ⬜ |

## Level 4 – Mains-Powered Audio, Radio & Appliances

Learn: working safely with mains devices, linear PSUs, audio stages, heating and thermostats.

| Device | Main blocks | Typical faults | Learn first | Risk | Status |
|---|---|---|---|---|---|
| Kettle / hair dryer / iron | Heating element, thermostat, **thermal fuse**, switch | Thermal fuse open (classic, easy fix), broken cable | F-03 | 🟠 | ⬜ |
| Desk / floor fan | AC motor, **run capacitor**, speed switch | Run capacitor dried out (fan hums, won't start) | PS-01 | 🟠 | ⬜ |
| Portable AM/FM radio | Superhet receiver, audio amp, linear PSU | Dirty volume pot, broken antenna, dried caps | DV-09 | 🟠 | ⬜ |
| Vintage Hi-Fi amplifier | Linear PSU, preamp, tone control, power stage, protection relay | Dirty pots/switches, **protection relay**, dried caps, blown output transistors | AN-06, AN-10, RP-12 | 🔴 | ⬜ |
| Turntable / cassette deck | Motor speed control, belts, preamp | **Worn belts** (mechanical!), speed drift | AN-07, MC-06 | 🟠 | ⬜ |
| LED bulb | Non-isolated driver (buck or capacitive dropper), LED strings | One LED open in the string | DV-01, PS-10 | 🔴 | ⬜ |
| Smart plug / WiFi bulb | Non-isolated buck, ESP-type MCU, relay | Dead PSU capacitor, relay contacts | MC-11, F-09 | 🔴 | ⬜ |

## Level 5 – Switching Power Supplies & Motor Control

Learn: flyback/forward converters, feedback with optocouplers, power stages, control boards.

| Device | Main blocks | Typical faults | Learn first | Risk | Status |
|---|---|---|---|---|---|
| USB phone charger | Flyback, controller IC, optocoupler feedback, isolation | Blown fuse/primary, dried output cap | PS-13 | 🔴 | ⬜ |
| Laptop power brick | Flyback with PFC, ID chip (some brands) | Broken DC cable (most common!), output cap | PS-13, RP-13 | 🔴 | ⬜ |
| PC ATX power supply | Standby PSU, PFC, main converter, multiple rails | Standby circuit, bulging caps, fan | DV-14, RP-13 | 🔴 | ⬜ |
| Coffee machine | Heater, pump, thermostats, control board | Scale, thermal fuse, pump, relay on board | RP-05 | 🟠 | ⬜ |
| Vacuum cleaner / food processor | Universal motor, speed control (triac) | Brushes, triac, switch | MC-06 | 🟠 | ⬜ |
| Washing machine / dishwasher | Control board, motor driver, pump, door lock, sensors | Door lock, drain pump, relays, heater | All of Level 4 | 🔴 | ⬜ |

## Level 6 – Complex Devices (partial repairs)

Learn: modular diagnosis. You won't fix every chip, but you can fix the most common faults.

| Device | What you **can** fix | What's out of reach | Risk | Status |
|---|---|---|---|---|
| LCD TV / monitor | Power supply board, **LED backlight strips** (very common fault), loose connectors | Main board chips, panel | 🔴 | ⬜ |
| Printer | Rollers, sensors, PSU, motors | Firmware, print heads | 🟠 | ⬜ |
| Laptop | Battery, charging port, keyboard, fan cleaning, SSD/RAM | Motherboard BGA chips | 🟡 | ⬜ |
| Smartphone / tablet | Battery, screen, charging port (modular parts) | Board-level microsoldering | 🟡 | ⬜ |
| Game controller | Joystick modules (drift!), buttons, battery | Main chip | 🟢 | ⬜ |
| ⛔ Microwave oven | Nothing: lethal capacitor and transformer, even unplugged | Everything | ⛔ | — |
| ⛔ CRT TV / monitor | Nothing without specific training: very high voltage | Everything | ⛔ | — |

---

## Where to Find Broken Devices

Buying broken devices is the cheapest way to practice: no risk of ruining something you need.

| Where | What to search | Notes |
|---|---|---|
| **Subito.it** | "guasto", "non funzionante", "per ricambi", "da riparare" | Often a few euros; local pickup, no shipping |
| **eBay** | Condition **"For parts or not working"** ("Per parti di ricambio o non funzionante") | Huge choice, especially vintage Hi-Fi, radios, instruments |
| **Second-hand markets** | Boxes of mixed electronics | Very cheap; sellers often don't know if it works |
| **Electronics & ham radio fairs** | Surplus, radios, instruments | E.g. Marzaglia, Montichiari, Pordenone and many local fairs; great for parts and tools too |
| **Friends, family, colleagues** | "Got anything broken to throw away?" | Free, and a favour if you fix it |
| **Repair Café** | Volunteer repair events | Learn from experienced people on real devices; held in many cities |
| **Municipal reuse centres** | Discarded items | Depends on the town; recycling centres (RAEE) usually don't allow taking items |

**What to buy first:** follow the levels above.
Levels 1–2 (headphones, remotes, mice, toys, USB speakers) are free or 1–5 €.
Then portable radios, old linear adapters, Bluetooth speakers.
**Vintage Hi-Fi amplifiers** are the best repair training: schematics are often online, parts are large,
faults are classic, and once fixed they are worth something.

**Tip: buy two identical units.** Compare voltages and waveforms between a working and a broken one
(or two broken ones): it's the fastest way to find a fault, and one can donate parts to the other.

**Avoid:**

- ⚠️ Swollen or damaged **lithium batteries**: fire risk. Remove them and take them to a collection point.
- ⛔ Microwave ovens and CRT TVs (see Level 6).
- Devices with obvious **fire damage**: damage is usually extensive and frustrating as a first repair.
- Highly integrated modern boards (smartphones, motherboards) as first repairs.

**Legal note:** if you repair a mains-powered device **and then sell or give it away**, you are responsible
for its safety. For practice and personal use, no problem.

---

## How to Document a Device

For each device, create `docs/devices/<name>.md` with:

1. **What it does** and photos (outside and inside).
2. **Block diagram**: which blocks you recognize, linked to the roadmap experiments.
3. **Measurements**: key voltages and waveforms (scope screenshots).
4. **Fault & diagnosis** (if broken): symptom → hypotheses → measurements → cause.
5. **Repair**: parts replaced, cost, result.
6. **What I learned.**
