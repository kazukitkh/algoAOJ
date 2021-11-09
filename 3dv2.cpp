#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

int main()
{
	vector<int>	data;
	vector <int> ans;
	int			cnt = 0, sum = 0, s;
	string		str;
	
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '\\') {
			data.push_back(0);
		} else if (str[i] == '/') {
			if (data.size()) {
				sum += s = data.back();
				ans.push_back(s);
				data.pop_back();
				cnt++;
			}
		}
		for (int j = 0; j < data.size() && data.size(); j++)
			data[j]++;
	}
	cout << sum << endl;
	cout << cnt << " ";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " \n"[i == ans.size() - 1];
	}

}