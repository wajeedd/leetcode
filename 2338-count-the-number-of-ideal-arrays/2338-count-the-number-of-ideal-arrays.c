#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAXV 10005
#define MAXF 15

long long comb[10020][MAXF];
int spf[MAXV];

void computeSPF() {
    for(int i = 1; i < MAXV; i++) spf[i] = i;

    for(int i = 2; i * i < MAXV; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j < MAXV; j += i) {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void computeComb(int n) {
    for(int i = 0; i <= n; i++) {
        comb[i][0] = 1;
        for(int j = 1; j < MAXF && j <= i; j++) {
            if(j == i)
                comb[i][j] = 1;
            else
                comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
        }
    }
}

int idealArrays(int n, int maxValue) {

    computeSPF();
    computeComb(n + 14);

    long long ans = 0;

    for(int x = 1; x <= maxValue; x++) {

        int num = x;
        long long ways = 1;

        while(num > 1) {

            int prime = spf[num];
            int count = 0;

            while(spf[num] == prime) {
                num /= prime;
                count++;
            }

            ways = (ways * comb[n - 1 + count][count]) % MOD;
        }

        ans = (ans + ways) % MOD;
    }

    return ans;
}