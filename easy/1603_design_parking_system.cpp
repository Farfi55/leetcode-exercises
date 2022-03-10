/*
 * @lc app=leetcode id=1603 lang=cpp
 *
 * [1603] Design Parking System
 */

// @lc code=start
class ParkingSystem {
    int spots[3] = {};
public:
    ParkingSystem(int big, int medium, int small) :
        spots{ big, medium, small } {}


    bool addCar(int carType) {
        if(spots[--carType] <= 0)
            return false;

        spots[carType]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

