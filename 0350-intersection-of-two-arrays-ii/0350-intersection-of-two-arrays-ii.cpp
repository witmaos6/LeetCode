class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> Table;
        for(int Num : nums1)
        {
            Table[Num]++;
        }
        
        vector<int> Result;
        for(int Num : nums2)
        {
            unordered_map<int,int>::iterator It = Table.find(Num);
            if(It != Table.end() && It->second > 0)
            {
                It->second--;
                Result.push_back(Num);
            }
        }
        
        return Result;
    }
};