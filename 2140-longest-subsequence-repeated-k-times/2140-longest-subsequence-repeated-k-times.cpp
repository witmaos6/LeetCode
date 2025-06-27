class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k)
    {
        string Result;
        queue<string> Q;
        Q.push("");
        while(!Q.empty())
        {
            string Curr = Q.front();
            Q.pop();

            for(char C = 'a'; C <= 'z'; C++)
            {
                string Next = Curr + C;
                if(IsK(Next, s, k))
                {
                    Result = Next;
                    Q.push(Next);
                }
            }
        }
        return Result;
    }

private:
    bool IsK(const string& Sub, const string& T, int K)
    {
        int Count = 0;
        int i = 0;
        for(char C : T)
        {
            if(C == Sub[i])
            {
                if(++i == Sub.size())
                {
                    i = 0;
                    if(++Count == K)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};