class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
       set<int>se;
        for(int i=0; i<nums.size(); i++)
        {
            if(se.find(nums[i]) !=se.end())
            {
                return nums[i];
            }
            se.insert(nums[i]);
        }
        return -1;
    }
};
