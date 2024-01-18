#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

struct Coefficient
{
    float SecondOrderCoeff;
    float FirstOrderCoeff;
    float ConstantCoeff;
};

struct ComplexRoots
{
    complex<float> root1;
    complex<float> root2;
};

enum RootType
{
    REAL_REPEATED,
    REAL_DIFFERENT,
    IMAGINARY
};

void printCoefficients(Coefficient *coefficients)
{
    cout << "\nThe equation is of the form ax^2 + bx + c. The coeficients are:\n"
         << "\ta = " << coefficients->SecondOrderCoeff << "\n"
         << "\tb = " << coefficients->FirstOrderCoeff << "\n"
         << "\tc = " << coefficients->ConstantCoeff << endl;
}

class Quadratic

{
    Coefficient *coefficients;
    RootType rootType;

public:
    Quadratic()
    {
        coefficients = new Coefficient();
        (*coefficients).ConstantCoeff = 0;
        (*coefficients).FirstOrderCoeff = 0;
        (*coefficients).SecondOrderCoeff = 0;
    }

    Quadratic(float SecondOrderCoeff, float FirstOrderCoeff, float ConstantCoeff)

    {
        coefficients = new Coefficient();

        (*coefficients).ConstantCoeff = ConstantCoeff;
        (*coefficients).FirstOrderCoeff = FirstOrderCoeff;
        (*coefficients).SecondOrderCoeff = SecondOrderCoeff;
    }

    void SetCoefficient(float SecondOrderCoeff, float FirstOrderCoeff, float ConstantCoeff)
    {
        (*coefficients).ConstantCoeff = ConstantCoeff;
        (*coefficients).FirstOrderCoeff = FirstOrderCoeff;
        (*coefficients).SecondOrderCoeff = SecondOrderCoeff;
    }

    void GetCoefficient(Coefficient *coefficient)
    {
        *coefficient = *coefficients;
        coefficients = coefficient;
    }

private:
    float CalcDeterminant()
    {
        float determinant = pow((*coefficients).FirstOrderCoeff, 2) - (4 * (*coefficients).SecondOrderCoeff * (*coefficients).ConstantCoeff);

        if (determinant > 0)
        {
            rootType = REAL_DIFFERENT;
        }
        else if (determinant < 0)
        {
            rootType = IMAGINARY;
        }
        else
        {
            rootType = REAL_REPEATED;
        }

        return determinant;
    }

public:
    void QuadraticRoots(ComplexRoots *roots)
    {
        complex<float> determinant = CalcDeterminant();

        float a = (*coefficients).SecondOrderCoeff;
        float b = (*coefficients).FirstOrderCoeff;
        float c = (*coefficients).ConstantCoeff;

        roots->root1 = (-b + sqrt(determinant)) / (2 * a);
        roots->root2 = (-b - sqrt(determinant)) / (2 * a);
    }

    void WriteRoots(ComplexRoots *roots)
    {
        if (rootType == IMAGINARY)
        {
            float real = round(roots->root1.real() * 10000) / 10000;
            float imag = round(roots->root1.imag() * 10000) / 10000;

            cout << "The roots are complex.\n"
                 << "\tRoot1: " << real << "+" << imag << "i\n"
                 << "\tRoot2: " << real << "-" << imag << "i" << endl;
        }
        else if (rootType == REAL_DIFFERENT)
        {
            cout << "The roots are different.\n"
                 << "\tRoot1: " << round(roots->root1.real() * 10000) / 10000 << "\n"
                 << "\tRoot2: " << round(roots->root2.real() * 10000) / 10000 << endl;
        }
        else
        {
            cout << "The roots are the equal.\n"
                 << "\tRoots: " << round(roots->root1.real() * 10000) / 10000 << " (twice)" << endl;
        }
    }
};

int main()
{
    Quadratic equation(1, -15, 56);
    Coefficient coefficient;
    ComplexRoots roots;

    equation.GetCoefficient(&coefficient);
    equation.QuadraticRoots(&roots);
    printCoefficients(&coefficient);
    equation.WriteRoots(&roots);

    Quadratic equation1, equation2, equation3;
    Coefficient coefficient1, coefficient2, coefficient3;
    ComplexRoots roots1, roots2, roots3;

    // Example of real and unequal roots
    equation1.GetCoefficient(&coefficient1);
    equation1.SetCoefficient(1, -5, 6);
    equation1.QuadraticRoots(&roots1);

    printCoefficients(&coefficient1);
    equation1.WriteRoots(&roots1);

    // Example of complex roots
    equation2.SetCoefficient(2, 2, 2);
    equation2.GetCoefficient(&coefficient2);
    equation2.QuadraticRoots(&roots2);

    printCoefficients(&coefficient2);
    equation2.WriteRoots(&roots2);

    // Example of real and equal roots
    equation3.SetCoefficient(1, -6, 9);
    equation3.GetCoefficient(&coefficient3);
    equation3.QuadraticRoots(&roots3);

    printCoefficients(&coefficient3);
    equation3.WriteRoots(&roots3);

    // system("pause");
    return 0;
}