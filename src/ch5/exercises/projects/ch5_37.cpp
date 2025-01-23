//
// Created by Peter Sims on 1/23/25.
//

#include <iostream>
#include <string>

#include "../exercise_classes/caesar_cipher.h"

// caesar_cipher.h
int main() {
    CaesarCipher cipher{3};
    std::string message{"I am A Test of Upper AnD LowER case LettERs."};
    std::string coded{cipher.encrypt(message)};
    std::println("Secret: {}", coded);
    std::string answer{cipher.decrypt(coded)};
    std::println("Message: {}", answer);

    return 0;
}
