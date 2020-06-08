/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    int row = numsSize, col = *numsColSize;
        
    if(r * c != row * col){
        *returnSize = row;
        *returnColumnSizes = malloc(row * sizeof(int));
        for(int i = 0; i < row; i++) *(*(returnColumnSizes)+i) = *(numsColSize+i);
        return nums;
    }
    
    int** result = malloc(r * sizeof(int*));
    for(int i = 0; i < r; i++) result[i] = malloc(c * sizeof(int));
        
    int index = 0, tmp = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(tmp == c){
                tmp = 0;
                index++;
            }
            *(*(result+index)+tmp) = *(*(nums+i)+j);
            tmp++;
        }
    }
    *returnSize = r;
    *returnColumnSizes = malloc(r * sizeof(int));
    for(int i = 0; i < r; i++) *(*(returnColumnSizes)+i) = c;    
    
    return result;
}
