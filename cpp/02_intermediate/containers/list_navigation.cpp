// list_route_navigation.cpp
// purpose               = demonstrate list iteration, wrap-around navigation, and stateful iterator usage
// container             = std::list<std::string> for ordered stops
// iterator behavior     = ++it and --it with wrap-around at begin()/end()
// best practice         = initialize iterator only when first element is added

#include <iostream>
#include <list>
#include <string>

typedef std::list<std::string> stops_t;
typedef std::string stop_t;
typedef std::list<std::string>::iterator iter;

class Route {
private:
    stops_t stops;        // container of stops
    iter it;              // iterator pointing to current stop
    bool initialized = false; // tracks whether iterator is valid

public:
    void add_stop(const stop_t& stop) {
        stops.push_back(stop);

        // initialize iterator on first insertion
        if (!initialized) {
            it = stops.begin();
            initialized = true;
        }

        std::cout << "Added stop: " << stop << "\n";
    }

    void current_stop() {
        if (!initialized) {
            std::cout << "No stops available.\n";
            return;
        }

        std::cout << "Currently stopped at: " << *it << "\n";
    }

    void next_stop() {
        if (!initialized) return;

        ++it;                       // advance iterator
        if (it == stops.end())      // wrap-around
            it = stops.begin();

        std::cout << "Advancing to next stop: " << *it << "\n";
    }

    void prev_stop() {
        if (!initialized) return;

        if (it == stops.begin()) {  // wrap-around backwards
            it = stops.end();
            --it;
        } else {
            --it;
        }

        std::cout << "Advancing to previous stop: " << *it << "\n";
    }
};

int main() {

    Route BusRoute;
    BusRoute.add_stop("Leopold Platz");
    BusRoute.add_stop("Sedans Platz");
    BusRoute.add_stop("Mess Platz");

    std::cout << "\n\n";
    BusRoute.current_stop();
    BusRoute.next_stop();
    BusRoute.next_stop();
    BusRoute.next_stop();
    BusRoute.next_stop();

    std::cout << "\n\n";
    BusRoute.current_stop();
    BusRoute.next_stop();
    BusRoute.next_stop();
    BusRoute.next_stop();
    BusRoute.next_stop();

    std::cout << "\n\n";
    BusRoute.current_stop();
    BusRoute.prev_stop();
    BusRoute.prev_stop();
    BusRoute.prev_stop();
    BusRoute.prev_stop();

    std::cout << "\n\n";
    BusRoute.current_stop();

    return 0;
}
