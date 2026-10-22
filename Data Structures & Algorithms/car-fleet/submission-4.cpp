
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<pair<int, int>> cars(n);

        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        double so_far = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;

            if (time > so_far) {
                count++;
                so_far = time;
            }
        }

        return count;
    }
};
