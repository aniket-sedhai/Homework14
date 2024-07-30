//
//  main.cpp
//  Homework14
//
//  Created by Aniket Sedhai on 7/14/24.
//

#include <iostream>
#include <algorithm>
#include <list>

void PrintList(std::list<int>& my_list);
void sort_by_even_odd(std::list<int>& my_list);

int main(void)
{
    std::list<int> a {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::cout << "a after intializing the list: ";
    PrintList(a);
    
    std::list<int> b {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::cout << "b after initializing the list: ";
    PrintList(b);
    
    b.reverse();
    std::cout << "b after reversing the list: ";
    PrintList(b);
    
    std::list<int> k = a;
    std::cout << "Using copy constructor to define list k using list a: ";
    PrintList(k);
    
    std::list<int> m(b.begin(), b.end());
    std::cout << "Using list b's iterator to define list m: ";
    PrintList(m);
    
    k.merge(m);
    std::cout << "After merging list m into k ";
    PrintList(k);
    
    k.unique();
    std::cout << "After removing duplicates from k: ";
    PrintList(k);
    
    std::list<int> d = a;
    std::cout << "Using copy constructor to define list d using list a: ";
    PrintList(d);
    
    std::list<int> c(b.begin(), b.end());
    std::cout << "Using list b's iterator to define list c: ";
    PrintList(c);
    
    std::list<int> e(7 , 9);
    std::cout << "Defining list e with 7 values all 9: ";
    PrintList(e);
    
    std::list<int> f;
    
    for (int i = 1; i <= 30; ++i)
    {
        f.push_back(i*i);
    }
    std::cout << "List f with squares for 1 through 30: ";
    PrintList(f);
    
    std::stable_partition(f.begin(), f.end(), [](int n) {return n % 2 == 0; });
    std::cout << "List f parted into even (first half) and odd(remaining): ";
    PrintList(f);
    
    std::list<int>::iterator iter;
    
    for (iter = f.begin(); iter != f.end();)
    {
        if (*iter % 2 != 0)
        {
            f.erase(iter, f.end());
            break;
        }
        else
        {
            ++iter;
        }
    }
    
    std::cout << "List f after erasing the odd elements: ";
    PrintList(f);
    
    
    std::list<int> h;
    
    for (int i = 1; i <= 50; ++i)
    {
        h.push_back(i*i);
    }
    
    std::cout << "List h after inserting squares of 1 through 50: ";
    PrintList(h);
    
    sort_by_even_odd(h);
    std::cout << "List h after partitioning and sorting as even group and odd group: ";
    PrintList(h);
    
    
    std::erase_if(h, [](int n) {return n % 2 != 0; });
    std::cout << "List h after deleting odd numbers: ";
    PrintList(h);
}

void sort_by_even_odd(std::list<int>& my_list)
{
    
    std::list<int> temp_even_list;
    std::list<int> temp_odd_list;
    std::list<int> temp_my_list;
    
    for (int val: my_list)
    {
        if (val % 2 == 0)
        {
            temp_even_list.push_back(val);
        }
        else
        {
            temp_odd_list.push_back(val);
        }
    }
        
    temp_even_list.sort();
    temp_odd_list.sort();
    
    temp_my_list.merge(temp_even_list);
    temp_my_list.splice(temp_my_list.end(), temp_odd_list);
    
    my_list.swap(temp_my_list);

    return;
}

void PrintList(std::list<int>& my_list)
{
    for (int i: my_list)
    {
        std::cout << i << " ";
    }
    
    std::cout << std::endl;
    
    return;
}
