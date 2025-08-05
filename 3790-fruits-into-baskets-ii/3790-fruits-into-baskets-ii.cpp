class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
    
   
    vector<int> availableBaskets = baskets;
    
   
    int unplaced = 0;
    
    for (int i = 0; i < n; i++) {
        bool placed = false;
        
        
        for (int j = 0; j < n; j++) {
            
            if (availableBaskets[j] != -1 && availableBaskets[j] >= fruits[i]) {
               
                availableBaskets[j] = -1;  
                placed = true;
                break;
            }
        }
        
        
        if (!placed) {
            unplaced++;
        }
    }
    
    return unplaced;
    }
};