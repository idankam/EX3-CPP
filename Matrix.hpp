#pragma once

#include <string>
#include <map>
#include <iterator>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace zich{

    const int column_length = 100;

    class Matrix{

        private:
            int rows_size;
            int columns_size;
            std::vector<double> mat;
            

        public:

            Matrix(std::vector<double> vec, int rows_size, int columns_size);

            //-----------------------------
            // Arithmetic Operators
            //-----------------------------

            Matrix operator-();
            Matrix operator-(const Matrix &m);
            Matrix operator-=(const Matrix &m);

            Matrix operator+();
            Matrix operator+(const Matrix &m);
            Matrix operator+=(const Matrix &m);


            Matrix operator*(double d) const;
            // Matrix operator*(const Matrix &m) const;

            Matrix operator*=(double num) const;
            Matrix operator*=(const Matrix &m) const;

            //-----------------------------
            // Friend Comparison Operators
            //-----------------------------

            friend bool operator!=(const Matrix &m1, const Matrix &m2);
            friend bool operator==(const Matrix &m1, const Matrix &m2);

            friend bool operator<=(const Matrix &m1, const Matrix &m2);
            friend bool operator>=(const Matrix &m1, const Matrix &m2);

            friend bool operator<(const Matrix &m1, const Matrix &m2);
            friend bool operator>(const Matrix &m1, const Matrix &m2);

            //-----------------------------
            // Increment Decrement Operators
            //-----------------------------

            Matrix operator--();
            Matrix operator--(int num);

            Matrix operator++();
            Matrix operator++(int num);

            //-----------------------------
            // Friend Operators
            //-----------------------------

            friend Matrix operator*(const Matrix &m, double d);
            friend Matrix operator*(double d, const Matrix &m);
            friend Matrix operator*(const Matrix &m1, const Matrix &m2);


            
            //-----------------------------
            // I/O Operators
            //-----------------------------
            friend std::ostream& operator<<(std::ostream& out, const Matrix &m);
            friend std::istream& operator>>(std::istream& in, const Matrix &m);

            //-----------------------------
            // Checks
            //-----------------------------
            void static is_size_equal(const Matrix &m1, const Matrix &m2);

            int getRowsSize() const;
            int getColumnsSize() const;
            double getValueAt(int row, int column) const;
            double sum() const;
    };
}
