#include <iostream>
#include <cmath>

// Function to find the root using Newton-Raphson method
double newtonRaphson(double initialGuess, double tolerance, int maxIterations) {
    double x = initialGuess; // Current approximation of the root

    for (int i = 0; i < maxIterations; i++) {
        double f = x * x - 612.0; // Change this to your function
        double f_prime = 2 * x; // Derivative of the function

        // Check if the derivative is zero
        if (fabs(f_prime) < tolerance) {
            std::cout << "Warning: Derivative near zero." << std::endl;
            break;
        }

        // Update x using the formula
        x = x - f / f_prime;

        // Check for convergence
        if (fabs(f) < tolerance) {
            return x;
        }
    }

    return x; // Return the found root
}

int main() {
    double initialGuess = 10.0; // Initial guess for the root
    double tolerance = 0.00001; // Tolerance for convergence
    int maxIterations = 1000; // Maximum number of iterations

    // Call the newtonRaphson function and display the result
    double root = newtonRaphson(initialGuess, tolerance, maxIterations);
    std::cout << "Root found: " << root << std::endl;

    return 0;
}
