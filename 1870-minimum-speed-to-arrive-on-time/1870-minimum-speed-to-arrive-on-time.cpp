class Solution {
    const int MaxHour = 1e9;
public:
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        int Low = 0, High = MaxHour;
        int MinSpeed = -1;
        
        while(Low <= High)
        {
            int Speed = Low + (High - Low) / 2;
            
            double Result = GetResultPerSpeed(dist, Speed);
            
            if(Result > hour)
            {
                Low = Speed + 1;
            }
            else
            {
                High = Speed - 1;
                MinSpeed = Speed;
            }
        }
        
        return MinSpeed;
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