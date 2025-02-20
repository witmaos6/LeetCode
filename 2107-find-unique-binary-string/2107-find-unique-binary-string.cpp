class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums)
    {
        const int N = static_cast<int>(nums.size());
        string Result;
        
        for(int i = 0; i < N; i++)
        {
            Result += (nums[i][i] == '0') ? '1' : '0';
        }
        return Result;
    }
};