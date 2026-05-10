class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result = 0;
        for(int i = 0; i < sizeof(uint32_t) * 8; i++){
            result += n % 2;
            n >>= 1;
            if(i != sizeof(uint32_t) * 8 - 1)
                result <<= 1;
        }
        return result;
    }
};
