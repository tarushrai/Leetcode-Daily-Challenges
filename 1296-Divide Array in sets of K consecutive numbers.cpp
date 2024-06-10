//Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.

// Return true if it is possible. Otherwise, return false.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) {
        return false;
    }

    map<int, int> numCount;
    for (int num : nums) {
        numCount[num]++;
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (const auto& entry : numCount) {
        minHeap.push(entry.first);
    }

    while (!minHeap.empty()) {
        int startNum = minHeap.top();
        for (int i = 0; i < k; i++) {
            if (numCount[startNum + i] > 0) {
                numCount[startNum + i]--;
                if (numCount[startNum + i] == 0) {
                    if (minHeap.top() == startNum + i) {
                        minHeap.pop();
                    }
                }
            } else {
                return false;
            }
        }
    }

    return true;
}
    };
