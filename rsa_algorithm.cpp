#include <iostream>
#include <cmath>

// Function to find the greatest common divisor
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// C++ implementation of RSA Algorithm
int main() {
    // Two random prime numbers (in practice, these should be large)
    int p = 3;
    int q = 7;

    // First part of the public key:
    // n = p*q
    int n = p * q;

    // Finding other part of public key.
    // e stands for encrypt
    int e = 2;
    int phi = (p - 1) * (q - 1);
    while (e < phi && gcd(e, phi) != 1) {
        e++;
    }

    // Private key (d stands for decrypt)
    // Choosing d such that it satisfies
    // d*e = 1 + k * phi for some k
    int k = 2; // A constant value
    int d = (1 + (k * phi)) / e;

    // Message to be encrypted
    int msg = 12;

    std::cout << "Message data = " << msg << std::endl;

    // Encryption: c = (msg ^ e) % n
    int c = pow(msg, e);
    c = fmod(c, n);
    std::cout << "Encrypted data = " << c << std::endl;

    // Decryption: m = (c ^ d) % n
    int m = pow(c, d);
    m = fmod(m, n);
    std::cout << "Decrypted data = " << m << std::endl;

    return 0;
}
