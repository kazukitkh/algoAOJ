#include <string>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
	std::ios_base::sync_with_stdio(false);// printf やscanfを使えなくなるが，処理速度は早くなる．
	set<string> st;
	int n;
	cin >> n;
	while (n--)
	{
		string BUFF, c;
		cin >> BUFF >> c;
		if (BUFF == "insert")
			st.insert(c);
		else
			cout << (st.find(c) != st.end() ? "yes" : "no") << endl;
	}
}