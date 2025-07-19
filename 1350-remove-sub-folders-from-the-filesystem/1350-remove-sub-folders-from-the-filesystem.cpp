class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders)
    {
        vector<string> Result;
        unordered_set<string_view> Set(folders.begin(), folders.end());
        

        for(const string& folder : folders)
        {
            bool isSubfolder = false;
            const int N = static_cast<int>(folder.size());

            for(int i = 2; i < N; i++)
            {
                if(folder[i] == '/' && Set.count(string_view(folder.c_str(), i)))
                {
                    isSubfolder = true;
                    break;
                }
            }
            if(!isSubfolder)
            {
                Result.emplace_back(folder);
            }
        }
        return Result;
    }
};