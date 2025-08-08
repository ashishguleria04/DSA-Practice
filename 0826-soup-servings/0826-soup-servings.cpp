class Solution {
public:
    
    std::unordered_map<int, std::unordered_map<int, double>> memo;

    double soupServings(int n) {
        
        if (n >= 4800) { 
            return 1.0;
        }

       
        int scaled_n = (n + 24) / 25; 
        return dfs(scaled_n, scaled_n);
    }

    double dfs(int a, int b) {
       
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;

       
        if (memo.count(a) && memo[a].count(b)) {
            return memo[a][b];
        }

       
        double prob = 0.25 * (dfs(a - 4, b) +  
                             dfs(a - 3, b - 1) + 
                             dfs(a - 2, b - 2) + 
                             dfs(a - 1, b - 3)); 

        
        return memo[a][b] = prob;
    }
};
