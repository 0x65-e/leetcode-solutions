//#231. Power of Two (C++) - 0ms/100.00% 6MB/27.08%
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        bitset<numeric_limits<int>::digits> bs(n);
        return bs.count() == 1;
    }
};