#include "../Headers/main.h"

int main()
{
    try{
    string fileName;
    file(fileName);
    string resultsFileName="rezultatai.txt";
    vector<string> lines = readFile(fileName);
    map<string, int> wordCount = countWords(lines);
    map<string, vector<int>> crossRef = generateCrossReference(lines);
    std::vector<std::string> urls = extractUrls(lines);
    writeFile(urls, wordCount, crossRef, resultsFileName);
    return 0;
    }
    catch(const exception& e)
    {
      cerr<<"Klaida: "<<e.what()<<endl;
      exit(1);
    }
}