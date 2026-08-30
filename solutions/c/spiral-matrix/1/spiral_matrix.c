#include "spiral_matrix.h"
#include <stdlib.h>

spiral_matrix_t *spiral_matrix_create(size_t size)
{
    spiral_matrix_t *structobj = malloc(sizeof(spiral_matrix_t));

    if (structobj == NULL) {
        return NULL;
    }

    structobj->size = size;

    // Empty matrix
    if (size == 0) {
        structobj->matrix = NULL;
        return structobj;
    }

    // Allocate rows
    structobj->matrix = malloc(size * sizeof(int *));

    if (structobj->matrix == NULL) {
        free(structobj);
        return NULL;
    }

    // Allocate each row
    for (size_t i = 0; i < size; i++) {
        structobj->matrix[i] = malloc(size * sizeof(int));

        if (structobj->matrix[i] == NULL) {
            for (size_t j = 0; j < i; j++) {
                free(structobj->matrix[j]);
            }

            free(structobj->matrix);
            free(structobj);
            return NULL;
        }
    }

    int num = 1;

    int top = 0;
    int bottom = size - 1;
    int left = 0;
    int right = size - 1;

    while (top <= bottom && left <= right) {

        // RIGHT →
        for (int j = left; j <= right; j++) {
            structobj->matrix[top][j] = num;
            num++;
        }
        top++;

        // DOWN ↓
        for (int i = top; i <= bottom; i++) {
            structobj->matrix[i][right] = num;
            num++;
        }
        right--;

        // Check before going LEFT
        if (top <= bottom) {
            // LEFT ←
            for (int j = right; j >= left; j--) {
                structobj->matrix[bottom][j] = num;
                num++;
            }
            bottom--;
        }

        // Check before going UP
        if (left <= right) {
            // UP ↑
            for (int i = bottom; i >= top; i--) {
                structobj->matrix[i][left] = num;
                num++;
            }
            left++;
        }
    }

    return structobj;
}

void spiral_matrix_destroy(spiral_matrix_t *matrix)
{
    if (matrix == NULL) {
        return;
    }

    for (int i = 0; i < matrix->size; i++) {
        free(matrix->matrix[i]);
    }

    free(matrix->matrix);
    free(matrix);
}