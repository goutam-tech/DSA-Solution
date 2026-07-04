/*
 * Complete the 'steadyGene' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING gene as parameter.
 */

int steadyGene(string gene) {
    int n = gene.size();
    int target = n / 4;
    
    int total[4] = {0, 0, 0, 0};
    auto idx = [](char c) -> int{
        if(c == 'A') return 0;
        if(c == 'C') return 1;
        if(c == 'G') return 2;
        return 3;
    };
    
    for(char c : gene){
        total[idx(c)]++;
    }
    
    int window[4] = {0, 0, 0, 0};
    int ans = n;
    int left = 0;
    
    for(int right = 0; right < n; right++){
        window[idx(gene[right])]++;
        
        while(left <= right && total[0] - window[0] <= target && total[1] - window[1] <= target && total[2] - window[2] <= target && total[3] - window[3] <= target){
            ans = min(ans, right - left + 1);
            window[idx(gene[left])]--;
            left++;
        }
    }
    
    return ans;
}