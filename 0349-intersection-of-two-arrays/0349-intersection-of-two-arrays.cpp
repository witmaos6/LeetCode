class Solution {
    array<bool, 1001> Intersection;
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> Result;
        
        for(int& Num : nums1)
        {
            Intersection[Num] = true;
        }
        
        for(int& Num : nums2)
        {
            if(Intersection[Num])
            {
                Result.push_back(Num);
                Intersection[Num] = false;
            }
        }
        
        return Result;
    }
};