//#869. Reordered Power of 2 (C++) - 529ms/6.21% 78.8MB/5.37%
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        queue<int> digits;
        while (n > 0) {
            digits.push(n % 10);
            n /= 10;
        }
        
        int rem_digits = digits.size();
        for (int i = 0; i < rem_digits; i++) {
            int digit = digits.front();
            digits.pop();
            if (digit != 0 && permute(digit, digits)) return true;
            digits.push(digit);
        }
        return false;
    }
private:
    bool isPower(long long n) {
        bitset<numeric_limits<long long>::digits> bs(n);
        return bs.count() == 1;
    }
    
    bool permute(long long n, queue<int>& remaining) {
        int rem_digits = remaining.size();
        if (rem_digits == 0) return isPower(n);
        
        for (int i = 0; i < rem_digits; i++) {
            int digit = remaining.front();
            remaining.pop();
            if (permute(n * 10 + digit, remaining)) return true;
            remaining.push(digit);
        }
        return false;
    }
};