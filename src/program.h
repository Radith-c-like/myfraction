//
// Created by rodio on 04.12.2024.
//

#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>

#include "fraction.h"

template<class T>
class Program {
public:
    Program(RationalNumber<T> val1, RationalNumber<T> val2);
    std::string ShowCompOperations() const;
    std::string ShowAdditionsOperations() const;
    std::string ShowSubtractionsOperations() const;
    std::string ShowMultiplicationsOperations() const;
    std::string ShowDivisionsOperations() const;
private:
    RationalNumber<T> num1, num2;
};

template<class T>
Program<T>::Program(RationalNumber<T> val1, RationalNumber<T> val2) : num1(val1), num2(val2) {};

template<class T>
std::string Program<T>::ShowCompOperations() const {
    return "(" + num1.toString() + " == " + num2.toString() + ") is "
    + std::to_string(num1 == num2)
    + "\n(" + num1.toString() + " != " + num2.toString() + ") is "
    + std::to_string(num1 != num2)
    + "\n(" + num1.toString() + " < " + num2.toString() + ") is "
    + std::to_string(num1 < num2)
    + "\n(" + num1.toString() + " <= " + num2.toString() + ") is "
    + std::to_string(num1 <= num2)
    + "\n(" + num1.toString() + " > " + num2.toString() + ") is "
    + std::to_string(num1 > num2)
    + "\n(" + num1.toString() + " >= " + num2.toString() + ") is "
    + std::to_string(num1 >= num2) + "\n";
}

template<class T>
std::string Program<T>::ShowAdditionsOperations() const {
    std::string str;
    RationalNumber<T> tmp(num1);
    tmp.sum(num2);
    str = num1.toString() + ".sum(" + num2.toString() + ") = " + tmp.toString()
        + "\n";
    tmp = num1 + num2;
    str += num1.toString() + " + " + num2.toString() + " = " + tmp.toString()
        + "\n";
    tmp = num1;
    tmp += num2;
    str += num1.toString() + " += " + num2.toString() + " is " + tmp.toString()
        + "\n";
    tmp = num1;
    +tmp;
    str += "+" + num1.toString() + " is " + tmp.toString() + "\n";
    tmp = num1;
    ++tmp;
    str += "++" + num1.toString() + " is " + tmp.toString() + "\n";
    return str;
}

template<class T>
std::string Program<T>::ShowSubtractionsOperations() const {
    std::string str;
    RationalNumber<T> tmp(num1);
    tmp.subtraction(num2);
    str = num1.toString() + ".subtraction(" + num2.toString() + ") = "
        + tmp.toString() + "\n";
    tmp = num1 - num2;
    str += num1.toString() + " - " + num2.toString() + " = " + tmp.toString()
        + "\n";
    tmp = num1;
    tmp -= num2;
    str += num1.toString() + " -= " + num2.toString() + " is " + tmp.toString()
        + "\n";
    tmp = num1;
    tmp = -tmp;
    str += "-" + num1.toString() + " is " + tmp.toString() + "\n";
    tmp = num1;
    --tmp;
    str += "--" + num1.toString() + " is " + tmp.toString() + "\n";
    return str;
}

template<class T>
std::string Program<T>::ShowDivisionsOperations() const {
    std::string str;
    RationalNumber<T> tmp(num1);
    tmp.division(num2);
    str = num1.toString() + ".division(" + num2.toString() + ") = "
        + tmp.toString() + "\n";
    tmp = num1 / num2;
    str += num1.toString() + " / " + num2.toString() + " = " + tmp.toString()
        + "\n";
    tmp = num1;
    tmp /= num2;
    str += num1.toString() + " /= " + num2.toString() + " is " + tmp.toString()
        + "\n";
    return str;
}

template<class T>
std::string Program<T>::ShowMultiplicationsOperations() const {
    std::string str;
    RationalNumber<T> tmp(num1);
    tmp.multiplication(num2);
    str = num1.toString() + ".multiplication(" + num2.toString() + ") = "
        + tmp.toString() + "\n";
    tmp = num1 * num2;
    str += num1.toString() + " * " + num2.toString() + " = " + tmp.toString()
        + "\n";
    tmp = num1;
    tmp *= num2;
    str += num1.toString() + " *= " + num2.toString() + " is " + tmp.toString()
        + "\n";
    return str;
}


#endif //PROGRAM_H
