#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib> // for exit()

using namespace std;

// Function prototypes
void displayMenu();
void listTasks(const vector<string>& tasks);
void addTask(vector<string>& tasks);
void saveTasks(const vector<string>& tasks);
void loadTasks(vector<string>& tasks);

int main() {
    vector<string> tasks;

    // Load tasks from file on program start
    loadTasks(tasks);

    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // ignore any leftover newline characters

        switch (choice) {
            case 1:
                listTasks(tasks);
                break;
            case 2:
                addTask(tasks);
                break;
            case 3:
                saveTasks(tasks);
                break;
            case 4:
                cout << "Exiting program." << endl;
                saveTasks(tasks); // Save tasks before exiting
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void displayMenu() {
    cout << "===== To-Do List Application =====" << endl;
    cout << "1. List tasks" << endl;
    cout << "2. Add task" << endl;
    cout << "3. Save tasks to file" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void listTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter task: ";
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added." << endl;
}

void saveTasks(const vector<string>& tasks) {
    ofstream outFile("tasks.txt");
    if (!outFile) {
        cerr << "Error: Unable to save tasks to file." << endl;
        return;
    }

    for (const auto& task : tasks) {
        outFile << task << endl;
    }

    cout << "Tasks saved to file." << endl;
    outFile.close();
}

void loadTasks(vector<string>& tasks) {
    ifstream inFile("tasks.txt");
    if (!inFile) {
        cout << "No existing tasks file found. Starting with an empty list." << endl;
        return;
    }

    string task;
    while (getline(inFile, task)) {
        tasks.push_back(task);
    }

    cout << "Tasks loaded from file." << endl;
    inFile.close();
}
