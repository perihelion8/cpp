Here's a simpler and clearer version of the passage:

---

### Why use an implied leading 1?

If we stored both the mantissa (significand) and exponent directly, the same number could be represented in many different ways:

* (2 \times 10^{-1} = 0.2 \times 10^0 = 0.02 \times 10^1)

All of these equal 0.2, but they would have different bit patterns. Having multiple representations for the same value wastes storage and makes hardware calculations more complicated.

To avoid this, floating-point numbers are **normalized**. In binary, every nonzero number is written so that there is exactly one digit before the binary point, and that digit is always 1.

For example:

* (101.1_2 = 1.011_2 \times 2^2)
* (0.00101_2 = 1.01_2 \times 2^{-3})

Since the leading 1 is always present for normalized numbers, it doesn't need to be stored. The hardware simply assumes it exists. This is called the **implicit (or hidden) leading 1**.

---

### How is zero represented?

There's a problem: zero cannot be normalized because it has no leading 1.

IEEE floating-point solves this by making zero a special case:

* If all exponent bits are 0 and all mantissa bits are 0, the value is **0**.
* The sign bit can still distinguish **+0** and **−0**.

---

### How can we represent 1.0?

The number 1.0 should be:

1.0 = 1.0 \times 2^0

This requires an exponent of 0.

However, exponent bits are not stored directly. Instead, IEEE single-precision uses a **bias of 127**:

Actual exponent = Stored exponent − 127

So:

* Stored exponent = 127 → Actual exponent = 0
* Stored exponent = 128 → Actual exponent = 1
* Stored exponent = 126 → Actual exponent = −1

Therefore, 1.0 is represented with:

* sign = 0
* exponent = 127
* mantissa = 0

---

### What exponent values are lost?

Because exponent values 0 and 255 are reserved for special purposes, normal numbers use exponent fields 1 through 254.

This means the smallest exponent available for a normalized number is:

1-127=-126

So the exponent −127 cannot be used for ordinary normalized numbers.

The designers considered this a reasonable trade-off because representing zero and 1.0 is far more important.

---

### How are infinity and NaN represented?

Some exponent patterns are reserved for special values.

#### Infinity

If:

* exponent bits are all 1s (255)
* mantissa bits are all 0s

then the value is:

* +∞ if sign bit = 0
* −∞ if sign bit = 1

#### NaN (Not a Number)

If:

* exponent bits are all 1s (255)
* mantissa is not zero

then the value is **NaN**.

NaN is used for undefined or invalid results, such as:

* (0/0)
* ∞ × 0
* square root of a negative number (in real arithmetic)

---

### Summary

For IEEE 754 single-precision floats:

| Exponent bits | Mantissa bits | Meaning                              |
| ------------- | ------------- | ------------------------------------ |
| 0             | 0             | Zero                                 |
| 0             | Nonzero       | Subnormal number (very small values) |
| 1–254         | Anything      | Normal floating-point number         |
| 255           | 0             | Infinity                             |
| 255           | Nonzero       | NaN                                  |

The key ideas are:

1. **Store numbers in normalized form** so every nonzero value has a unique representation.
2. **Don't store the leading 1** because it's always known.
3. **Use a bias of 127** so exponent 0 can be represented.
4. **Reserve special exponent patterns** for zero, infinity, and NaN.

