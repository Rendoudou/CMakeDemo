#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <iomanip>
#include <map>
using namespace std;

bool check_su(long long & a) {
	if (a == 1 || a == 0)
		return false;
	for (long long i = 2; i <= sqrt(a); i++) {
		if (a % i == 0){
			return false;
		}
	}
	return true;
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	string number_str;
	getchar();
	getline(cin, number_str);
	string str_temp;
	istringstream is;
	long long ll_temp;
	if (n >= m) {
		for (size_t i = 0; i <= number_str.size() - m; i++) {
			str_temp = number_str.substr(i, m);
			is = istringstream(str_temp);
			is >> ll_temp;
			//ll_temp = atoi(str_temp.c_str());
			if (check_su(ll_temp)) {
				cout << str_temp << endl;
				return 0;
			}
		}
	}
	cout << "404" << endl;
	return 0;
}
