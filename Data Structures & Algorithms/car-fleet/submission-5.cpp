class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars(n);

        for(int i = 0; i < n; i++) {
            cars[i].first = position[i];
            cars[i].second = speed[i];
        }

        sort(cars.begin(), cars.end(), greater<pair<int,int>>());

        vector<double> time(n);

        for(int i = 0; i < n; i++) {
            time[i] = double(target - cars[i].first) / cars[i].second;
        }

        int count = 0;
        double so_far = 0;
        for(int i = 0; i < n; i++) {
            if(time[i] > so_far) {
                count++;
                so_far = time[i];
            }
        }
    return count;
    }
};
