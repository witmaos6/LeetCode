class Solution {
public:
    vector<int> separateDigits(vector<int>& nums)
    {
        const int N = nums.size();
        vector<int> Result;

        for(int& Num : nums)
        {
            string NumStr = to_string(Num);
            for(char& C : NumStr)
            {
                Result.push_back(C - '0');
            }
        }
        return Result;
    }
};