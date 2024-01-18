#ifndef QUESTION2_H
#define QUESTION2_H

struct Student
{
    char Name[100];
    int Score1;
    int Score2;
    int Score3;
    int Score4;
    float AvgScore;
};


void ReadStudentInfo(Student student[3]);
void CalcAverage(Student students[3]);
void WriteAvgScore(Student students[3]);


#endif