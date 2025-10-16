#include <iostream>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<double> merged;
        merged.reserve(nums1.size() + nums2.size());

        if (num1.back() <= num2.front() || num2.back() <= num1.front()) {
            merged.insert(merged.end(), num1.begin(), num1.end());
            merged.insert(merged.end(), num2.begin(), num2.end());
            int med, flag;
            flag = (num1.size() + num2.size()) % 2;
            if (flag == 1) {
                med = (num1.size() + num2.size()) / 2;
                return (merged[med] + merged[med + 1]) / 2;
            } else {
                return (merged[med]);
            }
        }

        for () {
            if (num1.size() % 2 == 0) {
                med1 = (num1[num1.size()/2] + num1[num1.size()/2 + 1]) / 2;
            } else {
                med1 = (num1[num1.size()/2 + 1]);
            }
            if (num2.size() % 2 == 0) {
                med2 = (num2[num2.size()/2] + num2[num2.size()/2 + 1]) / 2;
            } else {
                med2 = (num2[num2.size()/2 + 1]);
            }

            if (med1 > med2) {
                b2.insert(b2.end, num2.begin(), num2[med2];
                num2 = b2;
                b1.insert(b1.end, num1[med1], num1.end());
                num1 = b1;
            } else {
                b1.insert(b1.end, num1.begin(), num1[med1];
                num1 = b1;
                b2.insert(b2.end, num2[med2], num2.end());
                num2 = b2;
            }
        }
    }
};
