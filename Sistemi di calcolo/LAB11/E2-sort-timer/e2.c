#include "e2.h"

int i;
int max;

static void do_sort(int *v, int n) {
    int j;
    extern int i;
    for (i=0; i<n; ++i)
        for (j=1; j<n; ++j)
            if (v[j-1] > v[j]) {
                int tmp = v[j-1];
                v[j-1] = v[j];
                v[j] = tmp;
            }
}

static void handler(int sig) {
    (void)sig;
    printf("%.2f%%\n", (float)i / (float)max * 100.0f);
    ualarm(100 * 1000, 0);
}



void sort(int *v, int n) {

    max = n;
    // completare con gestione segnali...

    signal(SIGALRM, &handler);
    
    ualarm(10 * 1000, 0);
    

    do_sort(v, n);
}

