#include "Reservoir.h"

void AddReservoir(Reservoir*& reservoirs, int& count) {
    char name[100], type[100];
    double width, length, depth;

    cout << "Enter reservoir name: ";
    cin >> name;
    cout << "Enter reservoir type: ";
    cin >> type;
    cout << "Enter dimensions (width, length, depth): ";
    cin >> width >> length >> depth;

    Reservoir* newReservoirs = new Reservoir[count + 1];

    for (int i = 0; i < count; i++) {
        newReservoirs[i] = reservoirs[i];
    }

    newReservoirs[count] = Reservoir(name, type, width, length, depth);

    delete[] reservoirs;
    reservoirs = newReservoirs;
    count++;

    cout << "Reservoir added successfully.\n";

    cout << endl;
}

void DeleteReservoir(Reservoir*& reservoirs, int& count) {
    if (count == 0) {
        cout << "No reservoirs to remove.\n";
        return;
    }

    int index;
    cout << "Enter the index of the reservoir to remove (1-" << count << "): ";
    cin >> index;

    if (index < 1 || index > count) {
        cout << "Invalid index.\n";
        return;
    }

    index--;

    Reservoir* newReservoirs = new Reservoir[count - 1];

    for (int i = 0, j = 0; i < count; i++) {
        if (i != index) {
            newReservoirs[j++] = reservoirs[i];
        }
    }

    delete[] reservoirs;
    reservoirs = newReservoirs;
    count--;

    cout << "Reservoir removed successfully.\n";
}

void ShowAllReservoirs(const Reservoir* reservoirs, int count) {
    if (count == 0) {
        cout << "No information about reservoirs.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "Reservoir " << i + 1 << ":\n";
        reservoirs[i].Display();
        cout << "------------------\n";
    }

    if (count > 1) {
        bool allSameType = true;
        for (int i = 1; i < count; i++) {
            if (!reservoirs[0].IsSameType(reservoirs[i])) {
                allSameType = false;
                break;
            }
        }
        if (allSameType) {
            cout << "All reservoirs are of the same type.\n";
        }
        else {
            cout << "Reservoirs are of different types.\n";
        }
    }
}

void ShowMenu(int count) {
    if (count >= 1) {
        cout << "\nMenu:\n";
        cout << "1. Add reservoir\n";
        cout << "2. Remove reservoir\n";
        cout << "3. Show all reservoirs\n";
        cout << "4. Exit\n";
    }
    else {
        cout << "\nMenu:\n";
        cout << "1. Add reservoir\n";
        cout << "4. Exit\n";
    }
}

int main() {
    Reservoir* reservoirs = nullptr;
    int count = 0;
    int choice;

    do {
        ShowMenu(count > 0);
        cout << "Choose an option: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            AddReservoir(reservoirs, count);
            break;
        case 2:
            if (count > 0) {
                DeleteReservoir(reservoirs, count);
            }
            else {
                cout << "Cannot remove reservoir. No data available.\n";
            }
            break;
        case 3:
            if (count > 0) {
                ShowAllReservoirs(reservoirs, count);
            }
            else {
                cout << "No data to display.\n";
            }
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
            break;
        }
    } while (choice != 4);

    delete[] reservoirs;
    return 0;
}
