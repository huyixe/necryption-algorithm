#include <stdio.h>
#include <stdint.h>
#include "present.h"

#define NUM_ROUNDS 31
#define BLOCK_SIZE 64

typedef uint64_t block;

// Key schedule
void key_schedule(uint64_t* key, uint64_t* round_keys) {
    round_keys[0] = key[0];
    for (int i = 1; i <= NUM_ROUNDS; ++i) {
        round_keys[i] = (round_keys[i - 1] << 61) | (round_keys[i - 1] >> 3);
        round_keys[i] ^= key[i % 2];
    }
}
/*
* 这段代码是用于生成轮密钥（round keys）的函数。轮密钥是在轮函数中使用的子密钥，通常在加密算法的不同轮次中都会有不同的子密钥。

让我来解释一下代码的逻辑：

round_keys[0] = key[0];: 将初始密钥的第一个64位赋值给轮密钥数组的第一个元素。

for (int i = 1; i <= NUM_ROUNDS; ++i) {: 使用一个循环生成更多的轮密钥，循环从1到总轮数。

round_keys[i] = (round_keys[i - 1] << 61) | (round_keys[i - 1] >> 3);: 将前一个轮密钥左移61位，然后与右移3位的前一个轮密钥进行按位或运算。这是一个位运算，目的是引入一些混淆和扩散，增加密码算法的安全性。

round_keys[i] ^= key[i % 2];: 对生成的轮密钥与初始密钥的另一部分进行异或运算。这里使用了取余操作符 %，以交替选择初始密钥的第一个或第二个64位块，从而使每轮的轮密钥都与不同的初始密钥块相关联。

总体来说，这段代码是一个基于初始密钥生成轮密钥的函数，用于支持某种加密算法。
*/

// Substitution layer
void s_box_layer(block* state) {
    for (int i = 0; i < 64; i += 4) {
        uint8_t nibble = (*state >> i) & 0xF;
        nibble = (nibble >> 1) | ((nibble & 1) << 3);
        *state &= ~((uint64_t)0xF << i);
        *state |= (uint64_t)nibble << i;
    }
}
/*
* 这段代码实现了一个S盒（Substitution Box）层的函数。S盒是密码学中常见的一种替代置换操作，用于替换输入状态的一部分。

我来分解一下这个函数的逻辑：

for (int i = 0; i < 64; i += 4) {: 通过一个循环，每次处理64位块中的4位。这是因为S盒通常会将每个4位的块映射到另一个4位的块。

uint8_t nibble = (*state >> i) & 0xF;: 取出输入状态的当前4位块。这是通过将输入状态右移i位，然后使用掩码0xF（二进制表示为00001111）进行按位与操作得到的。

nibble = (nibble >> 1) | ((nibble & 1) << 3);: 对取出的4位块进行一个简单的变换。将该4位块右移1位，然后将原始的最低位放到新位置的最高位。这种变换是S盒操作的一部分，目的是增加混淆性。

*state &= ~((uint64_t)0xF << i);: 通过按位与操作，清除输入状态中对应的4位块，将其置为0。

*state |= (uint64_t)nibble << i;: 将经过变换的4位块通过按位或操作，添加到输入状态中的对应位置。

综合起来，这个函数通过S盒的替代置换操作，对输入状态的每个4位块进行替换，从而实现了一种非线性的变换。这种非线性性质对于密码算法的安全性是很重要的。
*/

// Permutation layer
void p_layer(block* state) {
    block new_state = 0;
    for (int i = 0; i < 64; ++i) {
        int pos = (16 * i) % 63;
        new_state |= ((*state >> i) & 1) << pos;
    }
    *state = new_state | (*state & 1);
}
/*
* 这段代码实现了一个置换层（permutation layer）的函数，通常用于混淆输入数据的位。我来分解一下代码的逻辑：

block new_state = 0;: 创建一个新的64位块，用于存储置换后的状态。

for (int i = 0; i < 64; ++i) {: 使用一个循环遍历输入状态的每一位。

int pos = (16 * i) % 63;: 计算新位置，这里使用了一个计算新位置的公式。这个公式将当前位的索引乘以16，然后对63取余，得到新位置。这是为了确保新位置在0到63之间循环，以进行位的重新排列。

new_state |= ((*state >> i) & 1) << pos;: 将输入状态中的第i位按位右移i位，然后与1进行按位与操作，将结果左移得到的新位置，最后与新状态进行按位或操作。这一步是将输入状态的每一位根据新位置重新排列到新的状态中。

*state = new_state | (*state & 1);: 最后，将新的状态与输入状态的最低位进行按位或操作，以确保最低位保持不变。这是为了防止丢失信息，保持函数的逆操作存在。

综合起来，这个函数通过按照一定规则重新排列输入状态的位，实现了一种混淆操作，常见于分组密码等加密算法中。
*/

// Round function
void round_function(block* state, uint64_t round_key) {
    *state ^= round_key;
    s_box_layer(state);
    p_layer(state);
}

// Encryption function
void present_encrypt(block* block, uint64_t* round_keys) {
    for (int i = 0; i < NUM_ROUNDS; ++i) {
        round_function(block, round_keys[i]);
    }
    *block ^= round_keys[NUM_ROUNDS];
}
