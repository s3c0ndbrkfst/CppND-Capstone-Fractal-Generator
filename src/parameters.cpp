#include "parameters.h"

std::vector<double> ReadParameters(std::string input)
{
  std::ifstream filestream("predefined_fractals.txt");
  if (!filestream.is_open())
  {
    return {};
  }

  std::vector<double> values;
  std::string line, key, real, imag;
  while (std::getline(filestream, line))
  {
    std::istringstream linestream(line);
    while (linestream >> key >> real >> imag)
    {
      if (key == input)
      {
        values.push_back(std::stod(real));
        values.push_back(std::stod(imag));
      }
    }
  }
  return values;
}