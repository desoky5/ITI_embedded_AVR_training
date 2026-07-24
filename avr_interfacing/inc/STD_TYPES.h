#ifndef STD_TYPES_H
#define STD_TYPES_H

/**
 * @file  std_types.h
 * @brief Standard type definitions for exact-width integers and floating-point types.
 *
 * @note  Provides portable, concise type aliases (e.g., u8, s16, f32) commonly 
 *        used across embedded C drivers and application layers (AVR-style).
 */

/* Unsigned and Signed 8-bit Integer Types */
typedef unsigned char         u8;  /**< @brief Unsigned 8-bit integer  (0 to 255) */
typedef signed char           s8;  /**< @brief Signed 8-bit integer    (-128 to 127) */

/* Unsigned and Signed 16-bit Integer Types */
typedef unsigned short int    u16; /**< @brief Unsigned 16-bit integer (0 to 65,535) */
typedef signed short int      s16; /**< @brief Signed 16-bit integer   (-32,768 to 32,767) */

/* Unsigned and Signed 32-bit Integer Types */
typedef unsigned long int     u32; /**< @brief Unsigned 32-bit integer (0 to 4,294,967,295) */
typedef signed long int       s32; /**< @brief Signed 32-bit integer   (-2,147,483,648 to 2,147,483,647) */

/* Unsigned and Signed 64-bit Integer Types */
typedef unsigned long long    u64; /**< @brief Unsigned 64-bit integer */
typedef signed long long      s64; /**< @brief Signed 64-bit integer */

/* Floating-Point Types */
typedef float                 f32; /**< @brief Single-precision floating point (32-bit) */
typedef double                f64; /**< @brief Double-precision floating point (64-bit) */

#endif /* STD_TYPES_H */