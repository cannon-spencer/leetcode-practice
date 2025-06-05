class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // 4 bytes * 8 bits = 32 bits
        int numBits = sizeof(uint32_t) * 8;

        int output = 0;
        
        // shift as many bits as there are
        while(numBits--){
            // left shift output by 1 to make room for the next bit, or the zero with the LSB of the input
            output = (output << 1) | (n & 1);

            // Right shift n to queue the next least sig bit
            n >>= 1;
        }

        return output;

    }
};