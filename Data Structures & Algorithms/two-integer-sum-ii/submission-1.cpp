class Solution {
public:
    int bs(vector<int> &numbers, int target, int left, int right){
        if(right - left <= 1){
            if(numbers[left] == target)
                return left;

            if(right - left == 1){
                return numbers[left] < target ? bs(numbers, target, left + 1, right) : left - 1;
            }
            else{
                return numbers[left] < target ? left : left - 1;
            }
        }

        int mid = (left + right) / 2;
        if(numbers[mid] == target){
            return mid;
        }
        else{
            return numbers[mid] > target ? 
                bs(numbers, target, left, mid - 1) : bs(numbers, target, mid + 1, right);
        }
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int upper_bound = n-1;
        int left = 0;
        vector<int> result;
        while(upper_bound > left){
            int index = bs(numbers, target - numbers[left], left + 1, upper_bound);
            if(index > left && numbers[left] + numbers[index] == target){
                result.push_back(left+1);
                result.push_back(index+1);
            }
            upper_bound = index;
            left++;

        }
        cout << bs(numbers, 2, 1, n - 1) << endl;
        return result;
    }
};
