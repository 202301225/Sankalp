#include <bits/stdc++.h>
#include "CodeSnippetManager.h"
using namespace std;

CodeSnippetManager::CodeSnippetManager(string file) : store_File(file)
    {

        loadSnippets();
    }