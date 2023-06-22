#include <iostream>
using namespace std;

class queues {
	int FRONT, REAR, max = 5;
	int queue_array[5];

public:
	queues() {
		FRONT = -1;
		REAR - -1;
	}
	void insert() {
		int num;
		cout << "enter a number : ";
		cin >> num;
		cout << endl;

		//cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nqueue overflow\n";
			return;
		}

		//cek apakah antrian kosong 
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			//jika rear berada di posisi terakhir array ,kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_array[REAR] = num;
	}

	void remove() {
		// cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "queue underflow\n";
			return;
		}
		cout << "\n the element deleted from the queue is: " << queue_array[FRONT] << "\n";

		//cek jika antrianya hanya memiliki satu elemen
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			//jika elemen yang di hapus berada di posisi terakhir array ,kembali ke awal array 
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
			cout << "Queues is empty \n";
			return;
		}
		cout << "\nelement in the queue are : \n";

		//jika front position <= rear position ,iterasi dari front hingga rear
		if (FRONT_position <= REAR_position) {
			while (FRONT_position <= REAR_position) {
				cout << queue_array[FRONT_position] << "   ";
				FRONT_position++;
			}
			cout << endl;
		}

		else {
			//jika front position >rear position , iterasi dari front hingga akhir array 
			while (FRONT_position <= max - 1) {
				cout << queue_array[FRONT_position] << "   ";
				FRONT_position++;
			}
			FRONT_position = 0;

			//iterasi dari awal array hingga rear
			while (FRONT_position <= REAR_position) {
				cout << queue_array[FRONT_position] << "    ";
				FRONT_position++;

			}
			cout << endl;
		}
	}
}; 