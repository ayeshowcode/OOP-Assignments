#include <iostream>
using namespace std;
template <class T>
class Pet
{
protected:
    string name;
    T age;

public:
    Pet(const string &name, T age) : name(name), age(age) {}

    virtual void makeSound() = 0;
};
template <class T>
class Dog : public Pet<T>
{
public:
    Dog(string name, T age) : Pet<T>(name, age) {}

    void makeSound() override
    {
        cout << "woof" << endl;
    }
};

template <class T>
class Cat : public Pet<T>
{
public:
    Cat(string name, T age) : Pet<T> (name , age){}

    void makeSound() override
    {
        cout << "meow" << endl;
    }
};

template <class T>
class Bird: public Pet<T>
{
    public:
    Bird(string name, T age): Pet<T> (name, age){}

    void makeSound() override
    {
        cout << "chirp"<< endl;
    }
};
int main()
{
    Dog<int> D("farq", 12);
    Cat<int> C("ni", 11);
    Bird<int>B("parta", 69);

    D.makeSound();
    C.makeSound();
    B.makeSound();
}