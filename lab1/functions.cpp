#include "functions.h"
line* create_matrix(int m)
{
    line* tmp_matrix = new line[m];
    return tmp_matrix;
}
void input_matrix(line* matrix, int m)
{
    float* buf = new float[n];
    for(int i = 0; i < m; i++)
    {
        std:: cout << "Enter number of items in line #" << i + 1 << ": ";
        int n;
        get_num(n);
        for (int i = 0; i < n; i++)
        {
            buf[i] = 0.;
        }
        std:: cout << "Enter " << i+1 << " line" << endl;
        matrix[i].n = 0;
        int index = 0;
        while (index != -1)
        {
            std:: cout << "Enter index: ";
            get_num(index);
            std:: cout << "Enter value: ";
            float num;
            get_num(num);
            std:: cout << endl;
            buf[index] = num;
            matrix[i].n++;
        }
        matrix[i].a = new item[matrix[i].n];
        int full = 0;
        for (int k = 0; k < n; k++)
        {
            if (buf != 0)
            {
                matrix[i].a[full].data = buf[k];
                matrix[i].a[full].index = k;
                full++;
            }
        }
    }
    delete[] buf;
}
void output_matrix(line* matrix, int m)
{
    for(int i = 0; i < m; i++)
    {
        std:: cout << "Line #" << i + 1 << ": ";
        for (int j = 0; j < matrix[i].n; j++) std:: cout << matrix[i].a[j].data << " ";
        std:: cout << std:: endl;
    }
}
int count_positive_numbers(line l)
{
    int counter = 0;
    for (int i = 0; i < l.n; i++)
    {
        if (l.a[i].data > 0) counter++;
    }
    return counter;
}
int find_positive_line(line* matrix, int m)
{
    int max_counter = -1;
    int index = -1;
    for(int i = 0; i < m; i++)
    {
        if (max_counter < count_positive_numbers(matrix[i]))
        {
            max_counter = count_positive_numbers(matrix[i]);
            index = i;
        }
    }
    if (max_counter == -1) return -1;
    return index;
}
int count_negative_numbers(line l)
{
    int counter = 0;
    for (int i = 0; i < l.n; i++)
    {
        if (l.a[i] < 0) counter++;
    }
    return counter;
}
int find_negative_line(line* matrix, int m)
{
    int max_counter = -1;
    int index;
    for(int i = 0; i < m; i++)
    {
        if (max_counter < count_negative_numbers(matrix[i]))
        {
            max_counter = count_negative_numbers(matrix[i]);
            index = i;
        }
    }
    if (max_counter == 0) return -1;
    return index;
}
line* solution(line* res, int m, line* matrix)
{
    res = create_matrix(m);
    int index_n = find_negative_line(matrix, m);
    int index_p = find_positive_line(matrix, m);
    if ((index_n == -1) || (index_p == -1)) return nullptr;
    res[m-1] = matrix[index_n];
    res[index_n] = matrix[m-1];
    res[0] = matrix[index_p];
    res[index_p] = matrix[0];
    for(int i = 1; i < m - 1; i++)
    {
        if ((i != index_n) && (i != index_p))
        {
            res[i] = matrix[i];
        }
    }
    return res;
}
line *erase(line *&matrix, int m)
{
    int i;
    for (i = 0; i < m; i++) delete[] matrix[i].a;
    delete[] matrix;
    return nullptr;
}
