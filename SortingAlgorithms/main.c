#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

       srand(time(NULL));
    int num_sizes = 3;
    int sizes[] = {50000, 100000, 250000};

    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int *arr = malloc(size * sizeof(int));

        if (arr == NULL) {
            printf("Hukommelse kunne ikke allokeres.\n");
            return 1;
        }

        int lower = 1, upper = 50000;

        generateRandomNumbers(arr, size, lower, upper);

        clock_t startTime, endTime;
        double timeElapsed;

        printf("array size: %d\n", size);
         printf("\n-------------------------------------------------------");

        // Selection Sort
        startTime = clock();
        SelectionSort(size, arr);
        endTime = clock();
        timeElapsed = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        printf("\nSelection Sort: %f seconds\n", timeElapsed);

        // Insertion Sort
        startTime = clock();
        InsertionSort(size, arr);
        endTime = clock();
        timeElapsed = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        printf("Insertion Sort: %f seconds\n", timeElapsed);

        // Merge Sort
        startTime = clock();
        MergeSort(arr, 0, size - 1);
        endTime = clock();
        timeElapsed = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        printf("Merge Sort: %f seconds\n", timeElapsed);

        free(arr);
        printf("\n-------------------------------------------------------\n");
    }


    // // Initialiserer tilfældig nummergenerator
    // srand(time(0));

    // // Antallet af elementer i arrayet
    // int size = 50000;

    // // Allokerer hukommelse til arrayet
    // int *arr = malloc(size * sizeof(int));

    // if (arr == NULL)
    // {
    //     printf("Hukommelse kunne ikke allokeres.\n");
    //     return 1;
    // }

    // // Definerer de nedre og øvre grænser for tilfældige tal
    // int lower = 1, upper = 50000;

    // // Genererer tilfældige tal og gemmer dem i arrayet
    // generateRandomNumbers(arr, size, lower, upper);

    // // for (int i = 0; i < size; i++)
    // // {
    // //     printf("arr: %d\n", arr[i]);
    // // }
    // printf("-----------------\n");

    // clock_t startTime = clock();
    //  //selecion sort
    // // SelectionSort(size, arr);

    // // insertion sort
    //  InsertionSort(size, arr);

    // MergeSort(arr, 0, size-1);



    // clock_t endTime = clock();
    // double timeElapsed = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    // printf("Elapsed time: %f seconds\n", timeElapsed);




    // // Frigør hukommelsen
    // free(arr);
}

// generate n size array with random numbers
void generateRandomNumbers(int *arr, int size, int lower, int upper)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }
}

void SelectionSort(int size, int *sourceArr)
{
    int *unsortedarray = sourceArr;
    int *sorted = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {

        int minIndex = i;

        for (int n = i + 1; n < size; n++)
        {

            if (unsortedarray[n] < unsortedarray[minIndex])
            {
                minIndex = n;
            }
        }

        if (minIndex != i)
        {
            int temp = unsortedarray[i];
            unsortedarray[i] = unsortedarray[minIndex];
            unsortedarray[minIndex] = temp;
        }
    }

    // for (int i = 0; i < size; i++)
    // {
    //     printf("sorted: %d\n", unsortedarray[i]);
    // }

    free(sorted);
}

void InsertionSort(int size, int *sourceArr)
{
    int *unsortedarray = sourceArr;
    int *sorted = malloc(size * sizeof(int));

    for (int i = 1; i < size; i++)
    {
        int current = unsortedarray[i];
        int j;

        for (j = i - 1; j >= 0; j--)
        {

            if (unsortedarray[j] > current)
            {
                unsortedarray[j + 1] = unsortedarray[j];
            }
            else
            {
                break;
            }
        }

        unsortedarray[j + 1] = current;
    }

    // for (int i = 0; i < size; i++)
    // {
    //     printf("sorted: %d\n", unsortedarray[i]);
    // }

    free(sorted);
}

void MergeSort(int sourceArr[], int left, int right)
{
    // array already sorted
    if (left < right)
    {
        // find middle index
        int middle = left + (right - left) / 2;

        // recursively sort the two arrays
        MergeSort(sourceArr, left, middle);
        MergeSort(sourceArr, middle + 1, right);

        // merge the halves together
        merge(sourceArr, left, right, middle);
    }
}

void merge(int source[], int left, int right, int middle)
{

    // create two subarrays
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    int *leftArr = (int *)malloc(leftSize * sizeof(int));
    int *rightArr = (int *)malloc(rightSize * sizeof(int));

    // copy to left array
    for (int i = 0; i < leftSize; i++)
    {
        leftArr[i] = source[left + i];
    }

    // copy to right array
    for (int j = 0; j < rightSize; j++)
    {
        rightArr[j] = source[middle + 1 + j];
    }

    int leftIterator, rightIterator, sourceIterator;
    leftIterator = rightIterator = sourceIterator = 0;
    sourceIterator = left;

    // merge first part
    for (; leftIterator < leftSize && rightIterator < rightSize; sourceIterator++)
    {
        if (leftArr[leftIterator] <= rightArr[rightIterator])
        {
            source[sourceIterator] = leftArr[leftIterator];
            leftIterator++;
        }
        else
        {
            source[sourceIterator] = rightArr[rightIterator];
            rightIterator++;
        }
    }

    // merge remaining left part
    for (; leftIterator < leftSize; leftIterator++, sourceIterator++)
    {
        source[sourceIterator] = leftArr[leftIterator];
    }

    // merge remaining right part
    for (; rightIterator < rightSize; rightIterator++, sourceIterator++)
    {
        source[sourceIterator] = rightArr[rightIterator];
    }

    free(rightArr);
    free(leftArr);
}
