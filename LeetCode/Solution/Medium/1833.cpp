class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = 0;
        for(int c : costs){
            maxCost = max(maxCost, c);
        }
        vector<int> cnt(maxCost + 1, 0);
        for(int c : costs){
            cnt[c]++;
        }
        int bars = 0;
        for(int price = 1; price <= maxCost && coins > 0; price++){
            if(cnt[price] == 0) continue;
            int canBuy = min(cnt[price], coins / price);
            bars += canBuy;
            coins -= canBuy * price;
        }
        return bars;
    }
};