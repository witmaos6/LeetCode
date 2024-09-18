bool Compare(int a, int b)
{
    string sa = to_string(a);
    string sb = to_string(b);

    if((sa + sb) > (sb + sa))
    {
        return true;
    }
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), Compare);
        
        if(nums[0] == 0)
        {
            return "0";
        }
        
        string Result;
        for(int Num : nums)
        {
            Result += to_string(Num);
        }
        return Result;
    }
};