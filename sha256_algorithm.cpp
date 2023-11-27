#include <iostream>
#include <string>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>

int main() {
    std::string msg = "Hello World";
    std::string digest;

    // Create the hash object
    CryptoPP::SHA256 hash;

    // Compute the SHA-256 hash
    CryptoPP::StringSource s(msg, true, new CryptoPP::HashFilter(hash, new CryptoPP::HexEncoder(new CryptoPP::StringSink(digest))));

    // Print the hash
    std::cout << "Message: " << msg << std::endl;
    std::cout << "SHA-256: " << digest << std::endl;

    return 0;
}
