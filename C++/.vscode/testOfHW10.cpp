#include <bits/stdc++.h>
using namespace std;

/*define of CSS*/
const int max_courseNumber = 1024;
const int max_line = 256;

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

int main()
{
    CI ci[max_courseNumber];
    const char filename[] = "../../file/2.txt";
    ifstream in(filename, ios::in | ios::binary);
    if (in.is_open() == 0)
    {
        //if the file dont exist
        return -1;
    }
    //read
    //record inf of every line
    char line[max_line];
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
        //input
        sscanf(line, "%s %s %d %d %[^\r\n]", &ci[i].number,
               &ci[i].name, &ci[i].time, &ci[i].limitTerm,
               temp);
        //input preCourse
        stringstream ss;
        ss << temp;
        while (1)
        {
            ss >> ci[i].preCourse[ci[i].num_preCourse];
            if (ss.fail())
                break;
            ci[i].num_preCourse++;
        }
        printf("%s %s %d %d", ci[i].number,
               ci[i].name, ci[i].time, ci[i].limitTerm);
        cout << " ";
        for (int j = 0; j < ci[i].num_preCourse; j++)
        {
            cout << ci[i].preCourse[j] << " ";
        }
        cout << endl;
        memset(temp, 0, sizeof(temp));
        i++;
    }

    cout << i << endl;
    in.close();
}