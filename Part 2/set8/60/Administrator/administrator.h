#ifndef ADMINCLASS
#define ADMINCLASS

#include <queue>
#include <string>
#include <fstream>

class Semaphore; // Declaration only

class Administrator
{
  Semaphore &d_admin;
  Semaphore &d_result;
  std::queue<std::string> &d_resultQ;
  std::fstream &d_output;

  public:
    // Constructor initialising all reference fields
    Administrator(Semaphore &admin, Semaphore &result,
                  std::queue<std::string> &resultQ,
                  std::fstream &output);
    
    // Static wrapper function calling administrate()
    static void doWork(Administrator &obj);

  private:
    void administrate();             // Function doing the work
    bool another(std::string &line); // Retrieve another line from the resultQ
};

inline void Administrator::doWork(Administrator &obj)
{
  obj.administrate();
}

#endif // !ADMINCLASS
