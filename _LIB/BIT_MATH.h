/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BIT_MATH.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: August 9, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _LIB
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG, BIT) ((REG) |= (1U << BIT))
#define CLR_BIT(REG, BIT) ((REG) &= ~(1U << BIT))
#define TOG_BIT(REG, BIT) ((REG) ^= (1U << BIT))
#define GET_BIT(REG, BIT) (((REG) >> (BIT)) & 1U)

#define IS_IT_SET(reg, bit)      (((reg) >> (bit)) & 1U)
#define IS_BIT_CLR(reg, bit)     (!(((reg) >> (bit)) & 1U))

#define ROR(reg, num) \
    ((reg) = ((reg) >> (num)) | ((reg) << (REGISTER_SIZE - (num))))

#define ROL(reg, num) \
    ((reg) = ((reg) << (num)) | ((reg) >> (REGISTER_SIZE - (num))))

#endif /* BIT_MATH_H */
