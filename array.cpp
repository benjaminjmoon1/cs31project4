#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value)
{
    if (n < 0)  // Check for invalid input
        return -1;
    for (int i = 0; i < n; i++)  // Add value to each element
    {
        a[i] += value;
    }
    return n;  // Return number of elements processed
}

int lookup(const string a[], int n, string target)
{
    if (n < 0)  // Check for invalid input
        return -1;
    for (int i = 0; i < n; i++)  // Search for target string
    {
        if (a[i] == target)
        {
            return i;  // Return position if found
        }
    }
    return -1;  // Return -1 if not found
}

int positionOfMax(const string a[], int n)
{
    if (n <= 0)  // Check for empty array or invalid input
        return -1;
    int temp = 0;  // Keep track of position of largest string
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[temp])  // Compare strings lexicographically
            temp = i;
    }
    return temp;  // Return position of largest string
}

int rotateLeft(string a[], int n, int pos)
{
    if (n < 0 || pos < 0 || pos >= n)  // Check for invalid inputs
        return -1;
    string temp = a[pos];  // Save the element at pos
    for (int i = pos; i < n - 1; i++)  // Shift elements left
    {
        a[i] = a[i + 1];
    }
    a[n - 1] = temp;  // Put saved element at end
    return pos;
}

int countRuns(const string a[], int n)
{
    if (n < 0)  // Check for invalid input
        return -1;
    if (n == 0)  // Check for empty array
        return 0;

    int runs = 1;  // Start with first run
    for (int i = 1; i < n; i++)  // Count when consecutive elements differ
    {
        if (a[i] != a[i - 1])
            runs++;
    }
    return runs;
}

int flip(string a[], int n)
{
    if (n < 0)  // Check for invalid input
    {
        return -1;
    }
    if (n == 0)  // Check for empty array
        return 0;
    for (int i = 0; i < n / 2; i++)  // Swap elements from ends toward middle
    {
        string temp = a[i];
        a[i] = a[n - i - 1];
        a[n - 1 - i] = temp;
    }
    return n;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0)  // Check for invalid inputs
        return -1;

    int shorter = (n1 < n2) ? n1 : n2;  // Find shorter length
    for (int i = 0; i < shorter; i++)  // Compare elements until difference found
    {
        if (a1[i] != a2[i])
            return i;
    }
    return shorter;  // Return shorter length if no differences found
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0)  // Check for invalid inputs
        return -1;
    if (n2 == 0)  // Empty sequence is always a subsequence
        return 0;
    if (n2 > n1)  // Subsequence can't be longer than main sequence
        return -1;

    for (int i = 0; i <= n1 - n2; i++)  // Check each possible starting position
    {
        bool found = true;
        for (int j = 0; j < n2; j++)  // Check if subsequence matches at this position
        {
            if (a1[i + j] != a2[j])
            {
                found = false;
                break;
            }
        }
        if (found)
            return i;  // Return starting position if match found
    }
    return -1;  // Return -1 if no match found
}

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0)  // Check for invalid inputs
        return -1;

    for (int i = 0; i < n1; i++)  // Check each element in first array
    {
        for (int j = 0; j < n2; j++)  // Compare with each element in second array
        {
            if (a1[i] == a2[j])
                return i;  // Return position of first match
        }
    }
    return -1;  // Return -1 if no match found
}

