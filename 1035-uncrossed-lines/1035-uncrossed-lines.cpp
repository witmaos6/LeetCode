class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    {
        int Nums1Size = static_cast<int>(nums1.size());
        int Nums2Size = static_cast<int>(nums2.size());
        
        if(Nums1Size > Nums2Size)
        {
            return DP(nums1, nums2, Nums1Size, Nums2Size);
        }
        
        return DP(nums2, nums1, Nums2Size, Nums1Size);
    }
    
private:
    int DP(vector<int>& Nums1, vector<int>& Nums2, int Nums1Size, int Nums2Size)
    {
        vector<int> Memo(Nums1Size + 1);
        
        for(int i = 1; i <= Nums2Size; i++)
        {
            int Prev = 0;
            
            for(int j = 1; j <= Nums1Size; j++)
            {
                int Curr = Memo[j];
                
                if(Nums2[i - 1] == Nums1[j - 1])
                {
                    Memo[j] = Prev + 1;
                }
                else
                {
                    Memo[j] = max(Memo[j - 1], Curr);
                }
                Prev = Curr;
            }
        }
        
        return Memo[Nums1Size];
    }
};