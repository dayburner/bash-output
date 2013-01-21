#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <stdlib.h>

int main()
{
  // Pipe command to a temporary file
  system("/bin/bash -c ls > tmp_file.txt");
  // Open file
  std::ifstream infile("tmp_file.txt");
  // Read the file data into a string object
  std::string data(std::istreambuf_iterator<char>(infile), (std::istreambuf_iterator<char>()));
  // Delete the temporary file
  system("rm -f tmp_file.txt");

  std::cout << "OUTPUT" << data << std::endl;
}
