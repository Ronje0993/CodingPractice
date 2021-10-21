class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> max_prices(len);
        max_prices[len - 1] = prices[len - 1];
        for (int i = 1; i < len; i++){
            max_prices[len - 1 - i] = max(prices[len - 1 - i], max_prices[len - i]);
        }
        
        int max_profit = 0;
        for (int i = 0; i < len-1; ++i){
            
            int profit_i = max_prices[i+1] - prices[i];
            if (profit_i > 0 && max_profit < profit_i){
                max_profit = profit_i;
            }
        }
        
        return max_profit;
    }
};
