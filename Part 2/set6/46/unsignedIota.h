#ifndef UNSIGNED_IOTA
#define UNSIGNED_IOTA

struct unsigned_iota
{
    unsigned d_value;
    unsigned d_inc;     // value to update d_value with

    unsigned_iota(unsigned inc, unsigned initial_value = 0);

    operator unsigned() const;
    unsigned_iota& operator++(); // overload ++ for custom behaviour
};

unsigned_iota::unsigned_iota(unsigned inc, unsigned initial_value) 
: 
    d_value(initial_value), 
    d_inc(inc) 
{}


unsigned_iota &unsigned_iota::operator++() 
{ 
    d_value += d_inc; 
    return *this; 
}

unsigned_iota::operator unsigned() const
{
    return d_value;
}

#endif // !UNSIGNED_IOTA