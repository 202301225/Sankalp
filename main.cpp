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

//This function to load snippet in the file
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
//this snippet to save snippet in the file
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
//this function is use to add snippet in the file
    void addSnippet(const string &name, const string &code, const vector<string> &tags)
    {
        snippets[name] = make_pair(code, tags);
        saveSnippets();
        cout << "Snippet '" << name << "' added successfully.\n";
    }

//this function is use for get snippet from the file
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

//this function is use for get list of snippets from file
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

//this function is use for get all tags which is saved in file
    void listTags()
    {
        unordered_set<string> tagSet;
        for (const auto &entry : snippets)
        {
            for (const auto &tag : entry.second.second)
            {
                tagSet.insert(tag);
            }
        }

        if (tagSet.empty())
        {
            cout << "No tags available.\n";
        }
        else
        {
            cout << "Available tags:\n";
            for (const auto &tag : tagSet)
            {
                cout << "- " << tag << '\n';
            }
        }
    }

//this function is use to search snippet name by tag 
    void searchByTag(const string &tag)
    {
        vector<string> matchingSnippets;
        for (const auto &entry : snippets)
        {
            if (find(entry.second.second.begin(), entry.second.second.end(), tag) != entry.second.second.end())
            {
                matchingSnippets.push_back(entry.first);
            }
        }

        if (matchingSnippets.empty())
        {
            cout << "No snippets found with tag '" << tag << "'.\n";
        }
        else
        {
            cout << "Snippets with tag '" << tag << "':\n";
            for (const auto &snippet : matchingSnippets)
            {
                cout << "- " << snippet << '\n';
            }
        }
    }
//this function is use for edit snippet which you already stored
    void editSnippet(const string &name, const string &newCode, const vector<string> &newTags)
    {
        auto it = snippets.find(name);
        if (it != snippets.end())
        {
            snippets[name] = make_pair(newCode, newTags);
            saveSnippets();
            cout << "Snippet '" << name << "' edited successfully.\n";
        }
        else
        {
            cout << "Snippet '" << name << "' not found.\n";
        }
    }
};


int main()
{
    CodeSnippetManager snippetManager;

    while (true)
    {
        cout << "\nCode Snippet Manager Menu:\n";
        cout << "1. Add Snippet\n";
        cout << "2. Get Snippet\n";
        cout << "3. List Snippets\n";
        cout << "4. List Tags\n";
        cout << "5. Search by Tag\n";
        cout << "6. Edit Snippet\n";
        cout << "7. Remove Snippet\n";
        cout << "8. Exit\n";

        int choice;
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name, codeLine, code;
            vector<string> tags;

            cout << "Enter snippet name: ";
            cin.ignore(); // Ignore newline character left in the input buffer
            getline(cin, name);

            cout << "Enter code snippet (press Enter on an empty line to finish):\n";

            // Read multiple lines of code until an empty line is entered
            while (getline(cin, codeLine) && !codeLine.empty())
            {
                code += codeLine + '\n';
            }

            cout << "Enter tags (space-separated): ";
            string tagInput;
            getline(cin, tagInput);
            istringstream iss(tagInput);
            string tag;
            while (iss >> tag)
            {
                tags.push_back(tag);
            }

            // Add the snippet
            snippetManager.addSnippet(name, code, tags);
            break;
        }
        case 2:
        {
            string name;
            cout << "Enter snippet name: ";
            cin >> name;
            snippetManager.getSnippet(name);
            break;
        }
        case 3:
            snippetManager.listSnippets();
            break;
        case 4:
            snippetManager.listTags();
            break;
        case 5:
        {
            string tag;
            cout << "Enter tag to search: ";
            cin >> tag;
            snippetManager.searchByTag(tag);
            break;
        }
        case 6:
        {
            string name, newCode;
            vector<string> newTags;

            cout << "Enter snippet name to edit: ";
            cin >> name;

            cout << "Enter new code snippet (press Enter on an empty line to finish):\n";
            cin.ignore(); // Clear newline from the buffer
            string codeLine;
            while (getline(cin, codeLine) && !codeLine.empty())
            {
                newCode += codeLine + '\n';
            }

            cout << "Enter new tags (space-separated): ";
            string tagInput;
            getline(cin, tagInput);
            istringstream iss(tagInput);
            string tag;
            while (iss >> tag)
            {
                newTags.push_back(tag);
            }

            snippetManager.editSnippet(name, newCode, newTags);
            break;
        }
        case 7:
        {
            string name;
            cout << "Enter snippet name to remove: ";
            cin >> name;
            snippetManager.removeSnippet(name);
            break;
        }
        case 8:
            cout << "Exiting Code Snippet Manager. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 8.\n";
        }
    }

    return 0;
}
