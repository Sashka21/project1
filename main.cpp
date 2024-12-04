#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;


// -------------------- LOS_ARR --------------------
void los_arr(int arr[], int n) {

    srand(time(0));

    for(int i = 0; i < n; i++) {
        arr[i] = (rand()*rand())%n;
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



    //dystance = n; // Ciąg Shella



    int d = 2;
    while(d < n) {
        d = d*2;
        k++;
    }
    dystance = d-1; // CIĄG HIBBARDA (Przyrost O(n^(3/2)))
    //*/

    k = 0;
    while(dystance > 1) {

        //dystance = dystance / 2; // - CIĄG SHELLA

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

        /*
        k++;
        cout<< "\n\n" << k << ") D = " << dystance << "\n"; // - Wypisac array po kazdym nowym dystancje
        for(int i = 0; i < n; i++) {
            cout<< arr[i] << " ";
        }
        //*/

    }
}

// --------------------------- MAIN ---------------------------
int main()
{

    //int n;

    //int arr[n] = {9, 2, 6, 5, 4, 3, 1, 7, 8};
    //int arr[n];
    double start_clock, end_clock, result_time;

    /*
    cout << endl << "start array: ";
    wypisz_arr(arr, n);*/


    ofstream fout;
    string path = "insert.txt";
    fout.open(path);

    for (int i = 10000; i <= 250000; i += 10000) {
        int n = i;
        int arr[n];
        los_arr(arr, n);
        start_clock - clock();
        insert_sort(arr, n);
        cout << endl << "n = " << n;
        fout << endl << "n = " << n;
        end_clock = clock();
        result_time = (end_clock - start_clock) / CLOCKS_PER_SEC;
        cout << "\tTime: " << result_time;
        fout << "\tTime: " << result_time;
        //timer(start_clock);
        fout << endl;
        cout << endl;
    }

    fout.close();

    /*
    ofstream fout;
    string path = "myFile.txt";
    fout.open(path);

    if(!fout.is_open()) {
        cout << "!!!File didnt open!!!" << endl;
    }
    else {
        fout << "Data rerd!!!!!!!";
    }

    fout.close();

    //*/

    /*end_clock = clock();
    result_time = (end_clock - start_clock) / CLOCKS_PER_SEC;
    cout << endl << "Time of sorting = " << result_time << " sec" << endl;
    //*/





    return 0;
}
