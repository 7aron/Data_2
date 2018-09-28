#include <stdio.h> 


int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

      
        if (arr[mid] == x)
            return mid;

       
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

       
        return binarySearch(arr, mid + 1, r, x);
    }


    return -1;
}

int main(void)
{
    int arr[] = { 1, 3, 4, 15, 18, 28, 39 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 28;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not in array")
                    : printf("Element is present at index %d",
                                                    result);
    return 0;
} 
//End of ex1


//Start Ex2
// The running time of the program is O(n)

#include <iostream>

using namespace std;

class List
{
    struct Node
    {
        Node() : next(nullptr)
        {

        }
        Node* next;
        int data;
    };
    public:
    List() : start(nullptr), end(nullptr)
    {
    }
    void push_back(int x)
    {
        Node* t = new Node();
        t->data = x;
        if (start == nullptr)
        {
            start = end = t;
        }
        else
        {
            end->next = t;
            end = t;
        }
    }

    void reverse()
    {
        do_reverse(start, nullptr);
        swap(start, end);
    }

    void print()
    {
        do_print(start);
    }

    ~List()
    {
        destroy(start);
    }

    private:
    static void destroy(Node* now)
    {
        if (now == nullptr)
        {
            return;
        }

        destroy(now->next);
        delete now;
    }
    static void do_print(Node* now)
    {
        if (now == nullptr)
        {
            cout << endl;
            return;
        }
        cout << now->data << ' ';
        do_print(now->next);
    }
    static void do_reverse(Node* now, Node* prev)
    {
        if (now->next == nullptr)
        {
            now->next = prev;
            return;
        }
        do_reverse(now->next, now);
        now->next = prev;
    }
    Node* start;
    Node* end;
};

int main()
{
    List l;
    for (int i = 1; i <= 10; i++)
    {
        l.push_back(i);
    }
    l.print();
    l.reverse();
    l.print();


}

//End of ex2


//ex3


#include <iostream> 
#include <cmath>
using namespace std;


//Running time of both functions is O(n)






void findOPrec(double arr[], int left, int right)
{
    if (left < right)
    {
        if (abs(arr[left]) == abs(arr[right]))
        {
            cout << arr[left] << ' ' << arr[right] << endl;
            findOPrec(arr, left + 1, right - 1);
        }
        else if (abs(arr[left]) < abs(arr[right]))
        {
            findOPrec(arr, left, right - 1);
        }
        else
        {
            findOPrec(arr, left + 1, right);
        }
    }
};




int main()
{

    double arr[12] = { -100, -92, -36, -3, -1, 0, 1, 3, 6, 36, 100, 200 };

    findOPrec(arr, 0, 11);
    return 0;
};

//end of ex3

//ex4



#include <bits/stdc++.h> 
using namespace std; 
  

void printPairs(int arr[], int n)
{
    vector<int> v;


    for (int i = 0; i < n; i++)


        for (int j = i + 1; j < n; j++)


            if (abs(arr[i]) == abs(arr[j]))
                v.push_back(abs(arr[i]));

   
    if (v.size() == 0)
        return;


    sort(v.begin(), v.end());


    for (int i = 0; i < v.size(); i++)
        cout << -v[i] << " " << v[i] << "\n";
}

 
int main()
{
    int arr[] = { -19, -15, 4, 8, 9, -4, 1, -1, -8, -9, 10, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printPairs(arr, n);
    return 0;
}

//end of ex4



//ex6


// The running time of the program is O(n)

#include <iostream>

using namespace std;

class List
{
    struct Node
    {
        Node() : next(nullptr)
        {

        }
        Node* next;
        int data;
    };
    public:
    List() : start(nullptr), end(nullptr)
    {
    }
    void push_back(int x)
    {
        Node* t = new Node();
        t->data = x;
        if (start == nullptr)
        {
            start = end = t;
        }
        else
        {
            end->next = t;
            end = t;
        }
    }

    void reverse()
    {
        do_reverse(start, nullptr);
        swap(start, end);
    }



    void insertionSort()
    {
        Node* unsorted = start->next;
        Node* sortLast = start;

        while (unsorted != nullptr)
        {
            
            if (unsorted->data < start->data)
            {
                sortLast->next = unsorted->next;
                unsorted->next = start;
                start = unsorted;
                unsorted = sortLast->next;
                continue;
            }

            else
            {
                Node* temp = start;
                while (true)
                {
                    if (unsorted->data < temp->next->data)
                    {
                        sortLast->next = unsorted->next;
                        unsorted->next = temp->next;
                        temp->next = unsorted;
                        break;
                    }
                    else
                    {
                        temp = temp->next;
                    }
                    if (temp == unsorted)
                    {
                        sortLast = unsorted;
                        unsorted = unsorted->next;
                        break;
                    }
                }
            }
        }
    }




    void print()
    {
        do_print(start);
    }

    ~List()
    {
        destroy(start);
    }

    private:
    static void destroy(Node* now)
    {
        if (now == nullptr)
        {
            return;
        }

        destroy(now->next);
        delete now;
    }
    static void do_print(Node* now)
    {
        if (now == nullptr)
        {
            cout << endl;
            return;
        }
        cout << now->data << ' ';
        do_print(now->next);
    }
    static void do_reverse(Node* now, Node* prev)
    {
        if (now->next == nullptr)
        {
            now->next = prev;
            return;
        }
        do_reverse(now->next, now);
        now->next = prev;
    }
    Node* start;
    Node* end;
};

int main()
{
    List l;
    for (int i = 1; i <= 10; ++i)
    {
        l.push_back(i);
    }
    l.print();
    l.reverse();
    l.print();


}


//end of ex6
