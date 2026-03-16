int longestWPI(int* hours, int hoursSize) {
    int prefix = 0, ans = 0;

    int map[20001];
    for(int i=0;i<20001;i++) map[i] = -2;

    map[10000] = -1; 

    for(int i=0;i<hoursSize;i++){
        if(hours[i] > 8)
            prefix += 1;
        else
            prefix -= 1;

        int idx = prefix + 10000;

        if(prefix > 0)
            ans = i + 1;
        else{
            if(map[idx] == -2)
                map[idx] = i;

            if(map[idx - 1] != -2)
                ans = ans > (i - map[idx - 1]) ? ans : (i - map[idx - 1]);
        }
    }

    return ans;
}