#ifndef SECURE_PRNG_H
#define SECURE_PRNG_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void fill_random(uint8_t *buf, size_t bytes);
void set_seed_secure(uint64_t get_seed[4]);

#ifdef __cplusplus
}
#endif

#endif