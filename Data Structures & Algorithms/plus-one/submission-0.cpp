class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int c = 1;
        vector<int> result (n, 0);
        for(int i = n - 1; i >= 0; i--){
            if(digits[i] + c > 9){
                c = 1;
                result[(n-1) - i] = 0;
            }
            else{
                result[(n-1) - i] = digits[i] + c;
                c = 0;
            }

        }
        if(c != 0)
            result.push_back(1);
        reverse(result.begin(), result.end());
        return result;
    }
};
