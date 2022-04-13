#include <iostream>
#include <ctype.h>
#include "Matrix.hpp"
const int consta=0;
const int constab=1;
using namespace std;


namespace zich{
     //copy 
    Matrix::Matrix(const Matrix &new_mat){
        if((new_mat.col < 1 || new_mat.col < 1) && (this->row < 1 || this->col < 1)){
             throw runtime_error("size invaled");
        }
        //copy
        if(new_mat.row >= 1 || new_mat.col >= 1){
        this->col = new_mat.col;
        this->row = new_mat.row;
        this->mat = new_mat.mat;
        }
    }
    
        //build
        Matrix::Matrix(vector<double> v, int row, int col){
        this->row=row;
        this->col=col;
        if((row < 1 || row < 1) && (this->row < 1 || this->col < 1)){
            throw runtime_error("size invaled");
        }
        if(row*col != v.size() && !v.empty() ){
            throw runtime_error("size invaled");
        }
        if(row*col== v.size() && !v.empty()){
        unsigned long d=0;
         for(int i=0; i<row; ++i){
            vector <double> a;
            for(int j=0; j<col; ++j){ 
                a.push_back(v[d]);
                d++; 
            }
            this->mat.push_back(a);
        }
        }
        
    }
    //https://www.geeksforgeeks.org/stdto_string-in-cpp/
    
    std::ostream& operator<<(std::ostream& out, const Matrix& new_mat)
    {
        string str;
        if(new_mat.col >= 1 || new_mat.col >= 1){
        for(unsigned int i=0; i < new_mat.row; ++i){
            str+="[";
            for(unsigned int j=0; j < new_mat.col; ++j){
                str+=to_string((int)new_mat.mat[i][j]);
                if(j<new_mat.col- constab){
                    str+=" ";
                }
            }
            str+="]";
            if(i<new_mat.row-constab){
                str+="\n";
            }
        }
        }
        return  out<<str;
    }
    //https://www.geeksforgeeks.org/getline-string-c/ //getline
    std::istream& operator>>(std::istream& in, Matrix& new_mat)
    {

        if(new_mat.col >= 1 || new_mat.col >= 1){
        string str;
        getline(in, str, {});
        int i=0;
        int j=0;
        int col = 0;
        int w = 0;
        double count = 0;
        const int jump = 10;
        
        vector <vector<double>> vec;
         if(new_mat.col < 1 || new_mat.col < 1){
             throw runtime_error("size invaled");
        }
        if(w>=0 && i>=0 && j>=0 && col >=0){
        while(w<str.length()){
            if(str[(unsigned long)w] != '['){
                 throw runtime_error("size error input");
            }
            ++i;
            ++w;
            vector <double> ve;
            while(str[(unsigned long)w]!=']'){
                if(str[(unsigned long)w] == ' '  ){
                    ++w;
                }
                count = 0;
                while(str[(unsigned long)w] != ']' && str[(unsigned long)w] != ' ' ){
                    count = (double)str[(unsigned long)w]+count*jump ;
                    ++w;
                }
                ve.push_back(count);
                ++j;
            }
            
            vec.push_back(ve);
            if(col != j && col != 0 ){
                 throw runtime_error("size error input");
            }
            if(col == 0){
                col = j;
            }
            ++w;
            if(str[(unsigned long)w] == '\n'){
                break;
            }
            ++w;
            if(str[(unsigned long)w] != ' '){
                 throw runtime_error("size error input");
            }
            if(str[(unsigned long)w]=='\n'){

            }
            ++w;
            j=0;
        }
        }
         if(new_mat.col < 1 || new_mat.col < 1){
            throw runtime_error("size invaled");
        }
        if(str.length() <= 0){
             throw runtime_error("size invaled");
        }
        if(new_mat.col >= 1 || new_mat.col >= 1){
        //new columns
        new_mat.col = (int)col;
        //new rows
        new_mat.row = (int)i;
        //new vector
        new_mat.mat = vec;
        }
        }
        return in; 
    }

    
    
    Matrix Matrix::operator+(const Matrix &new_mat) const{
        if(this->row != new_mat.row || this->col != new_mat.col){
             throw runtime_error("size invaled");
        }
        vector <double> v;
        for(unsigned int i=0; i< this->row; i++){
            for(unsigned int j=0; j<this->col; j++){
                v.push_back(this->mat[i][j] + new_mat.mat[i][j]);
            }
        }
        
        return(Matrix{v, this->row , this->col});
    }
    Matrix& Matrix::operator=(const Matrix& new_mat){
        if((new_mat.col < 1 || new_mat.col < 1) && (this->row < 1 || this->col < 1)){
             throw runtime_error("size invaled");
        }
        //copy
        if(new_mat.col >= 1 || new_mat.col >= 1){
        this->col = new_mat.col;
        this->row = new_mat.row;
        this->mat = new_mat.mat;
        }
        return *this;
        }

    
    

    
    Matrix& Matrix::operator+=(const Matrix &new_mat){
       if(this->row != new_mat.row || this->col != new_mat.col){
             throw runtime_error("size invaled");
        }
        if(new_mat.col >= 1 || new_mat.col >= 1){
        for(unsigned int i=0; i<this->row; i++){
            for(unsigned int j=0; j<this->col; j++){
                this->mat[i][j] += new_mat.mat[i][j];
            }
        }
        }
        return (*this);
    }

