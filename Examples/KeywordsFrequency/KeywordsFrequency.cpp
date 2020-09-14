// ===========================================================================
// KeywordsFrequency.cpp // Keywords Frequency Counter Application
// ===========================================================================

#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <fstream>
#include <iterator>
#include <iomanip> 

namespace KeywordsFrequencyApplication {

    constexpr bool isVerbose = false;

    class KeywordsFrequency {
    private:
        std::string m_filename;
        const static std::vector<std::string> keywords;
        std::map<std::string, int> m_mapFrequency;

    public:
        // c'tor / d'tor
        KeywordsFrequency() = default;

        void setFile(const std::string& name);
        void parseFile();
        void printResults();

    private:
        void parseLine(const std::string& line);
        bool isKeyword(const std::string& identifier);
        bool isBeginOfKeywordChar(char ch);
        bool isKeywordChar(char ch);
    };

    // ===========================================================================

    void KeywordsFrequency::setFile(const std::string& filename) {
        m_filename = filename;
    }

    void KeywordsFrequency::parseFile() {
        try {
            if (m_filename.empty()) {
                throw std::invalid_argument("Filename not set");
            }

            m_mapFrequency.clear();

            std::ifstream file(m_filename);
            std::string line;
            if (file.is_open()) {

                int lineCounter = 0;
                while (std::getline(file, line)) {
                    ++lineCounter;

                    if (isVerbose) {
                        std::cout << "Parsing line " << std::setw(5)
                            << std::right << lineCounter << std::endl;
                    }

                    parseLine(line);
                }
                file.close();
            }
            else {
                throw std::invalid_argument("File " + m_filename + " not found!");
            }
        }
        catch (std::exception ex) {
            std::cout << "Exception occurred: " << ex.what() << std::endl;
        }
    }

    void KeywordsFrequency::parseLine(const std::string& line) {
        size_t current = 0;
        size_t lineLength = line.size();

        bool isDelim;
        bool isIdentifier;
        while (current < lineLength) {

            isDelim = true;
            while (isDelim == true && current < lineLength) {
                char ch = line[current];
                if (!isBeginOfKeywordChar(ch)) {
                    // it's a delimiter
                    ++current;
                }
                else {
                    // it's not a delimiter
                    isDelim = false;
                }
            }

            isIdentifier = true;
            std::string token;
            while (isIdentifier == true && current < lineLength) {
                char ch = line[current];
                if (isKeywordChar(ch)) {
                    // it's still an identifier
                    current++;
                    std::string tmp(1, ch);
                    token.append(tmp);
                }
                else {
                    // it's no more an identifier
                    isIdentifier = false;
                }
            }

            // store token
            if (!token.empty()) {
                if (isKeyword(token)) {
                    m_mapFrequency[token] ++;
                }
            }
        }
    }

    void KeywordsFrequency::printResults() {

        std::multimap<int, std::string> m_mapKeywordsReverse;

        // sort result map according to the 'frequency' value,
        // therefore dump result map into a 'reverse' map
        // (need a std::multimap for the reversed map,
        // because the keys needn't to be unique)
        for (std::map<std::string, int>::iterator iter = m_mapFrequency.begin();
            iter != m_mapFrequency.end();
            ++iter) {
            m_mapKeywordsReverse.insert(std::pair<int, std::string>(iter->second, iter->first));
        }

        // dump multi map with keyword and their frequency - descending order
        std::cout << "List of Keywords Frequency:" << std::endl;
        std::cout << "===========================" << std::endl << std::endl;
        std::multimap<int, std::string>::reverse_iterator iterRev = m_mapKeywordsReverse.rbegin();
        while (iterRev != m_mapKeywordsReverse.rend()) {
            std::cout << std::setw(17) << iterRev->second << " - " << iterRev->first << std::endl;
            ++iterRev;
        }
    }

    bool KeywordsFrequency::isBeginOfKeywordChar(char ch) {
        return std::isalpha(static_cast<unsigned char>(ch));
    }

    bool KeywordsFrequency::isKeywordChar(char ch) {
        return std::isalnum(static_cast<unsigned char>(ch)) != 0 || ch == '_';
    }

    bool KeywordsFrequency::isKeyword(const std::string& identifier) {

        std::vector<std::string>::const_iterator iter =
            std::find(
                KeywordsFrequency::keywords.begin(),
                KeywordsFrequency::keywords.end(),
                identifier);

        return iter != keywords.end();
    }

    // list-initialization of a static member
    const std::vector<std::string> KeywordsFrequency::keywords = {
        "asm",            "else",         "new",               "this",
        "auto",           "enum",         "operator",          "throw",
        "bool",           "explicit",     "private",           "true",
        "break",          "export",       "protected",         "try",
        "case",           "extern",       "public",            "typedef",
        "catch",          "false",        "register",          "typeid",
        "char",           "float",        "reinterpret_cast",  "typename",
        "class",          "for",          "return",            "union",
        "const",          "friend",       "short",             "unsigned",
        "const_cast",     "goto",         "signed",            "using",
        "continue",       "if",           "sizeof",            "virtual",
        "default",        "inline",       "static",            "void",
        "delete",         "int",          "static_cast"  ,     "volatile",
        "do",             "long",         "struct",            "wchar_t",
        "double",         "mutable",      "switch",            "while",
        "dynamic_cast",   "namespace",    "template"
    };
}

// ===========================================================================

void test_01_frequency() {

    using namespace KeywordsFrequencyApplication;

    KeywordsFrequency keywordsFrequency;
    keywordsFrequency.setFile("..\\Examples\\KeywordsFrequency\\KeywordsFrequency.cpp");
    // keywordsFrequency.setFile("..\\GeneralExamples\\KeywordsFrequency\\HugeCppTestFile.txt");
    keywordsFrequency.parseFile();
    keywordsFrequency.printResults();
}

void test_02_frequency() {

    using namespace KeywordsFrequencyApplication;

    KeywordsFrequency keywordsFrequency;
    keywordsFrequency.setFile("..\\Examples\\KeywordsFrequency\\KeywordsFrequency.cpp");
    keywordsFrequency.parseFile();
    keywordsFrequency.printResults();

    keywordsFrequency.setFile("..\\Examples\\KeywordsFrequency\\HugeCppTestFile.txt");
    keywordsFrequency.parseFile();
    keywordsFrequency.printResults();
}

void main_keywords_frequency() {

    test_01_frequency();
    test_02_frequency();   
}

// ===========================================================================
// End-of-File
// ===========================================================================
