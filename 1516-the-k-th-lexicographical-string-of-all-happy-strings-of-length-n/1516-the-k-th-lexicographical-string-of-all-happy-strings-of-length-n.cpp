class Solution {
    string HappyString;
    int K = 0;
public:
    string getHappyString(int n, int k)
    {
        if(k > 3 * pow(2, n - 1))
        {
            return "";
        }

        K = k;
        DFS(0, '-', n);
        reverse(HappyString.begin(), HappyString.end());
        return HappyString;
    }
private:
    bool DFS(int Index, char Prev, const int N)
    {
        if(Index == N)
        {
            K--;
            return (K == 0);
        }

        for(char C = 'a'; C <= 'c'; C++)
        {
            if(C != Prev)
            {
                if(DFS(Index + 1, C, N))
                {
                    HappyString += C;
                    return true;
                }
            }
        }
        return false;
    }
};