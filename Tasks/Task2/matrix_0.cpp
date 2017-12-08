#include <stdio.h>
#include <iostream>
#include <ctime>

class matrix{
    private:
        int rows, cols;
        int** table;
    public:
        matrix(int n, int m){
            rows = n; cols = m;
            table = new int*[rows];
            for (int i = 0; i < rows; i++)
                table[i] = new int[cols];
        }

        void fill(int a, int b){
            srand(time(NULL));
            for(int i = 0; i < this->rows; i++)
                for(int j = 0; j < this->cols; j++)
                    this->table[i][j] = a + rand()%b;
        }

        void print(){
            for(int i = 0; i < this->rows; i++){
                for(int j = 0; j < this->cols; j++)
                    printf("%d\t", this->table[i][j]);
                printf("\n");
            }
            printf("\n");
        }
        /*matrix add(matrix m);
        matrix mul(matrix m);
        matrix inv(matrix m);
        matrix trn();
        int det;
        void fill();
        void print();*/
};


int main(){
    matrix A(4, 5);
    matrix B(4, 5);
    A.fill(0, 90);
    B.fill(0, 90);
    A.print();
    B.print();

    return 0;
}
