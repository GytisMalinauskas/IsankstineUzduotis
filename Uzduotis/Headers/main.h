#ifndef main_h
#define main_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <regex>
#include <cctype>
#include <algorithm>
using namespace std;

void file(string &duomPav);
void writeFile(vector<string>& urls, map<string, int>& wordCount, map<string, vector<int>>& crossRef, string& fileName);
vector<string> readFile(string& fileName);
vector<string> tokenize(string& line);
map<string, int> countWords(vector<string>& lines);
map<string, vector<int>> generateCrossReference(vector<string>& lines);
vector<string> extractUrls(vector<string>& lines);


#endif