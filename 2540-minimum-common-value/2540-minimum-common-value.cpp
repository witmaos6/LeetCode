class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2)
    {
        const int Num1Size = static_cast<int>(nums1.size());
        const int Num2Size = static_cast<int>(nums2.size());
        int Index1 = 0;
        int Index2 = 0;
        
        while(Index1 < Num1Size && Index2 < Num2Size)
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