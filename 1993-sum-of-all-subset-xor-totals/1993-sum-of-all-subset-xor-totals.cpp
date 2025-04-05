class Solution {
public:
    int subsetXORSum(vector<int>& nums)
    {
        N = static_cast<int>(nums.size());

        Recursion(nums, 0, 0);

        return Result;
    }
private:
    int Result = 0;
    int N = 0;
    void Recursion(vector<int>& nums, int sum, int i)
    {
        if(i < N - 1)
        {
            Recursion(nums, sum, i + 1);
            Recursion(nums, (sum ^ nums[i]), i + 1);
        }
        else
        {
            Result += sum + (sum ^ nums[i]);
        }
    }
};