    Matrix Matrix::operator-(const Matrix &new_mat) const{
        vector <double> v;
        if(this->row != new_mat.row || this->col != new_mat.col){
             throw runtime_error("size invaled");
        }
        if(new_mat.col >= 1 || new_mat.col >= 1){
        for(unsigned int i=0; i<this->row; i++){
            for(unsigned int j=0; j<this->col; j++){
                v.push_back(this->mat[i][j] - new_mat.mat[i][j]);
            }
        }
        }
        return(Matrix{v, row, this->col});
    }

    
    Matrix Matrix::operator+() {
        if((this->row <1 || this->col < 1) && !(this->mat.empty()) ){
             throw runtime_error("size invaled");
        }
        Matrix this_new_mat (*this);
        return(this_new_mat);
    }

    
    Matrix& Matrix::operator-=(const Matrix &new_mat){
        if(this->row != new_mat.row || this->col != new_mat.col){
             throw runtime_error("size invaled");
        }
        if(new_mat.col >= 1 || new_mat.col >= 1){
        for(unsigned int i=0; i< this->row; i++){
            for(unsigned int j=0; j<this->col; j++){
                this->mat[i][j] -= new_mat.mat[i][j];
            }
        }
        }
        return (*this);
    }

   
    Matrix Matrix::operator-(){
        vector <double> v;
        if(this->row <1 || this->col < 1){
             throw runtime_error("size invaled");
        }
        if(this->col >= 1 || this->col >= 1){
        for(unsigned int i=0; i<this->row; i++){
            for(unsigned int j=0; j<this->col; j++){
                v.push_back((this->mat[i][j]) * (-1));
            }
        }
        }
        return (Matrix{v, this->row, this->col});
    }



    

    bool operator!=(const Matrix &mat_a, const Matrix &mat_b){
       if(mat_a.row != mat_b.row || mat_a.col != mat_b.col){
             throw runtime_error("size invaled");
        }
        if(!(mat_a == mat_b)){
         return (true);
         }

     return (false);
    }
    bool operator==(const Matrix &mat_a, const Matrix &mat_b){
        if(mat_a.row != mat_b.row || mat_a.col != mat_b.col){
             throw runtime_error("size invaled");
        }
        for(unsigned int i=0; i<mat_a.row; i++){
            for(unsigned int j=0; j<mat_a.col; j++){
                if(mat_a.mat[i][j] != mat_b.mat[i][j]){
                    return(false);
                }
            }
        }
        return(true);
    }

    

    bool operator>(const Matrix &mat_a, const Matrix &mat_b){
        if(mat_a.row != mat_b.row || mat_a.col != mat_b.col){
             throw runtime_error("size invaled");
        }
        int sum1 = 0;
        int sum2 = 0;
        for(unsigned int i = 0; i < mat_a.row; ++i){
            for(unsigned int j = 0; j < mat_b.col; ++j){
                sum1 += mat_a.mat[i][j];
            }
        }
        for(unsigned int i = 0; i < mat_a.row; ++i){
            for(unsigned int j = 0; j < mat_b.col; ++j){
                sum2 += mat_b.mat[i][j];
            }
        }

        if(sum1 > sum2){
            return (true);
        }
        return (false);
    }
    
    bool operator<(const Matrix &mat_a, const Matrix &mat_b){
       if(mat_a.row != mat_b.row || mat_a.col != mat_b.col){
             throw runtime_error("size invaled");
        }
        int sum1 = 0;
        int sum2 = 0;
        for(unsigned int i = 0; i < mat_a.row; ++i){
            for(unsigned int j = 0; j < mat_b.col; ++j){
                sum1 += mat_a.mat[i][j];
            }
        }
        for(unsigned int i = 0; i < mat_a.row; ++i){
            for(unsigned int j = 0; j < mat_b.col; ++j){
                sum2 += mat_b.mat[i][j];
            }
        }
        if(sum1 < sum2){
            return (true);
        }
        return (false);
    }
    bool operator>=(const Matrix &mat_a, const Matrix &mat_b){
        if(mat_a.row != mat_b.row || mat_a.col != mat_b.col){
             throw runtime_error("size invaled");
        }
        int sum1 = 0;
        int sum2 = 0;
        for(unsigned int i = 0; i < mat_a.row; ++i){
            for(unsigned int j = 0; j < mat_b.col; ++j){
                sum1 += mat_a.mat[i][j];
            }
        }
        for(unsigned int i = 0; i < mat_a.row; ++i){
            for(unsigned int j = 0; j < mat_b.col; ++j){
                sum2 += mat_b.mat[i][j];
            }
        }
        if(sum1 >= sum2){
            return (true);
        }
        return (false);
    }

