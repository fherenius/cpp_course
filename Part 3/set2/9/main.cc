    #include "unique/unique.h"
    #include <iostream>

    using namespace std;

    int main()
    {
        Counter<int> value{ 42 };
    
        Counter<int> second{ value };
    
        cout << value.get() << ' ' << second.get() << '\n';
    
        second.get() = 13;
    
        cout << value.get() << ' ' << second.get() << '\n';
    
        Counter<string> text{ "hello world" };
        text = Counter<string>{ "hello world (2)" };
    
        cout << text.get() << '\n';
    }