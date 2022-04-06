#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "doctest.h"
#include "Matrix.hpp"


using namespace std;
using namespace zich;



TEST_CASE("checking matrix size fits to array size"){

    std:: vector<double> arr1 = {2,5,8,4,3,7,85,3}; //size = 8

    //dont fit
    CHECK_THROWS(Matrix(arr1,3,5));
    CHECK_THROWS(Matrix(arr1,5,3));
    //negative
    CHECK_THROWS(Matrix(arr1,-1,3));
    CHECK_THROWS(Matrix(arr1,3,-1));
    CHECK_THROWS(Matrix(arr1,-3,-1));
    CHECK_THROWS(Matrix(arr1,-2,-4));
    //zero
    CHECK_THROWS(Matrix(arr1,0,-4));
    CHECK_THROWS(Matrix(arr1,0,4));
    CHECK_THROWS(Matrix(arr1,-4,0));
    CHECK_THROWS(Matrix(arr1,4,0));
    CHECK_THROWS(Matrix(arr1,0,0));

    // correct
    CHECK_NOTHROW(Matrix(arr1,2,4));
    CHECK_NOTHROW(Matrix(arr1,4,2));
    CHECK_NOTHROW(Matrix(arr1,1,8));
    CHECK_NOTHROW(Matrix(arr1,8,1));
    
};

TEST_CASE("I/O Operators"){

    std:: vector<double> arr2 = {1,1,1,1};
    std:: vector<double> arr3 = {2,0,0,2};
    std::stringstream buffer;

    // out

    buffer << Matrix(arr2,2,2);
    CHECK(buffer.str() == "[1 1]\n[1 1]");
    buffer.str(std::string());
    buffer << Matrix(arr2,1,4);
    CHECK(buffer.str() == "[1 1 1 1]");
    buffer.str(std::string());
    buffer << Matrix(arr2,4,1);
    CHECK(buffer.str() == "[1]\n[1]\n[1]\n[1]");
    buffer.str(std::string());    

    buffer << Matrix(arr3,2,2);
    CHECK(buffer.str() == "[2 0]\n[0 2]");
    buffer.str(std::string());
    buffer << Matrix(arr3,1,4);
    CHECK(buffer.str() == "[2 0 0 2]");
    buffer.str(std::string());
    buffer << Matrix(arr3,4,1);
    CHECK(buffer.str() == "[2]\n[0]\n[0]\n[2]");
    buffer.str(std::string());

    // in

}

TEST_CASE("Arithmetic Operators - success"){
    std:: vector<double> arr4 = {1,1,1,1};
    std:: vector<double> arr5 = {2,0,0,2};
    Matrix m4 = Matrix(arr4,2,2);
    Matrix m5 = Matrix(arr5,2,2);
    std::stringstream buffer;

    // -
    buffer << (-m4);
    CHECK(buffer.str() == "[-1 -1]\n[-1 -1]");
    buffer.str(std::string()); 

    // +
    buffer << +m4;
    CHECK(buffer.str() == "[1 1]\n[1 1]");
    buffer.str(std::string());

    // m5-m4
    buffer << m5-m4;
    CHECK(buffer.str() == "[1 -1]\n[-1 1]");
    buffer.str(std::string());

    // m4+m5
    buffer << m5+m4;
    CHECK(buffer.str() == "[3 1]\n[1 3]");
    buffer.str(std::string());

    // m5-=m4
    m5-=m4;
    buffer << m5;
    CHECK(buffer.str() == "[1 -1]\n[-1 1]");
    buffer.str(std::string());
    m5 = Matrix(arr5,2,2);

    // m5+=m4
    m5+=m4;
    buffer << m5;
    CHECK(buffer.str() == "[1 -1]\n[-1 1]");
    buffer.str(std::string());
    m5 = Matrix(arr5,2,2);  

    // m4*2
    buffer << 2*m4;
    CHECK(buffer.str() == "[2 2]\n[2 2]");
    buffer.str(std::string());

    // m4*-2
    buffer << -2*m4;
    CHECK(buffer.str() == "[-2 -2]\n[-2 -2]");
    buffer.str(std::string());

    // m4*m5
    buffer << m4*m5;
    CHECK(buffer.str() == "[2 2]\n[2 2]");
    buffer.str(std::string());

    // m4*=2
    m4*=2;
    buffer << m4;
    CHECK(buffer.str() == "[2 2]\n[2 2]");
    buffer.str(std::string());
    m4 = Matrix(arr4,2,2);

    // m4*=-2
    m4*=-2;
    buffer << m4;
    CHECK(buffer.str() == "[-2 -2]\n[-2 -2]");
    buffer.str(std::string());
    m4 = Matrix(arr4,2,2);

    // m4*=m5
    m4*=m5;
    buffer << m4;
    CHECK(buffer.str() == "[2 2]\n[2 2]");
    buffer.str(std::string());
    m4 = Matrix(arr4,2,2);

    // m4++
    m4++;
    buffer << m4;
    CHECK(buffer.str() == "[2 2]\n[2 2]");
    buffer.str(std::string());
    m4 = Matrix(arr4,2,2);

    // m4++
    m4--;
    buffer << m4;
    CHECK(buffer.str() == "[0 0]\n[0 0]");
    buffer.str(std::string());
    m4 = Matrix(arr4,2,2);
}

