#include <iostream>
#include <string>
#include <fstream> // <- include
using namespace std;

// A. Write program to process binary file.

// A1. (max 6 points) Given binary file of integers. 
// Return first odd number right after an even number. 
// Example 1. {1,8,4,5,6}→5. Example 2. {2,8,4,12,6}→0 (no odd numbers found). 
// Example 3. {1,3,5}→0 (no even numbers found).

// A2. (max 10 points) Given binary file of records of size 14 of the following structure: 
// {text: up to 10 bytes, including NULL character, number: int (4 bytes)}. 
// Print all texts with the maximum number. 
// Example 1. [(“alpha”,3),(“abc”,5),(“beta”,4),(“gamma”,5)]→abc, gamma. Example 2. [(“one”,3),(“abc”,5),(“two”,4)] →abc.

void createBinFiles(const char* filename, int arr[], int arrSize)
{
    fstream file(filename, ios::out | ios::binary);
    if (file.is_open())
    {
        for (int i = 0; i < arrSize; i++)
            file.write((char*)&arr[i], 4);
        file.close();
    }
}

int returnOdd(const char* filename)
{
    int returnValue = 0;
    fstream f(filename, ios::in | ios::binary);
    if (f.is_open())
    {
        int num;
        bool isEven = false;
        while(f)
        {
            f.read((char*)&num, 4);
            if (isEven)
            {
                if (num % 2 != 0)
                {
                    returnValue = num;
                    break;
                }
            }

            if (num % 2 == 0)
            {
                isEven = true;
            }
        }  
        f.close();
    }
    return returnValue;
}



int main()
{
    // int arr1[] = {1,8,4,5,6};
    // int arr2[] = {2,8,4,12,6};
    // int arr3[] = {1,3,5};
    // createBinFiles("example1.bin", arr1, 5);
    // createBinFiles("example2.bin", arr2, 5);
    // createBinFiles("example3.bin", arr2, 3);

    cout << returnOdd("example1.bin") << endl;
    cout << returnOdd("example2.bin") << endl;
    cout << returnOdd("example3.bin") << endl;
    


    return 0;
}