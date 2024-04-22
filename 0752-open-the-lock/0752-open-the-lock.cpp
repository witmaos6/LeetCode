class Solution {
public:
    int openLock(vector<string>& deadends, string target)
    {
        unordered_set<string> Table{deadends.begin(), deadends.end()};
        if(Table.find("0000") != Table.end())
            return -1;
        if(target == "0000")
            return 0;
        
        int Result = 0;
        queue<string> BFS;
        BFS.push("0000");
        while(!BFS.empty())
        {
            Result++;
            
            size_t Range = BFS.size();
            for(size_t i = 0; i < Range; i++)
            {
                string Word = BFS.front();
                BFS.pop();
                
                for(int j = 0; j < 4; j++)
                {
                    const char Cache = Word[j];
                    Word[j] = (Word[j] == '9') ? '0' : Word[j] + 1;
                    
                    if(Word == target)
                        return Result;
                    if(Table.find(Word) == Table.end())
                    {
                        BFS.push(Word);
                        Table.insert(Word);
                    }
                    Word[j] = Cache;
                    Word[j] = (Word[j] == '0') ? '9' : Word[j] - 1;
                    
                    if(Word == target)
                        return Result;
                    if(Table.find(Word) == Table.end())
                    {
                        BFS.push(Word);
                        Table.insert(Word);
                    }
                    Word[j] = Cache;
                }
            }
        }
        return -1;
    }
};