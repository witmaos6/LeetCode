class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        unordered_map<int, vector<int>> Graph;
        for(vector<int>& Prerequisite : prerequisites)
        {
            Graph[Prerequisite[1]].push_back(Prerequisite[0]);
        }

        for(int i = 0; i < numCourses; i++)
        {
            for(int j = 0; j < numCourses; j++)
            {
                if(IsExist(Graph[j], i))
                {
                    for(int& Num : Graph[i])
                    {
                        PushUnique(Graph[j], Num);
                    }
                }
            }
        }

        vector<bool> Result;
        Result.reserve(queries.size());
        for(vector<int>& Query : queries)
        {
            bool Temp = IsExist(Graph[Query[1]], Query[0]);
            Result.push_back(Temp);
        }

        return Result;
    }
private:
    bool IsExist(const vector<int>& Arr, const int Element)
    {
        for(const int& Num : Arr)
        {
            if(Num == Element)
                return true;
        }
        return false;
    }

    void PushUnique(vector<int>& Arr, const int Element)
    {
        bool IsExist = false;
        for(int& Num : Arr)
        {
            if(Num == Element)
            {
                IsExist = true;
            }
        }

        if(!IsExist)
        {
            Arr.push_back(Element);
        }
    }
};