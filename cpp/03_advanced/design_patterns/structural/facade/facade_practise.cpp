#include <iostream>

class Reservation{
public:
    void make_reservation(const std::string& reservation){
        std::cout << "Reseveration for: " << reservation << std::endl;
    }
};

class Payment{
public:
    void make_payment(const int& payment){
        std::cout << "Processing payment of: $" << payment << std::endl;
    }
};

class Confirmation{
public:
    void confirm(){
        std::cout << "Reservation confirmed!";
    }
};

class ReservationSystemFacade{
public:
    void handle_reservation(const std::string& reservation, const int& payment){
        m_reservation.make_reservation(reservation);
        m_payment.make_payment(payment);
        m_confirmation.confirm();
    }

private:
    Reservation m_reservation;
    Payment m_payment;
    Confirmation m_confirmation;
};

int main(){

    ReservationSystemFacade reserve_system;
    reserve_system.handle_reservation("Smith", 450);

    return 0;
}
