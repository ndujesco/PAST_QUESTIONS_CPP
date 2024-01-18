#include <iostream>
#include <string>

using namespace std;

struct Course
{
    string course_code;
    int course_unit;
    char course_grade;
    float course_point;
};

struct Summary
{
    int units_taken;
    int units_passed;
    int weighted_score;
    float gpa;
};

class Cgpa
{
public:
    int units_taken;
    int units_passed;
    int weighted_score;
    float gpa;

    Cgpa()
    {
        units_taken = 0;
        units_passed = 0;
        weighted_score = 0;
        gpa = 0;
    }

    Cgpa(int units_taken, int units_passed, int weighted_score, float gpa)
    {
        this->units_taken = units_taken;
        this->units_passed = units_passed;
        this->weighted_score = weighted_score;
        this->gpa = gpa;
    }

    void CalcParameters(Course courses[12], int no_of_courses)
    {
        for (int i = 0; i < no_of_courses; i++)
        {
            Course course = courses[i];
            units_taken += course.course_unit;
            weighted_score += course.course_point * course.course_unit;

            if (course.course_point > 0)
            {
                units_passed += course.course_unit;
            }
        }
        gpa = CalcGpa();
    }

    float CalcGpa()
    {
        return round((float)weighted_score * 100 / units_taken) / 100;
    }

    Summary GetSummaryResults(Summary *summary)
    {
        (*summary).units_taken = units_taken;
        (*summary).units_passed = units_passed;
        (*summary).weighted_score = weighted_score;
        (*summary).gpa = gpa;

        return *summary;
    }

    Cgpa operator+(const Cgpa &semester_result)
    {
        Cgpa cgpa;

        cgpa.units_taken = units_taken + semester_result.units_taken;
        cgpa.units_passed = units_passed + semester_result.units_passed;
        cgpa.weighted_score = weighted_score + semester_result.weighted_score;

        cgpa.gpa = round((float)cgpa.weighted_score * 100 / cgpa.units_taken) / 100;
        return cgpa;
    }
};

int main()
{

    Cgpa sgpa;
    Summary sgpa_summary;
    Course eeg, meg, ceg;

    eeg.course_code = "EEG 211";
    eeg.course_unit = 2;
    eeg.course_grade = 'B';
    eeg.course_point = 4.0;

    meg.course_code = "MEG 214";
    meg.course_unit = 2;
    meg.course_grade = 'A';
    meg.course_point = 5.0;

    ceg.course_code = "CEG 211";
    ceg.course_unit = 3;
    ceg.course_grade = 'C';
    ceg.course_point = 3.0;

    Course semester_courses[3] = {ceg, meg, eeg};
    sgpa.CalcParameters(semester_courses, 3);
    sgpa.GetSummaryResults(&sgpa_summary);

    cout << "Semester GPA summary:"
         << "\n\tUnits taken: " << sgpa_summary.units_taken
         << "\n\tUnits passed: " << sgpa_summary.units_passed
         << "\n\tWeighted score: " << sgpa_summary.weighted_score
         << "\n\tGPA: " << sgpa_summary.gpa << endl;

    Cgpa cgpa(30, 30, 140, 4.7);
    cout << "CGPA summary:"
         << "\n\tUnits taken: " << cgpa.units_taken
         << "\n\tUnits passed: " << cgpa.units_passed
         << "\n\tWeighted score: " << cgpa.weighted_score
         << "\n\tGPA: " << cgpa.gpa << endl;

    Cgpa added_cgpa = cgpa + sgpa;
    cout << "NEW CGPA summary:"
         << "\n\tUnits taken: " << added_cgpa.units_taken
         << "\n\tUnits passed: " << added_cgpa.units_passed
         << "\n\tWeighted score: " << added_cgpa.weighted_score
         << "\n\tGPA: " << added_cgpa.gpa << endl;

    return 0;
}