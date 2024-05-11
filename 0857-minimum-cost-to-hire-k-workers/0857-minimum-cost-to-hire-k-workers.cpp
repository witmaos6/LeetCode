class Solution {
    using P = pair<double, int>;
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k)
    {
        const int N = static_cast<int>(quality.size());
        
        vector<P> Ratios;
        for(int i = 0; i < N; i++)
        {
            double Ratio = static_cast<double>(wage[i]) / quality[i];
            Ratios.emplace_back(Ratio, i);
        }
        sort(Ratios.begin(), Ratios.end());
        
        priority_queue<int, vector<int>> MaxHeap;
        int QualitySum = 0;
        double MaxRate = 0.0;
        for(int i = 0; i < k; i++)
        {
            QualitySum += quality[Ratios[i].second];
            MaxRate = max(MaxRate, Ratios[i].first);
            MaxHeap.push(quality[Ratios[i].second]);
        }
        
        double Result = MaxRate * QualitySum;
        for(int i = k; i < N; i++)
        {
            MaxRate = max(MaxRate, Ratios[i].first);
            QualitySum -= MaxHeap.top();
            MaxHeap.pop();
            
            QualitySum += quality[Ratios[i].second];
            MaxHeap.push(quality[Ratios[i].second]);
            
            Result = min(Result, MaxRate * QualitySum);
        }
        
        return Result;
    }
};