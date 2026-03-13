#include <iostream>
#include <string>
#include <chrono>

int main(){
    using std::cout;
    using std::cin;
    using std::string;

    // chrono::system_clock::now()  =  gets the current time point
    // time_point                   =  represents a specific moment in time
    // duration<double>             =  stores elapsed time in seconds (as a double)

    auto start = std::chrono::system_clock::now();   // record time before input

    cout << "Type 'start' as quickly as you can and hit ENTER: " << std::flush;

    string input;
    cin >> input;                                    // wait for user input

    auto end = std::chrono::system_clock::now();
// scope resolution operator ::   =   used because system_clock::now() is static (no object needed)
// dot operator .                 =   only used when calling members on an instance


    std::chrono::duration<double> elapsed = end - start; // operator- is overloaded for time_point objects → returns a duration

    cout << "Reaction time: " << elapsed.count() << "s\n\n";

    return 0;
}


/*

#include <iostream>
#include <string>
#include <chrono>

// Type aliases for chrono classes
using Clock = std::chrono::system_clock;
using TimePoint = std::chrono::time_point<Clock>;
using Duration = std::chrono::duration<double>;

int main(){
    TimePoint *start, *end;
    Duration *elapsed_seconds = new Duration();
    std::string input;

    start = new TimePoint(Clock::now());

    std::cout << "Type 'start' as quickly as you can and hit ENTER: " << std::flush;
    std::cin >> input;

    end = new TimePoint(Clock::now());
    *elapsed_seconds = *end - *start;

    std::cout << "Reaction time: " << elapsed_seconds->count() << "s" << std::endl;

    delete start;
    delete end;
    delete elapsed_seconds;

    std::cout << std::endl << std::endl;
    return 0;
}


*/