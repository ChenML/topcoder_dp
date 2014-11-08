#include<string>

using namespace std;

string dp[55][55];

class ShortPalindromes {

string add(string base, int l, int r) {
	
	if (r-l == 0)
		return base.substr(l, 1);
	if (r-l < 0)
		return "";
	if (dp[l][r] != "")
		return dp[l][r];
	
	string res(100, ' ');	
		
	if (base[l] == base[r]) {
		
		res = base[l] + add(base, l+1, r-1) + base[r];
		
	}	
	else {
		
		string tmp;
		tmp = base[l] + add(base, l+1, r) + base[l];
		if (tmp.size() < res.size() || (tmp.size() == res. size() && tmp < res))
			res = tmp;
		
		tmp = base[r] + add(base, l, r-1) + base[r];
		if (tmp.size() < res.size() || (tmp.size() == res. size() && tmp < res))
			res = tmp;
	}	
	
	return dp[l][r] = res;	
	
}


public:

	string shortest(string base) {
		
		int n = base.size();	
		return add(base, 0, n-1);
			
	}
	
};
