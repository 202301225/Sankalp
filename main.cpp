#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class CodeSnippetManager
{
    private:
    unordered_map<string, pair<string, vector<string>>> snippets; // {name, {code, tags}}
    string storage_file;

    public:
    CodeSnippetManager(const string &file = "snippets.txt") : storage_file(file)
    {
        loadSnippets();
    }

    void loadSnippets()
    {
        ifstream file(storage_file);
        if (file.is_open())
        {
            string name, code, tags;
            while (file >> name >> ws && getline(file, code) && getline(file, tags))
            {
                vector<string> tagList;
                istringstream iss(tags);
                string tag;
                while (iss >> tag)
                {
                    tagList.push_back(tag);
                }
                snippets[name] = make_pair(code, tagList);
            }
            file.close();
        }
    }

    void saveSnippets()
    {
        ofstream file(storage_file);
        if (file.is_open())
        {
            for (const auto &entry : snippets)
            {
                file << entry.first << ' ' << entry.second.first << '\n';
                for (const auto &tag : entry.second.second)
                {
                    file << tag << ' ';
                }
                file << '\n';
            }
            file.close();
        }
    }

    void addSnippet(const string &name, const string &code, const vector<string> &tags)
    {
        snippets[name] = make_pair(code, tags);
        saveSnippets();
        cout << "Snippet '" << name << "' added successfully.\n";
    }

    void getSnippet(const string& name)
    {
        auto it = snippets.find(name);
        if (it != snippets.end())
        {
            cout << "Snippet '" << name << "':\n";
            cout << it->second.first << '\n'; // Output code snippet directly
            cout << "Tags: ";
            for (const auto& tag : it->second.second)
            {
                cout << tag << ' ';
            }
            cout << '\n';
        }
        else
        {
            cout << "Snippet '" << name << "' not found.\n";
        }
    }

    void listSnippets()
    {
        if (snippets.empty())
        {
            cout << "No snippets available.\n";
        }
        else
        {
            cout << "Available snippets:\n";
            for (const auto &entry : snippets)
            {
                cout << "- " << entry.first << '\n';
            }
        }
    }

};