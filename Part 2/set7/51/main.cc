#include "handler/handler.h"
#include <iostream>
#include <thread>
#include <fstream>

using namespace std;

int main(int argc, const char** argv) {

    string text = "mouse";
    ofstream output("output.txt");

    // Passing Handler object to a thread
    thread shiftThread(&Handler::shift, Handler(), ref(output), ref(text));
    shiftThread.join();

    // Thread creating Handler object itself
    thread shiftThread1(callShift, ref(output), ref(text));
    shiftThread1.join();
}