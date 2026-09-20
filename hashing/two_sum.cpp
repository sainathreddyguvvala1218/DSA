class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> m ;
    for(int i=0;i<nums.size();i++){
        int val = nums[i];
        int comp = target - val;
        if(m.find(comp)!=m.end()) {
            return {m[comp],i};
        } 
        m[val] = i;
    }
    return {};
    }
};