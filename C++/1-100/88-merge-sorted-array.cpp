//#88. Merge Sorted Array (C++) - 4ms/53.48% 8.9MB/89.77%
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto it1 = nums1.crbegin() + n, it2 = nums2.crbegin();
        vector<int>::reverse_iterator start = nums1.rbegin();
        while (it1 != nums1.crend() && it2 != nums2.crend()) {
            if (*it1 > *it2) {
                *start = *it1;
                it1++;
                start++;
            } else {
                *start = *it2;
                it2++;
                start++;
            }
        }
        if (it2 != nums2.crend()) {
            copy(it2, nums2.crend(), start);
        }
    }
};