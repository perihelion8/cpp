#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << "The program takes 3 parameters in the following order: a filename and two strings, s1 and s2." << std::endl;
    return 0;
  }
  std::string filename = argv[1], s1 = argv[2], s2 = argv[3];
  
  std::fstream input_file(filename.c_str(), std::ios::in);
  if (!input_file) {
    std::cout << "Error opening the file." << std::endl;
    return 1;
  }

  std::fstream output_file((filename + ".replace").c_str(), std::ios::out);
  if (!output_file) {
    std::cout << "Error opening the file." << std::endl;
    return 1;
  }

  std::string line;
  size_t pos;

  while (std::getline(input_file, line)) {
    while ((pos = line.find(s1)) != std::string::npos) {
      line.erase(pos, s1.length());
      line.insert(pos, s2);
    }
    output_file << line << std::endl;
  }

  input_file.close();
  output_file.close();
}
