class Solution {
    using P = pair<int, int>;
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson)
    {
        vector<vector<P>> Graph(n);
        for(vector<int>& Meeting: meetings)
        {
            Graph[Meeting[0]].push_back({Meeting[2], Meeting[1]});
            Graph[Meeting[1]].push_back({Meeting[2], Meeting[0]});
        }
        
        vector<int> Known(n, INT_MAX);
        vector<int> List;
        priority_queue<P, vector<P>, greater<P>> MinHeap;
        MinHeap.push({0, 0});
        MinHeap.push({0, firstPerson});
        while(!MinHeap.empty())
        {
            auto [Time, Person] = MinHeap.top();
            MinHeap.pop();
            
            if(Known[Person] != INT_MAX)
                continue;
            
            List.push_back(Person);
            Known[Person] = Time;
            for(auto& [NextTime, NextPerson] : Graph[Person])
            {
                if(Known[NextPerson] != INT_MAX || NextTime < Time)
                    continue;
                
                MinHeap.push({NextTime, NextPerson});
            }
        }
        
        return List;
    }
};