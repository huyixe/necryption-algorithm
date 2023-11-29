#include <stdio.h>
#include <stdint.h>

#define SBOX_SIZE 16

uint8_t multiply_with_inverse(uint8_t x) {
    uint8_t result = 0x00;
    uint8_t mask = 0x1B;

    for (int i = 0; i < 8; ++i) {
        if ((x >> i) & 0x01) {
            result ^= (mask << i);
        }
    }

    return result;
}

void generate_present_sbox(uint8_t sbox[SBOX_SIZE]) {
    for (int i = 0; i < SBOX_SIZE; ++i) {
        sbox[i] = multiply_with_inverse(i);
    }
}

void print_sbox(uint8_t sbox[SBOX_SIZE]) {
    for (int i = 0; i < SBOX_SIZE; ++i) {
        printf("%2X ", sbox[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}

int main() {
    uint8_t present_sbox[SBOX_SIZE];

    generate_present_sbox(present_sbox);

    printf("Generated PRESENT S-box:\n");
    print_sbox(present_sbox);

    return 0;
}