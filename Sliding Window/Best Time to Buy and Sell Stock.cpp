#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n= prices.size();
    
            int maxP = 0;
            int minBuy= prices[0];
    
            for(int sell:prices){
                maxP= max(maxP,sell-minBuy);
                minBuy= min(minBuy,sell);
            }
            return maxP;
    
        }
    };
int main(){
    Solution s;
    vector<int> prices={7,1,5,3,6,4};
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}