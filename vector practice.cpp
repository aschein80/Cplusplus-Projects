#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
 #include <iomanip>
#include <time.h>
using namespace std;

int main(){
	
	vector<char>storage;
	
	storage.push_back('0');
	storage.push_back('7');
	storage.push_back('A');
	storage.push_back(9);
	storage.push_back(70);
	
	for(vector<char>::iterator it= storage.begin(); it!=storage.end(); it++){
		cout<<*it<<endl;
	}
	
	
	return 0;
}
