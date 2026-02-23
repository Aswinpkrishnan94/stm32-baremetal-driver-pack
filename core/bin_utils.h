#ifndef INC_BIN_UTILS_H_
#define INC_BIN_UTILS_H_

#include <stdint.h>

/* ========================= */
/*      Basic Operations     */
/* ========================= */

#define SET_BIT(REG, BIT_MASK)        ((REG) |= (BIT_MASK))
#define CLEAR_BIT(REG, BIT_MASK)      ((REG) &= ~(BIT_MASK))
#define TOGGLE_BIT(REG, BIT_MASK)     ((REG) ^= (BIT_MASK))
#define READ_BIT(REG, BIT_MASK)       ((REG) & (BIT_MASK))

/* ========================= */
/*      Bit Position         */
/* ========================= */

#define BIT(pos)                      (1U << (pos))

/* ========================= */
/*      Field Operations     */
/* ========================= */

/* Create mask for field of width 'len' at position 'pos' */
#define FIELD_MASK(pos, len)          (((1U << (len)) - 1U) << (pos))

/* Write value to bitfield */
#define WRITE_FIELD(REG, pos, len, val)           \
    do {                                           \
        (REG) &= ~FIELD_MASK(pos, len);            \
        (REG) |= ((val) << (pos));                 \
    } while (0)

/* Read value from bitfield */
#define READ_FIELD(REG, pos, len)     \
    (((REG) >> (pos)) & ((1U << (len)) - 1U))

#endif /* INC_BIN_UTILS_H_ */
