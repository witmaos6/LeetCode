class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B)
    {
        const int N = static_cast<int>(A.size());
        vector<int> Table(N + 1);
        vector<int> Result(N);

        int Count = 0;
        for(int i = 0; i < N; i++)
        {
            Table[A[i]]++;
            if(Table[A[i]] == 2)
            {
                Count++;
            }

            Table[B[i]]++;
            if(Table[B[i]] == 2)
            {
                Count++;
            }

            Result[i] = Count;
        }

        return Result;
    }
};