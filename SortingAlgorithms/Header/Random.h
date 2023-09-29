
 void generaterandomnumbers(int *arr, int size, int lower, int upper) {
     for (int i = 0; i < size; ++i) {
         arr[i] = (rand() % (upper - lower + 1)) + lower;
     }
 }
