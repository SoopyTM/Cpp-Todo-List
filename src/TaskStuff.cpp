#include <iostream>
#include <fstream>
#include <cstdint> // Used for the uint32_t's
#include <sstream>

#include "TaskStuff.h"

// Reads the TaskList.csv file into the vector.
void TaskClass::readTasks(){
  std::ifstream InFile("TaskList.csv");

  if (!InFile) {
    std::cerr << "Failed to open file. File may not exist." << std::endl;
    return;
  }

  Tasks.clear();

  std::string line;

  while (std::getline(InFile, line)) {
    std::stringstream ss(line);

    std::string name, description, completedStr;

    std::getline(ss, name, ',');
    std::getline(ss, description, ',');
    std::getline(ss, completedStr, ',');

    Task t;
    t.Name = name;
    t.Description = description;

    // convert string -> bool
    t.Completed = (completedStr == "1" || completedStr == "true");

    Tasks.push_back(t);
    }

  InFile.close();
}
// Adds A Task to the Tasks (Tasks vector is initialised in the header file) vector.
void TaskClass::addTask() {
  Task t;

  std::cout << "Enter the task name: ";
  std::cin.ignore();
  std::getline(std::cin, t.Name);

  std::cout << "Enter the description (Optional): ";
  std::getline(std::cin, t.Description);

  t.Completed = false;

  Tasks.push_back(t);

  std::cout << "Added Task\n" << std::endl;
}

// Displays the tasks currently in the Tasks vector.
void TaskClass::viewTasks() {
  std::cout << "Todo List:" << std::endl;

  for (uint32_t i = 0; i < Tasks.size(); i++) {
    std::cout << i + 1 << ": Name: " << Tasks[i].Name << ", Description: " << Tasks[i].Description << ", Completed: " << (Tasks[i].Completed ? "y\n" : "n\n") << std::endl;
  }
}

// Sets the chosen task's complete variable to true.
void TaskClass::markTaskComplete() {
  uint32_t chosenID;
  std::cout << "Enter The Task ID: ";
  std::cin >> chosenID;

  if (chosenID <= 0 || chosenID > Tasks.size()) {
    std::cout << "You entered an incorrect ID.\n" << std::endl;
    return;
  }

  Tasks[chosenID - 1].Completed = true;

  std::cout << "Set Task " << chosenID << " To Complete.\n" << std::endl;
}

// Deletes the chosen task.
void TaskClass::deleteTask() {
  uint32_t chosenID;
  std::cout << "Enter the task ID you want to delete: ";
  std::cin >> chosenID;
  if (chosenID <= 0 || chosenID > Tasks.size()) {
    std::cout << "You entered an incorrect ID.\n" << std::endl;
    return;
  }
  Tasks.erase(Tasks.begin() + chosenID - 1);

  std::cout << "Removed task " << chosenID << " from list." << std::endl;
}

// Writes the Tasks vector to a csv (Comma Seperated Values) file.
void TaskClass::saveTasks() {
  std::ofstream OutFile("TaskList.csv");
  
  if (!OutFile) {
    std::cerr << "Failed to open file" << std::endl;
    return;
  }

  for (uint32_t i = 0; i < Tasks.size(); i++) {
    OutFile << Tasks[i].Name << "," << Tasks[i].Description << "," << Tasks[i].Completed << std::endl;
  }
  OutFile.close();
}
