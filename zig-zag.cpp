#include<iostream>
#include<vector>
#define N 55
using namespace std;

int dp[N];

class ZigZag {
public:

	int longestZigZag(vector<int> sequence) {
		int n = sequence.size();
		if (n == 1)
			return 1;
		if (n == 2) {
			
			if (sequence[0] == sequence[1])
				return 1;
			else
				return 2;			
			
		}
				
		vector<int> dif;
		for (int i = 1; i < n; ++i) {
			
			dif.push_back(sequence[i] - sequence[i-1]);
			
		}
		n = dif.size();
		
		dp[0] = (dif[0] == 0 ? 0 : 1);
		for(int i = 1; i < n; ++i) {
			
			if (dif[i] > 0) {
				
				dp[i] = 1;
				
				for (int j = i-1; j >= 0; --j) {
					
					if (dif[j] < 0) {
						dp[i] = dp[j] + 1;
						break;
					}
				}
			
			}
			
			else if(dif[i] < 0) {
				
				dp[i] = 1;
				
				for(int j = i-1; j >= 0; --j) {
					
					if (dif[j] > 0) {
						
						dp[i] = dp[j] + 1;
						break;
					}
				} 
			
			}
			
			else {
				
				dp[i] = dp[i-1];
				
			}
			
		} 
		
		int res = 0;
		
		for (int i = 0; i < n; ++i) {
			
			if (res < dp[i])
				res = dp[i];
		
		}
		
		return res + 1;
		
	}	
	
	
	
};
