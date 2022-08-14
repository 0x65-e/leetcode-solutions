//#2357. Make Array Zero by Subtracting Equal Amounts (C++) - 4ms/59.39% 8.6MB/5.96%
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> unique(nums.cbegin(), nums.cend());
        unique.erase(0);
        return unique.size();
    }
};