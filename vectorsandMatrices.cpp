#include <iostream>

using namespace std;

class vector {
    private:
        unsigned int n;
        void setN(unsigned int n) {
            this -> n = n;
        }
        
        double *data;
    public:
     vector(unsigned int n) {
        setN(n);
        data = new double[n];
     }

    void input() {
        for (int i = 0;i < n;i++) {
            cout<<"array["<<i + 1<<"]="; cin>>data[i];
        }
    }

    void changeAt(unsigned int index, double x) {
        if (index >= n) {
            cout<<"array max length is "<<n<<endl;
            exit(1);
        }

        data[index] = x;
    }

    double at(unsigned int index) {
        if (index >= n) {
            cout<<"array max length is "<<n<<endl;
            exit(1);
        }
        return data[index];
    }

    void print() {
        cout<<"[";
        for (int i = 0;i < n - 1;i++) {
            cout<<data[i]<<",";
        }

        cout<<data[n - 1]<<"]"<<endl;
    }
     

};


class matrix {
    private:
        unsigned int row;
        unsigned int col;
        vector **array;
        void setSize(unsigned int row,unsigned int col) {
            this -> row = row;
            this -> col = col;        
        }


    public:
        unsigned int getCol() {
            return col;
        }

        unsigned int getRow() {
            return row;
        }

        matrix(unsigned int row,unsigned int col) {
            setSize(row,col); 
            array = new vector*[row];
            for (int i = 0;i < row;i++) {
                array[i] = new vector(col);
                array[i]->input();
            }
        }


        void add(matrix& arr) {
            if (row != arr.getRow() || col != arr.getCol()) {
                cout<<"Matrices dimensions are not the same"<<endl;
                exit(1);
            }
            vector **ar = arr.get();
            for (int i = 0;i < row;i++) {
                for (int j = 0;j < col;j++) {
                    array[i]->changeAt(j,array[i]->at(j) + ar[i]->at(j));
                }
            }
        }

        void subtract(matrix& arr) {
            if (row != arr.getRow() || col != arr.getCol()) {
                cout<<"Matrices dimensions are not the same"<<endl;
                exit(1);
            }
            vector **ar = arr.get();
            for (int i = 0;i < row;i++) {
                for (int j = 0;j < col;j++) {
                    array[i]->changeAt(j,array[i]->at(j) - ar[i]->at(j));
                }
            }
        }

        void multiply(matrix& arr) {
            if (col != arr.getRow()) {
                cout<<"Matrices dimensions are not correct"<<endl;
                exit(1);
            }
            vector **ar = arr.get();
            vector **multipledArray = new vector*[row];

            for (int i = 0;i < row;i++) {
                multipledArray[i] = new vector(arr.getCol());
                for (int j = 0;j < arr.getCol();j++) {
                    for (int k = 0;k < arr.getRow();k++) {
                        multipledArray[i]->changeAt(j, array[i]->at(k) * ar[k]->at(j) + multipledArray[i]->at(j));
                    }   
                }
            }
    

            for (int i = 0;i < row;i++) {
                delete array[i];
            }

            delete[] array;

            setSize(row,arr.getCol());
            array = multipledArray;

        }


        void transpose() {
            vector **transposedArray = new vector*[col];
            for (int i = 0;i < col;i++) {
                transposedArray[i] = new vector(row);
                for (int j = 0;j < row;j++) {
                    transposedArray[i]->changeAt(j,array[j]->at(i));
                }
            }

            for (int i = 0;i < row;i++) {
                delete array[i];
            }

            delete[] array;


            setSize(col,row);
            array = transposedArray;

        }

        vector** get() {
            return array;
        }

        void print() {
            cout<<"["<<endl;
            for (int i = 0;i < row;i++) {
                array[i]->print();
            }
            cout<<"]"<<endl;
        }

};

int main() {

    matrix mat(3,3);
    mat.transpose();
    mat.print();
}
