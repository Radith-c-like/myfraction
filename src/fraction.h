//
// Created by rodio on 28.11.2024.
//

#ifndef FRACTION_H
#define FRACTION_H

#include <string>
#include <numeric>
#include <fstream>
#include <iostream>

template <class T>
class RationalNumber {
public:
  RationalNumber(T numerator = 0, T denominator = 1);
  RationalNumber(const RationalNumber<T>& other) = default;
  ~RationalNumber() = default;

  RationalNumber sum(const RationalNumber& other) const;
  RationalNumber sub(const RationalNumber& other) const;
  RationalNumber div(const RationalNumber& other) const;
  RationalNumber multiply(const RationalNumber& other) const;

  RationalNumber& operator + ();

  RationalNumber& operator - ();

  RationalNumber operator + (const RationalNumber &other)const;
  RationalNumber operator - (const RationalNumber &other)const;
  RationalNumber operator * (const RationalNumber &other)const;
  RationalNumber operator / (const RationalNumber &other)const;
  RationalNumber& operator += (const RationalNumber &other);
  RationalNumber& operator -= (const RationalNumber &other);
  RationalNumber& operator *= (const RationalNumber &other);
  RationalNumber& operator /= (const RationalNumber &other);
  bool operator == (const RationalNumber &other)const;
  bool operator != (const RationalNumber &other)const;
  bool operator < (const RationalNumber &other)const;
  bool operator > (const RationalNumber &other)const;
  bool operator <= (const RationalNumber &other)const;
  bool operator >= (const RationalNumber &other)const;
  RationalNumber& operator = (const RationalNumber &other);
  RationalNumber& operator ++ ();
  RationalNumber operator ++ (int);
  RationalNumber& operator -- ();
  RationalNumber operator -- (int);
  std::string toString() const;

  template<class T1>
  friend std::ifstream& operator >> (std::ifstream& fin, RationalNumber<T1>& number); //TODO test it

  template<class T1>
  friend std::ofstream& operator << (std::ofstream& fout, const RationalNumber<T1>& number); //TODO test it



private:
  T numerator_;
  T denominator_;

  void normalize();
};

template<class T>
RationalNumber<T>::RationalNumber(T numerator, T denominator) : numerator_(numerator), denominator_(denominator) {
  if (denominator_ == 0) {
    throw std::invalid_argument("denominator cannot be zero");
  }
  normalize();
}

template<class T>
void RationalNumber<T>::normalize() {
  if (denominator_ == 0) {
    throw std::invalid_argument("denominator cannot be zero");
  }
  T gcd = std::gcd(numerator_, denominator_);
  if (gcd > 1) {
    numerator_ /= gcd;
    denominator_ /= gcd;
  }
  if (denominator_ < 0) {
    numerator_ *= -1;
    denominator_ *= -1;
  }
}

template<class T>
RationalNumber<T> RationalNumber<T>::sum(const RationalNumber &other) const {
  T newNumerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
  T newDeminator = denominator_ * other.denominator_;
  return RationalNumber<T>(newNumerator, newDeminator);
}

template<class T>
RationalNumber<T> RationalNumber<T>::sub(const RationalNumber &other) const {
  T newNumerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
  T newDeminator = denominator_ * other.denominator_;
  return RationalNumber<T>(newNumerator, newDeminator);
}

template<class T>
RationalNumber<T> RationalNumber<T>::div(const RationalNumber &other) const {
  T newNumerator = numerator_ * other.denominator_;
  T newDeminator = denominator_ * other.numerator_;
  return RationalNumber<T>(newNumerator, newDeminator);
}

template<class T>
RationalNumber<T> RationalNumber<T>::multiply(const RationalNumber &other) const {
  T newNumerator = numerator_ * other.numerator_;
  T newDeminator = denominator_ * other.denominator_;
  return RationalNumber<T>(newNumerator, newDeminator);
}

