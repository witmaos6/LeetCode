struct AvgTime
{
    string Name;
    int TotalTime;
    int NrOfId;
    
    AvgTime() {}
    AvgTime(string name, int Total, int Id)
    {
        Name = name;
        TotalTime = Total;
        NrOfId = Id;
    }
};

class UndergroundSystem {
    typedef pair<string, int> Costom;
    unordered_map<int, Costom> StartStation;
    
    unordered_map<string, vector<AvgTime>> EndStation;
public:
    UndergroundSystem()
    {
        
    }
    
    void checkIn(int id, string stationName, int t)
    {
        StartStation[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t)
    {
        string StartStationName = StartStation[id].first;
        int StartTime = StartStation[id].second;        
        
        int Index = GetEndIndex(StartStationName, stationName);
        
        if(Index == -1)
        {
            AvgTime Temp = AvgTime(stationName, (t - StartTime), 1);
            EndStation[StartStationName].push_back(Temp);
        }
        else
        {
            EndStation[StartStationName][Index].TotalTime += (t - StartTime);
            EndStation[StartStationName][Index].NrOfId++;
        }
    }
    
    double getAverageTime(string startStation, string endStation)
    {
        int Index = GetEndIndex(startStation, endStation);
        
        if(Index != -1)
        {
            AvgTime& Temp = EndStation[startStation][Index];
            double Time = static_cast<double>(Temp.TotalTime);
            double Average = Time / Temp.NrOfId;
            
            return Average;
        }
        return 0;
    }
    
private:
    int GetEndIndex(const string& StationName, const string& EndStationName)
    {
        const int N = static_cast<int>(EndStation[StationName].size());
        
        for(int i = 0; i < N; i++)
        {
            if(EndStation[StationName][i].Name == EndStationName)
            {
                return i;
            }
        }
        return -1;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */