class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        // Sort workers in ascending order
        sort(workers.begin(), workers.end());
        
        // Binary search on the maximum number of tasks that can be completed
        int left = 0, right = min(tasks.size(), workers.size());
        
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            
            if (canAssign(tasks, workers, pills, strength, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
    
private:
    bool canAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength, int count) {
        // Get the first 'count' smallest tasks
        vector<int> smallestTasks(tasks.begin(), tasks.begin() + count);
        
        // Get the 'count' strongest workers
        vector<int> strongestWorkers(workers.end() - count, workers.end());
        
        // Try to assign tasks to workers
        int pillsUsed = 0;
        
        for (int i = count - 1; i >= 0; i--) {
            int taskStrength = smallestTasks[i];
            
            // If the strongest worker can handle the current task without a pill
            if (strongestWorkers[i] >= taskStrength) {
                continue;
            }
            
            // Otherwise, find the weakest worker who can handle the task with a pill
            auto it = lower_bound(strongestWorkers.begin(), strongestWorkers.end(), taskStrength - strength);
            
            // If no worker can handle this task even with a pill, return false
            if (it == strongestWorkers.end() || *it > taskStrength) {
                return false;
            }
            
            // Use a pill and remove the worker
            pillsUsed++;
            if (pillsUsed > pills) {
                return false;
            }
            
            strongestWorkers.erase(it);
            // Add a dummy worker at the end to maintain the size
            strongestWorkers.push_back(INT_MAX);
        }
        
        return true;
    }
};