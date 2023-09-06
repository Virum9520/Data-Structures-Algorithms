#include <stdio.h>
 
int n = 3;
int weight[10] = {18,15,20}; 
int v[10] = {24,25,15}; 
int W = 20; 
float tot_v;

void simple_fill() {
    int cur_w;
    int i, max;
    int used[10];
    int frac;
 
    for (i = 0; i < n; i++)
    {
        used[i] = 0; /* I have not used the ith object yet */
    }
    cur_w = W;
    while (cur_w > 0) { /* while there's still room*/
        /* Find the best object */
        max = -1;
        for (i = 0; i < n; i++)
            if ((used[i] == 0) && ((max == -1) || ((float)v[i]/weight[i] > (float)v[max]/weight[max])))
                max = i;
 
        used[max] = 1; /* mark the max-th object as used */
        cur_w -= weight[max]; /* with the object in the bag, I can carry less */
        tot_v += v[max];
        
        if (cur_w >= 0)
            printf("Added object %d (%d$, %dKg) completely in the bag. Space left: %d.\n", max + 1, v[max], weight[max], cur_w);
        else {
            frac = (int)((1 + (float)cur_w/weight[max]) * 100);
            printf("Added %d%% (%d$, %dKg) of object %d in the bag.\n", frac, v[max],weight[max], max + 1);
            tot_v -= v[max];
            tot_v += (1 + (float)cur_w/weight[max]) * v[max];
        }
    }
 
    printf("Filled the bag with objects worth %.2f$.\n", tot_v);
}
 
int main() {

    simple_fill();
    return 0;
}