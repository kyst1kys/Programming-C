#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main() {
    double alpha;

    printf("Enter the value of alpha (in radians): ");
    if (scanf("%lf", &alpha) != 1) {
        printf("Invalid input. Please enter a numeric value.\n");
        return 1;
    }

    // arguments for cos
    double arg1 = (3.0 / 8.0) * M_PI - (alpha / 4.0);
    double arg2 = (11.0 / 8.0) * M_PI + (alpha / 4.0);

    // z1 = cos^2(arg1) - cos^2(arg2)
    double cos1 = cos(arg1);
    double cos2 = cos(arg2);
    double z1 = cos1 * cos1 - cos2 * cos2;

    // z2 = (sqrt(2) / 2) * sin(alpha / 2)
    double z2 = (sqrt(2.0) / 2.0) * sin(alpha / 2.0);

    // Виведення результатів
    printf("\nFinal results:\n");
    printf("z1 = %.6f\n", z1);
    printf("z2 = %.6f\n", z2);

    return 0;
}