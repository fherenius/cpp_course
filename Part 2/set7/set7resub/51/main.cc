#include "main.ih"

int main() {

    string text = "mouse";
    ofstream output("output.txt");

    // Passing Handler object to a thread
    thread shiftThread(&Handler::shift, Handler(), ref(output), ref(text));
    shiftThread.join();

    // Thread creating Handler object itself
    thread shiftThread1(callShift, ref(output), ref(text));
    shiftThread1.join();
}