class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        const int Nums1Size = static_cast<int>(nums1.size());
        const int Nums2Size = static_cast<int>(nums2.size());
        
        unordered_map<int, int> Table;
        for(int i = 0; i < Nums1Size; i++)
        {
            Table[nums1[i]]++;
        }
        
        vector<int> Result;
        for(int i = 0; i < Nums2Size; i++)
        {
            unordered_map<int,int>::iterator It = Table.find(nums2[i]);
            if(It != Table.end() && It->second > 0)
            {
                It->second--;
                Result.push_back(nums2[i]);
            }
        }
        
        return Result;
    }
};