class Solution {
public:
    int rob(vector<int>& nums) {
        // f(n) = max(f(n+2) + nums[n], f(n+1))
        int n = nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n, 0);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1], nums[n-2]);
        for(int i = n-3; i >= 0; i--){
            dp[i] = max(dp[i+2] + nums[i], dp[i+1]);
        }
        return dp[0];
    }
};
