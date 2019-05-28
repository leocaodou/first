#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <assert.h>
using namespace std;
template<typename T>
class Matrix2D {
private:
    T* _data;
    int _row;
    int _col;
public:
    Matrix2D ( int r, int c) : _data(NULL), _row(r), _col(c) {
        if( r <= 0 || c <= 0)
           	return;
        _data = new T [r * c];
        memset( _data,0, r * c * sizeof(T));
    }
    Matrix2D() : _data(NULL), _row(0), _col(0) {
    }
    Matrix2D (T* data, int r, int c) : _data(NULL), _row(r), _col(c){

    	_data = new T [r * c];
    	for(int i = 1;i <= r*c; i++)
    	{
    		_data[i] = data[i];
    	}
    }
    template<typename F>
    Matrix2D(const Matrix2D<F>& a) : _row(a._row), _col(a._col)
    {
    	_data = new T [_row*_row];
    	for(int i = 0;i < _row*_row;i++)
    		_data[i] = a._data[i];
    }
    ~Matrix2D()
    {
    	if(_data)
    		delete [] _data;
    }
    static Matrix2D<T> diag(int n)
    {
    	Matrix2D<T> a;
    	a._row = n;
    	a._col = n;
    	a._data = new T [n*n];
    	for(int i = 1;i <= n*n; i++)
    	{
    		a._data[i] = 1;
    	}
    	return a;
    }
    void printMatrix() const {
        for(int i = 0; i < _row; ++i) {
           	int rowBase = i * _col;
           	for(int j = 0; j < _col; ++j) {
           	    	cout << * (_data + rowBase + j) <<" ";
           	}
           	cout << "\n";
       	}

    }
    T* getDataPtr() {
        return _data;
    }
    template<typename A>
    const A& at (int a,int b)
    {
    	return (A)_data[(a - 1)*_row + b - 1];
    }
    Matrix2D<T>& operator*= (const Matrix2D<T>& a)
    {
    	Matrix2D c(_row,_row);
    	assert(_row == _col && a._row == a._col && _col == a._col);
		for(int i = 1;i <= a._row;i++)
		{
			for(int j = 1; j <= a._row;j++)
			{
				int b = 0;
				for(int k = 1; k <= a._row;k++)
				{
					b = b + this->at<T>(i,k) * a.at<T>(k,j);
				}
				c.at<T>(i,j) = b;
			}
		}
    	delete [] _data;
    	_data = new T [_row*_row];
    	for(int i = 0;i < _row*_row;i++)
    		_data[i] = c._data[i];
    	return *this;
    } 
};
int main() {

    float data [] = {1.3f, 1, 1, 1, 2.3f, 1, 1, 1, 3.3f};

    Matrix2D<float> A(data, 3, 3);

    A.printMatrix();

    cout << "\n";

    A *= Matrix2D<float>::diag(3);

    A.printMatrix();

    cout << "\n";

    A.at<float> (0, 2) = 5.f;

    Matrix2D<int>(A).printMatrix();

    cout << "\n";

    

    float data1[] = {2.f,3.1f,4.98f};

    Matrix2D<float> B(data1, 3, 1);

    B.printMatrix();

    cout << "\n";

    A *= Matrix2D<float>(4,2);

    A *= B;

    A.printMatrix();

    

    return 1;

}
