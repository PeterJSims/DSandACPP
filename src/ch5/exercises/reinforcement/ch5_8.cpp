//
// Created by Peter Sims on 1/22/25.
//
#include <cctype>  // provides isupper() function
#include <string>
#include <iostream>

namespace dsac::array {
    /// Class for doing encryption and decryption using the Caesar Cipher.
    class CaesarCipher {
    private:
        std::wstring encoder = std::wstring(24, '?'); // Encryption string
        std::wstring decoder = std::wstring(24, '?'); // Decryption string
        std::wstring hebrewAlphabet = L"אבגדהוזחטיכלמנסעפצקרשת";

    public:
        CaesarCipher(int rotation = 1) {
            for (int k = 0; k < 22; k++) {
                encoder[k] = hebrewAlphabet[0] + (k + rotation) % 22;
                decoder[k] = hebrewAlphabet[0] + (k - rotation + 22) % 22;
            }
        }

        std::wstring encrypt(const std::wstring& message) {
            return transform(message, encoder); // use encoder string
        }


        std::wstring decrypt(const std::wstring& secret) {
            return transform(secret, decoder); // use decoder string
        }

    private:
        std::wstring transform(const std::wstring& original, const std::wstring& code) {
            std::wstring result{original};
            for (int k = 0; k < original.size(); k++)
                if (isupper(original[k])) {
                    // we have a letter to change
                    int j{original[k] - hebrewAlphabet[0]}; // will be value from 0 to 25
                    result[k] = code[j]; // replace the character
                }
            return result;
        }
    };
}


int main() {
    // TODO: Finish Hebrew implementation -- wide char issues printing

    using namespace dsac::array;
    using namespace std;
    CaesarCipher cipher{3};
    wstring message{L"בוקר טוב כל "};

    wstring coded{cipher.encrypt(message)};
    wcout << "Secret:  " << coded << endl;
    wstring answer{cipher.decrypt(coded)};
    wcout << "Message: " << answer << endl;
    return 0;
}
