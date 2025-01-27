#ifndef _IDIV_H_
#define _IDIV_H_

#include <stdint.h>

uint32_t idiv32_uu(uint32_t n, uint32_t d, uint32_t *rp);
int32_t  idiv32_ii(int32_t n, int32_t d, int32_t *rp);
int32_t  idiv32_ui(uint32_t n, int32_t d, uint32_t *rp);
int32_t  idiv32_iu(int32_t n, uint32_t d, int32_t *rp);

uint64_t idiv64_uu(uint64_t n, uint64_t d, uint64_t *rp);
int64_t  idiv64_ii(int64_t n, int64_t d, int64_t *rp);
int64_t  idiv64_ui(uint64_t n, int64_t d, uint64_t *rp);
int64_t  idiv64_iu(int64_t n, uint64_t d, int64_t *rp);

#endif
