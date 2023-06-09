class Solution {
public:
    int countElements(vector<int>& nums)
    {
        if(nums.size() < 3)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        
        if(nums.front() == nums.back())
        {
            return 0;
        }
        
        auto Begin = nums.begin();
        auto End = nums.end();
        
        int MinElement = upper_bound(Begin, End, nums[0]) - Begin;
        int MaxElement = lower_bound(Begin, End, nums.back()) - Begin;
        
        return MaxElement - MinElement;
    }
};