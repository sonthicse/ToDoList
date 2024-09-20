#include "include/ToDoList.hpp"
#include <iostream>

using namespace std;

int main() {
    Database database;

    while (true) {
        system("cls");

        cout << "\t\t\t--- TO DO LIST ---\n"
             << "\t\t\t1. Add Task\n"
             << "\t\t\t2. View Tasks\n"
             << "\t\t\t3. Mask Task as Completed\n"
             << "\t\t\t4. Remove Task\n"
             << "\t\t\t0. EXIT\n";
        cout << "\t\t\tEnter your choice: ";

        int choice;
        
        cin >> choice; cin.ignore();

        system("cls");

        if (choice == 0) {
            database.~Database();
            exit(0);
        } else if (choice == 1) {
            string title, description;

            cout << "\t\t\tEnter Title: "; getline(cin, title);
            cout << "\t\t\tEnter Description: "; getline(cin, description);

            database.addTask(Task(title, description));

            cout << "\t\t\tTask added completed!\n"
                 << "\t\t\tPress Enter to continue...";
            getchar();
        } else if (choice == 2) {
            if (!database.getTask().empty()) {
                for (const Task& task : database.getTask()) {
                    cout << "\t\t\t" << task.info() << endl;
                }
            } else {
                cerr << "\t\t\tNo tasks in the list!";
            }

            cout << endl << "\t\t\tPress Enter to continue...\n";
            getchar();
        } else if (choice == 3) {
            for (const Task& task : database.getTask()) {
                cout << "\t\t\t" << task.info() << endl;
            }

            string title;

            cout << "\t\t\tEnter Title: "; getline(cin, title);

            for (Task& task : database.getTask()) {
                if (title == task.getTitle()) {
                    task.maskCompleted();
                    cout << "\t\t\tMask Task completed successfully!\n"
                            "\t\t\tPress Enter to continue...\n";
                    getchar();
                    break;
                }
            }
        } else if (choice == 4) {
            for (const Task& task : database.getTask()) {
                cout << "\t\t\t" << task.info() << endl;
            }

            string title;

            cout << "\t\t\tEnter Title: "; getline(cin, title);

            database.deleteTask(title);

            cout << "\t\t\tTask deleted successfully!\n"
                    "\t\t\tPress Enter to continue...\n";
            getchar();
        }
    }
}