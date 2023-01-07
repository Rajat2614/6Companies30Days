class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if (n < 3)
            return 1.0/n;
        return 1 - (nthPersonGetsNthSeat(n-1));
    }
};
