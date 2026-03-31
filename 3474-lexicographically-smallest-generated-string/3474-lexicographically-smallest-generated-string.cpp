class Solution {
public:
    string generateString(string str1, string str2)
    {
        const int N = str1.size();
        const int M = str2.size();

        string Result(N + M - 1, '-');

        for(int i = 0; i < N; i++)
        {
            if(str1[i] != 'T')
                continue;
            
            for(int j = 0; j < M; j++)
            {
                char V = Result[i + j];
                if(V != '-' && V != str2[j])
                    return "";
                Result[i + j] = str2[j];
            }
        }

        string Old = Result;
        for(char& C : Result)
        {
            if(C == '-')
                C = 'a';
        }

        for(int i = 0; i < N; i++)
        {
            if(str1[i] != 'F')
                continue;
            
            if(string(Result.begin() + i, Result.begin() + i + M) != str2)
                continue;
            
            bool Flag = false;
            for(int j = i + M - 1; j >= i; j--)
            {
                if(Old[j] == '-')
                {
                    Result[j] = 'b';
                    Flag = true;
                    break;
                }
            }
            if(!Flag)
            {
                return "";
            }
        }
        return Result;
    }
};