#include<graphics.h>
#include<bits/stdc++.h>
#include<thread>
using namespace std;

int sizeN = 200;
int gap = 4;


// draw bar
void drawBar(int win, int x, int height, int color){
    setcurrentwindow(win);
    setcolor(color);
    line(x, sizeN, x, sizeN-height);
}

// bubble sort
vector<int> arrBubble;

void bubbleSortGraphics(int win){
    auto start = chrono::high_resolution_clock::now();

    for(int i = 0; i<sizeN-1; i++){
        for(int j = 0; j<sizeN-i-1; j++){

            if(arrBubble[j] > arrBubble[j+1]){
                drawBar(win, gap * j+1, arrBubble[j], BLACK);
                drawBar(win, gap*(j+1) + 1, arrBubble[j+1], WHITE);

                swap(arrBubble[j], arrBubble[j+1]);

                drawBar(win, gap* j+1, arrBubble[j], WHITE);    
                drawBar(win, gap* (j+1) + 1, arrBubble[j+1], WHITE);

                delay(2);
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();

    long long t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout<< "Bubble Sort Time : "<<t<<" ms "<<endl;
}


// selection sort

vector<int>arrSelect;

void swap_visual(int win, int x1, int x2, int h1, int h2){
    setcurrentwindow(win);

    drawBar(win, x1, h1, BLACK);
    drawBar(win, x2, h2, BLACK);

    drawBar(win, x1, h2, WHITE);
    drawBar(win, x2, h1, WHITE);

    delay(5);
}


void selectionSortGraphics(int win){
    auto start = chrono::high_resolution_clock::now();

    for(int i = 0; i<sizeN-1; i++){

        int min_index = i;

        for(int j = i+1; j<sizeN; j++){
            if(arrSelect[j] < arrSelect[min_index]){
                min_index= j;
            }
        }

        if(min_index != i){
            swap(arrSelect[min_index], arrSelect[i]);
            swap_visual(win, gap * i+1, gap * min_index +1, arrSelect[min_index], arrSelect[i]);
        }
    }

    auto end= chrono::high_resolution_clock::now();
    long long t = chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cout<<"Selection Sort Time: "<<t<<" ms "<<endl;

}


int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);


    // 2 windows 
    // 1. bubble sort 
    // 2. selection sort

     int winBubble = initwindow(gap * sizeN + 1, sizeN + 1, "Bubble Sort");
    int winSelect = initwindow(gap * sizeN + 1, sizeN + 1, "Selection Sort");

    // Generate array
    vector<int> original;
    for (int i = 1; i <= sizeN; i++) original.push_back(i);

    // Shuffle
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(original.begin(), original.end(), default_random_engine(seed));

    // Copy arrays for each sort
    arrBubble = original;
    arrSelect = original;

    // Draw initial arrays
    for (int i = 0; i < sizeN; i++) {
        drawBar(winBubble, gap * i + 1, arrBubble[i], WHITE);
        drawBar(winSelect, gap * i + 1, arrSelect[i], WHITE);
    }

    //RUN BOTH IN PARALLEL

    bubbleSortGraphics(winBubble);
    selectionSortGraphics(winSelect);


    

    cout << "\n=== FINAL TIME COMPARISON ===\n";
    cout << "(Check above printed times)\n";
    
    delay(1);
    closegraph();
    return 0;
}