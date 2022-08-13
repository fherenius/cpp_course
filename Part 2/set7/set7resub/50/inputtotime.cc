#include "main.ih"

std::chrono::seconds inputToTime(std::string input)
{
  char unit = input.back();
  input.pop_back(); // Remove last char to only have the integer
  int duration = std::stoi(input);

  std::chrono::seconds inputSeconds;

  switch (unit)
  {
    case 'h' : inputSeconds = hours(duration);
    case 'm' : inputSeconds = minutes(duration);
    case 's' : inputSeconds = seconds(duration);
  } 

  return inputSeconds;
}