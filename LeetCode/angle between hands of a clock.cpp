class Solution {
public:
    double angleClock(int hour, int minutes) {
        float theta_hr = hour*30 + 30*(minutes/60.0);
        float theta_min = 360*(minutes/60.0);
        return min(abs(theta_hr - theta_min), 360 - abs(theta_hr - theta_min));
    }
};