class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        unordered_map<int, unordered_set<int>> Graph;
        for(vector<int>& Prerequisite : prerequisites)
        {
            Graph[Prerequisite[1]].insert(Prerequisite[0]);
        }

        for(int i = 0; i < numCourses; i++)
        {
            for(int j = 0; j < numCourses; j++)
            {
                if(Graph[j].count(i))
                {
                    Graph[j].insert(Graph[i].begin(), Graph[i].end());
                }
            }
        }

        vector<bool> Result;
        Result.reserve(queries.size());
        for(vector<int>& Query : queries)
        {
            bool Temp = Graph[Query[1]].count(Query[0]) > 0;
            Result.push_back(Temp);
        }

        return Result;
    }
};