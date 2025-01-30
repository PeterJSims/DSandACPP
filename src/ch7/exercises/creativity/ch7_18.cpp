//
// Created by Peter Sims on 1/29/25.
//
#include <print>
#include <stack>
#include <sstream>


// Infinite overkill! Cleans entire <X> tag where needed
std::string clean_tag(const std::string& raw_string) {
    std::stringstream ss{raw_string};
    std::vector<std::string> split_html{};
    for (std::string temp; ss >> temp;) {
        split_html.push_back(temp);
    }

    std::string cleaned_tag{};
    if (split_html.size() == 1) {
        cleaned_tag = split_html[0];
    } else {
        if (split_html[0].size() == 1) {
            // just an < tag
            cleaned_tag += '<';
            if (!split_html[1].ends_with('>')) {
                // may have tags after the tag name
                cleaned_tag += split_html[1] + '>';
            }
        } else {
            // item is at least '<' and the tag name
            if (split_html[0].ends_with('>')) {
                cleaned_tag = split_html[0];
            } else {
                cleaned_tag += split_html[0] + '>';
            }
        }
    }
    return cleaned_tag;
}

bool is_html_matched(const std::string& html) {
    std::stack<std::string> buffer;
    int j(html.find('<'));
    while (j != std::string::npos) {
        size_t k{html.find('>', j + 1)};
        if (k == std::string::npos) return false;
        std::string tag{html.substr(j + 1, k - j - 1)};

        if (tag.substr(0, 1) != "/") {
            const size_t first_char_index{tag.find_first_not_of(' ')};
            const size_t last_letter_index{tag.find_first_of(' ', first_char_index)};
            if (last_letter_index != std::string::npos) {
                buffer.push(tag.substr(first_char_index, last_letter_index - first_char_index));
            } else {
                buffer.push(tag.substr(first_char_index));
            }
        } else {
            if (buffer.empty())
                return false;
            if (tag.substr(1) != buffer.top())
                return false;
            buffer.pop();
        }
        j = html.find('<', k + 1);
    }
    return buffer.empty();
}


int main() {
    const std::string test{
        "<name attribute1='value1' attribute2='value2'>"
        "<b> bold text</b>"
        "< div border='3'> in a div with a space in a tag </div>"
        " text here </name>"
    };
    const std::string bad_test{
        "<name attribute1='value1' attribute2='value2'>"
        "<b> bold text</b>"
        "< div border='3'> in a div with a space in a tag </div>"
        " text here "
    };
    std::println("{}", is_html_matched(test));
    std::println("{}", is_html_matched(bad_test));

    return 0;
}
