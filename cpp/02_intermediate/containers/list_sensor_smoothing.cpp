#include <iostream>
#include <list>

typedef std::list<float> list_t;
typedef std::list<float>::iterator iterator_t;

class SensorData{
private:
    list_t readings;
    iterator_t it;
    bool initialized = false;

public:
    void add_reading(float reading);
    void smoth_data();
    void print_data();
};

void SensorData::add_reading(float reading){
    // add a value to the list and set iterator during the first add
    readings.push_back(reading);
    std::cout << "Reading: " << reading << " added.\n";

    if(!initialized) {
        it = readings.begin();
        initialized = true;
    }
};

void SensorData::smoth_data(){
    // check if the next element is twice or half the size of the current one
    // if it is, replace with the current value
    for(it = readings.begin(); it != readings.end(); it++){
        iterator_t next = it;
        ++next;

        if(next == readings.end()) break;
        
        float current = *it;
        float next_val = *next;

        if((next_val * 2) < current || (next_val / 2) > current){
            *next = current;
        }
    }
};

void SensorData::print_data(){
    for(auto &el : readings){
        std::cout << "Reading: " << el << std::endl;
    }
};

int main(){

    SensorData MyData;
    MyData.add_reading(4.5);
    MyData.add_reading(17.5);
    MyData.add_reading(11.9);
    MyData.add_reading(5.7);
    MyData.add_reading(1.5);

    std::cout << "\n";
    MyData.print_data();
    std::cout << "\n";

    MyData.smoth_data();
    std::cout << "\n";
    MyData.print_data();
    

    return 0;
}