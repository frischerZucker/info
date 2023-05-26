#include <iostream>

class stack
{
private:
    int MAX_LAENGE;
    int laenge;
    int *daten;

    bool is_empty();
    bool is_full();
public:
    stack(int max_laenge);
    ~stack();

    void push(int element);
    int pop();
    int peek();
};

stack::stack(int max_laenge)
{
    if (max_laenge < 1)
    {
        std::cerr << "Stack kann nicht richtig erstellt werden, da maximale Größe < 1!" << std::endl;
    }
    MAX_LAENGE = max_laenge;
    laenge = 0;
    daten = (int*) malloc(sizeof(int) * MAX_LAENGE);
}

stack::~stack()
{
    free(daten);
}

void stack::push(int element)
{
    if (stack::is_full())
    {
        std::cerr << "Der Stack ist voll, das Element kann nicht hinzugefügt werden!" << std::endl;
    }
    daten[laenge] = element;
    laenge += 1;
}

int stack::peek()
{
    if (stack::is_empty())
    {
        std::cerr << "Der Stack ist leer!" << std::endl;
        return 0;
    }

    return daten[laenge - 1];
}

int stack::pop()
{
    if (stack::is_empty())
    {
        std::cerr << "Der Stack ist leer!" << std::endl;
        return 0;
    }

    int element = daten[laenge - 1];
    daten[laenge - 1] = 0;
    laenge -= 1;
    return element;
}

bool stack::is_empty()
{
    return (laenge <= 0);
}

bool stack::is_full()
{
    return (laenge >= MAX_LAENGE);
}

int main(int argc, char const *argv[])
{
    stack a(20);

    int element; 
    std::string aktion;

    std::cout << "Aktionen: pop, peek, push \"Zahl\", x -> Programm beenden\n";
    do
    {
        std::cout << "Aktion? ";
        std::cin >> aktion;

        if (aktion == "pop") std::cout << a.pop() << std::endl;
        else if (aktion == "peek") std::cout << a.peek() << std::endl;
        else if (aktion == "push")
        {
            std::cin >> element;
            a.push(element);
        }
        
    } while (aktion != "x");
    
    return 0;
}