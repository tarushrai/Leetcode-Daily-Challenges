/* 
A school is trying to take an annual photo of all the students. 
The students are asked to stand in a single file line in non-decreasing order by height. 
Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.
You are given an integer array heights representing the current order that the students are standing in. 
Each heights[i] is the height of the ith student in line (0-indexed). */

Return the number of indices where heights[i] != expected[i].

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
         vector<int> expected = heights;
    sort(expected.begin(), expected.end());

    // Count mismatches between heights and expected
    int mismatchCount = 0;
    for (size_t i = 0; i < heights.size(); ++i) {
        if (heights[i] != expected[i]) {
            ++mismatchCount;
        }
    }

    return mismatchCount;
}

int main() {
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    int mismatches = heightChecker(heights);
    cout << "Number of indices where heights[i] != expected[i]: " << mismatches << endl;
    return 0;
    }
};
