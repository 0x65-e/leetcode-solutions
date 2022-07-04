//#167. Two Sum II - Input Array Is Sorted (C++) - 13ms/87.98% 15.5MB/92.77%
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        while (start != end) {
            int diff = target - numbers[start] - numbers[end];
            if (diff == 0) {
                return {start + 1, end + 1};
            } else if (diff > 0) {
                start++;
            } else {
                end--;
            }
        }
        return {};
    }
};