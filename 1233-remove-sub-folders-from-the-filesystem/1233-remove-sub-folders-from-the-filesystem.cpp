class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {
        sort(folder.begin(), folder.end());
        
        vector<string> Result;
        Result.push_back(folder.front());
        
        const int N = static_cast<int>(folder.size());
        for(int i = 1; i < N; ++i)
        {
            string LastFolder = Result.back() + '/';
            
            if(SubCompare(folder[i], LastFolder) == false)
            {
                Result.push_back(folder[i]);
            }
        }
        
        return Result;
    }
    
private:
    bool SubCompare(const string& Str1, const string& Str2)
    {
        const int N = static_cast<int>(min(Str1.size(), Str2.size()));
        
        for(int i = 0; i < N; ++i)
        {
            if(Str1[i] != Str2[i])
                return false;
        }
        
        return true;
    }
};