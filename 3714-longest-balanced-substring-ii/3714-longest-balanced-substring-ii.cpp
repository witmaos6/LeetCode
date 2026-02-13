class Solution {
public:
    int longestBalanced(string s)
    {
        const int N = static_cast<int>(s.size());
        int Result = 0;
        int A = 0, B = 0, C = 0, Run = 1;
        map<pair<int, int>, int> Table;
        map<int, int> AB, AC, BC;

        Table[{0,0}] = -1;
        AB[0] = -1;
        AC[0] = -1;
        BC[0] = -1;

        for(int i = 0; i < N; i++)
        {
            if(s[i] == 'a')
            {
                BC.clear();
                A++;
            }
            else if(s[i] == 'b')
            {
                AC.clear();
                B++;
            }
            else
            {
                AB.clear();
                C++;
            }

            if(AB.count(A - B))
            {
                Result = max(Result, i - AB[A - B]);
            }
            else
            {
                AB[A - B] = i;
            }

            if(AC.count(A - C))
            {
                Result = max(Result, i - AC[A - C]);
            }
            else
            {
                AC[A - C] = i;
            }

            if(BC.count(B - C))
            {
                Result = max(Result, i - BC[B - C]);
            }
            else
            {
                BC[B - C] = i;
            }

            if(Table.count({A - B, A - C}))
            {
                Result = max(Result, i - Table[{A - B, A - C}]);
            }
            else
            {
                Table[{A - B, A - C}] = i;
            }

            if(i != 0 && s[i] == s[i - 1])
            {
                Run++;
            }
            else
            {
                Run = 1;
            }

            Result = max(Result, Run);
        }
        return Result;
    }
};