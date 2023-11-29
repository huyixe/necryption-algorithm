/*
 * present.h
 *
 *  Created on: Nov 29, 2023
 *      Author: 1
 */

#ifndef __present_h;

#define __present_h;

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#define NUM_ROUNDS 31
#define BLOCK_SIZE 64

typedef uint64_t block;

// Key schedule
void key_schedule(uint64_t* key, uint64_t* round_keys);

void s_box_layer(block* state);

void p_layer(block* state) ;

void round_function(block* state, uint64_t round_key);

void present_encrypt(block* block, uint64_t* round_keys);

#endif




