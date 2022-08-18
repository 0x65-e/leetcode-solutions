//#8. String to Integer (atoi) (C++) - 8ms/32.80% 7.1MB/54.16%
class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        while (idx < s.size() && s[idx] == ' ') idx++;
        bool negative = false;
        if (idx < s.size() && s[idx] == '-') {
            negative = true;
            idx++;
        } else if (idx < s.size() && s[idx] == '+') {
            idx++;
        }
        cout << negative << endl;
        unsigned long long out = 0;
        while (idx < s.size()) {
            if (s[idx] >= '0' && s[idx] <= '9') {
                out = out * 10 + s[idx] - '0';
                cout << out << endl;
                idx++;
            } else {
                break;
            }
            // clip
            if (negative && out > INT_MAX) return INT_MIN;
            else if (!negative && out >= INT_MAX) return INT_MAX;
        }
        return (negative) ? (-1 * (int) out) : (int) out;
    }
};