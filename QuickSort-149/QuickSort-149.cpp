#include <iostream>

using namespace std;


int a[20]; 
int cmp_count = 0;
int mov_count = 0; 
int n;

void input() {
    while (true) {
        cout << " Masukkan Panjang Element Array : ";
        cin >> n;
        if (n <= 20)
            break;
        else
            cout << "\n Maksimuam panjang array addalah 20";
      
    }
    cout << "\n_______________________________" << endl;
    cout << "\nEnter Array Element " << endl;
    cout << "\n_______________________________" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> a[i];
    }
}

void swap(int x, int y)
{
    int temp;
    temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void q_sort(int low, int high)
{
    int pivot, i, j;
    if (low > high)
        return;
    
    pivot = a[low];

    i = low + 1;
    j = high;

    while (i <= j)
    {
        while ((a[i] <= pivot) && (j <= high))
        {
            i++;
            cmp_count++;
        }
        cmp_count++;

     while ((a[j] > pivot) && (j >= low))
        {
            j--;
            cmp_count++;
     }
        cmp_count++;

        if (i < j) {
         swap(i, j);
         mov_count++;
        }
    }
    if (low < j)
    {
        swap(low, j);
        mov_count++;
    }
    q_sort(low, j - 1);
    q_sort(j + 1, high);
}
void display() {
    cout << "\n----------------------------------" << endl;
    cout << " Sorted Array " << endl;
    cout << "\n----------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";

    }
    cout << "\nNumber Of Comparasions : " << cmp_count << endl;
    cout << " Number of data movements : " << mov_count << endl;
}

int main()
{
    input();
    q_sort(0, n - 1);
    display();
    system("Pause");

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
