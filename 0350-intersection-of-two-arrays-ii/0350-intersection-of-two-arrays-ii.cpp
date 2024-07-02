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
            if(Table.find(nums2[i]) != Table.end() && Table[nums2[i]] > 0)
            {
                Table[nums2[i]]--;
                Result.push_back(nums2[i]);
            }
        }
        
        return Result;
    }
};