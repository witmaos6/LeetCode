class Solution {
    const char Slash = '/';
public:
    string simplifyPath(string path)
    {
        vector<string> Directory;
        int N = static_cast<int>(path.size());

        for(int i = 0; i < N; i++)
        {
            if(path[i] == Slash)
            {
                continue;
            }

            string Temp;
            while(i < N && path[i] != Slash)
            {
                Temp += path[i];
                i++;
            }

            if(Temp == ".")
            {
                continue;
            }
            if(Temp == "..")
            {
                if(!Directory.empty())
                {
                    Directory.pop_back();
                }
            }
            else
            {
                Directory.push_back(Temp);
            }
        }
        
        string Result;
        
        for(string S : Directory)
        {
            Result += '/' + S;
        }

        if(Result.size() == 0)
        {
            return "/";
        }
        
        return Result;
    }
};