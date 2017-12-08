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

        friend matrix operator + (matrix m1, matrix m2){
            if((m1.cols != m2.cols)||(m1.rows != m2.rows)) throw -1;
            else{
                matrix result(m1.rows, m1.cols);
                for(int i = 0; i < result.rows; i++)
                    for(int j = 0; j < result.cols; j++)
                        result.table[i][j] = m1.table[i][j] + m2.table[i][j];
                return result;
            }
        }

        friend matrix operator * (matrix m1, matrix m2){
            if(m1.cols != m2.rows) throw -1;
            else{
                matrix result(m1.rows, m2.cols);
                result.fill(0, 1);
                for(int i = 0; i < result.rows; i++)
                    for(int j = 0; j < result.cols; j++)
                        for(int k = 0; k < m1.cols; k++)
                            result.table[i][j] += m1.table[i][k] + m2.table[k][j];
                return result;
            }
        }

        /*
        matrix inv(matrix m);
        matrix trn();
        int det;
        void fill();
        void print();*/
};


int main(){
    try{
        matrix A(2, 3);
        matrix B(3, 4);
        A.fill(0, 90);
        B.fill(0, 90);
        A.print();
        B.print();
        (A * B).print();
    }
    catch(...){
        printf("Illegal matrix size for these operations!");
    }
    return 0;
}
