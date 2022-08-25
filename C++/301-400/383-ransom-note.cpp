//#383. Ransom Note (C++) - 27ms/49.42% 8.9MB/15.41%
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> available;
        unordered_map<char, int> required;
        for (char c : magazine) {
            available[c]++;
        }
        for (char c : ransomNote) {
            required[c]++;
        }
        for (auto it : required) {
            auto found = available.find(it.first);
            if (found == available.end() || found->second < it.second) return false;
        }
        return true;
    }
};