#ifndef BIT_MATH_H
#define BIT_MATH_H

/**
 * @file  bit_math.h
 * @brief Generic bit-manipulation macros for 8-bit registers (AVR-style).
 *
 * @note  Arguments must be simple lvalues/literals (e.g. reg, 3, x).
 *        Passing expressions (e.g. x+1) as Bit or Register may produce
 *        incorrect results due to macro text-substitution and operator
 *        precedence. Wrap arguments in parentheses in your own code if needed.
 */

#define NO_OF_BITS 8U

/** @brief Set (write 1 to) a single bit in Register. */
#define SET_BIT(Register, Bit)         ((Register) |= (1U << (Bit)))

/** @brief Clear (write 0 to) a single bit in Register. */
#define CLEAR_BIT(Register, Bit)       ((Register) &= (~(1U << (Bit))))

/** @brief Toggle (invert) a single bit in Register. */
#define TOGGLE_BIT(Register, Bit)      ((Register) ^= (1U << (Bit)))

/** @brief Read a single bit from Register into value (0 or 1). */
#define GET_BIT(Register, Bit, value)  (value) = (((Register) >> (Bit)) & 1)

/** @brief Rotate an 8-bit Register left by Bit positions. */
#define ROTATE_LEFT(Register, bitN)     ((unsigned char)(((Register) << (bitN)) | ((Register) >> (NO_OF_BITS - (bitN)))))

/** @brief Rotate an 8-bit Register right by Bit positions. */
#define ROTATE_RIGHT(Register, bitN)    ((unsigned char)(((Register) >> (bitN)) | ((Register) << (NO_OF_BITS- (bitN)))))

/** @brief Overwrite the entire Register with Set_Value. */
#define SET_BYTE(Register, Set_Value)  (Register) = (Set_Value)

#endif /* BIT_MATH_H */