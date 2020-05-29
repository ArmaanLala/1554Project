#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

typedef unsigned int uint;

class Matrix
{

public:
  Matrix(uint rows, uint cols);
  Matrix(double **values, int w, int h);
  Matrix(const Matrix &m);
  ~Matrix(); // destructor
  Matrix add(double s) const;

  Matrix add(const Matrix &m) const;

  Matrix subtract(double s) const;
  Matrix subtract(const Matrix &m) const;

  Matrix multiply(double s) const;
  Matrix multiply(const Matrix &m) const;

  Matrix divide(double s) const;

  friend Matrix operator+(const Matrix &m, double s);
  friend Matrix operator-(const Matrix &m, double s);
  friend Matrix operator*(const Matrix &m, double s);
  friend Matrix operator/(const Matrix &m, double s);

  friend Matrix operator+(double s, const Matrix &m);
  friend Matrix operator-(double s, const Matrix &m);
  friend Matrix operator*(double s, const Matrix &m);
  friend Matrix operator/(double s, const Matrix &m);

  Matrix operator-(double s) const;
  Matrix operator*(double s) const;
  Matrix operator/(double s) const;
  Matrix operator-() const;
  Matrix t() const;

  Matrix operator+(const Matrix &m) const;
  Matrix operator-(const Matrix &m) const;
  Matrix operator*(const Matrix &m) const;
  void operator=(const Matrix &m);

  const uint numRows() const;
  const uint numCols() const;
  double &operator()(uint row, uint col);
  double &at(uint row, uint col);
  const double &at(uint row, uint col) const;
  friend std::ostream &operator<<(std::ostream &os, const Matrix &m);

private:
  uint rows;
  uint cols;
  double *firstPtr;
};

#endif
