#pragma once
#include "flight.h"
#include <iostream>
#include <vector>

class FlightQueue {
private:
	struct flightNode {
		Flight data;
		flightNode* next;
	};
	flightNode* head;
	flightNode* tail;

public:
	FlightQueue() : head(nullptr), tail(nullptr) {}

	void addToQueue(const Flight& newFlight) {
		flightNode* newNode = new flightNode{ newFlight, nullptr };
		if (tail == nullptr) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	 Flight removeAt(int position) {
		if (head == nullptr) {
			throw out_of_range("Очередь пуста");
		}

		if (position < 0) {
			throw out_of_range("Позиция не может быть отрицательной");
		}

		if (position == 0) {
			// Удаляем первый элемент (head)
			Flight data = head->data;
			flightNode* temp = head;
			head = head->next;
			if (head == nullptr) {
				tail = nullptr; // Очередь стала пустой
			}
			delete temp;
			return data;
		}

		// Поиск элемента по позиции
		flightNode* current = head;
		flightNode* previous = nullptr;
		int currentPosition = 0;
		while (current != nullptr && currentPosition < position) {
			previous = current;
			current = current->next;
			currentPosition++;
		}

		if (current == nullptr) {
			throw out_of_range("Позиция превышает длину очереди");
		}

		// Удаляем найденный элемент
		Flight data = current->data;
		previous->next = current->next;
		if (current->next == nullptr) {
			tail = previous; // Удаленный элемент был последним
		}
		delete current;
		return data;
	}


	Flight getElementAtPozition(int pozition) {
		if (pozition < 0) {
			throw out_of_range("Позиция не может быть отрицательной");
		}
		flightNode* current = head;
		int currentPozition = 0;
		while (current != nullptr) {
			if (currentPozition == pozition) {
				return current->data;
			}
			current = current->next;
			currentPozition++;
		}
		throw out_of_range("Позиция превышает длину массива");
	}

	vector<int> findFlightByDepartureAirport(const string& DepartureAirport) {
		vector<int> pozitions;
		flightNode* current = head;
		int currentPozition = 0;
		while (current != nullptr) {
			if (current->data.departureAirport == DepartureAirport) {
				pozitions.push_back(currentPozition);
			}
			current = current->next;
			currentPozition++;
		}
		if (pozitions.empty()) {
			pozitions.push_back(-1);
		}
		return pozitions;
	}

	vector<int> findFlightByArrivalAirport(const string& ArrivalAirport) {
		vector<int> pozitions;
		flightNode* current = head;
		int currentPozition = 0;
		while (current != nullptr) {
			if (current->data.arrivalAirport == ArrivalAirport) {
				pozitions.push_back(currentPozition);
			}
			current = current->next;
			currentPozition++;
		}
		if (pozitions.empty()) {
			pozitions.push_back(-1);
		}
		return pozitions;
	}

};