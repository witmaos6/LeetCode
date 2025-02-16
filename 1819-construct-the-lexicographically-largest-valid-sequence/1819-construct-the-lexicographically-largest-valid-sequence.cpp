class Solution {
    vector<int> Result;
    vector<bool> Used;
    int ResultSize = 0;
public:
    vector<int> constructDistancedSequence(int n)
    {
        ResultSize = 2 * n - 1;
        Result.resize(ResultSize);
        
        Used.resize(n + 1);

        BackTracking(n, 0);
        return Result;
    }

private:
    bool BackTracking(int N, int Index)
    {
        while(Index < ResultSize && Result[Index] != 0)
        {
            Index++;
        }

        if(Index == ResultSize)
        {
            return true;
        }

        for(int i = N; i >= 1; i--)
        {
            if(Used[i])
                continue;

            if(i == 1)
            {
                Result[Index] = 1;
                Used[1] = true;

                if(BackTracking(N, Index + 1))
                    return true;
                
                Result[Index] = 0;
                Used[1] = false;
            }
            else if(Index + i < ResultSize && Result[Index + i] == 0)
            {
                Result[Index] = i;
                Result[Index + i] = i;
                Used[i] = true;

                if(BackTracking(N, Index + 1))
                    return true;

                Result[Index] = 0;
                Result[Index + i] = 0;
                Used[i] = false;
            }
        }
        return false;
    }
};