class Solution {
public:
    int uniquePaths(int m, int n) {
        long long result =  1;
        int x = m + n - 2;
        int k = min(m, n) - 1;
        
        for(int i = 1; i <= k; i++){

            result *= (x - i + 1);
            result /= i;
        }
        
        return result;
    }
};
