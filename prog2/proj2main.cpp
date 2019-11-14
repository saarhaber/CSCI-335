//Saar Haber

#include <set>
#include <unordered_set>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include "proj2.hpp"

int main(int argc, char *argv[]) {

    std::unordered_set<std::string>dictionary;
    //std::set<std::string>dictionary;
    //std::vector<std::string>dictionary;
    std::set<std::string>wrongWords;

    //reading and creating the dictionary
    std::ifstream dict;
    std::string word, word2;
    dict.open(argv[2]);

    while (dict >> word) 
    {
        dictionary.insert(word);
        //dictionary.push_back(word);
    }
    dict.close();
 
    //reading and creating the wrongwords
    std::ifstream plainText;
    plainText.open(argv[1]);

    while (plainText >> word) 
    {   word2="";
        for (int i=0; i<word.length(); i++){
            char fixChar = word[i];
            if (isupper(word[i])){
                fixChar = tolower(fixChar);
                word2+=fixChar;
            }
            else if (isalpha(fixChar) || fixChar=='-' || fixChar=='\''){
                word2+=word[i];
            }
        }
        //Set or Unordered Set
        if (dictionary.find(word2)==dictionary.end() && wrongWords.find(word2)==wrongWords.end())
        {
            wrongWords.insert(word2);
        }

        //For Vector:
        // bool inDict=false;
        // if (wrongWords.find(word2)!=wrongWords.end()) {
        //     continue;
        // }
        // for (int i=0; i<dictionary.size(); i++) {
        //     if (dictionary[i]==word2) {
        //         inDict = true;
        //     }
        // }
        // if (!inDict) {
        //     wrongWords.insert(word2);
        // }
    }
    plainText.close();

    std::vector<std::string>suggestedWords;
    std::map<std::string, std::vector<std::string>> suggestions;

    //time:
    using Timer = std::chrono::steady_clock;
    auto start {Timer::now()};

    for (auto it=wrongWords.begin(); it!=wrongWords.end(); it++){
        suggestions.insert(std::pair<std::string,std::vector<std::string>>(*it,suggestedWords));
        missingLetter(*it, dictionary, suggestions);
        extraLetter(*it, dictionary, suggestions);
        replacedLetter(*it, dictionary, suggestions);
        neighboringLetters(*it, dictionary, suggestions);
    }

    //time:
    auto finish {Timer::now()};
    std::cout<< std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << std::endl;

    //printing to check the map and creating the file
    std::ofstream outfile ("output.txt");
    for (auto it=suggestions.begin(); it!=suggestions.end(); it++){
        //std::cout<< it->first << ": ";
        outfile << it->first << ": ";
        for (int i=0; i<it->second.size(); i++) {
            //std::cout<< it->second[i] << " ";
            outfile << it->second[i] << " ";
        }
        //std::cout << std::endl;
        outfile << std::endl;
    }
    outfile.close();
}
