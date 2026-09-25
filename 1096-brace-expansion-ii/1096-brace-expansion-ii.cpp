class Solution {
public:
    vector<string> braceExpansionII(string expression)
    {
        vector<string> Result, Curr;
        stack<vector<string>> St;

        for(char& C : expression)
        {
            if(C >= 'a' && C <= 'z')
            {
                if(Curr.size())
                {
                    for(string& S : Curr)
                    {
                        S += C;
                    }
                }
                else
                {
                    Curr.push_back((string(1, C)));
                }
            }
            else if(C == '{')
            {
                St.push(Result);
                St.push(Curr);
                Result.clear();
                Curr.clear();
            }
            else if(C == '}')
            {
                vector<string> PreCurr = St.top();
                St.pop();
                vector<string> PreResult = St.top();
                St.pop();

                for(string& S : Curr)
                {
                    Result.push_back(S);
                }
                Curr = Multiply(PreCurr, Result);
                Result = PreResult;
            }
            else if(C == ',')
            {
                for(string& S : Curr)
                {
                    Result.push_back(S);
                }
                Curr.clear();
            }
        }

        for(string& S : Curr)
        {
            Result.push_back(S);
        }
        sort(Result.begin(), Result.end());
        return vector<string>(Result.begin(), unique(Result.begin(), Result.end()));
    }

private:
    vector<string> Multiply(vector<string>& A, vector<string>& B)
    {
        if(A.empty())
            return B;
        if(B.empty())
            return A;

        vector<string> Result;
        for(string& S1 : A)
        {
            for(string& S2 : B)
            {
                Result.push_back(S1 + S2);
            }
        }
        return Result;
    }
};