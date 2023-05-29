class ParkingSystem {
    vector<int> ParkSize;
    vector<int> ParkIndex;
public:
    ParkingSystem(int big, int medium, int small)
    {
        ParkSize = {0, big, medium, small};
        ParkIndex.resize(4);
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