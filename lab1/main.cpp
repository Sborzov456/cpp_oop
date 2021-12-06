#include "functions.h"
int main()
{
    line* matrix;
    line* res_matrix;
    std:: cout << "Enter number of lines in matrix: ";
    int m;
    get_num(m);
    matrix = create_matrix(m);
    input_matrix(matrix, m);
    std:: cout << "MATRIX:"<<endl;
    output_matrix(matrix, m);
    res_matrix = solution(res_matrix, m, matrix);
    if (res_matrix == nullptr)
    {
        std:: cout << "Error: NO RES" << endl;
        return 0;
    }
    std:: cout << "RES MATRIX: "<<endl;
    output_matrix(res_matrix, m);
    erase(matrix, m);
    std:: cout <<"Bye, bye ^_^";
    return 0;
}





