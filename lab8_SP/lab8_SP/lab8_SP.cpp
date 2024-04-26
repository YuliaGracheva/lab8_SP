#include <iostream>
#include "flight.h"
#include "flightQueue.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    FlightQueue queue;

    Flight flight1{ "RUS", "USA", 1, 10 };
    Flight flight2{"JAP", "RUS", 2, 20};
    Flight flight3{ "USA", "JAP", 3, 30 };
    Flight flight4{ "JAP", "CH", 4, 40 };

    cout << "1) Рейс отправляется из RUS в USA" << endl;
    cout << "2) Рейс отправляется из JAP в RUS" << endl;
    cout << "3) Рейс отправляется из USA в JAP" << endl;
    cout << "4) Рейс отправляется из JAP в CH" << endl;

    queue.addToQueue(flight1);
    queue.addToQueue(flight2);
    queue.addToQueue(flight3);
    queue.addToQueue(flight4);

    try {
        Flight firstFlight = queue.dequeue();
        cout << "Голова очереди рейсов: " << firstFlight.departureAirport << " " << firstFlight.arrivalAirport << endl;
    }
    catch (const std::exception& e) {
        cout << "Исключение: " << e.what() << endl;
    }


    try {
        Flight Flight1 = queue.removeAt(1);
        cout << "Удаление 1 рейса";
    }
    catch (const exception& e) {
        cout << "Исключение: " << e.what() << endl;
    }
    cout << endl;

    try {
        Flight Flight1 = queue.getElementAtPozition(1);
        cout << "Рейс с указанной позицией (1):" << Flight1.departureAirport << " " << Flight1.arrivalAirport;
    }
    catch (const exception& e) {
        cout << "Исключение: " << e.what() << endl;
    }
    cout << endl;

    vector<int> pozitions = queue.findFlightByArrivalAirport("USA");
    cout << "Рейс с указанным аэпортом прибытия (USA): ";
    for (int pos : pozitions) {
        cout << "" << pos+1;
    }
    cout << endl;

    vector<int> pozition = queue.findFlightByDepartureAirport("RUS");
    cout << "Рейс с указанным аэпортом отправления (RUS): ";
    for (int pos : pozition) {
        cout << "" << pos+1;
    }
    cout << endl;
    system("pause");
    return 0;
}