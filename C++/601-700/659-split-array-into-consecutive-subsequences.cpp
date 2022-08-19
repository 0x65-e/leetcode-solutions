//#659. Split Array into Consecutive Subsequences (C++) - 110ms/87.72% 54.5MB/94.81%
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        cout << "test" << endl;
        int chains[] = {0, 0, 0};
        int prev = numeric_limits<int>::min();
        for (auto it = nums.cbegin(), runner = it; it != nums.cend(); it = runner) {
            int count = 0;
            for (runner = it; runner != nums.cend() && *runner == *it; runner++) count++;
            
            if (*it > prev + 1) {
                // Breaking jump
                if (chains[0] > 0 || chains[1] > 0) return false; // There are uncompleted chains
                else {
                    chains[2] = 0; // Ignore all completed chains
                    chains[0] = count; // Start all new chains
                }
            } else {
                // Non-breaking jump
                if (count < chains[0] + chains[1]) return false; // Not enough to extend each chain
                int remaining = count - chains[0] - chains[1]; // Number remaining after fulfilling obligations
                int newchains = max(0, remaining - chains[2]);
                chains[2] = chains[1] + min(chains[2], remaining); // Keep as many completed chains as possible
                chains[1] = chains[0];
                chains[0] = newchains;
            }
            prev = *it;
        }
        return (chains[0] == 0 && chains[1] == 0);
    }
};