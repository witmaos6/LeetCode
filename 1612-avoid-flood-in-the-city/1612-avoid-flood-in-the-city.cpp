class UnionFind{
public:
    vector<int> Parent;

    UnionFind(int Size) : Parent(Size + 1)
    {
        iota(Parent.begin(), Parent.end(), 0);
    }

    int Find(int i)
    {
        if(i == Parent[i])
            return i;

        Parent[i] = Find(Parent[i]);
        return Parent[i];
    }

    void Unite(int i) {Parent[i] = Find(i + 1); }
};

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains)
    {
        const int N = static_cast<int>(rains.size());

        UnionFind UF(N + 1);
        unordered_map<int, int> Table;
        vector<int> Result(N, 1);

        for(int i = 0; i < N; i++)
        {
            int Lake = rains[i];

            if(Lake != 0)
            {
                Result[i] = -1;
                UF.Unite(i);

                if(Table.find(Lake) != Table.end())
                {
                    int Prev = Table[Lake];
                    int Dry = UF.Find(Prev + 1);

                    if(Dry >= i)
                    {
                        return {};
                    }

                    Result[Dry] = Lake;
                    UF.Unite(Dry);
                    Table[Lake] = i;
                }
                else
                {
                    Table[Lake] = i;
                }
            }
        }
        return Result;
    }
};