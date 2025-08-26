#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int i =0, left = -1, maxSum = 0;
    unordered_set<char> unique;
    for(i=0; i< s.size(); i++){
        if(unique.count(s[i])){
            unique.erase(left++);
        }
        unique.insert(s[i]);
        maxSum = max(maxSum, i-left);
    }
    return maxSum;

}

int main() {
    string s = "depakk";
    cout << lengthOfLongestSubstring(s);

    return 0;
}