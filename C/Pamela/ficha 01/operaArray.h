int *newReverse(int array[], int tamanho);
int elemNum(int array[], int tamanho, int valor);
int *unique(int *array, int tamanho);
int *deleteN(int array[], int tamanho, int position);

int *newReverse(int array[], int tamanho){
    int reverse[tamanho], k = 0;

    for(int i = (tamanho - 1); i >= 0; i--){
        reverse[k] = array[i];
        k++;
    }
    return(reverse);
}

int eleNum(int array[], int tamanho, int valor){
    int count = 0;

    for(int i = 0; i <= (tamanho - 1); i++){
        if (valor == array[i]){
            count++;
        }
    }
    return(count);
}

int *unique(int array[], int tamanho)
{
    int *aux = array;
    int count = 0;
    int k = 0;

    for (int i = 0; i < tamanho; i++) {
        count = 0;
        for (int j = 0; j < tamanho; j++) {
            if (array[i] == array[j])
                count++;
        }
        if (count == 1) {
            aux[k] = array[i];
            k++;
        }
    }
    return aux;
}

int *deleteN(int array[], int tamanho, int position){
    int new_array[(tamanho - 1)];
    int i;

    for(i = 0; i < position; i++){
        new_array[i] = array[i];
    }
    for(i = (position + 1); i <= tamanho; i++){
        new_array[i] = array[i];
    }
    return(new_array);
}
