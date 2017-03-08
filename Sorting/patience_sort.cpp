#include <bits/stdc++.h>
using namespace std;
template <class T>
struct pile_less
{
    bool operator()(const stack<T> &pile1, const stack<T> &pile2) const
    {
        return pile1.top() < pile2.top();
    }
};
template <class T>
struct pile_greater
{
    bool operator()(const stack<T> &pile1, const stack<T> &pile2) const
    {
        return pile1.top() > pile2.top();
    }
};
//Complexity: O(nlogn)
template <class T>
void patience_sort(T first, T last)
{
    typedef typename iterator_traits<T>::value_type E;
    typedef stack<E> Pile;
    vector<Pile> piles;
    for (T it = first; it != last; it++)
    {
        E &x = *it;
        Pile newPile;
        newPile.push(x);
        typename vector<Pile>::iterator i = lower_bound(piles.begin(), piles.end(), newPile, pile_less<E>());
        if (i != piles.end())
            i->push(x);
        else
            piles.push_back(newPile);
    }
    // priority queue allows us to merge piles efficiently
    // we use greater-than comparator for min-heap
    make_heap(piles.begin(), piles.end(), pile_greater<E>());
    for (T it = first; it != last; it++)
    {
        pop_heap(piles.begin(), piles.end(), pile_greater<E>());
        Pile &smallPile = piles.back();
        *it = smallPile.top();
        smallPile.pop();
        if (smallPile.empty())
            piles.pop_back();
        else
            push_heap(piles.begin(), piles.end(), pile_greater<E>());
    }
    assert(piles.empty());
}
int main()
{
    int a[] = {4, 65, 2, -31, 0, 99, 83, 782, 1};
    patience_sort(a, a + sizeof(a) / sizeof(*a));
    copy(a, a + sizeof(a) / sizeof(*a), ostream_iterator<int>(cout, ", "));
    cout << endl;
    return 0;
}