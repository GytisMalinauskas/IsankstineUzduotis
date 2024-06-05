#include "../Headers/main.h"

void file(string &duomPav)
{
  try{
  int ret = system("dir *.txt");
    if (ret != 0) {
        std::cerr << "Error executing system command 'dir *.txt'" << std::endl;
    }
    cout << "Pasirinkite duomenų failą: ";
    cin >> duomPav;
    ifstream in(duomPav);
    try
    {    
        if (!in) 
        {
        throw runtime_error("Failas nerastas.");
        }
    }
    catch(const runtime_error& e)
    {cout<<e.what()<<endl;}
  }
  catch(const exception& e)
    {
      cerr<<"Klaida: "<<e.what()<<endl;
      exit(1);
    }  
}

vector<string> readFile (string& filename) {
    vector<string> lines;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

vector<string> tokenize(string& line) {
    vector<string> tokens;
    stringstream ss(line);
    string word;
    while (ss >> word) {
        // Pašalinti skyrybos ženklus
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return ispunct(static_cast<unsigned char>(c));
        }), word.end());
        if (!word.empty()) {
            tokens.push_back(word);
        }
    }
    return tokens;
}

map<string, int> countWords(vector<string>& lines) {
    map<string, int> wordCount;
    for (auto& line : lines) {
        vector<string> words = tokenize(line);
        for (auto& word : words) {
            ++wordCount[word];
        }
    }
    return wordCount;
}

map<string, vector<int>> generateCrossReference(vector<string>& lines) {
    map<string, vector<int>> crossRef;
    for (int i = 0; i < lines.size(); ++i) {
        vector<string> words = tokenize(lines[i]);
        for (auto& word : words) {
            if (crossRef[word].empty() || crossRef[word].back() != i + 1) {
                crossRef[word].push_back(i + 1);
            }
        }
    }
    return crossRef;
}

vector<string> extractUrls(vector<string>& lines) {
    vector<string> urls;
    regex urlRegex(R"((https?://[^\s]+)|(www\.[^\s]+)|(\b[^\s]+\.(com|net|org|lt)\b))");
    smatch urlMatch;
    for (auto& line : lines) {
        string::const_iterator searchStart(line.cbegin());
        while (regex_search(searchStart, line.cend(), urlMatch, urlRegex)) {
            urls.push_back(urlMatch[0]);
            searchStart = urlMatch.suffix().first;
        }
    }
    return urls;
}

void writeFile(vector<string>& urls, map<string, int>& wordCount, map<string, vector<int>>& crossRef, string& fileName) {
    ofstream file(fileName);
    for (auto& url : urls) {
        file << url << "\n";
    }
    for (auto& pair : wordCount) {
        if (pair.second > 1) {
            file << pair.first << ": " << pair.second << "\n";
        }
    }
    for (auto& pair : crossRef) {
        if (pair.second.size() > 1) {
            file << pair.first << ": ";
            for (auto& line : pair.second) {
                file << line << " ";
            }
            file << "\n";
        }
    }
}
