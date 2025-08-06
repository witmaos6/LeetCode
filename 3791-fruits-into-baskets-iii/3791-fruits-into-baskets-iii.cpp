class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets)
    {
        const int N = static_cast<int>(fruits.size());
        int Root = floor(sqrt(N));
        vector<int> V(Root + 2);
        for(int i = 0; i < N; i++)
        {
            V[i / Root] = max(V[i / Root], baskets[i]);
        }

        int Result = 0;
        for(int i = 0; i < N; i++)
        {
            int Index = -1;
            for(int j = 0; j < Root + 2; j++)
            {
                if(V[j] >= fruits[i])
                {
                    Index = j;
                    break;
                }
            }
            if(Index == -1)
            {
                Result++;
                continue;
            }
            for(int j = Root * Index; j < (Index + 1) * Root; j++)
            {
                if(baskets[j] >= fruits[i])
                {
                    baskets[j] = 0;
                    break;
                }
            }
            V[Index] = 0;
            for(int j = Root * Index; j < min(N, (Index + 1) * Root); j++)
            {
                V[Index] = max(V[Index], baskets[j]);
            }
        }
        return Result;
    }
};