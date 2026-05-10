class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        map<int, vector<int>> mp;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            cnt[nums[i]]++;
        }
        for(const auto &iter: cnt){
            mp[-1 * iter.second].push_back(iter.first);
            // cout << iter.second << " " << iter.first << endl;
        }
        int cur = k;
        for(const auto &iter: mp){
            for(int i = 0; i < iter.second.size() && cur > 0; i++){
                result.push_back(iter.second[i]);
                cur--;
            }
        }
        return result;
    }
};
