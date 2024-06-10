/* In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. 
For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".
Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, 
replace all the derivatives in the sentence with the root forming it. 
If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.
Return the sentence after the replacement.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<std::string> rootSet(dictionary.begin(), dictionary.end());

    istringstream iss(sentence);
    ostringstream oss;
    string word;
    
    while (iss >> word) {
        string prefix = word;
        for (int i = 1; i <= word.length(); ++i) {
            prefix = word.substr(0, i);
            if (rootSet.find(prefix) != rootSet.end()) {
                break;
            }
        }
        oss << prefix << " ";
    }
    
    string result = oss.str();
    if (!result.empty()) {
        result.pop_back(); // Remove the trailing space
    }
    return result;
}

int main() {
    // Sample dictionary of roots
    vector<std::string> roots = {"cat", "bat", "rat"};

    // Sample sentence
    string sentence = "the cattle was rattled by the battery";

    // Replace derivatives with roots
    string result = replaceWords(roots, sentence);

    // Output the result
    cout << result << endl;

    return 0;
}
    };
