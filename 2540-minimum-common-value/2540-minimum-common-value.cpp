class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2)
    {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        int Index1 = 0;
        int Index2 = 0;

        while(Index1 < N1 && Index2 < N2)
        {
            if(nums1[Index1] == nums2[Index2])
            {
                return nums1[Index1];
            }
            else if(nums1[Index1] > nums2[Index2])
            {
                Index2++;
            }
            else
            {
                Index1++;
            }
        }
        return -1;
    }
};