class Solution {
public:
    bool canReachOnTime(vector<int>& dist, double hour, int speed){
        double totalTime = 0.0;
        int n = dist.size();

        for (int i = 0; i < n - 1; i++){
            totalTime += ceil((double)dist[i]/speed);
        }

        totalTime += (double)dist[n-1]/speed;

        return totalTime <= hour;
    }


    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        int right = 1e7;
        int result = -1;

        while (left <= right){
            int mid = (left+right)/2;

            if (canReachOnTime(dist, hour, mid)){
                result = mid;
                right = mid - 1;
            } else{
                left = mid + 1;
            }
        }
        return result;
    }
};