#include <iostream>
using namespace std;
typedef struct item
{
    float data;
    int index;
}item;
typedef struct line
{
    int n;//number of items
    item* a;//items of line
}line;
template <typename T>
int get_num(T& n)
{
    std:: cin >> n;
    if (!std:: cin.good()) return -1;
    return 1;
}
line* create_matrix(int m);
line get_line(line l, float* buf, int n);
void input_matrix(line* matrix, int m);
void output_matrix(line* matrix, int m);
int find_positive_line(line* matrix, int m);
int count_negative_numbers(line l);
int find_negative_line(line* matrix, int m);
line* solution(line* res, int m, line* matrix);
line *erase(line* &matrix, int m);
