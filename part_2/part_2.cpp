#include <iostream>

class MyMatrix 
{
public:

    MyMatrix(int _xSize, int _ySize, std::string *_info, std::string *_description)
    {
        int XSize = _xSize;
        int YSize = _ySize;
        int* matrix = new int(XSize * YSize);

        for (int i = 0; i < XSize; i++) {
            for (int j = 0; j < YSize; j++) {
                *(matrix + i * XSize + j) = int(rand() * 100);
            }
        }

        std::string* Info = _info;
        std::string* Description = _description;       
    }


    ~MyMatrix()
    {
        delete this->matrix;
        delete Info;
        delete Description;

    }

    MyMatrix& operator=(MyMatrix& _myMatrix) {
        XSize =_myMatrix.XSize;
        YSize = _myMatrix.YSize;
        matrix = new int(*(_myMatrix.matrix));
        Info = new std::string(*(_myMatrix.Info));
        Description = new std::string(*(_myMatrix.Description));
    }

private:
    int XSize;
    int YSize;
    int* matrix;
    std::string* Info;
    std::string* Description;
};

int main()
{
    
}


