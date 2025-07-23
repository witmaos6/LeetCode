class Solution {
public:
    int maximumGain(string s, int x, int y)
    {
        int Result = 0;
        int HighScore = max(x, y);

        if(HighScore == x)
        {
            string RemoveStrX = RemoveString(s, 'a', 'b', x, Result);

            string RemoveStrY = RemoveString(RemoveStrX, 'b', 'a', y, Result);
        }
        else
        {
            string RemoveStrY = RemoveString(s, 'b', 'a', y, Result);

            string RemoveStrX = RemoveString(RemoveStrY, 'a', 'b', x, Result);
        }
        return Result;
    }

private:
    string RemoveString(const string& S, char P, char Q, int X, int& Result)
    {
        stack<char> St;
        for(const char& C : S)
        {
            if(!St.empty() && St.top() == P && C == Q)
            {
                St.pop();
                Result += X;
            }
            else
            {
                St.push(C);
            }
        }
        const int N = static_cast<int>(St.size());
        string RemoveStr(N, ' ');
        for(int i = N - 1; i >= 0; i--)
        {
            RemoveStr[i] = St.top();
            St.pop();
        }
        return RemoveStr;
    }
};