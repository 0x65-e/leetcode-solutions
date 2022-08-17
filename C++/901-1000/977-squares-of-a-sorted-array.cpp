//#977. Squares of a Sorted Array (C++) - 50ms/62.08% 25.9MB/81.92%
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> out;
        out.reserve(nums.size());
        int pos = 0;
        while (pos < nums.size() && nums[pos] < 0) pos++;
        int neg = pos-1;
        while (neg >= 0 && pos < nums.size()) {
            if (abs(nums[neg]) < nums[pos]) {
                out.push_back(nums[neg] * nums[neg]);
                neg--;
            } else {
                out.push_back(nums[pos] * nums[pos]);
                pos++;
            }
        }
        while (neg >= 0) {
            out.push_back(nums[neg] * nums[neg]);
            neg--;
        }
        while (pos < nums.size()) {
            out.push_back(nums[pos] * nums[pos]);
            pos++;
        }
        return out;
    }
};