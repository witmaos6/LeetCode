class ParkingSystem {
    vector<int> ParkSize;
    vector<int> ParkIndex;
public:
    ParkingSystem(int big, int medium, int small)
    {
        ParkSize.resize(4);
        ParkIndex.resize(4);
        
        ParkSize[1] = big;
        ParkSize[2] = medium;
        ParkSize[3] = small;
    }
    
    bool addCar(int carType)
    {
        if(ParkSize[carType] > ParkIndex[carType])
        {
            ParkIndex[carType]++;
            return true;
        }
        
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */