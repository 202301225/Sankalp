#ifndef CODE_SNIPPET_MANAGER_H
#define CODE_SNIPPEY_MANAGER_H

#include <bits/stdc++.h>
using namespace std;

class CodeSnippetManager
{
private:
    unordered_map<string, pair<string, string>> snippets;
    string store_File;

public:
    CodeSnippetManager(string file = "snippets.txt");
    int closestSnippet( string s1,string s2);
    string findclosestSnippet( string input);
    void saveSnippets();
    void loadSnippets();
    void addSnippet(string snippetname, string codeSnippet, string tagOfSnippet);
    void getSnippet(string Snippetname);
    void listSnippets();
    void listTags();
    void searchByTag(string tag);
    void editSnippet(string Snippetname, string CodeOfSnippet, string SetOfTags);
    void removeSnippet(string Snippet_name);
    bool check_if_available(string name);
};

#endif
