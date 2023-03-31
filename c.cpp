#include <iostream>
#include <string>
#include <cmath>


using namespace std;


class complexNumberArray {
	private:
		unsigned int n = 0;
		string *array;
		double Number = 0;
		double complexNumber = 0;
		double GNumber = 1;
		int Gn = 0;
		double GcomplexNumber = 1;
		double stringToNumber(string str) {
			bool dot = false;
			double integerNumber = 0;
			double floatNumber = 0;
			int counter = 0;
			int sign = 1;
			
			for (int i = 0;i < str.length();i++) {
				if (i == 0 && str[i] == '-') {
					sign = -1;
					continue;
				}
				else if (str[i] == '.') {
					dot = true;
					continue;
				}
				else if (!isdigit(str[i]) && str[i] != 'i'){
					cout<<"it is illegal to use "<<str[i]<<endl;
					
				}
				else if (!isdigit(str[i])){
					break;
				}
			
			
				if (!dot) {
					integerNumber *= 10;
					integerNumber += str[i] - '0';
				} 
				else {
					floatNumber *= 10;
					floatNumber += str[i] - '0';
					counter++;
				}
			}
			
			floatNumber /= pow(10,counter);
			
			if (integerNumber == 0 && floatNumber == 0) {
				integerNumber++;
			}
			
			return (integerNumber + floatNumber) * sign;
		}
		
		bool isComplex(string str) {
			if (str[str.length() - 1] == 'i') {
				return true;
			}
			
			return false;
		}
		
	bool isLegal(string str) {
		    if (str.length() == 1 && str[0] == 'i') {
		        return true;
		    }
		    
		    for (int i = 0;i < str.length();i++) {
		        if (str[i] == '.' && i < 1) {
		            return false;
		        }

                if (str[i] == '.' && i > str.length() - 2) {
		            return false;
		        }
		        
		        if (str[i] == '-' && i != 0) {
		            return false;
		        }
		        
		        if (isalpha(str[i]) && str[i] != 'i') {
		            return false;
		        }
		        
		        if (str[i] == 'i' && i != str.length() - 1) {		
		            return false;
		        }
		    }
		    
		    return true;
		}
		
		
	public:
		void add(string data) {
		    if (!isLegal(data)) {
		        cout<<"It is illegal to use the number "<<data<<endl;
		        exit(1);
		    }
			double number = stod(data);
			string *_array = new string[n + 1];
			for (int i = 0;i < n;i++) {
				_array[i] = array[i];
			}
			
			_array[n] = data;
			
			array = _array;
			n++;
		
			if (isComplex(data)) {
				if (data.length() == 1) {
					complexNumber++;
				}
				else {
					complexNumber += number;
					GcomplexNumber *= number;
				}
				
				Gn++;
			}
			else {
				Number += number;
				GNumber *= number;
			}
		}
		
		void getArray() {
			cout<<complexNumber<<endl;
			for (int i = 0;i < n;i++) {
				cout<<i+1<<" "<<array[i]<<endl;
			}
		}
			
			
		void arith() {
// 		    string a = to_string(complexNumber / n);
// 			string b = to_string(Number / n);
// 			if (complexNumber != 0) {
			    cout<<complexNumber/n<<"i + "<<Number/n<<endl;
				// return  a + "i" + " + " + b;
			//}
// 			else {
			      
			      cout<<Number/n<<endl;
			 //   return y;
// 			}
		}
		
		
		void geom() {
// 		    string a = to_string(GcomplexNumber);
// 			string b = to_string(GNumber);
			cout<<"(("<<GcomplexNumber<<"i ** "<<Gn<<")"<<" * "<<GNumber<<") ** (1/"<<n<<")"<<endl;
// 			return "((" + a + "i ** " + to_string(Gn) +")" + " * " + b + ") ** (1/" + to_string(n) + ")";	
			
		}
};
int main(...) {
	complexNumberArray obj;
	for (int i = 0;i < 5;i++) {
		string number;cin>>number;
		obj.add(number);
	}
	obj.arith();
	obj.geom();

	return 0;
}
