
#include <iostream>
using namespace std;

class Queues {
	int FRONT, REAR, max = 5;
	int queues_array[5];

public:
	Queues() {
		FRONT = -1;
		REAR = -1;
	}

	void Insert() {
		int num;
		cout << "Enter a number: ";
		cin >> num;
		cout << endl;

		// Cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueue overflow\n";
			return;
		}

		// Cek apakah antrian kosong
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}

		else {
			// Jika REAR berada di posisi terakhir array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;

		}
		queues_array[REAR] = num;
	}

	void remove() {
		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue UnderFlow\n";
			return;
		}
		cout << "\nThe element deleted from the queue is: " << queues_array[FRONT] << "\n";

		// Cek jika antrian hanya memiliki satu element
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			// Jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}

	}
	
	void display() {
		int FRONT_position = FRONT;
		int REAR_position = REAR;

		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue is empty\n";
			return;
		}

		cout << "\nElements in the queue are.../n";

		//jika FRONT_position <= REAR_position, iterasi dari FRONT HINGGA REAR
		if (FRONT_position <= REAR_position) {
			while (FRONT_position <= REAR_position) {
				cout << queues_array[FRONT_position] << " ";
				FRONT_position++;
			}
			cout << endl;
		}
		else {
			//jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
			while (FRONT_position <= max - 1) {
				cout << queues_array[FRONT_position] << " ";
				FRONT_position++;
			}
		}
		
	}
	
};

