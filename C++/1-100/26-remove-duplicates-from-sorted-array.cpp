//#26. Remove Duplicates from Sorted Array (C++) - 17ms/63.75% 18.4MB/37.02%
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow] && fast != ++slow) nums[slow] = nums[fast];
        }
        return slow + 1;
    }
};