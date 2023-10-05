#include <iostream> //Header File
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Start of the main function
    list<int> li;
    // Insertion (at end)
    li.push_back(10);
    li.push_back(15);
    li.push_back(7);
    for (auto it = li.begin(); it != li.end(); it++)
    { // Print from left to right
        cout << *it << " ";
    }
    cout << endl;
    // Insertion (at middle)
    auto it1 = li.begin();
    advance(it1, 1);
    li.insert(it1, 20);
    for (auto it = li.begin(); it != li.end(); it++)
    { // Print from left to right
        cout << *it << " ";
    }
    cout << endl;
    // Deletion (in middle)
    auto j = li.begin();
    advance(j, 2);
    li.erase(j);
    for (auto it = li.begin(); it != li.end(); it++)
    { // Print from left to right
        cout << *it << " ";
    }
    cout << endl;
    li.push_back(20);
    li.push_back(2);
    li.push_back(35);
    li.push_back(18);
    li.push_back(2);
    li.push_back(2);
    for (auto it = li.begin(); it != li.end(); it++)
    { // Print from left to right
        cout << *it << " ";
    }
    cout << endl;
    // Sort (in ascending order)
    li.sort();
    for (auto it = li.begin(); it != li.end(); it++)
    { // Print from left to right
        cout << *it << " ";
    }
    cout << endl;
    // Reverse
    li.reverse();
    for (auto it = li.begin(); it != li.end(); it++)
    { // Print from left to right
        cout << *it << " ";
    }
    cout << endl;
    // Searching
    int element = 100;
    auto it2 = find(li.begin(), li.end(), element);
    if (it2 != li.end())
    {
        cout << element << " is found" << endl;
    }
    else
    {
        cout << element << " is not found" << endl;
    }
    element = 10;
    auto it3 = find(li.begin(), li.end(), element);
    if (it3 != li.end())
    {
        cout << element << " is found" << endl;
    }
    else
    {
        cout << element << " is not found" << endl;
    }
    // Counting
    element = 2;
    int n = count(li.begin(), li.end(), element);
    cout << element << " occurs " << n << " times." << endl;
    // Minimum Element
    int min_value = *min_element(li.begin(), li.end());
    cout << "Minimum Value is " << min_value << endl;
    // Maximum Element
    int max_value = *max_element(li.begin(), li.end());
    cout << "Maximum Value is " << max_value << endl;
}

// Linked List : STL (Standard Template Library) is a library of container classes, algorithms, and iterators. It is a generalized library and so, its components are parameterized. A working knowledge of template classes is a prerequisite for working with STL.
