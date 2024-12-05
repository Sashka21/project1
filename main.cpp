#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;


// -------------------- LOS_ARR --------------------
void los_arr(int arr[], int n) {

    srand(time(0));

    for(int i = 0; i < n; i++) {
        arr[i] = (rand()*rand());
    }

}

// -------------------- WYPISZ_ARR --------------------
void wypisz_arr(int arr[], int n) {

    cout << endl << endl << "ARR[" << n << "]: \n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }

}

// -------------------- TIMER --------------------
void timer(double start_clock) {

    double result_time = (clock() - start_clock) / CLOCKS_PER_SEC;
    cout << "\tTime: " << result_time;

}

// --------------------- INSERT SORT ---------------------
void insert_sort(int arr[], int n) {

    int p;

    for (int i = 1; i < n; i++) {
        if(arr[i] < arr[i-1]) {
            for (int j = 0; j < i; j++) {
                if(arr[j] > arr[i]) {
                    for(int k = i; k > j; k--) {
                        p = arr[k];
                        arr[k] = arr[k-1];
                        arr[k-1] = p;
                    }
                    break;
                }
            }
        }
        /*cout << endl << endl;     // - Wypisac array po kazdym nowym wprowadzeniu liczby
        for (int j = 0; j < n; j++) {
            cout << arr[j] << "\t";
        }*/
    }
}

// ------------------------- SHELL_SORT -------------------------
void shell_sort(int arr[], int n) {

    int dystance;

    int dod_zmienna, k=0;

    dystance = n; // Ciąg Shella

    while(dystance > 1) {

        dystance = dystance / 2; // - CIĄG SHELLA

        for (int i = dystance; i < n; i++) {
                for(int j = i; j > dystance-1; j = j-dystance) {
                    if(arr[j] < arr[j-dystance]) {
                        dod_zmienna = arr[j];
                        arr[j] = arr[j-dystance];
                        arr[j-dystance] = dod_zmienna;
                    }
                    else{
                        break;
                    }
                }
        }

        /*
        k++;
        cout<< "\n\n" << k << ") D = " << dystance << "\n"; // - Wypisac array po kazdym nowym dystancje
        for(int i = 0; i < n; i++) {
            cout<< arr[i] << " ";
        }
        //*/

    }
}

// ------------------------- SHELL_HIBBARD_SORT (O(n^3/2)) -------------------------
void shell_hibbard_sort(int arr[], int n) {

    int dystance;

    int dod_zmienna, k=0;

    int d = 2;
    while(d < n) {
        d = d*2;
        k++;
    }
    dystance = d-1; // CIĄG HIBBARDA (Przyrost O(n^(3/2)))
    //*/

    k = 0;
    while(dystance > 1) {

        dystance = ((dystance + 1) / 2 ) - 1; // - CIĄG HIBBARDA

        for (int i = dystance; i < n; i++) {
                for(int j = i; j > dystance-1; j = j-dystance) {
                    if(arr[j] < arr[j-dystance]) {
                        dod_zmienna = arr[j];
                        arr[j] = arr[j-dystance];
                        arr[j-dystance] = dod_zmienna;
                    }
                    else{
                        break;
                    }
                }
        }

        /*k++;
        cout<< "\n\n" << k << ") D = " << dystance << "\n"; // - Wypisac array po kazdym nowym dystancje
        for(int i = 0; i < n; i++) {
            cout<< arr[i] << " ";
        }
        //*/

    }
}

// ------------------------- SHELL_KNUT_SORT (O(n^5/4))-------------------------
void shell_knut_sort(int arr[], int n) {

    int dystance = 0, dod_zmienna, k = 0;

    while(dystance < n) {
        k++;
        dystance = (pow(3, k) - 1) / 2;

    }
    k--;

    while(dystance > 1) {

        dystance = (pow(3, k)-1) / 2;

        for (int i = dystance; i < n; i++) {
                for(int j = i; j > dystance-1; j = j-dystance) {
                    if(arr[j] < arr[j-dystance]) {
                        dod_zmienna = arr[j];
                        arr[j] = arr[j-dystance];
                        arr[j-dystance] = dod_zmienna;
                    }
                    else{
                        break;
                    }
                }
        }

        /*
        cout<< "\n\n" << k << ") D = " << dystance << "\n"; // - Wypisac array po kazdym nowym dystancje
        for(int i = 0; i < n; i++) {
            cout<< arr[i] << " ";
        }

        //*/
        k--;
    }
}

