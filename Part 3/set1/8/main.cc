#include <iostream>
#include <functional>
    
class CPU
{
  static void (CPU::*s_opcode[])();
  std::function<void (const CPU &)> exitptr = &CPU::exit;

  public:
    void invoke(int opcodeByte);
  private:
    void jmp() { std::cout << "Jmp\n"; };
    void exit() const { std::cout << "Exit\n"; };

};

void (CPU::*CPU::s_opcode[])() = 
{
  &CPU::jmp,
  &CPU::exitptr
};

void CPU::invoke(int opcodeByte)
{
  (this->*s_opcode[opcodeByte])();
}

int main()
{
  CPU cpu;

  cpu.invoke(1);
}