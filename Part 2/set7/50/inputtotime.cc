#include "main.ih"

std::chrono::seconds inputToTime(std::string input)
{
  char unit = input.back();
  input.pop_back(); // Remove last char to only have the integer
  int duration = std::stoi(input);

  hours inputHours(0);
  minutes inputMinutes(0);
  seconds inputSeconds(0);

  switch (unit)
  {
    case 'h' : inputHours = hours(duration);
    case 'm' : inputMinutes = minutes(duration);
    case 's' : inputSeconds = seconds(duration);
  } 

  return inputHours + inputMinutes + inputSeconds;
}