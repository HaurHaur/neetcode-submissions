class TimeMap {
public:
    unordered_map<string, unordered_map<int, string>> mp;
    unordered_map<string, vector<int>> ts;
    TimeMap() {
        
    }

    int bs(vector<int> &v, int start, int end, int target){
        if(start > end)
            return -1;
        int mid = (start + end) / 2;

        if(v[mid] == target)
            return target;
        else if(v[mid] > target){
            if(mid - 1 >= start)
                return bs(v, start, mid-1, target);
            else
                return -1;
        }
        else{
            if(mid + 1 <= end && v[mid+1] <= target)
                return bs(v, mid+1, end, target);
            else
                return v[mid];
        }
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
        ts[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        int n = ts[key].size();
        int time = bs(ts[key], 0, n-1, timestamp);
        if(time == -1)
            return "";
        cout << "get: key = " << key << " timestamp = " <<  timestamp << " got time = " << time << endl;
        return mp[key][time];
    }
};
