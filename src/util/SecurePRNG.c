#include <windows.h>
#include <ntstatus.h>
#include <bcrypt.h>
#include <stdio.h>
#include <stdlib.h>
#include "SecurePRNG.h"
#include "xoshiro256starstar.h"

void fill_random(uint8_t *buf, size_t bytes)
{
	BCRYPT_ALG_HANDLE h;
	NTSTATUS err;

	err = BCryptOpenAlgorithmProvider(&h, L"RNG", NULL, 0);

	if (err != STATUS_SUCCESS) {
		fprintf(stderr, "BCryptOpenAlgorithmProvider %ld\n", err);
		exit(1);
	}
	
	err = BCryptGenRandom(h, buf, bytes, 0);

	if (err != STATUS_SUCCESS) {
		fprintf(stderr, "BCryptGenRandom %ld\n", err);
		exit(1);
	}

	BCryptCloseAlgorithmProvider(h, 0);
}

void set_seed_secure(uint64_t get_seed[4])
{
	uint64_t tmp[4];

	fill_random((uint8_t *) tmp, sizeof(*tmp) * 4);
	set_seed_manual(tmp);

	if (get_seed)
		for (int i = 0; i < 4; i++)
			get_seed[i] = tmp[i];
}