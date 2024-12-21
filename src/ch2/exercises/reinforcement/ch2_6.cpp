//
// Created by Peter Sims on 11/21/24.
//

#include <print>
#include "credit_card.h"

int main() {
    using namespace dsac::design;
    constexpr int test_length{3};
    bool hit_limit{false};

    CreditCard wallet[test_length] = {
        CreditCard("John Bowman", "California Savings", "5391 0375 9387 5309", 5000),
        CreditCard("John Bowman", "California Federal", "3485 0399 3395 1954", 3500),
        CreditCard("John Bowman", "California Finance", "5391 0375 9387 5309", 2500, 300)
    };


    double balances[test_length];
    for (int i{0}; i < test_length; ++i) {
        balances[i] = wallet[i].get_balance();
    }


    for (int val = 1; val <= 100; val++) {
        if (hit_limit) {
            break;
        }
        wallet[0].charge(3 * val);
        wallet[1].charge(2 * val);
        wallet[2].charge(val);

        for (int i{0}; i < test_length; ++i) {
            if (wallet[i].get_balance() == balances[i]) {
                std::println("First wallet to hit maximum: {} at value {}", wallet[i].get_account(), val);
                hit_limit = true;
            }
            balances[i] = wallet[i].get_balance();
        }
    }
    return 0;
}
