class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2)
    {
        const int Nums1Size = static_cast<int>(nums1.size());
        const int Nums2Size = static_cast<int>(nums2.size());
        
        if(Nums1Size < Nums2Size)
        {
            return maxDotProduct(nums2, nums1);
        }
        
        vector<long> Memo(Nums2Size + 1, INT_MIN);
        
        for(int i = 0; i < Nums1Size; i++)
        {
            long Prev = 0;
            for(int j = 0; j < Nums2Size; j++)
            {
                long Cache = Memo[j + 1];
                long Temp = static_cast<long>(nums1[i] * nums2[j]);
                Prev += Temp;
                
                long MaxDot = max(Memo[j], Memo[j + 1]);
                MaxDot = max(MaxDot, Temp);
                MaxDot = max(MaxDot, Prev);
                Memo[j + 1] = MaxDot;
                
                Prev = Cache;
            }
        }
        
        return static_cast<int>(Memo[Nums2Size]);
    }
};