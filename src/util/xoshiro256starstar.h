#ifndef XOSHIRO256STARSTAR_H
#define XOSHIRO256STARSTAR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint64_t next(void);

void set_seed(void);
void set_seed_manual(const uint64_t x[4]);

void jump(void);
void long_jump(void);

int64_t next_r(int64_t a, int64_t b);


double next_f(void);
double next_fr(double a, double b);
double next_z(void);
double next_normal(double m, double sigma);

#ifdef __cplusplus
}
#endif

#endif