class Solution {
    typedef pair<int, int> Inform;
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        map<int, vector<int>> Tree;
        for(int i = 0; i < n; i++)
        {
            if(i != headID)
            {
                Tree[manager[i]].push_back(i);
            }
        }
        
        queue<Inform> BFS;
        BFS.push({headID, 0});
        
        int NeedTime = 0;
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            
            for(size_t i = 0; i < Range; i++)
            {
                int Head = BFS.front().first;
                int Time = BFS.front().second;
                BFS.pop();
                
                int CurrTime = Time + informTime[Head];
                
                NeedTime = max(NeedTime, CurrTime);
                
                for(int& Next : Tree[Head])
                {
                    BFS.push({Next, CurrTime});
                }
            }
        }
        
        return NeedTime;
    }
};