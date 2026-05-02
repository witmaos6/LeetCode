class Solution {
public:
    int rotatedDigits(int n)
    {
        vector<int> Memo(n + 1);
        int Count = 0;

        for(int i = 0; i <= n; i++)
        {
            if(i < 10)
            {
                if(i == 0 || i == 1 || i == 8)
                {
                    Memo[i] = 1;
                }
                else if(i == 2 || i == 5 || i == 6 || i == 9)
                {
                    Memo[i] = 2;
                    Count++;
                }
                else
                {
                    Memo[i] = 0;
                }
            }
            else
            {
                int A = Memo[i / 10];
                int B = Memo[i % 10];

                if(A == 1 && B == 1)
                {
                    Memo[i] = 1;
                }
                else if(A >= 1 && B >= 1)
                {
                    Memo[i] = 2;
                    Count++;
                }
                else
                {
                    Memo[i] = 0;
                }
            }
        }
        return Count;
    }
};