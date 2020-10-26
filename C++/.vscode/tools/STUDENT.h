#pragma once
#include "HEADFILES.h"
/*------------------------------------------------------------------------
学生类的声明
------------------------------------------------------------------------*/
class STUDENT {
private:
    int no;
    string name;
    string sex;
    int age;
    string pick;
public:
    STUDENT();
    STUDENT(int n, string na, string se, int ag, string pic) :no(n), name(na), sex(se), age(ag), pick(pic) {};
    ~STUDENT() {}
    STUDENT& operator=(const STUDENT& stu);
    int operator==(const STUDENT& stu);
    int operator>(const STUDENT& stu);
    int operator<(const STUDENT& stu);
    friend istream& operator>>(istream& in, STUDENT& stu);
    explicit operator int();
    int get_no();
    string get_name();
    string get_sex();
    int get_age();
    string get_pick();
};
