class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> result;
        for(int i = 0; i < k; i++){
            while(!deq.empty() && nums[i] > deq.back()){
                deq.pop_back();
            }
            deq.push_back(nums[i]);
        }

        result.push_back(deq.front());

        for(int i = k; i < nums.size(); i++){
            if(deq.front() == nums[i-k]){
                deq.pop_front();
            }

            while(!deq.empty() && nums[i] > deq.back()){
                deq.pop_back();
            }
            deq.push_back(nums[i]);
            result.push_back(deq.front());

        }

        return result;
    }
};
