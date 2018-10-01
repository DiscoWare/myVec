#include "myVec.h"
#include <utility>
#include <map>
using namespace std;

void test(const pair< char, myVec<int>& >& v)
{
    cout << "////////////////////////" << endl;
    cout << "Testing " << v.first << endl;
    cout << "////////////////////////" << endl;
    cout << "Size of " << v.first << ": " << v.second.size() << endl;
    cout << "Capacity of " << v.first << ": " << v.second.capacity() << endl;
    cout << "Elements of " << v.first << endl;
    for (int i = 0; i < v.second.size(); ++i)
    {
        cout << v.second[i] << endl;
    }
    
    cout << "TESTING OUT OF RANGE\n";
    try{
    cout << v.second[v.second.size()];
    }catch(invalid_argument e){
        cerr << e.what();
    }
    cout << endl << endl;
}

int main()
{
    myVec<int> a;
    for (unsigned int i = 0; i < 21; ++i)
    {
        a.insert(i + 1);
    }

    myVec<int> b(5);
    b.insert(1);

    pair< char, myVec<int>& > A('A', a);
    pair< char, myVec<int>& > B('B', b);

    map< char, myVec<int>& > vecMap;
    vecMap.insert(A);
    vecMap.insert(B);

    for (pair< char, myVec<int>& > v : vecMap)
    {
        test(v);
    }

    cout << "Making B equal to A. Testing B:\n";
    b = a;

    test(B);

    cout << "Deleting first two elements of B.\n";
    b.remove(0);
    b.remove(0);
    test(B);

    return 0;
}