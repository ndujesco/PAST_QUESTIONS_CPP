
#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>

#include "header.h"

using namespace std;

void ReadStudentInfo(Student students[3])
{
    ifstream inputInfo;
    inputInfo.open("StudentInfo.txt");

    if (inputInfo.is_open())
    {
        for (int i = 0; i < 3; i++)

        {
            char firstName[20];
            char lastName[20];
            char space[] = " ";

            inputInfo >> firstName >> lastName >> students[i].Score1 >> students[i].Score2 >> students[i].Score3 >> students[i].Score4;

            strcpy(students[i].Name, firstName);
            strcat(students[i].Name, space);
            strcat(students[i].Name, lastName);
        }
    }
    else
    {
        cerr << "Could not open file. Do well to provide one if it does not exist";
    }
}

void CalcAverage(Student students[3])
{
    for (int i = 0; i < 3; i++)
    {
        Student student = students[i];
        students[i].AvgScore = (float)(student.Score1 + student.Score2 + student.Score3 + student.Score4) / 4;
    }
}

void WriteAvgScore(Student students[3])
{
    ofstream outputFIle;

    outputFIle.open("AvgScoreFIle.txt");

    if (outputFIle.is_open())
    {
        int width = 20;
        outputFIle << left << setw(width) << "Student Name"
                   << "Average Score" << endl
                   << endl;

        for (int i = 0; i < 3; i++)
        {
            outputFIle << setw(width) << students[i].Name << students[i].AvgScore << endl
                       << endl;
        }
    }
    else
    {
        cerr << "Could not create file. Try again.";
    }
    outputFIle.close();
}