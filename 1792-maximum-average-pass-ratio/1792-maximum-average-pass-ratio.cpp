class Solution {
    using Pair = pair<double, int>;
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        priority_queue<Pair, vector<Pair>> MaxHeap;
        const int N = static_cast<int>(classes.size());
        
        for(int i = 0; i < N; i++)
        {
            double Pass = static_cast<double>(classes[i][0]);
            double Total = static_cast<double>(classes[i][1]);
            double Average = Pass / Total;
            
            double NewAverage = (Pass + 1) / (Total + 1);
            MaxHeap.emplace(NewAverage - Average, i);
        }
        
        for(int i = 0; i < extraStudents; i++)
        {
            auto[RiseAverage, Index] = MaxHeap.top();
            MaxHeap.pop();
            
            classes[Index][0]++;
            classes[Index][1]++;
            
            double Pass = static_cast<double>(classes[Index][0]);
            double Total = static_cast<double>(classes[Index][1]);
            double Average = Pass / Total;
            
            double NewAverage = (Pass + 1) / (Total + 1);
            MaxHeap.emplace(NewAverage - Average, Index);
        }
        
        double Sum = 0;
        for(int i = 0; i < N; i++)
        {
            Sum += static_cast<double>(classes[i][0]) / static_cast<double>(classes[i][1]);
        }
        return Sum / static_cast<double>(N);
    }
};