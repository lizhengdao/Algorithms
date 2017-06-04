#include <bits/stdc++.h>
using namespace std;
class WrongDimensionsException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nWrong matrix dimensions\n";
    }
};
class IncompatibleMatricesException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nThe matrices are not compatible with each other\n";
    }
};
template <class T>
class Matrix
{
  private:
    T **mat;
  public:
    unsigned int rows, cols;
    Matrix(unsigned int m, unsigned int n)
    {   rows = m;
        cols = n;
        mat = new T*[rows];
        while(m--)
        {   mat[m]=new T[cols];
        }
    }
    Matrix<T> operator+(Matrix<T> m)
    {
        if(rows==m.rows && cols==m.cols)
        {
            Matrix<T> res(rows,cols);
            int i,j;
            for(i=0;i<rows;i++)
            {
                for(j=0;j<cols;j++)
                {
                    res.set(i,j,mat[i][j]+m.get(i,j));
                }
            }
            return res;
        }
        else
        {
            IncompatibleMatricesException e;
            throw e;
        }
    }
    Matrix<T> operator-(Matrix<T> m)
    {
        if(rows != m.rows || cols!=m.cols)
        {
            IncompatibleMatricesException e;
            throw e;
        }
        else
        {
            Matrix<T> res(rows,cols);
            int i,j;
            for(i=0;i<rows;i++)
            {
                for(j=0;j<cols;j++)
                {
                    res.set(i,j,mat[i][j]-m.get(i,j));
                }
            }
            return res;
        }
    }
    void set(unsigned int i, unsigned int j, T value)
    {
        if(i>=rows || j>=cols)
        {
            WrongDimensionsException e;
            throw e;
        }
        mat[i][j]=value;
    }
    T get(unsigned int i, unsigned int j)
    {
        if(i>=rows || j>=cols)
        {
            WrongDimensionsException e;
            throw e;
        }
        return mat[i][j];
    }
    bool operator==(Matrix m)
    {
        if(rows != m.rows || cols!=m.cols)
        {
            return false;
        }
        else
        {
            int i,j;
            for(i=0;i<rows;i++)
            {
                for(j=0;j<cols;j++)
                {
                    if(mat[i][j]!=m.get(i,j))
                        return false;
                }
            }
        }
        return true;
    }
    friend ostream &operator<<(ostream &output, Matrix<T> m)
    {   
        output << m.toString();
        return output;
    }
    //utility functions
    string toString()
    {   unsigned int i,j;
        stringstream ss;
        for(i=0;i<rows;i++)
        {   for(j=0;j<cols;j++)
                ss<<mat[i][j]<<" ";
            ss<<"\n";
        }
        return ss.str();
    }
};
int main()
{
    Matrix<int> mat1(4, 3), mat2(4,3);
    cout<<"\nMatrix 1\n"<<mat1;
    cout<<"\nMatrix 2\n"<<mat2;
    cout<<"\nMatrix 1 is "<<(mat1==mat2?"":"not ")<<"equal to Matrix 2";
    int i,j;
    for(i=0;i<4;i++)
    {   for(j=0;j<3;j++)
        {
            mat1.set(i,j,rand()%10);
            mat2.set(i,j,rand()%10);
        }
    }
    cout<<"\nMatrix 1\n"<<mat1;
    cout<<"\nMatrix 2\n"<<mat2;
    cout<<"\nMatrix 1 is "<<(mat1==mat2?"":"not ")<<"equal to Matrix 2";
    cout<<"\nMatrix 1 + Matrix 2\n"<<(mat1+mat2);
    cout<<"\nMatrix 1 - Matrix 2\n"<<(mat1-mat2);
    return 0;
}