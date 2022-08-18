//#1338. Reduce Array Size to The Half (C++) - 237ms/86.11% 76.9MB/88.23%
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (int const &n : arr) {
            counts[n]++;
        }
        vector<int> order;
        order.reserve(counts.size());
        for (auto it : counts) {
            order.push_back(it.second);
        }
        sort(order.begin(), order.end(), greater<int>());
        int total = 0, target = arr.size() / 2, num = 0;
        for (; total < target; num++) {
            total += order[num];
        }
        return num;
    }
};