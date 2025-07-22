class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        if(nums.size()==1)
        {
            return nums[0];
        }
        int left = 0;
        int right = 1;
        int SumOfSubarray = nums[0];
        int MaximumSubarray = 0;
        set<int> Subarray = { nums[0] };

        while (right < (int)nums.size())
        {
            while(Subarray.find(nums[right])!=end(Subarray))
            {
                Subarray.erase(nums[left]);
                SumOfSubarray -= nums[left];
                left++;
            }
            Subarray.insert(nums[right]);
            SumOfSubarray += nums[right];
            right++;
            MaximumSubarray = max(MaximumSubarray, SumOfSubarray);
        }

        return MaximumSubarray;
    }
};