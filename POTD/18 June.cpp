class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (hour % 12) * 30 + minutes * 0.5;
        double mi = minutes * 6;

        double diff = abs(h - mi);
        return min(diff, 360 - diff);
    }
};