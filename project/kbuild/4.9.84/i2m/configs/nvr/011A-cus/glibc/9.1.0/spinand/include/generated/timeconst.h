/* Automatically generated by kernel/time/timeconst.bc */
/* Time conversion constants for HZ == 100 */

#ifndef KERNEL_TIMECONST_H
#define KERNEL_TIMECONST_H

#include <linux/param.h>
#include <linux/types.h>

#if HZ != 100
#error "include/generated/timeconst.h has the wrong HZ value!"
#endif

#define HZ_TO_MSEC_MUL32	U64_C(0xA0000000)
#define HZ_TO_MSEC_ADJ32	U64_C(0x0)
#define HZ_TO_MSEC_SHR32	28
#define MSEC_TO_HZ_MUL32	U64_C(0xCCCCCCCD)
#define MSEC_TO_HZ_ADJ32	U64_C(0x733333333)
#define MSEC_TO_HZ_SHR32	35
#define HZ_TO_MSEC_NUM		10
#define HZ_TO_MSEC_DEN		1
#define MSEC_TO_HZ_NUM		1
#define MSEC_TO_HZ_DEN		10

#define HZ_TO_USEC_MUL32	U64_C(0x9C400000)
#define HZ_TO_USEC_ADJ32	U64_C(0x0)
#define HZ_TO_USEC_SHR32	18
#define USEC_TO_HZ_MUL32	U64_C(0xD1B71759)
#define USEC_TO_HZ_ADJ32	U64_C(0x1FFF2E48E8A7)
#define USEC_TO_HZ_SHR32	45
#define HZ_TO_USEC_NUM		10000
#define HZ_TO_USEC_DEN		1
#define USEC_TO_HZ_NUM		1
#define USEC_TO_HZ_DEN		10000

#endif /* KERNEL_TIMECONST_H */