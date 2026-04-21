class UnionFind
{
    vector<int> RT;
    vector<int> RK;
public:
    UnionFind(int N)
    {
        RT.resize(N);
        for(int i = 0; i < N; i++)
        {
            RT[i] = i;
        }
        RK.resize(N, 0);
    }

    int Find(int X)
    {
        return (X == RT[X]) ? X : RT[X] = Find(RT[X]);
    }

    bool Union(int X, int Y)
    {
        X = Find(X), Y = Find(Y);
        if(X == Y)
            return false;

        if(RK[X] > RK[Y])
        {
            swap(X, Y);
        }

        RT[X] = Y;
        if(RK[X] == RK[Y])
        {
            RK[Y]++;
        }   
        
        return true;
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps)
    {
        const int N = source.size();
        UnionFind G(N);
        vector<int> Freq(100001);

        for(vector<int>& Swap : allowedSwaps)
        {
            G.Union(Swap[0], Swap[1]);
        }

        vector<vector<int>> Indices(N);
        for(int i = 0; i < N; i++)
        {
            Indices[G.Find(i)].push_back(i);
        }

        int Match = 0;
        for(int i = 0; i < N; i++)
        {
            if(Indices[i].empty())
                continue;

            for(const int& Index : Indices[i])
            {
                Freq[source[Index]]++;
            }

            for(const int& Index : Indices[i])
            {
                if(Freq[target[Index]] > 0)
                {
                    Freq[target[Index]]--;
                    Match++;
                }
            }

            for(const int& Index : Indices[i])
            {
                Freq[source[Index]] = 0;
            }
        }
        return N - Match;
    }
};