class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums)
    {
        const int N = static_cast<int>(nums[0].size());
        string Result;
        for(int i = 0; i < N; i++)
        {
            Result += (nums[i][i] == '1') ? '0' : '1';
        }
        return Result;
    }
};