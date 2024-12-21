//
// Created by Peter Sims on 11/21/24.
//
#include <iostream>


class Flower {
public:
    Flower(const std::string& name, int petals, float price): m_name(name), m_petals(petals), m_price(price) {
    }



    std::string get_name() const {
        return m_name;
    }

    void set_name(const std::string& name) {
        m_name = name;
    }

    int get_petals() const {
        return m_petals;
    }

    void set_petals(const int petals) {
        m_petals = petals;
    }

    float get_price() const {
        return m_price;
    }

    void set_price(const float price) {
        m_price = price;
    }

    friend std::ostream& operator<<(std::ostream& os, const Flower& obj) {
        return os
            << "Name: " << obj.m_name
            << " Petals: " << obj.m_petals
            << " Price: " << obj.m_price;
    }

private:
    std::string m_name;
    int m_petals;
    float m_price;
};


int main() {
    Flower f{"Rose", 35, 8.5};
    Flower f2{"Iris", 6, 3.25};

    std::cout << f << "\n";
    std::cout << f2 << "\n";
    std::cout << f.get_name() << "\n";
    std::cout << f2.get_petals() << "\n";

}
