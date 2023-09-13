/****************************************************************
*   Problem: Builder Design pattern                             *
*   Author:  https://github.com/anonymousAlpha-96               *
*   Date:    01.Sep.23                                          *
*****************************************************************/

/*
NOTE:
1. Pizza is the product class that represents the complex object we want to create, in this case, a pizza.
2. PizzaBuilder is an abstract builder class that defines the steps for building a pizza.
3. HawaiianPizzaBuilder is a concrete builder class that implements the PizzaBuilder interface to build a specific type of pizza (Hawaiian pizza).
4. PizzaDirector is responsible for directing the construction process and creating the final product
*/


#include <iostream>
#include <string>

// Product class
class Pizza {
public:
    void setDough(const std::string& dough) {
        dough_ = dough;
    }

    void setSauce(const std::string& sauce) {
        sauce_ = sauce;
    }

    void setTopping(const std::string& topping) {
        topping_ = topping;
    }

    void display() {
        std::cout << "Pizza with Dough: " << dough_
                  << ", Sauce: " << sauce_
                  << ", Topping: " << topping_ << std::endl;
    }

private:
    std::string dough_;
    std::string sauce_;
    std::string topping_;
};

// Abstract Builder class
class PizzaBuilder {
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza* getPizza() = 0;
};

// Concrete Builder class for a specific type of pizza
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    HawaiianPizzaBuilder() {
        pizza_ = new Pizza();
    }

    void buildDough() override {
        pizza_->setDough("Thin crust");
    }

    void buildSauce() override {
        pizza_->setSauce("Tomato sauce");
    }

    void buildTopping() override {
        pizza_->setTopping("Corn and Onion");
    }

    Pizza* getPizza() override {
        return pizza_;
    }

private:
    Pizza* pizza_;
};

// Director class
class PizzaDirector {
public:
    Pizza* buildPizza(PizzaBuilder* builder) {
        builder->buildDough();
        builder->buildSauce();
        builder->buildTopping();
        return builder->getPizza();
    }
};

int main() {
    PizzaDirector director;
    HawaiianPizzaBuilder hawaiianBuilder;

    Pizza* hawaiianPizza = director.buildPizza(&hawaiianBuilder);
    hawaiianPizza->display();

    delete hawaiianPizza;

    return 0;
}
