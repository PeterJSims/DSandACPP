//
// Created by Peter Sims on 11/21/24.
//



#include <iostream>
#include "credit_card.h"

// See credit_card.h for relevant adjustments from exercise

int main() {
    using namespace dsac::design;

    CreditCard cc{"John Bowman", "California Savings", "5391 0375 9387 5309", 5000};

    std::cout << cc.get_balance() << '\n';
    cc.charge(300);
    std::cout << cc.get_balance() << '\n';
    cc.make_payment(50);
    std::cout << cc.get_balance() << '\n';
    cc.make_payment(50, true);
    std::cout << cc.get_balance() << '\n';

}
