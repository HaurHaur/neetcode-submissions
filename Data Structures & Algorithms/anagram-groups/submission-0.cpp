class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        vector<vector<string>> result;
        for(int i = 0; i < strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }
        for(const auto &iter : mp){
            vector<string> g;
            for(int i = 0; i < iter.second.size(); i++){
                g.push_back((iter.second)[i]);
            }
            result.push_back(g);
        }

        return result;
    }
};
