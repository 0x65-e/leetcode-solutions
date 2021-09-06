//#3. Longest Substring Without Repeating Characters (C++) - 20ms/47.64% 9MB/31.92%
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charset;
        int len = 0, start = 0, size = s.length();
        char c;
        
        for (int i = 0; i < size; i++) {
            c = s[i];
            if (!charset.insert(c).second) {
                while (s[start] != c) {
                    charset.erase(charset.find(s[start]));
                    start++;
                }
                start++;
            }
            len = max(len, i - start + 1);
        }
        return len;
    }
};