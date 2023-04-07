#include <iostream>
#include <cmath>

using namespace std;

long long int nod(long long int a, long long int b){
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
	x = fabs(x);
	long long int integeri = x;
	x = x - integeri;
	long long int n = 1;

	while (x - int(x) > 0.00000001 && x - int(x) < 0.99999999) {
		x *= 10;
		n *= 10;
	}

	x = x + (n * integeri);
	long long int divisor = nod(x,n);
	long long int a = x/divisor;
	long long int b = n/divisor;
	cout<<a<<"/"<<b<<endl;
}

int main() {
	fromDouble(-512.99);
	fromDouble(5.3E-5);
	fromDouble(-1.20003E-7);
	fromDouble(5.3);
	fromDouble(17.00003);
	fromDouble(3001.0001);
	fromDouble(3002.0009);
	fromDouble(41.5);
	fromDouble(0);
}
