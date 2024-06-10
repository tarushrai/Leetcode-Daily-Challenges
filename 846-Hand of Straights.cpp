/* 
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, 
return true if she can rearrange the cards, or false otherwise.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) {
        return false;
    }

    map<int, int> numCount;
    for (int num : hand) {
        numCount[num]++;
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (const auto& entry : numCount) {
        minHeap.push(entry.first);
    }

    while (!minHeap.empty()) {
        int startNum = minHeap.top();
        for (int i = 0; i < groupSize; i++) {
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
