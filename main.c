#include <stdio.h>
#include <stdlib.h>


static int amountNumbers = 10000;

/**< Bruges til at udskrive et array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
/**< Bruges til at generere X antal tilfældige nummere */
int * ManyNumbers(){
   static int mNumbers[10000];
     for(int i = 0; i<amountNumbers; i++)
        mNumbers[i] = rand();
        return mNumbers;

}
/**< 1000 tal = 0,053 | 10000 tal = 2,415 | 100000 tal = 14,032 */
int * sort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        //Finder det mindste element i det usorteret array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        //Bytter det mindste element ud med det første
        swap(&arr[min_idx], &arr[i]);
    }
    return arr;
}
//aaa
int main()
{
    int *numbers, *sortedNumbers;
    numbers = ManyNumbers(amountNumbers);
    sortedNumbers = sort(numbers, amountNumbers);
    printArray(sortedNumbers, amountNumbers);

    return 0;
}
