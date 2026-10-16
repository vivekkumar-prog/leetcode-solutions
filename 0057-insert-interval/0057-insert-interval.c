
/**
 * Return an array of arrays of size *returnColumnSizes.
 * The sizes of the arrays are returned as *returnColumnSizes.
 * Note: Both returned array and *returnColumnSizes must be malloced.
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize,
             int* newInterval, int newIntervalSize,
             int* returnSize, int** returnColumnSizes) {

    int** result = malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = malloc((intervalsSize + 1) * sizeof(int));

    int i = 0, k = 0;

    // Add intervals that come before newInterval
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[k] = malloc(2 * sizeof(int));
        result[k][0] = intervals[i][0];
        result[k][1] = intervals[i][1];
        (*returnColumnSizes)[k] = 2;
        k++;
        i++;
    }

    // Merge overlapping intervals
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        if (intervals[i][0] < newInterval[0]) {
            newInterval[0] = intervals[i][0];
        }
        if (intervals[i][1] > newInterval[1]) {
            newInterval[1] = intervals[i][1];
        }
        i++;
    }

    // Add the merged interval
    result[k] = malloc(2 * sizeof(int));
    result[k][0] = newInterval[0];
    result[k][1] = newInterval[1];
    (*returnColumnSizes)[k] = 2;
    k++;

    // Add remaining intervals
    while (i < intervalsSize) {
        result[k] = malloc(2 * sizeof(int));
        result[k][0] = intervals[i][0];
        result[k][1] = intervals[i][1];
        (*returnColumnSizes)[k] = 2;
        k++;
        i++;
    }

    *returnSize = k;
    return result;
}
