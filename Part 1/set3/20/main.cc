#include "quicksort.ih"

extern char **environ;

int main(int argc, char **argv)
{
    size_t env_size = 0;
                                    // calculate number of environment vars
    for (char **env = environ; *env != 0; ++env)
        env_size++;

    string env_vars[env_size];      // initialize array for environment vars

    for (size_t idx = 0; idx != env_size; ++idx)
        env_vars[idx] = environ[idx];  // store env vars as string in array

    quicksort(env_vars, 0, env_size);

    for (size_t idx = 0; idx != env_size; ++idx)
                                    // output sorted array
       cout << env_vars[idx] << "\n";
}