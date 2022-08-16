//#2351. First Letter to Appear Twice (C++) - 0ms/100.00% 6.3MB/18.77%
class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> counts;
        for (char const &c : s) {
            counts[c]++;
        }
        for (char const &c : s) {
            if (counts[c]) counts[c] = 0;
            else return c;
        }
        return 0;
    }
};