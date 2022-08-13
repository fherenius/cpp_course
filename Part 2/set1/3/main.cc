#include <string>

int main(int argc, char **argv)
{
    std::string cmdInput = "cp --preserve=timestamps " 
                            + std::string(argv[1]) 
                            + " " 
                            + std::string(argv[2]);

    system(cmdInput.c_str());             // exec with null-terminated string.
}