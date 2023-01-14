class Solution {
public:
    int magicalString(int n) {
        string s = " ";
        for (int i = 1, x = 0; i <= n; ++i) {
            if (i >= s.size()) { x = i; }
            else { x = s[i] - '0'; }
            
            if (i & 1) {
                s.append(x, '1');
            } else {
                s.append(x, '2');
            }
        }
        return count(s.begin(), s.begin() + n + 1, '1');
    }
};
