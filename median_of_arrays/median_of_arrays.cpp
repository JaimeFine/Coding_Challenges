#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        while (nums1.size() > 2 && nums2.size() > 2) {
            int med1, med2;
            med1 = (nums1.size() % 2 == 0)
                ? (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2 : nums1[nums1.size() / 2];
            med2 = (nums2.size() % 2 == 0) 
                ? (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) / 2 : nums2[nums2.size() / 2];
            if (med1 < med2) {
                nums1.assign(nums1.begin() + med1, nums1.end());
                nums2.assign(nums2.begin(), nums2.begin() + med1);
            } else {
                nums2.assign(nums2.begin() + med2, nums2.end());
                nums1.assign(nums1.begin(), nums1.begin() + med2);
            }
        }

        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        std::sort(nums1.begin(), nums1.end());
        double med = (nums1.size() % 2 == 0)
            ? static_cast<double>(nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2
            : nums1[nums1.size() / 2];

        return med;
    }
};
