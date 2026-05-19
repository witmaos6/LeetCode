class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int L = 0, R = nums.size() - 1;

        while(L < R)
        {
            int Mid = (L + R) / 2;

            if(nums[Mid] < nums[R])
            {
                R = Mid;
            }
            else
            {
                L = Mid + 1;
            }
        }
        return nums[L];
    }
};