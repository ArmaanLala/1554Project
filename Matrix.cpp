#include "Matrix.h"

Matrix::Matrix(uint rows, uint cols){
    this->rows = rows;
    this->cols = cols;
    firstPtr = new double[rows * cols];
    for (uint i = 0; i < (rows * cols); i++)
    {
        *(firstPtr + i) = 0;
    }
}

Matrix ::Matrix(double **values, int w, int h){
    rows = h;
    cols = w;
    firstPtr = new double[rows * cols];
    uint count{0};
    for (uint i = 0; i < rows; i++)
    {
        for (uint j = 0; j < cols; j++)
        {
            *(firstPtr + (count)) = *(*(values+i)+j);
            count++;
        }
    }
}

Matrix ::Matrix(const Matrix &m){
    rows = m.numRows();
    cols = m.numCols();
    firstPtr = new double[rows * cols];
    uint count{0};
    for (uint i = 0; i < rows; i++)
    {
        for (uint j = 0; j < cols; j++)
        {
            *(firstPtr + (count)) = m.at(i, j);
            count++;
        }
    }
}

Matrix Matrix::add(double s) const{
    Matrix m(*this);
    for (uint i = 0; i < rows; i++)
    {
        for (uint j = 0; j < cols; j++)
        {
            m.at(i, j) = m.at(i, j) + s;
        }
    }
    return m;
}
Matrix Matrix::add(const Matrix &m) const
{
    Matrix ret(*this);
    for (uint i = 0; i < rows; i++)
    {
        for (uint j = 0; j < cols; j++)
        {
            ret.at(i, j) = ret.at(i, j) + m.at(i, j);
        }
    }
    return ret;
}

Matrix Matrix::subtract(double s) const{
    Matrix m(*this);
    for (uint i = 0; i < rows; i++)
    {
        for (uint j = 0; j < cols; j++)
        {
            m.at(i, j) = m.at(i, j) - s;
        }
    }
    return m;
}

Matrix Matrix::subtract(const Matrix &m) const{
    Matrix ret(*this);
    for (uint i = 0; i < rows; i++)
    {
        for (uint j = 0; j < cols; j++)
        {
            ret.at(i, j) = ret.at(i, j) - m.at(i, j);
        }
    }
    return ret;
}

Matrix Matrix::multiply(double s) const {
    Matrix m(*this);
    for (uint i = 0; i < rows; i++)
    {
        for (uint j = 0; j < cols; j++)
        {
            m.at(i, j) = m.at(i, j) * s;
        }
    }
    return m;
}

Matrix Matrix::multiply(const Matrix &m) const {
    Matrix ret(this->numRows(), m.numCols());
    for (uint i = 0; i < ret.numRows(); i++)
    {
        for (uint j = 0; j < ret.numCols(); j++)
        {
            for (uint k = 0; k < m.numRows(); k++)
            {
                ret.at(i, j) += this->at(i, k) * m.at(k, j);
            }
        }
    }
    return ret;
}

Matrix Matrix::divide(double s) const {
    Matrix m(*this);
    for (uint i = 0; i < rows; i++)
    {
        for (uint j = 0; j < cols; j++)
        {
            m.at(i, j) = m.at(i, j) / s;
        }
    }
    return m;
}

Matrix Matrix::t() const {
    Matrix m(cols, rows);
    for (uint i = 0; i < rows; i++)
    {
        for (uint j = 0; j < cols; j++)
        {
            m.at(j, i) = this->at(i, j);
        }
    }
    return m;
}

Matrix operator+(const Matrix &m, double s) {
    return m.add(s);
}
Matrix operator-(const Matrix &m, double s) {
    return m.subtract(s);
}
Matrix operator*(const Matrix &m, double s) {
    return m.multiply(s);
}
Matrix operator/(const Matrix &m, double s) {
    return m.divide(s);
}

Matrix operator+(double s, const Matrix &m) {
    return m.add(s);
}
Matrix operator-(double s, const Matrix &m) {
    return m.subtract(s);
}
Matrix operator*(double s, const Matrix &m) {
    return m.multiply(s);
}
Matrix operator/(double s, const Matrix &m) {
    return m.divide(s);
}

Matrix Matrix::operator-() const {
    return this->multiply(-1);
}

Matrix Matrix::operator+(const Matrix &m) const {
    return this->add(m);
}
Matrix Matrix::operator-(const Matrix &m) const {
    return this->subtract(m);
}
Matrix Matrix::operator*(const Matrix &m) const {
    return this->multiply(m);
}

void Matrix::operator=(const Matrix &m) {
  delete[] firstPtr;
  rows = m.numRows();
  cols = m.numCols();
  firstPtr = new double[rows * cols];
  uint count{0};
  for (uint i = 0; i < rows; i++)
  {
      for (uint j = 0; j < cols; j++)
      {
          *(firstPtr + (count)) = m.at(i, j);
          count++;
      }
  }
}

const uint Matrix::numCols() const {
    return this->cols;
}

const uint Matrix::numRows() const {

    return this->rows;
}

double &Matrix ::operator()(uint row, uint col) {
    return this->at(row, col);
}

double &Matrix::at(uint row, uint col) {
    uint location = cols * row + col;
    return *(this->firstPtr + (location));
}

const double &Matrix::at(uint row, uint col) const {

    uint location = cols * row + col;
    return *(this->firstPtr + (location));
}

std::ostream &operator<<(std::ostream &os, const Matrix &m) {

    for (uint i = 0; i < m.numRows(); i++)
    {
        os << "[";
        for (uint j = 0; j < m.numCols(); j++)
        {
            os << m.at(i, j);
            if (j != (m.numCols() - 1))
            {
                os << ",";
            }
        }
        if (i == m.numRows() - 1)
        {
            os << "]";
        }
        else
        {
            os << "]" << std::endl;
        }
    }
    return os;
}

Matrix::~Matrix(){
    delete[] firstPtr;
}
