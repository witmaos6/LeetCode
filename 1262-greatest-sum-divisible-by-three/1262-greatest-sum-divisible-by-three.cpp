class Solution {
public:
    int maxSumDivThree(vector<int>& nums)
    {
        vector<int> V[3];

        for(int& Num : nums)
        {
            V[Num % 3].push_back(Num);
        }

        sort(V[1].begin(), V[1].end(), greater<int>());
        sort(V[2].begin(), V[2].end(), greater<int>());

        int Result = 0;
        int V1Size = V[1].size();
        int V2Size = V[2].size();

        for(int Count1 = V1Size - 2; Count1 <= V1Size; Count1++)
        {
            if(Count1 >= 0)
            {
                for(int Count2 = V2Size - 2; Count2 <= V2Size; Count2++)
                {
                    if(Count2 >= 0 && (Count1 - Count2) % 3 == 0)
                    {
                        int Count1Sum = accumulate(V[1].begin(), V[1].begin() + Count1, 0);
                        int Count2Sum = accumulate(V[2].begin(), V[2].begin() + Count2, 0);
                        Result = max(Result, Count1Sum + Count2Sum);
                    }
                }
            }
        }
        return Result + accumulate(V[0].begin(), V[0].end(), 0);
    }
};