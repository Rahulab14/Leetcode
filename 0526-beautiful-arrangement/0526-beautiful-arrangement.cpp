class Solution {
public:
    int beautiful(int n, vector<bool>& visible, int pos) {
        if (n < pos) {
            return 1;
        }
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (!visible[i]&&( pos % i == 0 || i % pos == 0)) {
                visible[i] = true;
                count += beautiful(n, visible, pos + 1);
                visible[i] = false;
            }
        }
        return count;
    }
    int countArrangement(int n) {
        vector<bool> vector(n, false);
        return beautiful(n, vector, 1);
    }
};