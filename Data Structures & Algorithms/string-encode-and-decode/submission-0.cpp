class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(int i = 0 ; i < strs.size(); i++){
            result += encode_len(strs[i]) + strs[i];
        }
        return result;
    }

    vector<string> decode(string s) {
        int cur = 0;
        vector<string> result;
        while(cur < s.length()){
            string num = "";
            while(s[cur] != '#'){
                num += s[cur++];
            }
            cur++;
            string cur_str = "";
            for(int i = 0; i < stoi(num); i++, cur++){
                cur_str += s[cur];
            }
            result.push_back(cur_str);
        }
        return result;
    }

    string encode_len(string str){
        int n = str.length();
        return to_string(n) + "#";
    }
};
