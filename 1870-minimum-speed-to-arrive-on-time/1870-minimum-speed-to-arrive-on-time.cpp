class Solution {
    const int MaxHour = 1e7;
public:
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        if(hour <= static_cast<double>(dist.size() - 1))
        {
            return -1;
        }
        
        int Low = 1, High = MaxHour;
        
        while(Low < High)
        {
            int Speed = (High + Low) >> 1;
            
            double Result = GetResultPerSpeed(dist, Speed);
            
            if(Result > hour)
            {
                Low = Speed + 1;
            }
            else
            {
                High = Speed;
            }
        }
        
        return High;
    }
    
private:
    double GetResultPerSpeed(const vector<int>& Dist, int Speed)
    {
        double Result = 0.f;
        
        for(const int& D : Dist)
        {
            Result = ceil(Result);
            
            Result += (static_cast<double>(D) / Speed);
        }
        
        return Result;
    }
};