template<class T>
std::string RationalNumber<T>::toString() const{
  std::string res;
  res += std::to_string(numerator_) + "/" + std::to_string(denominator_);
  return res;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator + () {
  normalize();
  return *this;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator - () {
  numerator_ = -numerator_;
  return *this;
}

template<class T>
RationalNumber<T> RationalNumber<T>::operator+(const RationalNumber &other) const {
  T newNumerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
  T newDeminator = denominator_ * other.denominator_;
  return RationalNumber<T>(newNumerator, newDeminator);
}

template<class T>
RationalNumber<T> RationalNumber<T>::operator - (const RationalNumber &other) const {
  T newNumerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
  T newDeminator = denominator_ * other.denominator_;
  return RationalNumber<T>(newNumerator, newDeminator);
}

template<class T>
RationalNumber<T> RationalNumber<T>::operator * (const RationalNumber &other) const {
  T newNumerator = numerator_ * other.numerator_;
  T newDeminator = denominator_ * other.denominator_;
  return RationalNumber<T>(newNumerator, newDeminator);
}

template<class T>
RationalNumber<T> RationalNumber<T>::operator / (const RationalNumber &other) const {
  T newNumerator = numerator_ * other.denominator_;
  T newDeminator = denominator_ * other.numerator_;
  return RationalNumber<T>(newNumerator, newDeminator);
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator+=(const RationalNumber &other) {
  numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_;
  denominator_ = denominator_ * other.denominator_;
  normalize();
  return *this;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator -=(const RationalNumber &other) {
  numerator_ = numerator_ * other.denominator_ - other.numerator_ * denominator_;
  denominator_ = denominator_ * other.denominator_;
  normalize();
  return *this;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator*=(const RationalNumber &other) {
  numerator_ *= other.denominator_;
  denominator_ *= * other.denominator_;
  normalize();
  return *this;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator/=(const RationalNumber &other) {
  numerator_ *= other.denominator_;
  denominator_ *= other.numerator_;
  normalize();
  return *this;
}

template<class T>
bool RationalNumber<T>::operator==(const RationalNumber &other) const {
  if (numerator_ == other.numerator_ && denominator_ == other.denominator_) {
    return true;
  }
  return false;
}

template<class T>
bool RationalNumber<T>::operator!=(const RationalNumber &other) const {
  if (*this == other) {
    return false;
  }
  return true;
}

template<class T>
bool RationalNumber<T>::operator>(const RationalNumber &other) const {
  if (numerator_ * other.denominator_ > other.numerator_ * denominator_) {
    return true;
  }
  return false;
}

template<class T>
bool RationalNumber<T>::operator<(const RationalNumber &other) const {
  if (*this > other || *this == other) {
    return false;
  }
  return true;
}

template<class T>
bool RationalNumber<T>::operator>=(const RationalNumber &other) const {
  if (*this < other) {
    return false;
  }
  return true;
}

template<class T>
bool RationalNumber<T>::operator<=(const RationalNumber &other) const {
  if (*this > other) {
    return false;
  }
  return true;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator = (const RationalNumber &other) {
  numerator_ = other.numerator_;
  denominator_ = other.denominator_;
  return *this;
}

template<class T>
RationalNumber<T>& RationalNumber<T>::operator ++ () {
  ++numerator_;
  normalize();
  return *this;
}

template<class T>
RationalNumber<T> RationalNumber<T>::operator ++(int) {
  RationalNumber<T> temp = *this;
  ++(*this);
  normalize();
  return temp;
}

template<class T>
RationalNumber<T> &RationalNumber<T>::operator--() {
  --numerator_;
  normalize();
  return *this;
}


template<class T>
RationalNumber<T> RationalNumber<T>::operator--(int) {
  RationalNumber<T> temp = *this;
  --(*this);
  normalize();
  return temp;
}

template<class T>
std::istream& operator >> (std::istream& fin, RationalNumber<T>& number) {
  T numerator;
  T denominator;
  fin >> numerator;
  fin >> denominator;
  number = RationalNumber<T>(numerator, denominator);
  return fin;
}
template<class T1>
std::ostream& operator << (std::ostream& fout, const RationalNumber<T1>& number) {
  fout << number.toString();
  return fout;
}

#endif //FRACTION_H
