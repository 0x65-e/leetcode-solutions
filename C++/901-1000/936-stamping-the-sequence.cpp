//#936. Stamping The Sequence (C++) - 81ms/43.44% 7.2MB/97.54%
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        if (target.back() != stamp.back()) return {};
        vector<int> moves;
        while (true) {
            int best = 0;
            int matches = 0;
            for (int i = 0; i < target.length() - stamp.length() + 1; i++) {
                int trial = numMatches(stamp, target, i);
                if (trial > matches) {
                    best = i;
                    matches = trial;
                    if (trial == stamp.length()) break;
                }
            }
            if (matches > 0) {
                for (int i = 0; i < stamp.length(); i++) {
                    target[best + i] = '?';
                }
                moves.push_back(best);
            } else {
                break;
            }
        }
        if (target.find_first_not_of('?') == string::npos) {
            reverse(moves.begin(), moves.end());
            return moves;
        } else {
            return {};
        }
    }
private:
    int numMatches(const string& stamp, const string& target, int start) {
        int matches = 0;
        for (int i = 0; i < stamp.length(); i++) {
            if (target.at(start + i) == '?') {
                continue;
            } else if (target.at(start + i) == stamp.at(i)) {
                matches++;
            } else {
                return -1;
            }
        }
        return matches;
    }
};