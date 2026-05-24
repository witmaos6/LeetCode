class Solution {
    int N = 0;
    vector<int> Memo;
public:
    int maxJumps(vector<int>& arr, int d)
    {
        N = arr.size();
        Memo.resize(N, -1);

        int Result = 1;
        for(int i = 0; i < N; i++)
        {
            Result = max(Result, DFS(i, arr, d));
        }

        return Result;
    }

private:
    int DFS(int i, vector<int>& Arr, int D)
    {
        if(Memo[i] != -1)
            return Memo[i];
        
        int Result = 1;

        int LeftRange = min(N - 1, i + D);
        for(int j = i + 1; j <= LeftRange; j++)
        {
            if(Arr[j] >= Arr[i])
                break;

            Result = max(Result, 1 + DFS(j, Arr, D));
        }

        int RightRange = max(0, i - D);
        for(int j = i - 1; j >= RightRange; j--)
        {
            if(Arr[j] >= Arr[i])
                break;
            
            Result = max(Result, 1 + DFS(j, Arr, D));
        }

        return Memo[i] = Result;
    }
};