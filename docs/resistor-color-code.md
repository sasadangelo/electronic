# Resistor Color Code

Through-hole resistors show their value with colored bands. This page is a quick reference
to read them and to pick standard values when designing.

## Color Table

| Color | | Digit | Multiplier | Tolerance |
|---|---|---|---|---|
| Black | <span style="display:inline-block;width:2.5em;height:1em;background:#000000;border:1px solid #999"></span> | 0 | ×1 | |
| Brown | <span style="display:inline-block;width:2.5em;height:1em;background:#8B4513;border:1px solid #999"></span> | 1 | ×10 | ±1% |
| Red | <span style="display:inline-block;width:2.5em;height:1em;background:#E00000;border:1px solid #999"></span> | 2 | ×100 | ±2% |
| Orange | <span style="display:inline-block;width:2.5em;height:1em;background:#FF8C00;border:1px solid #999"></span> | 3 | ×1 k | |
| Yellow | <span style="display:inline-block;width:2.5em;height:1em;background:#FFE000;border:1px solid #999"></span> | 4 | ×10 k | |
| Green | <span style="display:inline-block;width:2.5em;height:1em;background:#00A000;border:1px solid #999"></span> | 5 | ×100 k | ±0.5% |
| Blue | <span style="display:inline-block;width:2.5em;height:1em;background:#0050E0;border:1px solid #999"></span> | 6 | ×1 M | ±0.25% |
| Violet | <span style="display:inline-block;width:2.5em;height:1em;background:#8A2BE2;border:1px solid #999"></span> | 7 | ×10 M | ±0.1% |
| Grey | <span style="display:inline-block;width:2.5em;height:1em;background:#808080;border:1px solid #999"></span> | 8 | ×100 M | ±0.05% |
| White | <span style="display:inline-block;width:2.5em;height:1em;background:#FFFFFF;border:1px solid #999"></span> | 9 | ×1 G | |
| Gold | <span style="display:inline-block;width:2.5em;height:1em;background:#D4AF37;border:1px solid #999"></span> | | ×0.1 | ±5% |
| Silver | <span style="display:inline-block;width:2.5em;height:1em;background:#C0C0C0;border:1px solid #999"></span> | | ×0.01 | ±10% |
| None | | | | ±20% |

## How to Read It

**Which side to start from?** The tolerance band (usually gold or brown) is at the right, often a bit
separated from the others. Gold and silver are never the first band.

**4 bands** (±5% resistors, the most common in kits):

| Band 1 | Band 2 | Band 3 | Band 4 |
|---|---|---|---|
| 1st digit | 2nd digit | Multiplier | Tolerance |

**5 bands** (±1% metal film resistors):

| Band 1 | Band 2 | Band 3 | Band 4 | Band 5 |
|---|---|---|---|---|
| 1st digit | 2nd digit | 3rd digit | Multiplier | Tolerance |

## Examples

| Value | 4 bands (±5%) | 5 bands (±1%) |
|---|---|---|
| 220 Ω | red · red · brown · gold | red · red · black · black · brown |
| 390 Ω (used in [Simple LED](simple-led.md)) | orange · white · brown · gold | orange · white · black · black · brown |
| 680 Ω | blue · grey · brown · gold | blue · grey · black · black · brown |
| 1 kΩ | brown · black · red · gold | brown · black · black · brown · brown |
| 10 kΩ | brown · black · orange · gold | brown · black · black · red · brown |
| 100 kΩ | brown · black · yellow · gold | brown · black · black · orange · brown |

Example, reading 390 Ω: orange (3) · white (9) · brown (×10) → 39 × 10 = **390 Ω**, gold → **±5%**.

## Standard Values (E12 Series)

Resistors are not made in every value. The E12 series (±10%, but also used for ±5%)
repeats these numbers in every decade (×1, ×10, ×100, ×1k, …):

| 10 | 12 | 15 | 18 | 22 | 27 | 33 | 39 | 47 | 56 | 68 | 82 |
|---|---|---|---|---|---|---|---|---|---|---|---|

So the available values around 390 Ω are … 270, 330, **390**, 470, 560 …

**Which one to pick when the calculation falls between two values?** For a current-limiting
resistor (like an LED), choose the **next value up**: the current will be slightly lower, never higher.

## Tips

- Colors are hard to tell apart under poor light (red/orange, brown/red, blue/violet).
  **When in doubt, measure it with the ohmmeter**, with the resistor out of the circuit.
- The ohmmeter shows the real value: a ±5% 390 Ω resistor can read anywhere from 370 to 410 Ω.
- SMD resistors use a numeric code instead: `391` = 39 × 10¹ = 390 Ω, `103` = 10 × 10³ = 10 kΩ.
