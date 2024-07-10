class Solution {
public:
    int minOperations(vector<string>& logs)
    {
        vector<string> Folders = {"Main"};
        
        for(const string& Log : logs)
        {
            if(Log.front() == '.')
            {
                if(Log[1] == '.')
                {
                    if(Folders.back() != "Main")
                    {
                        Folders.pop_back();
                    }
                }
            }
            else
            {
                Folders.push_back(Log);
            }
        }
        return Folders.size() - 1;
    }
};