int separate(string a[], int n, string separator)
{
    if (n < 0)  // Check for invalid input
        return -1;

    int left = 0;
    int right = n - 1;

    while (left <= right)  // Partition array around separator
    {
        while (left <= right && a[left] < separator)  // Find element >= separator
            left++;

        while (left <= right && a[right] >= separator)  // Find element < separator
            right--;

        if (left < right)  // Swap elements if needed
        {
            string temp = a[left];
            a[left] = a[right];
            a[right] = temp;

            left++;
            right--;
        }
    }
    return left;  // Return position of first element >= separator
}
int main()
{
    // Test appendToAll function
    // Tests adding a string to end of each array element
    string arr1[5] = { "a", "b", "c", "d", "e" };
    assert(appendToAll(arr1, 5, "!") == 5);  // Normal case: append "!" to all elements
    assert(arr1[0] == "a!" && arr1[4] == "e!");  // Verify first and last elements
    assert(appendToAll(arr1, -1, "x") == -1);  // Error case: negative array size
    assert(appendToAll(arr1, 0, "x") == 0);  // Edge case: empty array

    // Test lookup function
    // Tests finding position of a target string in array
    string arr2[5] = { "kamala", "donald", "jd", "tim", "jill" };
    assert(lookup(arr2, 5, "tim") == 3);  // Normal case: find existing element
    assert(lookup(arr2, 5, "joe") == -1);  // Normal case: element not in array
    assert(lookup(arr2, 3, "jill") == -1);  // Normal case: element outside search range
    assert(lookup(arr2, -1, "tim") == -1);  // Error case: negative array size
    assert(lookup(arr2, 0, "tim") == -1);  // Edge case: empty array

    // Test positionOfMax function
    // Tests finding position of largest string
    string arr3[6] = { "doug", "kamala", "melania", "usha", "gwen", "donald" };
    assert(positionOfMax(arr3, 6) == 3);  // Normal case: find max in full array
    assert(positionOfMax(arr3, 2) == 1);  // Normal case: find max in partial array
    assert(positionOfMax(arr3, -1) == -1);  // Error case: negative array size
    assert(positionOfMax(arr3, 0) == -1);  // Edge case: empty array
    string maxArr[4] = { "tim", "tim", "tim", "tim" };
    assert(positionOfMax(maxArr, 4) == 0);  // Edge case: all elements equal
    assert(positionOfMax(maxArr, 1) == 0);  // Edge case: single element

    // Test rotateLeft function
    // Tests rotating array elements left from given position
    string arr4[5] = { "kamala", "donald", "jd", "tim", "joe" };
    assert(rotateLeft(arr4, 5, 1) == 1);  // Normal case: rotate from position 1
    assert(arr4[1] == "jd" && arr4[4] == "donald");  // Verify rotation results
    assert(rotateLeft(arr4, -1, 1) == -1);  // Error case: negative array size
    assert(rotateLeft(arr4, 5, -1) == -1);  // Error case: negative position
    assert(rotateLeft(arr4, 5, 5) == -1);  // Error case: position >= array size

    // Test countRuns function
    // Tests counting sequences of consecutive identical elements
    string arr5[9] = { "melania", "doug", "gwen", "gwen", "jill", "jill", "jill", "gwen", "gwen" };
    assert(countRuns(arr5, 9) == 5);  // Normal case: multiple runs of different lengths
    string arr5a[3] = { "tim", "tim", "tim" };
    assert(countRuns(arr5a, 3) == 1);  // Edge case: single run
    assert(countRuns(arr5, -1) == -1);  // Error case: negative array size
    assert(countRuns(arr5, 0) == 0);  // Edge case: empty array
    string singleRun[1] = { "a" };
    assert(countRuns(singleRun, 1) == 1);  // Edge case: single element

    // Test flip function
    // Tests reversing elements in array
    string arr6[6] = { "kamala", "doug", "", "jill", "jd", "donald" };
    assert(flip(arr6, 4) == 4);  // Normal case: flip first 4 elements
    assert(arr6[0] == "jill" && arr6[3] == "kamala");  // Verify flip results
    assert(flip(arr6, -1) == -1);  // Error case: negative array size
    assert(flip(arr6, 0) == 0);  // Edge case: empty array

    // Test differ function
    // Tests finding first position where two arrays differ
    string arr7a[6] = { "kamala", "doug", "", "jill", "jd", "donald" };
    string arr7b[5] = { "kamala", "doug", "donald", "", "jd" };
    assert(differ(arr7a, 6, arr7b, 5) == 2);  // Normal case: arrays differ at position 2
    assert(differ(arr7a, 2, arr7b, 1) == 1);  // Normal case: shorter length comparison
    assert(differ(arr7a, -1, arr7b, 5) == -1);  // Error case: negative array size

    // Test subsequence function
    // Tests finding a sequence within another sequence
    string arr8a[6] = { "kamala", "tim", "usha", "gwen", "donald", "jd" };
    string arr8b[3] = { "tim", "usha", "gwen" };
    assert(subsequence(arr8a, 6, arr8b, 3) == 1);  // Normal case: subsequence exists
    string arr8c[2] = { "kamala", "gwen" };
    assert(subsequence(arr8a, 5, arr8c, 2) == -1);  // Normal case: subsequence doesn't exist
    assert(subsequence(arr8a, 6, arr8b, 0) == 0);  // Edge case: empty subsequence
    assert(subsequence(arr8a, -1, arr8b, 3) == -1);  // Error case: negative array size

    // Test lookupAny function
    // Tests finding first element that appears in both arrays
    string arr9a[6] = { "kamala", "tim", "usha", "gwen", "donald", "jd" };
    string arr9b[4] = { "donald", "melania", "gwen", "tim" };
    assert(lookupAny(arr9a, 6, arr9b, 4) == 1);  // Normal case: common element exists
    string arr9c[2] = { "jill", "joe" };
    assert(lookupAny(arr9a, 6, arr9c, 2) == -1);  // Normal case: no common elements
    assert(lookupAny(arr9a, -1, arr9b, 4) == -1);  // Error case: negative array size

    // Test separate function
    // Tests partitioning array around a separator value
    string sepArr[6] = { "joe", "joe", "joe", "joe", "joe", "joe" };
    int sepResult = separate(sepArr, 6, "joe");
    assert(sepResult >= 0 && sepResult <= 6);  // Edge case: all elements equal to separator

    string arr10[6] = { "doug", "kamala", "melania", "usha", "gwen", "donald" };
    int pos = separate(arr10, 6, "joe");
    assert(pos >= 0 && pos <= 6);  // Normal case: mixed elements
    // Verify partition: elements before pos are < "joe"
    for (int i = 0; i < pos; i++)
        assert(arr10[i] < "joe");
    // Verify partition: elements after pos are >= "joe"
    for (int i = pos; i < 6; i++)
        assert(arr10[i] >= "joe");

    cout << "All tests succeeded" << endl;
}