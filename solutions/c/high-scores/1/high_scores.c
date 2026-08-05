#include "high_scores.h"
/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len){
    return scores[scores_len-1];
}
/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len){
    int highest=scores[0];
    for(size_t i=0;i<scores_len;i++){
        if(scores[i]>highest){highest=scores[i];}
    }
    return highest;
}
/// Write the highest scores to `output` (in non-ascending order).
size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output)
{
    int32_t temp[scores_len];

    // Copy scores into a temporary array
    for (size_t i = 0; i < scores_len; i++)
    {
        temp[i] = scores[i];
    }

    // Sort in descending order
    for (size_t i = 0; i < scores_len - 1; i++)
    {
        for (size_t j = i + 1; j < scores_len; j++)
        {
            if (temp[i] < temp[j])
            {
                int32_t t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    // Number of scores to copy
    size_t count = (scores_len < 3) ? scores_len : 3;

    // Copy top scores to output
    for (size_t i = 0; i < count; i++)
    {
        output[i] = temp[i];
    }

    return count;
}