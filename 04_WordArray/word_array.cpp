#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string sentence_Type(const string& sentence);

int main()
{
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);
    cout << "The sentence is " << sentence_Type(input) << "." << endl;

    vector <string> words;
    string word;

    for (char c : input) {
        if (isspace(c) or ispunct(c)) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }

    if (!word.empty()) {
		words.push_back(word);
	}

    cout << "Character amount in each word:" << endl;
    for (const string& w : words) {
        cout << w << ": " << w.length() << " " << endl;
    }

    string longest_word = *max_element(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
        });
    reverse(longest_word.begin(), longest_word.end());
    cout << "Longest word spelled backwards: " << longest_word << endl;

    string acronym;
    for (const string& w : words) {
        acronym += tolower(w[0]);
    }
    cout << "Acronym: " << acronym << endl;

    return 0;
}

string sentence_Type(const string &sentence) {

    char last = sentence.back();
    if (last == '.') {
		return "declarative";
    }
    else if (last == '?') {
		return "interrogative";
    }
    else if (last == '!') {
		return "exclamatory";
    }
    else {
		return "unknown";
	}
}