TEST_CASE("Arithmetic Operators - fail"){
    std:: vector<double> arr4 = {1,1,1,1};
    std:: vector<double> arr5 = {2,0,0,2};
    Matrix m4 = Matrix(arr4,2,2);
    Matrix m5 = Matrix(arr5,1,4);

    // m5-m4
    CHECK_THROWS(m5-m4);

    // m4+m5
    CHECK_THROWS(m5+m4);

    // m5-=m4
    CHECK_THROWS(m5-=m4);

    // m5+=m4
    CHECK_THROWS(m5+=m4);

    // m4*m5
    CHECK_THROWS(m5*m4);

    // m4*=m5
    CHECK_THROWS(m5*=m4);
}

TEST_CASE("Comparison Operators - success"){
    std:: vector<double> arr6 = {1,1,1,1};
    std:: vector<double> arr7 = {2,0,0,2};
    std:: vector<double> arr8 = {2,1,0,0};
    Matrix m6 = Matrix(arr6,2,2);
    Matrix m7 = Matrix(arr7,2,2);
    Matrix m8 = Matrix(arr8,2,2);

    CHECK(m8!=m6);
    CHECK(m6!=m8);
    CHECK(m8==m8);
    CHECK(m6==m7);
    CHECK(m6<=m7);
    CHECK(m6>=m7);
    CHECK(m8<=m7);
    CHECK(m7>=m8);
    CHECK(m8<m7);
    CHECK(m7>m8);

}

TEST_CASE("Comparison Operators - fail"){
    std:: vector<double> arr6 = {1,1,1,1};
    std:: vector<double> arr7 = {2,0,0,2};
    std:: vector<double> arr8 = {2,1,0,0};
    Matrix m6 = Matrix(arr6,2,2); // sum = 4
    Matrix m7 = Matrix(arr7,2,2); // sum = 4
    Matrix m8 = Matrix(arr8,2,2); // sum = 3
    
    CHECK_FALSE(m7!=m6);
    CHECK_FALSE(m6!=m7);
    CHECK_FALSE(m8==m6);
    CHECK_FALSE(m6==m8);
    CHECK_FALSE(m6<=m8);
    CHECK_FALSE(m8>=m7);
    CHECK_FALSE(m7<m8);
    CHECK_FALSE(m8>m7);

    m6 = Matrix(arr6,2,2);
    m7 = Matrix(arr7,1,4);
    m8 = Matrix(arr8,4,1);

    bool result;
    CHECK_THROWS(result = m8!=m6);
    CHECK_THROWS(result = m6!=m8);
    CHECK_THROWS(result = m6==m7);
    CHECK_THROWS(result = m6<=m7);
    CHECK_THROWS(result = m6>=m7);
    CHECK_THROWS(result = m8<=m7);
    CHECK_THROWS(result = m7>=m8);
    CHECK_THROWS(result = m8<m7);
    CHECK_THROWS(result = m7>m8);

}
