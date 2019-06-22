#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	map< string, string > ph;

	ph["jones"] = "123";
	int s = 1223334444;
	cout << "jones\t" << ph["jones"] << endl << s;

	system("pause");
	return 0;
}
