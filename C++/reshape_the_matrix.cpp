class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size(), col = nums[0].size();
        
        if(r * c != row * col) return nums;
        
        vector<vector<int>> result(r, vector<int>(c, 0));
        
        int index = 0, tmp = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(tmp == c) {
                    tmp = 0;
                    index++;
                }
                result[index][tmp++] = nums[i][j];
            }
        }
        
        return result;
    }
};
