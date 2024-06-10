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
