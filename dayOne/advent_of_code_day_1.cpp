#include <iostream>
#include <string>
#include <fstream>
#include <map>

std::map<std::string, char> numberMap = { 
  {"one", '1'},
  {"two", '2'},
  {"three", '3'},
  {"four", '4'},
  {"five", '5'},
  {"six", '6'},
  {"seven", '7'},
  {"eight", '8'},
  {"nine", '9'}
};

int main()
{
  int numberTotal{};

  std::fstream inputFile("input.txt", std::ios::in);
  std::string line;
  while (!inputFile.eof())
  {
    std::getline(inputFile, line);

    int numberOne = 0;
    int numberTwo = 0;

    for (int lineIndex = 0; lineIndex < line.length(); lineIndex++){

      for (auto const& pair : numberMap){

        if ((isdigit(line[lineIndex]) || line.substr(lineIndex, pair.first.length()) == pair.first) && numberOne == 0){
          numberOne = (isdigit(line[lineIndex])) ? (line[lineIndex] - '0') : (pair.second - '0');
          numberTwo = numberOne;

        } else if ((isdigit(line[lineIndex]) || line.substr(lineIndex, pair.first.length()) == pair.first)){
          numberTwo = (isdigit(line[lineIndex])) ? (line[lineIndex] - '0') : (pair.second - '0');

        }
      }
    }

    int foundNumber = numberOne * 10 + numberTwo;
    numberTotal += foundNumber;

    std::cout << foundNumber << '\t' 
              << line << '\n';
  }

  std::cout << numberTotal << '\n';

  inputFile.close();
}

    //DAY 1

    // for (int i = 0; i < line.length(); i++) {

    //   if (isdigit(line[i]) && numberOne == 0) {
    //     numberOne = line[i] - '0';
    //     numberTwo = line[i] - '0';

    //   } else if (isdigit(line[i])) {
    //     numberTwo = line[i] - '0';

    //   }
    // }
