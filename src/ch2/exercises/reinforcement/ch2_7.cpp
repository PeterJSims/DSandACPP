//
// Created by Peter Sims on 11/21/24.
//

#include <print>


class AllKinds {
    int m_i;
    long m_l;
    float m_f;

public:
    AllKinds(int i = 100, long l = 50000, float f = 2.55): m_i(i), m_l(l), m_f(f) {
    };

    int get_i() const {
        return m_i;
    }

    void set_i(const int i) {
        m_i = i;
    }

    long get_l() const {
        return m_l;
    }

    void set_l(const long l) {
        m_l = l;
    }

    float get_f() const {
        return m_f;
    }

    void set_f(const float f) {
        m_f = f;
    }


    long get_i_plus_l() const {
        return m_i + m_l;
    }

    float get_i_plus_f() const {
        return m_i + m_f;
    }

    float get_l_plus_f() const {
        return m_l + m_f;
    }

    float get_i_plus_l_plus_f() const {
        return m_i + m_l + m_f;
    }
};


int main() {
    AllKinds ak{};
    std::println("{}", ak.get_i_plus_f());
    std::println("{}", ak.get_i_plus_l());
    std::println("{}", ak.get_l_plus_f());
    std::println("{}", ak.get_i_plus_l_plus_f());

    return 0;
}

