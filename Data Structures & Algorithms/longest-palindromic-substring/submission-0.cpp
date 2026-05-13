class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int res_i = 0;
        int res_len = 0;
        for(int k = 1; k <= n; k++){
            for(int i = 0; i+k-1 < n; i++){
                if(k == 1){
                    dp[i][i] = true;
                }
                else if(k == 2){
                    dp[i][i+1] = s[i] == s[i+1];
                }
                else{
                    dp[i][i+k-1] = s[i] == s[i+k-1] ? dp[i+1][i+k-2] : false;
                }

                if(dp[i][i+k-1]){
                    res_i = i;
                    res_len = k;
                }
            }
        }

        return s.substr(res_i, res_len);
    }
};
