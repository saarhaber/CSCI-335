//Saar Haber

#include <set>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

// //---------SET / UNORDERED_SET ------------//
void missingLetter(const std::string &word, const std::unordered_set<std::string>&dictionary, std::map<std::string, std::vector<std::string>> &suggestions){
    std::string newWord = word;
    for (int j=0; j<word.length(); j++){
        for (char i='a'; i<='z'; i++) {
            if (word[j]==i) {
                continue;
            }
            newWord = newWord.substr(0,j) + i + newWord.substr(j);
            if (dictionary.count(newWord)==1) {
                suggestions[word].push_back(newWord);
            }
            newWord = word;
        }
    }
    return;
}

void extraLetter(const std::string &word, const std::unordered_set<std::string>&dictionary, std::map<std::string, std::vector<std::string>> &suggestions
){
    std::string newWord = word;
    for (int j=0; j<word.length(); j++){
            newWord = newWord.substr(0,j) + newWord.substr(j+1);
            if (dictionary.count(newWord)==1) {
                suggestions[word].push_back(newWord);
            }
            newWord = word;
    }
    return;
}

void replacedLetter(const std::string &word, const std::unordered_set<std::string>&dictionary, std::map<std::string, std::vector<std::string>> &suggestions
){
    std::string newWord = word;
    for (int j=0; j<word.length(); j++){
        for (char i='a'; i<='z'; i++) {
            if (word[j]==i) {
                continue;
            }
            if (j+1 < word.length())
            newWord = newWord.substr(0,j) + i + newWord.substr(j+1);
            if (dictionary.count(newWord)==1) {
                suggestions[word].push_back(newWord);
            }
            newWord = word;
        }
    }
    return;
}

void neighboringLetters(const std::string &word, const std::unordered_set<std::string>&dictionary, std::map<std::string, std::vector<std::string>> &suggestions
){
std::string newWord = word;
    for (int j=0; j<word.length()-1; j++){
            newWord = newWord.substr(0,j) + word[j+1] + word[j] + newWord.substr(j+2);
            if (dictionary.count(newWord)==1) {
                suggestions[word].push_back(newWord);
            }
            newWord = word;
        }
    return;
}

//-------------VECTOR-----------//

// void missingLetter(const std::string &word, const std::vector<std::string>&dictionary, std::map<std::string, std::vector<std::string>> &suggestions){
//     std::string newWord = word;
//     for (int j=0; j<word.length(); j++){
//         for (char i='a'; i<='z'; i++) {
//             if (word[j]==i) {
//                 continue;
//             }
//             newWord = newWord.substr(0,j) + i + newWord.substr(j);
//             for (int k=0; k<dictionary.size(); k++)
//             if (dictionary[k]==newWord) {
//                 suggestions[word].push_back(newWord);
//                 break;
//             }
//             newWord = word;
//         }
//     }
//     return;
// }

// void extraLetter(const std::string &word, const std::vector<std::string>&dictionary, std::map<std::string, std::vector<std::string>> &suggestions
// ){
//     std::string newWord = word;
//     for (int j=0; j<word.length(); j++){
//         newWord = newWord.substr(0,j) + newWord.substr(j+1);
//         for (int k=0; k<dictionary.size(); k++)
//         if (dictionary[k]==newWord) {
//             suggestions[word].push_back(newWord);
//             break;
//         }
//         newWord = word;
//     }
//     return;
// }

// void replacedLetter(const std::string &word, const std::vector<std::string>&dictionary, std::map<std::string, std::vector<std::string>> &suggestions
// ){
//     std::string newWord = word;
//     for (int j=0; j<word.length(); j++){
//         for (char i='a'; i<='z'; i++) {
//             if (word[j]==i) {
//                 continue;
//             }
//             if (j+1 < word.length())
//             newWord = newWord.substr(0,j) + i + newWord.substr(j+1);
//             for (int k=0; k<dictionary.size(); k++) {
//                 if (dictionary[k]==newWord) {
//                     suggestions[word].push_back(newWord);
//                     break;
//                 }
//             }
//             newWord = word;
//         }
//     }
//     return;
// }

// void neighboringLetters(const std::string &word, const std::vector<std::string>&dictionary, std::map<std::string, std::vector<std::string>> &suggestions
// ){
// std::string newWord = word;
//     for (int j=0; j<word.length()-1; j++){
//             newWord = newWord.substr(0,j) + word[j+1] + word[j] + newWord.substr(j+2);
//             for (int k=0; k<dictionary.size(); k++)
//             if (dictionary[k]==newWord) {
//                 suggestions[word].push_back(newWord);
//                 break;
//             }
//             newWord = word;
//         }
//     return;
// }