#include <iostream>

class MyMatrix 
{
public:

    MyMatrix(int _xSize, int _ySize, std::string _info, std::string _description)
    {
        XSize = new int(_xSize);
        YSize = new int(_ySize);

        matrix = new int[(*XSize) * (*YSize)];

        for (int i = 0; i < (*XSize); i++) {
            for (int j = 0; j < (*YSize); j++) {
                *(matrix + i * (*XSize) + j) = int(rand() * 100);
            }
        }

        Info = new std::string(_info);
        Description = new std::string(_description);

        arrayOfArray = new int* [(*XSize)];
        
        for (int i = 0; i < (*XSize); i++) {
            arrayOfArray[i] = new int[(*YSize)];
        }
    }


    ~MyMatrix()
    {
        delete[] matrix;
        delete Info;
        delete Description;

        for (int i = 0; i < (*XSize); i++) {
            delete[] arrayOfArray[i];
        }
        delete[] arrayOfArray;
        delete XSize;
        delete YSize;
    }

    int operator()(const int i, const int j) {
        return *(matrix + i * (*XSize) + j);
    }

    MyMatrix& operator=(MyMatrix& _myMatrix) {
        XSize =_myMatrix.XSize;
        YSize = _myMatrix.YSize;
        matrix = new int(*(_myMatrix.matrix));
        Info = new std::string(*(_myMatrix.Info));
        Description = new std::string(*(_myMatrix.Description));
    }

private:
    int* XSize;
    int* YSize;
    // Матрица представлена как одномерный массив, где каждая следующая строка является продолжением предыдущей, т.е.
    /*
    Матрица вида:
    123
    321
    111
    Хранится в памяти, как 123321111, а доступ по индексам матрицы осуществляется с помощью вычисления положения ячейки в общей цепочке
    Для наглядности сделал перегрузку оператора () для доступа к элементам массива по индексам
    */
    int* matrix; 

    /*Матрица представленна как "массив масивов"*/
    int** arrayOfArray;


    std::string* Info;
    std::string* Description;
};

int main()
{
    MyMatrix testMatrix = MyMatrix(3, 3, "матрица 3 на 3", "Создана для проверки");
    std::cout << testMatrix(1, 1);
}


