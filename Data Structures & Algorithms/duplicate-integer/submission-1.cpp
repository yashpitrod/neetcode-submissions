class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map <int, int> mp;

        for(auto n:nums){
            mp[n]++;
        }

        for(auto it:mp){
            if (it.second > 1)
                return true;
        }

        return false;
    }
};