#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;

class datatype {
    public:
        string key;
        string type;
        string stringValue;
        int integerValue;
};

class object {
    private:
        unsigned int length = 0;
        datatype* array;
        bool isNumber(string number) {
                bool dot = false;
                for (int i = 0;i < number.length();i++) {
                    if (!isdigit(number[i])) {
                        if (dot) {
                            return false;
                        }
                        
                        if (number[i] == '.' && i != number.length() - 1) {
                            dot = true;
                        }
                        else {
                            return false;
                        }

                    }
                }

                return true;
            }
    public:

        void add(string key, string each) {
            datatype properties;
            properties.key = key;
            if (isNumber(each)) {
                properties.type = "number";
                properties.integerValue = atoi(each.c_str());
            }
            else {
                properties.type = "string";
            }
            properties.stringValue = each;
            length++;
            datatype* new_array = new datatype[length];
            for (int i = 0;i < length - 1;i++) {
                new_array[i] = array[i];
            }

            new_array[length - 1] = properties;

            array = new_array;
        }

        string get(string key) {
            for (int i = 0;i < length;i++) {
                if (array[i].key == key) {
                   return array[i].stringValue;
                }
            }

            exit(1);
        }

        //  auto get(string key) {
        //     for (int i = 0;i < length;i++) {
        //         if (array[i].key == key) {
        //             if (array[i].type == "string") {
        //                 return array[i].stringValue;
        //             }
        //         }
        //     }

        //     exit(1);
        // }

        void remove(string key) {
            datatype* new_array = new datatype[length - 1];
            bool founded = false;
            for (int i = 0,j = 0;i < length;i++) {
                if (array->key == key) {
                    founded = true;
                    continue;
                }
                new_array[j] = array[i];
                j++;
            }

            if (!founded) {
                return;
            }

            array = new_array;
            length--;
        }

        void print() {
            cout<<"{"<<endl;
            for (int i = 0;i < length;i++) {
                cout<<"\t"<<array[i].key<<":"<<array[i].stringValue<<endl;
            }
            cout<<"}"<<endl;
        }
         
};

class persons { 
    private:
        unsigned int length = 0;
        object* array;
    public:
        void add(object one) {
            length++;
            object* new_array = new object[length];
            for (int i = 0;i < length - 1;i++) {
                new_array[i] = array[i];
            }

            new_array[length - 1] = one;

            array = new_array;
        }

        template <class type>
        void remove(string key,type value) {
            object* new_array = new object[length - 1];
            bool founded = false;
            for (int i = 0,j = 0;i < length;i++) {
                string one = array[i].get(key);
                if (one == value) {
                    founded = true;
                    continue;
                }
                new_array[j] = array[i];
                j++;
            }

            if (!founded) {
                return;
            }

            array = new_array;
            length--;
        }

        // void remove(string key,int value) {
        //     object* new_array = new object[length - 1];
        //     bool founded = false;
        //     for (int i = 0,j = 0;i < length;i++) {
        //         datatype one = array[i].get(key);
        //         cout<<one.type<<endl;
        //         if (one.type == "number") {
        //             if (one.integerValue == value) {
        //                 founded = true;
        //                 continue;
        //             }
                   
        //         }
        //         new_array[j] = array[i];
        //         j++;
        //     }

        //     if (!founded) {
        //         return;
        //     }

        //     array = new_array;
        //     length--;
        // }
        
        void print() {
            cout<<"["<<endl;
            for (int i = 0;i < length;i++) {
                array[i].print();
            }
            cout<<"]"<<endl;
        }
};


class tools: public persons {
    public:
        void readFile(string url, unsigned int n) {
            ifstream fin(url);
            string each;
            string* keys = new string[n + 1];

            for (int i = 0;i < n + 1;i++) {
                fin>>keys[i];
            }

            object someone;
            int index = 0;
            while (fin>>each)
            {
                someone.add(keys[index],each);
                index++;
                if (index == n + 1) {
                    index = 0;
                    add(someone);
                    object new_someone;
                    someone = new_someone;
                }
            }

        }
};

int main() {
    tools tl;
    tl.readFile("./users.txt",6);
    tl.print();
    tl.remove("id","1");
    cout<<"#########################################################"<<endl;
    tl.print();
    object someone;
    someone.add("id","5");
    someone.add("name", "saba");
    someone.add("surname", "ninidze");
    someone.add("years", "2004");
    someone.add("gender", "0");
    someone.add("position", "student");
    someone.add("salary","40");
    tl.add(someone);
    tl.print();
    tl.remove("id", "5");
    tl.print();
    tl.remove("id","2");
    tl.remove("id","3");
    tl.remove("id","4");
    tl.print();
    tl.add(someone);
    tl.print();

    return 0;
}
