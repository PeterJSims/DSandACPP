//
// Created by Peter Sims on 11/21/24.
//
/*
*
Class Goat extends Object and adds a instance variable tail and functions milk() and jump().
Class Pig extends Object and adds a instance variable nose and functions eat() and wallow().
Class Horse extends Object and adds instance variables height and color, and functions run() and jump().
Class Racer extends Horse and adds a function race().
Class Equestrian extends Horse and adds a instance variable weight and functions trot() and is_trained().
*/

#include <print>

class Object {
};

class Goat : public Object {
public:
    bool tail;

    Goat(): tail(true) {
    }

    void milk() { std::println("I am getting milked"); }
    void jump() { std::println("I am jumping"); }
};

class Pig : public Object {
    bool nose;

    Pig(): nose(true) {
    }

    void eat() { std::println("I am eating"); }
    void wallow() { std::println("I am wallowing"); }
};

class Horse : public Object {
public:
    int height;
    std::string color;

    Horse(int height = 65, std::string color = "Brown"): height(height),color(std::move(color)) {}

    void run(){std::println("I am running");}
    void jump(){std::println("I am jumping");}
};
class Racer: public Horse {
public:
    Racer() = default;
    void race(){std::println("I am racing");}
};

class Equestrian: public Horse {
public:
    double weight;

    Equestrian(int height, std::string color, double weight): Horse(height, std::move(color)),weight(weight) {}
    Equestrian(double weight): Horse(65, "Brown"),weight(weight) {}

    void trot(){std::println("I am trotting");}
    bool is_trained(){return true;}
};


int main() {
    Horse* d = new Equestrian(900);
    auto x{(Racer*)d};
    d->jump();

    return 0;
}
