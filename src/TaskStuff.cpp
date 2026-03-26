#include <iostream>
#include <cstdint> // Used for the uint32_t's
#include <fstream>

#include "TaskStuff.h"
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

void TaskClass::viewTasks() {
  std::cout << "Todo List:" << std::endl;

  for (uint32_t i = 0; i < Tasks.size(); i++) {
    std::cout << i + 1 << ": Name: " << Tasks[i].Name << ", Description: " << Tasks[i].Description << ", Completed: " << (Tasks[i].Completed ? "y\n" : "n\n") << std::endl;
  }
}

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

void TaskClass::saveTasks() {
    std::ofstream file("TaskList.txt");

    if (!file) {
        std::cerr << "Failed to open file\n";
        return;
    }

    file << "[\n";

    for (size_t i = 0; i < Tasks.size(); ++i) {
        const auto& t = Tasks[i];

        file << "  {\n";
        file << "    \"Name\": \"" << t.Name << "\",\n";
        file << "    \"Description\": " << t.Description << "\n";
        file << "    \"Completed\": \"" << t.Completed << "\",\n";
        file << "  }";

        if (i != Tasks.size() - 1)
            file << ",";

        file << "\n";
    }

    file << "]\n";
}
