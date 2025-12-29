class Solution {
public:
    
    int allowedTopBlocks[7][7];
  
   
    unordered_map<string, bool> memo;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        
        memset(allowedTopBlocks, 0, sizeof(allowedTopBlocks));
      
        
        for (auto& pattern : allowed) {
            int leftBlock = pattern[0] - 'A';
            int rightBlock = pattern[1] - 'A';
            int topBlock = pattern[2] - 'A';
          
            
            allowedTopBlocks[leftBlock][rightBlock] |= (1 << topBlock);
        }
      
    
        return buildPyramid(bottom, "");
    }

    bool buildPyramid(string& currentRow, string nextRow) {
        if (currentRow.size() == 1) {
            return true;
        }
      
        if (nextRow.size() + 1 == currentRow.size()) {
            return buildPyramid(nextRow, "");
        }
        string stateKey = currentRow + "." + nextRow;
        if (memo.count(stateKey)) {
            return memo[stateKey];
        }
        int leftBlockIndex = currentRow[nextRow.size()] - 'A';
        int rightBlockIndex = currentRow[nextRow.size() + 1] - 'A';
      
        int possibleBlocks = allowedTopBlocks[leftBlockIndex][rightBlockIndex];
      
        for (int blockIndex = 0; blockIndex < 7; ++blockIndex) {

            if ((possibleBlocks >> blockIndex) & 1) {
                if (buildPyramid(currentRow, nextRow + (char)(blockIndex + 'A'))) {
                    memo[stateKey] = true;
                    return true;
                }
            }
        }
        memo[stateKey] = false;
        return false;
    }
};