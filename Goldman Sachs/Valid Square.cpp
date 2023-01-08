class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(is_right_angle_equal_edge(p1, p3, p4) &&
           is_right_angle_equal_edge(p2, p3, p4))
            return true;
        
        if(is_right_angle_equal_edge(p1, p2, p4) &&
           is_right_angle_equal_edge(p3, p2, p4))
            return true;
        
        if(is_right_angle_equal_edge(p1, p3, p2) &&
           is_right_angle_equal_edge(p4, p3, p2))
            return true;
        return false;
    }
    
    bool is_right_angle_equal_edge(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
        int v1[2] = {p2[0]-p1[0], p2[1]-p1[1]};
        int v2[2] = {p3[0]-p1[0], p3[1]-p1[1]};
        
        if(v1[0]*v2[0] + v1[1] * v2[1] != 0) return false;
        
        int t1 = v1[0] * v1[0] + v1[1] * v1[1];
        int t2 = v2[0] * v2[0] + v2[1] * v2[1];
        return  t1==t2 && t1 != 0  ;
    }
};
