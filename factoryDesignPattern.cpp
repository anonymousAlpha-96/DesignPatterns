/****************************************************************
*   Problem: Factory Design pattern                             *
*   Author:  https://github.com/anonymousAlpha-96               *
*   Date:    26.Aug.23                                          *
*****************************************************************/

#include <iostream>

// Abstract Product
class Product {
public:
    virtual void display() = 0;
};

// Concrete Products
class ConcreteProductA : public Product {
public:
    void display(){
        std::cout << "Product A" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void display(){
        std::cout << "Product B" << std::endl;
    }
};

// Abstract Factory
class Factory {
public:
    virtual Product* createProduct() = 0;
};

// Concrete Factories
class ConcreteFactoryA : public Factory {
public:
    Product* createProduct(){
        return new ConcreteProductA();
    }
};

class ConcreteFactoryB : public Factory {
public:
    Product* createProduct(){
        return new ConcreteProductB();
    }
};

int main() {
    // Client code uses the Factory to create objects
    Factory* factoryA = new ConcreteFactoryA();
    Product* productA = factoryA->createProduct();
    productA->display();

    Factory* factoryB = new ConcreteFactoryB();
    Product* productB = factoryB->createProduct();
    productB->display();

    delete factoryA;
    delete factoryB;
    delete productA;
    delete productB;

    return 0;
}


/*
NOTE:
1. Product is the abstract class representing the products to be created.
2. ConcreteProductA and ConcreteProductB are concrete implementations of the Product interface.
3. Factory is the abstract class representing the factory responsible for creating products.
4. ConcreteFactoryA and ConcreteFactoryB are concrete implementations of the Factory interface, each producing a specific type of product.
*/