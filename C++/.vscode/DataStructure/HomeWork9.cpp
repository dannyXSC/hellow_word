/*------------------------------------------------------------------------
course scheduling system
------------------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

/*define return value*/
typedef int Status;
#define YES 1
#define NO 0
#define OK 1
#define ERROR 0
#define LOVERFLOW -1
#define INFEASIBLE -2
#define TRUE 1
#define FALSE 0

//define of CI
const int max_preCourse = 16;
const int max_numberBit = 16;
const int max_nameBit = 256;

//record information of course
typedef class CourseInformation
{
public:
    char number[max_numberBit]; //courseNumber
    char name[max_nameBit];     //courseName
    int time;                   //times
    int limitTerm;              //given courseTerm
    int num_preCourse;
    char preCourse[max_preCourse][max_numberBit]; //preCourse use Course's number
    CourseInformation() : number(""), name(""), time(0),
                          limitTerm(0), num_preCourse(0), preCourse() {}
} CI;

/*define of CSS*/
const int max_courseNumber = 64;
const int max_line = 256;

typedef class CourseSchedulingSystem
{
protected:
    //format
    //information of course
    CI ci[max_courseNumber];
    //number of course
    int totalNumber; //total number of course

public:
    CourseSchedulingSystem() {}
    ~CourseSchedulingSystem() {}
    Status ReadInformation(const char *filename);
} CSS;

Status CSS::ReadInformation(const char *filename)
{
    ifstream in(filename, ios::in | ios::binary);
    if (in.is_open() == 0)
    {
        //if the file dont exist
        return ERROR;
    }
    //record inf of every line
    char line[max_line];
    //to read preCourse
    char temp[max_line];
    //record number of every course
    int i = 0;
    //read the first line
    in.getline(line, max_line);
    while (1)
    {
        in.getline(line, max_line);
        if (in.good() == 0)
            break;
        //input all by sscanf
        sscanf(line, "%s %s %d %d %[^\n]", &ci[i].number,
               &ci[i].name, &ci[i].time, &ci[i].limitTerm,
               temp);
        //input preCourse by stringstream
        stringstream ss;
        ss << temp;
        while (1)
        {
            ss >> ci[i].preCourse[ci[i].num_preCourse]; //numCourse is the number of course
            if (ss.fail())                              //if buffer has nothing then break
                break;
            ci[i].num_preCourse++;
        }
        //set 0
        memset(temp, 0, sizeof(temp));
        i++;
    }
    in.close();
    return OK;
}

int main()
{
    CSS css;
}
