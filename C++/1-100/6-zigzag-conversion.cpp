//#6. Zigzag Conversion (C++) - 13ms/70.67% 8.1MB/95.00%
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string out(s.length(), 0);
        int i = 0;
        for (int row = 0; row < numRows; row++) {
            int idx = row;
            bool down = true;
            while (idx < s.length()) {
                out[i] = s[idx];
                if (down) {
                    idx += (numRows - row - 1) * 2;
                    if (row != numRows - 1) i++;
                } else {
                    idx += row * 2;
                    if (row != 0) i++;
                }
                down = !down;
            }
        }
        return out;
    }
};