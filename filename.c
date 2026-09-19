#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

void showMenu(void);
void basicArithmetic(void);
void expressionCalculator(void);
void modulusOperation(void);
void powerOperation(void);
void squareRootOperation(void);
void trigonometricOperation(void);
void logarithmOperation(void);
void factorialOperation(void);
void percentageOperation(void);
void averageOperation(void);
void quadraticSolver(void);
long long factorial(int n);

int main(void) {
    int choice;

    do {
        showMenu();
        printf("Enter your choice (0 to Exit): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                basicArithmetic();
                break;

            case 2:
                expressionCalculator();
                break;

            case 3:
                modulusOperation();
                break;

            case 4:
                powerOperation();
                break;

            case 5:
                squareRootOperation();
                break;

            case 6:
                trigonometricOperation();
                break;

            case 7:
                logarithmOperation();
                break;

            case 8:
                factorialOperation();
                break;

            case 9:
                percentageOperation();
                break;

            case 10:
                averageOperation();
                break;

            case 11:
                quadraticSolver();
                break;

            case 0:
                printf("Exiting Calculator. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select between 0-11.\n");
        }

        printf("\n");

    } while (choice != 0);

    return 0;
}

void showMenu(void) {
    printf("=========================================\n");
    printf("        MULTI-FUNCTION CALCULATOR\n");
    printf("=========================================\n");
    printf(" 1. Basic Arithmetic (+, -, *, /)\n");
    printf(" 2. Expression Calculator\n");
    printf(" 3. Modulus (Remainder)\n");
    printf(" 4. Power (x^y)\n");
    printf(" 5. Square Root\n");
    printf(" 6. Trigonometric (sin, cos, tan)\n");
    printf(" 7. Logarithm (log10 & natural log)\n");
    printf(" 8. Factorial\n");
    printf(" 9. Percentage\n");
    printf("10. Average of N Numbers\n");
    printf("11. Quadratic Equation Solver\n");
    printf(" 0. Exit\n");
    printf("=========================================\n");
}

void basicArithmetic(void) {
    double a, b;
    char op;

    printf("Enter first number: ");
    scanf("%lf", &a);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%lf", &b);

    switch (op) {
        case '+':
            printf("Result: %.4lf\n", a + b);
            break;

        case '-':
            printf("Result: %.4lf\n", a - b);
            break;

        case '*':
            printf("Result: %.4lf\n", a * b);
            break;

        case '/':
            if (b == 0)
                printf("Error: Division by zero!\n");
            else
                printf("Result: %.4lf\n", a / b);
            break;

        default:
            printf("Invalid operator!\n");
    }
}

void expressionCalculator(void) {
    double a, b, c, d, e, result;

    printf("Enter five numbers for:\n");
    printf("a / b * c + d - e\n\n");

    printf("Enter a: ");
    scanf("%lf", &a);

    printf("Enter b: ");
    scanf("%lf", &b);

    printf("Enter c: ");
    scanf("%lf", &c);

    printf("Enter d: ");
    scanf("%lf", &d);

    printf("Enter e: ");
    scanf("%lf", &e);

    if (b == 0) {
        printf("Error: Division by zero!\n");
        return;
    }

    result = (a / b) * c + d - e;

    printf("Result: %.4lf\n", result);
}

void modulusOperation(void) {
    int a, b;

    printf("Enter first integer: ");
    scanf("%d", &a);

    printf("Enter second integer: ");
    scanf("%d", &b);

    if (b == 0) {
        printf("Error: Division by zero!\n");
        return;
    }

    printf("Result: %d %% %d = %d\n", a, b, a % b);
}

void powerOperation(void) {
    double base, exponent;

    printf("Enter base: ");
    scanf("%lf", &base);

    printf("Enter exponent: ");
    scanf("%lf", &exponent);

    printf("Result: %.4lf\n", pow(base, exponent));
}

void squareRootOperation(void) {
    double num;

    printf("Enter a number: ");
    scanf("%lf", &num);

    if (num < 0)
        printf("Error: Cannot compute square root of a negative number!\n");
    else
        printf("Square Root: %.4lf\n", sqrt(num));
}

void trigonometricOperation(void) {
    double angleDeg, angleRad, cosVal;

    printf("Enter angle in degrees: ");
    scanf("%lf", &angleDeg);

    angleRad = angleDeg * PI / 180.0;

    printf("sin(%.2lf) = %.4lf\n", angleDeg, sin(angleRad));
    printf("cos(%.2lf) = %.4lf\n", angleDeg, cos(angleRad));

    cosVal = cos(angleRad);

    if (fabs(cosVal) < 1e-9)
        printf("tan(%.2lf) = undefined\n", angleDeg);
    else
        printf("tan(%.2lf) = %.4lf\n", angleDeg, tan(angleRad));
}

void logarithmOperation(void) {
    double num;

    printf("Enter a positive number: ");
    scanf("%lf", &num);

    if (num <= 0) {
        printf("Error: Logarithm undefined for zero or negative numbers!\n");
        return;
    }

    printf("log10(%.4lf) = %.4lf\n", num, log10(num));
    printf("ln(%.4lf) = %.4lf\n", num, log(num));
}

long long factorial(int n) {
    long long result = 1;

    for (int i = 2; i <= n; i++)
        result *= i;

    return result;
}

void factorialOperation(void) {
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error: Factorial not defined for negative numbers!\n");
    } else if (n > 20) {
        printf("Error: Number too large. Try n <= 20.\n");
    } else {
        printf("%d! = %lld\n", n, factorial(n));
    }
}

void percentageOperation(void) {
    double part, whole;

    printf("Enter the part value: ");
    scanf("%lf", &part);

    printf("Enter the whole value: ");
    scanf("%lf", &whole);

    if (whole == 0) {
        printf("Error: Division by zero!\n");
        return;
    }

    printf("Percentage: %.4lf%%\n", (part / whole) * 100.0);
}

void averageOperation(void) {
    int n;
    double sum = 0, num;

    printf("Enter how many numbers: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Count must be positive!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%lf", &num);
        sum += num;
    }

    printf("Average: %.4lf\n", sum / n);
}

void quadraticSolver(void) {
    double a, b, c;
    double discriminant;
    double realPart, imagPart;
    double root1, root2;

    printf("Solve ax^2 + bx + c = 0\n");

    printf("Enter a: ");
    scanf("%lf", &a);

    printf("Enter b: ");
    scanf("%lf", &b);

    printf("Enter c: ");
    scanf("%lf", &c);

    if (a == 0) {
        printf("Error: 'a' cannot be zero for a quadratic equation.\n");
        return;
    }

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);

        printf("Two real roots:\n");
        printf("x1 = %.4lf\n", root1);
        printf("x2 = %.4lf\n", root2);

    } else if (discriminant == 0) {
        root1 = -b / (2 * a);

        printf("One repeated real root:\n");
        printf("x = %.4lf\n", root1);

    } else {
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);

        printf("Two complex roots:\n");
        printf("x1 = %.4lf + %.4lfi\n", realPart, imagPart);
        printf("x2 = %.4lf - %.4lfi\n", realPart, imagPart);
    }
}
