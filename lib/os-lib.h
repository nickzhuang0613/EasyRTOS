#ifndef __OS_LIB_H__
#define __OS_LIB_H__

#include "lib-cfg.h"

#if __MATH
#include "os-math.h"
#endif  /* __MATH */

#if __STRING
#include "os-string.h"
#endif  /* __STRING */

#if __RING
#include "os-ring.h"
#endif  /* __RING */

#endif /* __OS_LIB_H__ */