#include <iostream>
#include <cmath>

#ifdef _WIN32
#include <conio.h>
#define CLEAR_COMMAND "cls"
#else
#include <termios.h>
#include <unistd.h>
#define CLEAR_COMMAND "clear"
#endif

using namespace std;

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exponent);
double squareRoot(double num);
double logarithm(double num);
double sine(double angle);
double cosine(double angle);
double tangent(double angle);

int main()
{
    int choice;

    do
    {
        double num1, num2;

        cout << "Scientific Calculator" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Power" << endl;
        cout << "6. Square Root" << endl;
        cout << "7. Logarithm (base 10)" << endl;
        cout << "8. Sine" << endl;
        cout << "9. Cosine" << endl;
        cout << "10. Tangent" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice (0-10): ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exiting the calculator. Goodbye!" << endl;
            return 0;
        case 1:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Result: " << add(num1, num2) << endl;
            break;
        case 2:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Result: " << subtract(num1, num2) << endl;
            break;
        case 3:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Result: " << multiply(num1, num2) << endl;
            break;
        case 4:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            if (num2 != 0)
            {
                cout << "Result: " << divide(num1, num2) << endl;
            }
            else
            {
                cout << "Error: Cannot divide by zero." << endl;
            }
            break;
        case 5:
            cout << "Enter base and exponent: ";
            cin >> num1 >> num2;
            cout << "Result: " << power(num1, num2) << endl;
            break;
        case 6:
            cout << "Enter a number: ";
            cin >> num1;
            if (num1 >= 0)
            {
                cout << "Result: " << squareRoot(num1) << endl;
            }
            else
            {
                cout << "Error: Cannot calculate square root of a negative number." << endl;
            }
            break;
        case 7:
            cout << "Enter a number: ";
            cin >> num1;
            if (num1 > 0)
            {
                cout << "Result: " << logarithm(num1) << endl;
            }
            else
            {
                cout << "Error: Cannot calculate logarithm of a non-positive number." << endl;
            }
            break;
        case 8:
            cout << "Enter an angle in degrees: ";
            cin >> num1;
            cout << "Result: " << sine(num1) << endl;
            break;
        case 9:
            cout << "Enter an angle in degrees: ";
            cin >> num1;
            cout << "Result: " << cosine(num1) << endl;
            break;
        case 10:
            cout << "Enter an angle in degrees: ";
            cin >> num1;
            cout << "Result: " << tangent(num1) << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Press any key to continue..." << endl;

        #ifdef _WIN32
        _getch();
        #else
        struct termios old_tio, new_tio;
        tcgetattr(STDIN_FILENO, &old_tio);
        new_tio = old_tio;
        new_tio.c_lflag &= (~ICANON & ~ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
        getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
        #endif

        // Clear the screen
        system(CLEAR_COMMAND);

    } while (true);

    return 0;
}

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}

double power(double base, double exponent)
{
    return pow(base, exponent);
}

double squareRoot(double num)
{
    return sqrt(num);
}

double logarithm(double num)
{
    return log10(num);
}

double sine(double angle)
{
    return sin(angle * M_PI / 180.0);
}

double cosine(double angle)
{
    return cos(angle * M_PI / 180.0);
}

double tangent(double angle)
{
    return tan(angle * M_PI / 180.0);
}
