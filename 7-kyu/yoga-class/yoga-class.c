​
#include <stdio.h>
​
int yoga(size_t n, const int classroom[n][n], size_t p, const int poses[p])
{
    int total = 0;
​
    for (size_t i = 0; i < n; i++)
    {
        int row_sum = 0;
        for (size_t j = 0; j < n; j++)
        {
            row_sum += classroom[i][j];
        }
​
        for (size_t j = 0; j < n; j++)
        {
            int ability = row_sum + classroom[i][j];
​
            for (size_t k = 0; k < p; k++)
            {
                if (ability >= poses[k])
                {
                    total++;
                }
            }
        }
    }
​
    return total;
}