class Solution {
public:
    static bool my_comp(vector<int> a, vector<int> b){
        return a[0] > b[0] ? true : false;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> cars;
        int n = position.size();
        for(int i = 0; i < n; i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), my_comp);
        int result = 1;
        double arrival_time = (double)(target - cars[0][0]) / cars[0][1];

        for(int i = 1; i < n; i++){
            double cur_arrival_time = (double)(target - cars[i][0]) / cars[i][1];
            // cout << "position[i] = " << cars[i][0] << " arrival_time = " << arrival_time << " cur_arrival_time = " << cur_arrival_time << endl;
            if(cur_arrival_time > arrival_time){
                result++;
                arrival_time = cur_arrival_time;
            }
        }
        return result;
    }
};
