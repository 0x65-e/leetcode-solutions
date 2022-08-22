//#342. Power of Four (C++) - 0ms/100.00% 6MB/24.97%
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        while (true) {
            if (n % 4 == 0) {
                n /= 4;
            } else {
                return false;
            }
            if (n == 1) return true;
        }
        return false;
    }
};