//#1. Two Sum (C++) - 11ms/90.86% 11MB/31.48%
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> match;
        for (int i = 0; i < nums.size(); i++) {
            int partner = target - nums[i];
            auto query = match.find(partner);
            if (query != match.end()) {
                vector<int> results{query->second, i};
                return results;
            }
            match.emplace(nums[i], i);
        }
        vector<int> out;
        return out;
    }
};