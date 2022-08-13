

class Base
{
    int d_num;

    public:
        void setNum(int num);
};

void Base::setNum(int num)
{
    d_num = num;
}

class Derived: public Base
{
    public:
        Derived();
};

inline Derived::Derived()
{
    setNum(1);
}

int main()
{
    Derived der;
}