class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums)
    {
        auto Comp = [](int a, int b)
        {
            return abs(a) < abs(b);
        };

        priority_queue<int, vector<int>, decltype(Comp)> MaxHeap;

        for(int& Num : nums)
        {
            MaxHeap.push(Num);
        }

        const int N = nums.size();
        int Add = (N / 2) + (N & 1);
        long long Result = 0;

        while(!MaxHeap.empty())
        {
            long long Num = MaxHeap.top();
            MaxHeap.pop();

            if(Add > 0)
            {
                Result += Num * Num;
                Add--;
            }
            else
            {
                Result -= Num * Num;
            }
        }
        return Result;
    }
};