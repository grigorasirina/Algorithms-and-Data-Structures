#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// Function to estimate the value of Pi using Monte Carlo method
double monteCarloPi(int numSamples) {
    int insideCircle = 0;

    for (int i = 0; i < numSamples; i++) {
        // Generate random points
        double x = static_cast<double>(rand()) / RAND_MAX;
        double y = static_cast<double>(rand()) / RAND_MAX;

        // Check if the point is inside the unit circle
        if (sqrt(x * x + y * y) <= 1.0) {
            insideCircle++;
        }
    }

    // Calculate the ratio of points inside the circle to total points
    double piEstimate = 4.0 * insideCircle / numSamples;
    return piEstimate;
}

int main() {
    srand(time(0)); // Seed the random number generator
    int numSamples = 1000000; // Number of samples

    // Call the monteCarloPi function and display the result
    double piEstimate = monteCarloPi(numSamples);
    std::cout << "Estimated Pi: " << piEstimate << std::endl;

    return 0;
}
