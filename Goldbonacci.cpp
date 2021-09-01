/** Alexandre Schein
* CECS 282 - 07
* Program 5 - GoldBonacci
* 5/1/2019
**/

#include"BigInt.cpp"
#include<string>
#include<vector>
#include<iomanip>
#include <time.h>
#include<algorithm>
#include <cstring>
#include<map>
#include<iostream>

using namespace std;

BigInt goldbonacci(int n){
	static map<int,BigInt> temp;
	if(n==1||n==0){
		temp[n]==temp[n-1]+temp[n-2];
	}
	else{
		return temp[n];
	}
}

int fact(int temp){
	if(temp>12){
		throw "Exception";
	}
	else{
		return temp*fact(temp-1);
	}
}


int main()

{

//int n = 45;
//
//int intResult = goldBonacci(n);
//
//cout << "\n... calculating goldBonacci(45)...\n";
//
//cout << "\ngoldBonacci["<<n<<"] = "<<intResult<<endl;
//
//cout << "function was called "<<goldBonacci(-1) << " times\n";
//
//getchar();
//
//
//goldBonacci(-2); // reset counter to 0
//
//n = 50;
//
//cout << "\n... calculating goldBonacci(50)...\n";
//
//intResult = goldBonacci(n);
//
//cout << "\ngoldBonacci["<<n<<"] = "<<intResult<<endl;
//
//cout << "function was called "<<goldBonacci(-1) << " times\n";
//
//getchar();
//
//BigInt N = 45;
//
//cout << "\n... calculating goldBonacci(BigInt(45))...\n";
//
//BigInt BigIntResult = goldBonacci(N);
//
//cout << "\ngoldBonacci["<<N<<"] = "<<BigIntResult<<endl;
//
//cout << "function was called "<<goldBonacci(BigInt(-1)) << " times\n";
//
//getchar();
//
//
//goldBonacci(BigInt(-2)); // reset counter to BigInt(0)
//
//
//N = BigInt(50);
//
//cout << "\n... calculating goldBonacci(BigInt(50))...\n";
//
//BigIntResult = goldBonacci(N);
//
//cout << "\ngoldBonacci["<<N<<"] = "<<BigIntResult<<endl;
//
//cout << "function was called "<<goldBonacci(BigInt(-1)) << " times\n";
//
//getchar();
//
//
//goldBonacci(BigInt(-2)); // reset counter to BigInt(0)
//
//
//N = BigInt(2000);
//
//cout << "\n... calculating goldBonacci(BigInt(2000))...\n";
//
//BigIntResult = goldBonacci(N);
//
//cout << "\ngoldBonacci["<<N<<"] = "<<BigIntResult<<endl;
//
//cout << "function was called "<<goldBonacci(BigInt(-1)) << " times\n";
//
//getchar();
//

return 0;

}
