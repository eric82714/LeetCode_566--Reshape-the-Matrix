class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        row, col = len(nums), len(nums[0])
        
        if r * c != row * col: return nums
        
        result = [[]]
        
        for i in range(row):
            for j in range(col):
                if len(result[-1]) == c: result.append([])
                result[-1].append(nums[i][j])
        
        return result
