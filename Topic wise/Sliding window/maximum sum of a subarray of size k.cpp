#include <bits/stdc++.h>
using namespace std;
int maxSum(vector<int>& arr, int k) {
    int windowSum = 0, maxSum = 0;
    
    for(int i=0; i<k; i++){
        windowSum += arr[i];    
    }
    maxSum = windowSum;
    for(int i=k; i<arr.size(); i++){
        windowSum += arr[i] - arr[i-k];
        maxSum = max(windowSum, maxSum);
    }
    
    return maxSum;
}


int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << maxSum(arr , k);

    return 0;
}