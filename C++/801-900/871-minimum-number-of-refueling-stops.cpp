//#871. Minimum Number of Refueling Stops (C++) - 45ms/58.63% 16.2MB/51.25%
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0, range = startFuel;
        vector<int> heap;
        auto it = stations.cbegin();
        for (; range < target; stops++) {
            // Add all reachable stops on the journey
            for (; it != stations.cend() && (*it)[0] <= range; it++) {
                heap.push_back((*it)[1]);
                push_heap(heap.begin(), heap.end());
            }
            // Out of gas stations
            if (heap.empty()) return -1;
            // Fill up with the most gas available anywhere along the route
            pop_heap(heap.begin(), heap.end());
            range += heap.back();
            heap.pop_back();
        }
        return stops;
    }
};