    bool operator<=(const Matrix &mat_a, const Matrix &mat_b){
        if(mat_a.row != mat_b.row || mat_a.col != mat_b.col){
             throw runtime_error("size invaled");
        }
        int sum1 = 0;
        int sum2 = 0;
        for(unsigned int i = 0; i < mat_a.row; ++i){
            for(unsigned int j = 0; j < mat_b.col; ++j){
                sum1 += mat_a.mat[i][j];
            }
        }
        for(unsigned int i = 0; i < mat_a.row; ++i){
            for(unsigned int j = 0; j < mat_b.col; ++j){
                sum2 += mat_b.mat[i][j];
            }
        }
        if(sum1 <= sum2){
            return (true);
        }
        return (false);
    }

    
    
    Matrix& Matrix::operator--(){
        if(this->row >=1 || this->col >= 1){
        for(unsigned int i=0; i<this->row; ++i){
            for(unsigned int j=0; j < this->col; ++j){
                this->mat[i][j]--;
            }
        }
        }
        
        return (*this);
    }

    Matrix& Matrix::operator++(){
        if(this->row >= 1 || this->col >= 1){
        for(unsigned int i=0; i<this->row; ++i){
            for(unsigned int j=0; j<this->col; ++j){
                this->mat[i][j]++;
            }
        }
        }
        return (*this);
    }



    Matrix Matrix::operator++(const int number){
        Matrix reff(*this);
         if(this->row >= 1 || this->col >= 1){
        for(unsigned int i=0; i< this->row; ++i){
            for(unsigned int j=0; j < this->col; ++j){
                this->mat[i][j]++;
            }
        }
        }
        return reff;
    }


    
    Matrix Matrix::operator*(const Matrix &new_mat) const{
        const int consta=0;
        unsigned int w = 0;
        vector <double> v;
        if(this->col != new_mat.row && !(this->mat.empty())){
             throw runtime_error("size invaled");
        }
         if(this->row >= 1 || this->col >= 1){
        for (unsigned int i = consta; i < this->row; ++i) {
            for(unsigned int j = consta; j < new_mat.col; ++j) {
                v.push_back(consta);
                for (unsigned int k = consta; k < new_mat.row; ++k) {
                    v[w] += ( this->mat[i][k] ) * ( new_mat.mat[k][j] );
                }
                ++w;
            }
        }
        }
        return (Matrix{v, this->row, new_mat.col});
    }

    Matrix Matrix::operator--(const int number){
        Matrix copy(*this);
         if(this->row >= 1 || this->col >= 1){
        if(!(this->mat.empty())){
        for(unsigned int i=0; i<this->row; ++i){
            for(unsigned int j=0; j<this->col; ++j){
                this->mat[i][j]--;
            }
        }
        }
        }
        return copy;
    }
    
    Matrix& Matrix::operator*=(const Matrix &new_mat){
        const int consta=0;
        if(this->col != new_mat.row && !(this->mat.empty())){
             throw runtime_error("size invaled");
        }
        unsigned int w = 0;
        vector <double> vec;

        if(!(this->mat.empty())){
        if(new_mat.row >= 1 || new_mat.col >= 1){
        for (unsigned int i = consta; i < this->row; ++i) {
            for (unsigned int j = consta; j < new_mat.col; ++j) {
                vec.push_back(consta);
                for (unsigned int z = consta; z < new_mat.row; ++z) {
                    vec[w] += this->mat[i][z] * new_mat.mat[z][j];
                }
                ++w;
            }
        }
        }
        w=consta;
        if(!(this->mat.empty())){
        for(unsigned int i=consta; i<this->row; ++i){
            for(unsigned int j=consta; j< this->col ; ++j){
                this->mat[i][j] = vec[w++];
            }
        }
        }
        }
        return(*this);
    }

    
    Matrix& Matrix::operator*=(double x){
        const int consta=0;
         if(this->row >= 1 || this->col >= 1){
        for(unsigned int i=consta; i< this -> row; ++i){
            for(unsigned int j=consta; j< this->col; ++j){
                this->mat[i][j] *= x;
            }
        }
         }
        return(*this);
    }

    
    

    Matrix operator*(double num, Matrix& mat){
        vector <double> vec;
         if(num*mat.row >= 1 || num*mat.col >= 1){
        for(unsigned int i=consta; i<mat.row; ++i){
            for(unsigned int j=consta; j< mat.col; ++j){
                vec.push_back(mat.mat[i][j] * num);
            }
        }
    }
        return(Matrix{vec, mat.row,  mat.col});
    }
    
    Matrix Matrix::operator*(double x){
        const int consta=0;
        vector <double> vec;
         if(this->row*x >= 1 || this->col*x >= 1){
        for(unsigned int i=consta; i<this->row; ++i){
            for(unsigned int j=consta; j<this->col; ++j){
                vec.push_back(this->mat[i][j] * x);
            }
        }
        }
        return(Matrix{vec, this->row, this->col});
    }

    

    
    
}