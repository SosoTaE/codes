#include <iostream>
#include <cmath>

using namespace std;

unsigned long long int nod(unsigned long long int a, unsigned long long int b){
	while(a!=0 && b!=0){
		if(a>b){
			a=a%b;
		}
		else{
			b=b%a;
		}
	}
	return a+b;

}


void fromDouble(double x) {
	if (x == 0) {
		cout<<x<<" "<<"1"<<endl;
		exit(0);
	}
	long long int n = 10000000000000;
	x = fabs(x) * n;
	unsigned long long int divisor = nod(x ,n);
	cout<<divisor<<endl;	
	cout<<x/divisor<<" "<<n/divisor<<endl;
	cout<<(x/divisor)/(n/divisor)<<endl;
}

int main() {
	fromDouble(-512.99);
}
