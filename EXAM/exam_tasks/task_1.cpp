/*НАЧАЛЬНЫЙ КОД*/
#include <iostream>

struct BigMatrix {
       double ** data;
       size_t * columns;
       size_t rows;
       BigMatrix() // создание пустой матрицы
       {
             rows = 0;
       };

       BigMatrix (size_t rows_count, size_t * columns_count) // создание матрицы с заданной конфигурацией

       {
             rows = rows_count;
             columns = columns_count;
             data = new double *[rows];
             for (int x = 0; x < rows_count; ++x)
                    data[x] = new double[columns_count[x]];
       }

       ~BigMatrix() // деструктор для матрицы

       {
             delete[] columns;
             delete[] data;
       }

       void setElement(size_t row, size_t column, double x)

       {
             data[row][column] = x;
       };

       double getElement(size_t row, size_t column)

       {
             return data[row][column];
       }

/*
A)Ошибки, допущенные программистом 
1)Так как это структура, по умолчанию все ее переменные-члены и методы являются public, лучше сделать переменные-члены private
2)В пустом конструкторе нет зануления значений указателей на матрицу и на столбцы
3)В методе setElement отуствуют проверки на выход за пределы границы массива
4)Метод getElement является селектором, отсутвует модификатор const
5)В прицнипе полезно добавить поле кол-ва столбцов
7)Нет функции расширения матрицы
8)Корректный прототип:
*/
class BigMatrix
{
private:
    double ** data;
    size_t * columns;
    size_t rows;
    unsigned size;
public:
      BigMatrix();
      BigMatrix (const size_t& rows_count, const size_t* columns_count);
      ~BigMatrix();
      void setElement(const size_t& row, const size_t& column, const double& x);
      double getElement(const size_t& row, const size_t& column) const;
      //передача всяких чисельных типов не по константной ссылке не является ошибкой


      //ДЛЯ ПУНКТА B
      bool operator && (const BigMatrix& m1, const BigMatrix& m2);
      BigMatrix& operator += (const double& x);
      BigMatrix& operator + (const BigMatrix& m1, const BigMatrix& m2);
      BigMatrix& operator = (const BigMatrix& m2);
}
/*
Б)Реализация методов из прототипа выше:
*/
BigMatrix::BigMatrix() : data(nullptr), columns(nullptr), rows(0), size(0) {}
BigMatrix::BigMatrix (const size_t& rows_count, const size_t* columns_count) : rows(rows_count), columns(columns_count), size(0)
{
      data = new double *[rows];
      for (int x = 0; x < rows_count; ++x)
             data[x] = new double[columns_count[x]];
 }
BigMatrix::~BigMatrix() 
{
      delete[] columns;
      delete[] data;
}
void BigMatrix::setElement(const size_t& row, const size_t& column, const double& x)
{
     if(row < 0 || column < 0 || row > rows || row > columns[column]) //если введен отрицательный индекс строки, если индекс строки больше, чем вообще строк существует, если индекс строки больше, чем кол-во элементов в столбце
          throw std::exception("Out of range!\n");
     data[row][column] = x;
     ++size;
}

double BigMatrix::getElement(const size_t& row, const size_t& column) const
{
      if(row < 0 || row > rows || row > columns[column]) //аналогично
          throw std::exception("Out of range!\n");
      return data[row][column];
}
/*В)Доработка класса: внизу будут написаны только реализации добавленных методов, их прототипы уже есть сверху*/
bool BigMatrix::operator && (const BigMatrix& m1, const BigMatrix& m2) //1 - если обе матрицы не пусты, 0 иначе
{
      if(m1.size && m2.size) return true;
      else return false;
}
BigMatrix& BigMatrix::operator += (const double& x) //увеличивает каждое значение матрицы на x
{
      for(int i = 0; i < rows; i++)
            for(int j = 0; j < columns[i]; ++j) //находимся на i-ой строке, columns[i] - кол-во элементов на i-ой строке, обходим ее
                  data[i][j] += x; 
}
BigMatrix& BigMatrix::operator + (const BigMatrix& m1, const BigMatrix& m2)
{
      /*Создать результирующую матрицу, с минимальным из m1 и m2 кол-вом строк и минимальной длинной каждого соотвествующего столбца*/
      /*В каждый элемент результирующей матрицы записать сумму соотвествующих элементов m1 и m2*/
      //Не успеваю дописать
}
BigMatrix& operator = (const BigMatrix& m2)
{
      /*Изменить размер исходной матрицы на размер m2, поочередно записать туда элементы - это будет копирование
      Просто переставить указатели, что будет более эффективно - перемещение*/
      //Не успеваю дописать 
}