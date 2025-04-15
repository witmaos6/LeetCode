class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2)
    {
        const int N = static_cast<int>(nums1.size());
        vector<int> Pos(N);

        for(int i = 0; i < N; i++)
        {
            Pos[nums2[i]] = i;
        }

        vector<int> Mapped(N);
        for(int i = 0; i < N; i++)
        {
            Mapped[i] = Pos[nums1[i]];
        }

        vector<long long> Left(N);
        vector<long long> Right(N);

        vector<int> Bit(N + 2);
        for(int  i = 0; i < N; i++)
        {
            Left[i] = Query(Bit, Mapped[i]);
            Update(Bit, Mapped[i] + 1, 1);
        }

        fill(Bit.begin(), Bit.end(), 0);
        for(int i = N - 1; i >= 0; i--)
        {
            Right[i] = Query(Bit, N) - Query(Bit, Mapped[i] + 1);
            Update(Bit, Mapped[i] + 1, 1);
        }

        long long Result = 0;
        for(int i = 0; i < N; i++)
        {
            Result += Left[i] * Right[i];
        }
        return Result;
    }

private:
    int Query(vector<int>& Bit, int Index)
    {
        int Result = 0;
        while(Index > 0)
        {
            Result += Bit[Index];
            Index -= Index & -Index;
        }
        return Result;
    }

    void Update(vector<int>& Bit, int Index, int Value)
    {
        const int N = static_cast<int>(Bit.size());
        while(Index < N)
        {
            Bit[Index] += Value;
            Index += Index & -Index;
        }
    }
};