//#387. First Unique Character in a String (C++) - 63ms/45.22% 10.8MB/15.65%
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> counts;
        for (char const &c : s) {
            counts[c]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (counts[s[i]] == 1) return i;
        }
        return -1;
    }
};