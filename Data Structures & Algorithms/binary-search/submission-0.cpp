class Solution {
public:
    int bs(vector<int> &nums, int target, int start, int end){
        if(start == end){
            if(nums[start] == target)
                return start;
            else
                return -1;
        }

        int mid = (start + end) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target){
            if(mid - 1 >= start)
                return bs(nums, target, start, mid-1);
            else
                return -1;
        }
        else{
            if(mid + 1 <= end)
                return bs(nums, target, mid + 1, end);
            else
                return -1;
        }

    }
    int search(vector<int>& nums, int target) {
        return bs(nums, target, 0, nums.size()-1);
    }
};
