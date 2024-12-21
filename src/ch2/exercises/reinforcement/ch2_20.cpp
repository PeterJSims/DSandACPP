//
// Created by Peter Sims on 11/21/24.
//

#include <iostream>
using namespace std;


class Object {
public:
    virtual void print_me() = 0;
};
class Place : public Object {
public:
    virtual void print_me() { cout << "Buy it.\n"; }
};
class Region : public Place {
public:
    virtual void print_me() { cout << "Box it.\n"; }
};
class State : public Region {
public:
    virtual void print_me() { cout << "Ship it.\n"; }
};
class Maryland : public State {
public:
    virtual void print_me() { cout << "Read it.\n"; }
};

int main() {
    Region* mid = new State;
    State*   md = new Maryland;
    Object* obj = new Place;
    Place*  usa = new Region;
    md->print_me();
    mid->print_me();
    (dynamic_cast<Place*>(obj))->print_me();
    obj = md;
    (dynamic_cast<Maryland*>(obj))->print_me();
    obj = usa;
    (dynamic_cast<Place*>(obj))->print_me();
    usa = md;
    (dynamic_cast<Place*>(usa))->print_me();

    delete mid;
    delete md;
    delete obj;
    delete usa;
    return 0;

}