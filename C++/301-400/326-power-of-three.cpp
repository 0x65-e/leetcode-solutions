//#326. Power of Three (C++) - 27ms/73.41% 5.9MB/29.00%
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (true) {
            if (n == 1) return true;
            if (n % 3 != 0) return false;
            n /= 3;
        }
    }
};