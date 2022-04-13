#include <iostream>
#include <vector>

using namespace std;

namespace zich{
    class Matrix{
        public:
        vector<vector<double>> mat;
        int row,col;
        Matrix();
        //destractor
        ~Matrix(){};
        Matrix(vector<double> v, int row, int col);
        Matrix(const Matrix &new_mat);
        //i++
        Matrix& operator++();
        //i--
        Matrix& operator--();
        //++i
        Matrix operator++(int);
        //--i
        Matrix operator--(int); 
        //equal to be
        Matrix& operator=(const Matrix &mat);
        //x = y+z 
        Matrix operator+(const Matrix &new_mat) const;
        //x = y-z 
        Matrix operator-(const Matrix &new_mat) const;
        //x+=y
        Matrix& operator+=(const Matrix &new_mat);
        //x-=y
        Matrix& operator-=(const Matrix &new_mat);
        //x = +y (x=y)
        Matrix operator+() ;
        //onary
        Matrix operator-() ;
        //x = y*z
        Matrix operator*(double x);
        //x *= y
        Matrix& operator*=(double x);
        //mult and to be const function
        Matrix operator*(const Matrix &new_mat) const;
        //mul equal to be const function //x *= num
        Matrix& operator*=(const Matrix &new_mat);
        //bool operator
        friend bool operator>=(const Matrix &mat_a, const Matrix &mat_b);
        friend bool operator>(const Matrix &mat_a, const Matrix &mat_b);
        friend bool operator==(const Matrix &mat_a, const Matrix &mat_b);
        friend bool operator!=(const Matrix &mat_a, const Matrix &mat_b);
        friend bool operator<(const Matrix &mat_a, const Matrix &mat_b);
        friend bool operator<=(const Matrix &mat_a, const Matrix &mat_b);
        //frind operators to input and output and to mult const number //x = y * num
        friend Matrix operator*(const double num, Matrix& mat);
        friend std::ostream& operator<<(std::ostream& output, const Matrix& new_mat);
        friend std::istream& operator>>(std::istream& in, Matrix& new_mat);
    };
};