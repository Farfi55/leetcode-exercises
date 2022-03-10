/*
 * @lc app=leetcode id=1603 lang=cpp
 *
 * [1603] Design Parking System
 */

// @lc code=start
class ParkingSystem {
    int big_spots;
    int medium_spots;
    int small_spots;
public:
    ParkingSystem(int big, int medium, int small) :
        big_spots(big), medium_spots(medium), small_spots(small) {}


    bool addCar(int carType) {
        switch(carType) {
            case 1:
            if(big_spots > 0) {
                big_spots--;
                return true;
            }
            break;
            case 2:
            if(medium_spots > 0) {
                medium_spots--;
                return true;
            }
            break;
            case 3:
            if(small_spots > 0) {
                small_spots--;
                return true;
            }
            break;
        }

        return false;

    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

