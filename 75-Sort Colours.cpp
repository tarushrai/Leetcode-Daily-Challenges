/* Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function. */

#include<iostream>
#include<vector>

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        switch (nums[mid]) {
            case 0: // Red
                swap(nums[low], nums[mid]);
                low++;
                mid++;
                break;
            case 1: // White
                mid++;
                break;
            case 2: // Blue
                swap(nums[mid], nums[high]);
                high--;
                break;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
    }
};
