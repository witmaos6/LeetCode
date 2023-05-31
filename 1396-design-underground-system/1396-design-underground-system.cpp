struct AvgTime
{
    int TotalTime;
    int NrOfId;
    
    AvgTime() {}
    AvgTime(int Total, int Id)
    {
        TotalTime = Total;
        NrOfId = Id;
    }
};

class UndergroundSystem {
    typedef pair<string, int> Costom;
    unordered_map<int, Costom> CheckIn;
    
    unordered_map<string, map<string, AvgTime>> CheckOut;
public:
    UndergroundSystem()
    {
        
    }
    
    void checkIn(int id, string stationName, int t)
    {
        CheckIn[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t)
    {
        string StartStation = CheckIn[id].first;
        int StartTime = CheckIn[id].second;        
        
        map<string, AvgTime>& Map = CheckOut[StartStation];
        
        if(Map.find(stationName) != Map.end())
        {
            Map[stationName].TotalTime += (t - StartTime);
            Map[stationName].NrOfId++;
        }
        else
        {
            Map[stationName] = AvgTime(t - StartTime, 1);
        }
    }
    
    double getAverageTime(string startStation, string endStation)
    {
        map<string, AvgTime>& Temp = CheckOut[startStation];
        
        if(Temp.find(endStation) != Temp.end())
        {
            double Time = static_cast<double>(Temp[endStation].TotalTime);
            double Average = Time / Temp[endStation].NrOfId;
            return Average;
        }
        return 0;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */