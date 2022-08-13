//#217. Contains Duplicate (C++) - 190ms/19.71% 54.7MB/13.84%
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> unique(nums.begin(), nums.end());
        return nums.size() != unique.size();
    }
};