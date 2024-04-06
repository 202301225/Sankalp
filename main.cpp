#include <bits/stdc++.h>

using namespace std;

class CodeSnippetManager
{
    private:
    unordered_map<string, pair<string, vector<string>>> snippets; // {name, {code, tags}}
    string storage_file;

    public:
    CodeSnippetManager(const string &file = "snippets.txt") : storage_file(file)//constructor of a class CodeSnippetManager
    {
        loadSnippets();
    }

    //This function to load snippet in the file
    void loadSnippets()
    {
        ifstream file(storage_file);//open file in the read mode
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
            int count = 0;
            cout << "Available snippets:\n";
            for (const auto &entry : snippets)
            {
                cout << ++count<<"->" << entry.first << '\n';
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
            cout << "Snippet '" << name << "' not found"<<endl;
        }
    }

};


int main()
{
    CodeSnippetManager snippetManager;

    while (true)
    {  
        cout<<"\n--------------------------------";
        cout << "\nCode Snippet Manager Menu:"<<endl;
        cout<<"--------------------------------"<<endl;
        cout << "Enter 1 for Add Snippet"<<endl;
        cout << "Enter 2 for Get Snippet"<<endl;
        cout << "Enter 3 for List Snippets"<<endl;
        cout << "Enter 4 for List Tags"<<endl;
        cout << "Enter 5 for Search by Tag"<<endl;
        cout << "Enter 6 for Edit Snippet"<<endl;
        cout << "Enter 7 for Remove Snippet"<<endl;
        cout << "Enter 8 for Exit"<<endl;
        cout<<"--------------------------------"<<endl;
        int choice;
        cout << "\nEnter your choice (1-8): ";
        cin >> choice;

        switch (choice)
        {
case 1:
{
    string SnippetName, CodeOfSnippet, codeOfSnippet;
    vector<string> tagForSnippet;

    cout << "Enter snippet Name: ";
    cin.ignore(); // Ignore newline character left in the input buffer
    getline(cin, SnippetName);

    cout << "Enter code snippet (## to finish your Snippet Code):" << endl;

    // Read multiple lines of code until '#' symbol is entered twice
    while (true)
    {
        string line;
        getline(cin, line);
        if (line == "##") // Check if '#' symbol has been entered twice
            break;
        codeOfSnippet += line + '\n';
    }

    cout << "Enter tags (space-separated) for Your Snippet: ";
    string str;
    getline(cin, str);
    istringstream iss(str);
    string tag;
    while (iss >> tag)
    {
        tagForSnippet.push_back(tag);
    }

    // Add the snippet
    snippetManager.addSnippet(SnippetName, codeOfSnippet, tagForSnippet);
    cout << "\n*------------------------------------------------------------*" << endl;
    break;
}

        case 2:
        {
            string name;
            cout << "Enter Snippet Name that You Want: ";
            cin >> name;
            snippetManager.getSnippet(name);
            cout << "------------------------------------------------------------"<<endl;
            break;
        }
        case 3:
            snippetManager.listSnippets();
            cout << "------------------------------------------------------------"<<endl;
            break;
        case 4:
            snippetManager.listTags();
            cout << "------------------------------------------------------------"<<endl;
            break;
        case 5:
        {
            string tag;
            cout << "Enter tag that you search: ";
            cin >> tag;
            snippetManager.searchByTag(tag);
            cout << "------------------------------------------------------------"<<endl;
            break;
        }
        case 6:
        {
            string name, newCode;
            vector<string> newTags;

            cout << "Enter snippet name that you edit: ";
            cin >> name;

            cout << "Enter new code for your snippet (press Enter on an empty line to finish):"<<endl;
            cin.ignore(); // Clear newline from the buffer
            string codeLine;
            while (getline(cin, codeLine) && !codeLine.empty())
            {
                newCode += codeLine + '\n';
            }

            cout << "Enter new tag (space-separated) after you edit Code of your Snippet: ";
            string tagInput;
            getline(cin, tagInput);
            istringstream iss(tagInput);
            string tag;
            while (iss >> tag)
            {
                newTags.push_back(tag);
            }

            snippetManager.editSnippet(name, newCode, newTags);
            cout << "------------------------------------------------------------"<<endl;
            break;
        }
        case 7:
        {
            string name;
            cout << "Enter snippet name that you remove: ";
            cin >> name;
            snippetManager.removeSnippet(name);
            cout << "------------------------------------------------------------"<<endl;
            break;
        }
        case 8:
            cout << "Exit From Snippet Manager! Goodbye!"<<endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 8"<<endl;
        }

    }

    return 0;
}
