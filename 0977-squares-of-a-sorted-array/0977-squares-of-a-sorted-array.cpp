class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int l=0, r = n - 1;
        while(l <= r) {
            if(nums[l] * nums[l] > nums[r]*nums[r]) {
                ans[n-1] = nums[l] * nums[l];
                l++;
                n--;
            } else {
                ans[n-1] = nums[r] * nums[r];
                n--;
                r--;
            }
        }
        return ans;
    }
};