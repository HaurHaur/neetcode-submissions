class Solution {
public:
    // uint32_t reverseBits(uint32_t n) {
    //     int result = 0;
    //     for(int i = 0; i < sizeof(uint32_t) * 8; i++){
    //         result += n % 2;
    //         n >>= 1;
    //         if(i != sizeof(uint32_t) * 8 - 1)
    //             result <<= 1;
    //     }
    //     return result;
    // }

    uint32_t reverseBits(uint32_t n) {
        int result = 0;
        result = (n >> 16) | (n << 16);
        result = (result & 0xff00ff00) >> 8 | (result & 0x00ff00ff) << 8;
        result = (result & 0xf0f0f0f0) >> 4 | (result & 0x0f0f0f0f) << 4;
        result = (result & 0xcccccccc) >> 2 | (result & 0x33333333) << 2;
        result = (result & 0xaaaaaaaa) >> 1 | (result & 0x55555555) << 1;
        return result;
    }
};
