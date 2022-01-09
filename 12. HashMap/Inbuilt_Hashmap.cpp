#include<bits/stdc++.h>
#include<unordered_map>
#include<string>
using namespace std;

int main() {
	unordered_map<string, int>ourmap;
	//insert
	pair<string, int>p("abc", 1);
	ourmap.insert(p);
	ourmap["def"] = 2;
	ourmap["ef"] = 0;

	//find or access
	cout << ourmap["abc"] << endl;
	cout << ourmap.at("abc") << endl;

	cout << ourmap.size() << endl;
	//to check key is present or not
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}

	//remove
	ourmap.erase("ghi");

	return 0;
}
