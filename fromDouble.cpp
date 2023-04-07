#include <iostream>
#include <cmath>

using namespace std;

unsigned int nod(unsigned int a, unsigned int b){
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


// int toInt()

bool isInt(double x) {
	if (x - int(x) > 0 && x - int(x) < 1) {
		return false;
	}

	return true;
}

int fromDouble(double x) {
	if (x == 0) {
		cout<<x<<" "<<"1"<<endl;
		exit(0);
	}
	x = fabs(x);
	unsigned int counter = 1;
	while (!isInt(x)) {
		x *= 10;
		counter *= 10;
	}
	int divisor = nod(x,counter);
	cout<<x/divisor<<" "<<counter/divisor;
}

int main() {
	//-1.20003E-7
	//5.3E-5
	double x = 120003.2;
	x = -1.20003E-7;
	cout<<isInt(x);
	// fromDouble(-1.20003E-7);
}
