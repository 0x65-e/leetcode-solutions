#1184. Distance Between Bus Stops (Python3) - 40ms/91.38% 15.1MB/36.51%
class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        if start == destination:
            return 0
        if start > destination:
            start, destination = destination, start # Normalize for clockwise path
        clockwise, counterclockwise = 0, 0
        for i, dist in enumerate(distance):
            if i >= start and i < destination:
                clockwise += dist
            else:
                counterclockwise += dist
        return min(clockwise, counterclockwise)