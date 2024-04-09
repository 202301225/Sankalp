#include <bits/stdc++.h>
#include "CodeSnippetManager.h"
using namespace std;

bool CodeSnippetManager::check_if_available(string name)
{

    auto it1 = snippets.find(name);

    return it1 == snippets.end();
}
