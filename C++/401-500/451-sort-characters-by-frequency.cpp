//#451. Sort Characters By Frequency (C++) - 26ms/22.57% 8.3MB/84.10%
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counts;
        for (char const &c : s) {
            counts[c]++;
        }
        multimap<int, char, greater<int>> order;
        for (auto e : counts) {
            order.emplace(e.second, e.first);
        }
        string os;
        os.reserve(s.size());
        for (auto e : order) {
            for (int i = 0; i < e.first; i++) {
                os.push_back(e.second);
            }
        }
        return os;
    }
};