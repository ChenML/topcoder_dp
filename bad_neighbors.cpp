#include<vector>
#define N 45

using namespace std;

int left[N];
int right[N];
class BadNeighbors {
	
public:
	
	int get_mx(vector<int> &don) {
		int n = don.size();
		left[0] = don[0];
		int tmp;
		for (int i = 1; i < n-1; ++i) {
			tmp = 0;
			for (int j = 0; j < i-1; ++j) {
				
				if (left[j] > tmp)
					tmp = left[j];
			}
			
			left[i] = tmp + don[i];
			
		}
		right[1] = don[1];
		for (int i = 2; i < n; ++i) {
			tmp = 0;
			for (int j = 1; j < i-1; ++j) {
				
				if (right[j] > tmp)
					tmp = right[j];
			}
			right[i] = don[i] + tmp;
		}
		
		int res = 0;
		
		for (int i = 0; i < n; ++i) {
			
			res = max(res, left[i]);
			res = max(res, right[i]);
			
		}
		
		return res;
	}
	
	int maxDonations(vector<int> donations) {
		
		int res = get_mx(donations);
		
		return res;
		
	}
	
};
