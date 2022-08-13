#include <iostream>
#include <string>

using namespace std;						

int main(int argc, char **argv)
{
    int value = stoi(argv[1]);                    // convert argument to int
    int valueCopy = value;                        // copy for printing  
    
    int bitValue = 0;
    string bitString;   
    string bitValues;

    for (int bitPos = 31; bitPos >= 0; --bitPos)  // iterate over bit-positions
    {
        bitValue |= (1 << bitPos);                // set bit at bitPos to 1

        if (value & bitValue)                     // check if bit position  
        {                                         // bitPos of value is 1
            bitString.append("1");              

            value -= bitValue;
                                                  // append no "+" if last 1 
                                                  // bit is reached
            value ? bitValues.append(to_string(bitValue) + " + ") 
                : bitValues.append(to_string(bitValue));
            
        } 
        else 
        {
            bitString.append("0");                // bit position in value is 0
        }
        bitValue = 0;                             // reset bit value 
    }
    cout << valueCopy << " = " << bitString << " = "<< bitValues << "\n";
}