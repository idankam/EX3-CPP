#include "Matrix.hpp"

using namespace std;
using namespace zich;


void Matrix::is_size_equal(const Matrix &m1, const Matrix &m2){
    if (m1.rows_size != m2.rows_size || m1.columns_size != m2.columns_size){
        throw invalid_argument("the matrixes are not the same size!");
    }   
}

int Matrix::getColumnsSize() const{
    return this->columns_size;
}

int Matrix::getRowsSize() const{
    return this->rows_size;
}

double Matrix::sum() const{
    double sum_of_elems = 0;
    for(int i = 0; i< this->columns_size * this->rows_size; i++){
        sum_of_elems += this->mat[static_cast<std::vector<int>::size_type>(i)];
    }
    return sum_of_elems;
}

double Matrix::getValueAt(int row, int column) const{
    return this->mat[static_cast<std::vector<int>::size_type>(row*int(this->getColumnsSize()) + column)];
}

Matrix::Matrix(std::vector<double> vec, int rows_size, int columns_size){

    if (vec.size() != rows_size*columns_size){
        throw invalid_argument("vector size doesn't match to rows*columns");
    }

    if (vec.empty()){
        throw invalid_argument("vector size is 0");
    }

    if (rows_size <= 0 || columns_size <= 0){
        throw invalid_argument("size is 0");
    }


    this->mat = vec;
    this->rows_size = rows_size;
    this->columns_size = columns_size;
}

//-----------------------------
// Arithmetic Operators
//-----------------------------


Matrix Matrix::operator-(){
    return *this;
}

Matrix Matrix::operator-(const Matrix &m){
    is_size_equal(*this, m);
    return *this;
}

Matrix Matrix::operator-=(const Matrix &m){
    is_size_equal(*this, m);
    return *this;
}

Matrix Matrix::operator+(){
    return *this;
}
Matrix Matrix::operator+(const Matrix &m){
    is_size_equal(*this, m);
    return *this;
}
Matrix Matrix::operator+=(const Matrix &m){
    is_size_equal(*this, m);
    return *this;
}

Matrix Matrix::operator*=(double num) const{
    return *this;
}
Matrix Matrix::operator*=(const Matrix &m) const{
    if (this->getColumnsSize() != m.getRowsSize()){
        throw invalid_argument("sizes not fit for matrix multiply");
    }
    return *this;
}

Matrix Matrix::operator*(double d) const{
    return *this;
}


//-----------------------------
// Friend Comparison Operators
//-----------------------------

bool zich::operator!=(const Matrix &m1, const Matrix &m2){
    Matrix::is_size_equal(m1, m2);
    return m1.sum() != m2.sum();
}
bool zich::operator==(const Matrix &m1, const Matrix &m2){
    Matrix::is_size_equal(m1, m2);
    return m1.sum() == m2.sum();
}
bool zich::operator<=(const Matrix &m1, const Matrix &m2){
    Matrix::is_size_equal(m1, m2);
    return m1.sum() <= m2.sum();
}
bool zich::operator>=(const Matrix &m1, const Matrix &m2){
    Matrix::is_size_equal(m1, m2);
    return m1.sum() >= m2.sum();
}

bool zich::operator<(const Matrix &m1, const Matrix &m2){
    Matrix::is_size_equal(m1, m2);
    return m1.sum() < m2.sum();
}
bool zich::operator>(const Matrix &m1, const Matrix &m2){
    Matrix::is_size_equal(m1, m2);
    return m1.sum() > m2.sum();
}

//-----------------------------
// Increment Decrement Operators
//-----------------------------

Matrix Matrix::operator--(){
    return *this;
}
Matrix Matrix::operator--(int num){
    return *this;
}

Matrix Matrix::operator++(){
    return *this;
}
Matrix Matrix::operator++(int num){
    return *this;
}

//-----------------------------
// Friend Operators
//-----------------------------

Matrix zich::operator*(double d, const Matrix &m){
    return m;
}

Matrix zich::operator*(const Matrix &m1, const Matrix &m2){
    if (m1.getColumnsSize() != m2.getRowsSize()){
        throw invalid_argument("sizes not fit for matrix multiply");
    }
    return m1;
}

    //-----------------------------
    // friend I/O Operators
    //-----------------------------
std::ostream& zich::operator<<(std::ostream& out, const Matrix &m){
    std::string result;
    for (int row = 0; row < m.getRowsSize(); row++)
    {
        result += "[";
        for (int col = 0; col < m.getColumnsSize(); col++)
        {
            result += to_string(int(m.getValueAt(row,col)));
            if (col < m.getColumnsSize()-1){
                result += " ";
            }
        }
        result += "]";
        if (row < m.getRowsSize()-1){
                result += "\n";
        }
    }
    out << result;
    return out;
}
std::istream& zich::operator>>(std::istream& in, const Matrix &m){
    
    

    return in;
}
