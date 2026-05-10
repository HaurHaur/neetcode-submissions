class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if(s.count(target - nums[i])){
                result.push_back(s[target-nums[i]]);
                result.push_back(i);
                return result;
            }
            else
                s[nums[i]] = i;
        }
        return result;
    }
};
