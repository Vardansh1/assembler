#include <iostream>

#include <fstream>

#include <string>

#include <sstream>
#include<map>

int main() {
  std::ifstream inputFile("test2.txt"); // Open the text file

  std::map<std::string, int> map;

  // Insert some values into the map
  map["ADD"] = 18;
  map["ADDF"] = 58;
  map["ADDR"] = 90;
  map["AND"] = 40;
  map["CLEAR"] = 34;

  if (inputFile.is_open()) {
    std::string line;
    int wordCount = 0;

    while (std::getline(inputFile, line)) {
    	int count=0;
      std::stringstream ss(line);
      std::string word;

      while (ss >> word) {
        wordCount++;
        count++;
        if(count==1){
        	if(map.find(word)!=map.end()){
        		std::cout<<map[word]<<" ";
			}
			else{
				std::cout<<word<<" ";
			}
		}
		else{
			std::cout<<word<<" ";
		}
      }
      std::cout<<std::endl;
    }

    inputFile.close();

    std::cout << "Number of words in the said file: " << wordCount << std::endl;
  } else {
    std::cout << "Failed to open the file." << std::endl;
  }


  return 0;
}