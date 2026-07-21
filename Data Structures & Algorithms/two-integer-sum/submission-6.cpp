class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int y,k = 0;
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=0 ; j<nums.size() ; j++){
                if(nums[i] + nums[j] == target && i!=j){
                    y = i;
                    k = j;
                }
                else{
                    continue;
                }
            }
        }
        if (y > k){
            int x = k;
            k = y;
            y = x;
        }
        return {y,k};
    }
};
