s Solution {
public:

    int max_points = 0, max_mask = 0;
    
    void dfs(int k, int numArrows, vector<int>& aliceArrows, int points, int mask) {
        if (numArrows >= 0 && points > max_points) {
            max_points = points;
            max_mask = mask;
        }
        if (k > 0) {
            dfs(k - 1, numArrows - aliceArrows[k] - 1, aliceArrows, points + k, mask + (1 << k));
            dfs(k - 1, numArrows, aliceArrows, points, mask);
        }
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> res(12);
        dfs(11, numArrows, aliceArrows, 0, 0);
        for (int k = 11; k > 0; --k) {
            if (max_mask & (1 << k)) {
                res[k] = aliceArrows[k] + 1;
                numArrows -= aliceArrows[k] + 1;
            }
        }
        
        res[0] = numArrows;
        return res;
    }
};
