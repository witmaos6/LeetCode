class Solution {
    using Pair = pair<int, int>;
public:
    int maxPalindromes(string s, int k)
    {
        const int N = s.size();
        vector<Pair> Indices;

        for(int i = 0; i < N; i++)
        {
            int Left = i - 1, Right = i + 1;
            int Count = 1;
            while(Left >= 0 && Right < N && (s[Left] == s[Right]))
            {
                if(Count >= k)
                {
                    break;
                }
                Count += 2;
                Left--;
                Right++;
            }
            if(Count >= k)
            {
                Indices.push_back({Left + 1, Right - 1});
            }

            if(i + 1 < N)
            {
                Left = i, Right = i + 1;
                Count = 0;
                while(Left >= 0 && Right < N && (s[Left] == s[Right]))
                {
                    if(Count >= k)
                    {
                        break;
                    }
                    Count += 2;
                    Left--;
                    Right++;
                }
                if(Count >= k)
                {
                    Indices.push_back({Left + 1, Right - 1});
                }
            }
        }

        sort(Indices.begin(), Indices.end(), [](const Pair& A, const Pair& B){
            return A.second < B.second;
        });

        int Result = 0;
        int Prev = -1;
        for(Pair& P : Indices)
        {
            if(P.first > Prev)
            {
                Result++;
                Prev = P.second;
            }
        }

        return Result;
    }
};