// ------------------------- SHELL_SEDGEWICKA_SORT (O(n^4/3)) -------------------------
void shell_sedgewicka_sort(int arr[], int n) {

    int dystance;

    int dod_zmienna, k = 0, d = 0;

    while(true) {

        if(k%2 == 0) {
            d = 9*pow(2, k) - 9*pow(2, (k/2)) + 1;

        }
        else{
            d = 8*pow(2, k) - 6*pow(2, (k+1)/2) + 1;
        }
        //cout << "\n\n\nK = " <<k << "\t D = " << d;
        if(d >= n) break;
        k++;
    }

    k--; // - zakomentowac dla knutha
    while(dystance > 1) {

        if(k%2 == 0) {
            dystance = 9*pow(2, k) - 9*pow(2, (k/2)) + 1;
        }
        else{
            dystance = 8*pow(2, k) - 6*pow(2, (k+1)/2) + 1;
        }

        for (int i = dystance; i < n; i++) {
                for(int j = i; j > dystance-1; j = j-dystance) {
                    if(arr[j] < arr[j-dystance]) {
                        dod_zmienna = arr[j];
                        arr[j] = arr[j-dystance];
                        arr[j-dystance] = dod_zmienna;
                    }
                    else{
                        break;
                    }
                }
        }

        /*
        cout<< "\n\n" << k << ") D = " << dystance << "\n"; // - Wypisac array po kazdym nowym dystancje
        for(int i = 0; i < n; i++) {
            cout<< arr[i] << " ";
        }
        //*/
        k--;
    }
}

// ------------------------------- SWOJ_CIĄG -------------------------------
void shell_swoj_sort(int arr[], int n) {

    int dystance;

    int dod_zmienna, k=1;


    while(true) {

        dystance = k*(k+1)/2;

        if(dystance >= n) break;
        k++;
    }

    k--;

    while(dystance > 1) {

        dystance = k*(k+1) / 2;

        for (int i = dystance; i < n; i++) {
                for(int j = i; j > dystance-1; j = j-dystance) {
                    if(arr[j] < arr[j-dystance]) {
                        dod_zmienna = arr[j];
                        arr[j] = arr[j-dystance];
                        arr[j-dystance] = dod_zmienna;
                    }
                    else{
                        break;
                    }
                }
        }


        /*
        cout<< "\n\n" << k << ") D = " << dystance << "\n"; // - Wypisac array po kazdym nowym dystancje
        for(int i = 0; i < n; i++) {
            cout<< arr[i] << " ";
        }
        //*/
        k--;
    }
}

// --------------------------- MAIN ---------------------------
int main()
{

    //int n = 100;

    //int arr[n] = {9, 2, 6, 5, 4, 3, 1, 7, 8};
    //int arr[n];
    double start_clock, end_clock, result_time;

    /*los_arr(arr, n);
    shell_swoj_sort(arr, n);
    wupisz_arr(arr, n);
    //*/

    ofstream fout;
    string path = "insert.txt";
    fout.open(path);


    for (int i = 10000; i <= 250000; i += 10000) {
        int n = i;
        int arr[n];
        los_arr(arr, n);
        start_clock = clock();
        insert_sort(arr, n);

        cout << endl << "n = " << n;
        fout << endl << "n = " << n;

        end_clock = clock();
        result_time = (end_clock - start_clock) / CLOCKS_PER_SEC;

        cout << "\tTime: " << result_time;
        fout << "\tTime: " << result_time;

        cout << endl;
        fout << endl;
        //wypisz_arr(arr, n);
    }

    fout.close();
    //*/

    return 0;
}
