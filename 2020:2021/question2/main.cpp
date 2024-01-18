#include "source.cpp"

int main()
{
    Student students[3];

    ReadStudentInfo(students);
    CalcAverage(students);
    WriteAvgScore(students);

    return 0;
}
