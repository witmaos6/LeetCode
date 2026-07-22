class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries)
    {
        const int N = s.size();
        int Ones = ranges::count(s, '1');

        vector<int> Zs, Ze;
        for(int i = 0; i < N; )
        {
            if(s[i] == '0')
            {
                int j = i;
                while(j < N && s[j] == '0')
                    j++;

                Zs.push_back(i);
                Ze.push_back(j - 1);
                i = j;
            }
            else
            {
                i++;
            }
        }
        int NBlocks = Zs.size();

        vector<int> V;
        for(int j = 0; j + 1 < NBlocks; j++)
        {
            V.push_back((Ze[j] - Zs[j] + 1) + (Ze[j + 1] - Zs[j + 1] + 1));
        }

        int NV = V.size();
        vector<vector<int>> Sparse{V};
        for(int Half = 1; Half * 2 <= NV; Half *= 2)
        {
            vector<int>& Prev = Sparse.back();
            vector<int> Next;
            Next.reserve(Prev.size() - Half);

            for(int i = 0; i + Half < Prev.size(); i++)
            {
                Next.push_back(max(Prev[i], Prev[i + Half]));
            }
            Sparse.push_back(move(Next));
        }

        auto RMQ = [&](int Low, int High)
        {
            int T = bit_width(unsigned(High - Low + 1)) - 1;
            return max(Sparse[T][Low], Sparse[T][High - (1 << T) + 1]);
        };

        auto Clip = [&](int j, int L, int R)
        {
            return V[j] - max(0, L - Zs[j]) - max(0, Ze[j + 1] - R);
        };

        auto Gain = [&](int L, int R)
        {
            if(NBlocks < 2)
                return 0;
            int Ja = ranges::lower_bound(Ze, L) - Ze.begin();
            int Jb = ranges::upper_bound(Zs, R) - Zs.begin() - 2;
            if(Ja > Jb)
                return 0;
            
            return max({Clip(Ja, L, R), Clip(Jb, L, R), Jb - Ja >= 2 ? RMQ(Ja + 1, Jb - 1) : 0});
        };

        vector<int> Result;
        Result.reserve(queries.size());
        for(vector<int>& Query : queries)
        {
            Result.push_back(Ones + Gain(Query[0], Query[1]));
        }
        return Result;
    }
};