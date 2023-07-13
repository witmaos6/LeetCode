class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int, vector<int>> Graph;
        vector<int> PreReq(numCourses);
        for(vector<int>& Req : prerequisites)
        {
            Graph[Req[0]].push_back(Req[1]);
            PreReq[Req[1]]++;
        }
        
        queue<int> BFS;
        for(int i = 0; i < numCourses; i++)
        {
            if(PreReq[i] == 0)
            {
                BFS.push(i);
            }
        }
        
        int TakeCourse = 0;
        while(!BFS.empty())
        {
            int Course = BFS.front();
            BFS.pop();
            TakeCourse++;
            
            for(int& Next : Graph[Course])
            {
                PreReq[Next]--;
                if(PreReq[Next] == 0)
                {
                    BFS.push(Next);
                }
            }
        }
        
        return TakeCourse == numCourses;
    }
};