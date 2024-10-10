/**
 *	author 	: nxtsourav7
 *	created : 2024-10-10 12:50:47
**/

#include<bits/stdc++.h>
using namespace std;

int maxWidthRamp(vector<int>& nums) {
    // fastIO
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
// ---------------------------------------- //
    int n = nums.size();
    vector<int> rightMax(n);
    rightMax[n - 1] = nums[n - 1];
    for(int i = n - 2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i + 1], nums[i]);
    }

    int lptr = 0, rptr = 0, maxWid = 0;
    while(rptr < n) {
        while(lptr < rptr and nums[lptr] > rightMax[rptr]) {
            lptr++;
        }
        maxWid = max(maxWid, rptr - lptr);
        rptr++;
    }

    return maxWid;
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    // Input for nums array
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << maxWidthRamp(nums) << '\n';
    
    return 0;
}
