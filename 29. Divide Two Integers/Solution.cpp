class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        long long res = 0;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        
        return sign * res;
    }
};