class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 0 || cost.size() == 0) {
            return -1;
        }
        
        int fuel = 0;
        int start = -1;
        int total = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            fuel += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (fuel >= 0 && start == -1) {
                start = i;
            } else if (fuel < 0) {
                fuel = 0;
                start = -1;
            }
        }
        
        if (total < 0) {
            start = -1;
        }
        
        return start;
    }
};
