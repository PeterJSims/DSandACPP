#pragma once
#include <cctype>
#include <string>
#include  <print>

class CaesarCipher {
    std::string encoder = std::string(26, '?');
    std::string decoder = std::string(26, '?');

public:
    explicit CaesarCipher(const int rotation = 1) {
        for (int k = 0; k < 26; k++) {
            encoder[k] = 'A' + (k + rotation) % 26;
            decoder[k] = 'A' + (k - rotation + 26) % 26;
        }
    }

    std::string encrypt(const std::string& message) const {
        return transform(message, encoder);
    }

    std::string decrypt(const std::string& secret) const {
        return transform(secret, decoder);
    }

private:
    static std::string transform(const std::string& original, const std::string& code) {
        std::string result{};
        for (const char k : original)
            if (isupper(k)) {
                const int j{k - 'A'};
                result.push_back(code[j]);
            } else if (islower(k)) {
                constexpr int offset{32};
                const int j{k - 'A' - offset};
                result.push_back(tolower(code[j]));
            } else {
                result.push_back(k);
            }
        return result;
    }
};
