#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <stdint.h>

#define ROUNDS 32
#define BLOCK_SIZE 64

typedef uint64_t uint64;
typedef uint16_t uint16;

void addRoundKey(uint64* block, uint64 key) {
    *block ^= key;
}

void sBoxLayer(uint64* block) {
    uint8_t sBox[16][16] = {
        {0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2},
    };

    for (int i = 0; i < BLOCK_SIZE; i += 4) {
        uint16 nibble = (*block >> i) & 0xF;
        *block &= ~(0xFULL << i);
        *block |= (uint64)sBox[i / 4][nibble] << i;
    }
}

void pLayer(uint64* block) {
    uint64 result = 0;
    for (int i = 0; i < BLOCK_SIZE; i++) {
        int sourceBit = (16 * i) % (BLOCK_SIZE - 1);
        result |= ((*block >> i) & 0x1) << sourceBit;
    }
    *block = result;
}

void presentRound(uint64* block, uint64 key) {
    addRoundKey(block, key);
    sBoxLayer(block);
    pLayer(block);
}

void presentEncrypt(uint64* block, uint64* key) {
    for (int round = 0; round < ROUNDS; ++round) {
        presentRound(block, key[round]);
    }
}

int main() {
    uint64 plaintext = 0x0123456789ABCDEF;
    uint64 key[ROUNDS] = {
        0x0000000000000000, 0xFFFFFFFFFFFFFFFF, 0x0123456789ABCDEF, /* ... */
    };

    printf("Plaintext: 0x%016llX\n", plaintext);

    presentEncrypt(&plaintext, key);

    printf("Ciphertext: 0x%016llX\n", plaintext);

    return 0;
}