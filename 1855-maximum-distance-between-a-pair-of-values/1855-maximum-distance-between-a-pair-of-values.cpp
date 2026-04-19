class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2)
    {
        const int N = nums1.size();
        const int M = nums2.size();
        int i = 0, j = 0;
        int Result = 0;

        while(i < N && j < M)
        {
            if(nums1[i] <= nums2[j])
            {
                Result = max(Result, j - i);
                j++;
            }
            else if(nums1[i] > nums2[j])
            {
                i++;
                if(i > j)
                {
                    j++;
                }
            }
        }
        return Result;
    }
};