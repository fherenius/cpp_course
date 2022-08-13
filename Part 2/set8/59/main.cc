#include <future>
#include <thread>
#include <iostream>

std::string threadFun()
    {
        std::cerr << "entry\n";
    
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cerr << "first cerr\n";
    
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cerr << "second cerr\n";
    
        return "end the program";
    }

int main()
{
  auto ret = std::async(threadFun);

  size_t count = 0;
  while (true)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cerr << "inspecting: " << ++count << '\n';

    if (ret.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
      std::cout << "done";
      break;
    }
  }
}