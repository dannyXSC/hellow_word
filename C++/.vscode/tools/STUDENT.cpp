#include "STUDENT.h"
/*------------------------------------------------------------------------
学生类的成员函数的实现
------------------------------------------------------------------------*/
int STUDENT::get_no()
{
    return this->no;
}
string STUDENT::get_name()
{
    return this->name;
}
string STUDENT::get_sex()
{
    return this->sex;
}
int STUDENT::get_age()
{
    return this->age;
}
string STUDENT::get_pick()
{
    return this->pick;
}
istream& operator>>(istream& in, STUDENT& stu)
{
    cin >> stu.no >> stu.name >> stu.sex >> stu.age >> stu.pick;
    return in;
}
STUDENT::STUDENT()
{
    this->no = 0;
    this->name = "";
    this->sex = "";
    this->age = 0;
    this->pick = "";
}
STUDENT& STUDENT::operator=(const STUDENT& stu)
{
    this->no = stu.no;
    this->name = stu.name;
    this->sex = stu.sex;
    this->age = stu.age;
    this->pick = stu.pick;
    return *this;
}
int STUDENT::operator==(const STUDENT& stu)
{
    if (this->no == stu.no)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int STUDENT::operator>(const STUDENT& stu)
{
    if (this->no > stu.no)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
int STUDENT::operator<(const STUDENT& stu)
{
    if (this->no < stu.no)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
STUDENT::operator int()
{
    return this->no;
}
