#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Stack
{
public:
    void Push(T item)
    {
        _vec.push_back(item);
    }

    void Pop()
    {
        _vec.pop_back();
    }

    T Top()
    {
        int size = Size();
        return _vec[size - 1];
    }

    int Size()
    {
        return _vec.size();
    }

    bool IsEmpty()
    {
        return Size() == 0;
    }

private:
    vector<T> _vec;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        Stack<char> charContainer;
        char* arr = new char[100005];
        cin.getline(arr, 100005);

        int index = 0;
        while (1)
        {
            if (arr[index] == '\0') break;

            if (charContainer.IsEmpty() == false)
            {
                if (charContainer.Top() == arr[index])
                {
                    charContainer.Pop();
                }
                else
                {
                    charContainer.Push(arr[index]);
                }
            }
            else
            {
                charContainer.Push(arr[index]);
            }

            index++;
        }

        if (charContainer.IsEmpty()) cnt++;
    }

    cout << cnt;


    return 0;
}

// 비교해서 다른 문자인 경우 push 해줘야한다.
// top의 index는 size - 1이어야 한다.