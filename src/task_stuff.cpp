#include <iostream>
#include <fstream>
#include <cstdint> // Used for the uint32_t's
#include <sstream>

#include "task_stuff.h"

void TaskClass::ReadTasksFromFile(){
  std::ifstream in_file("task_list.csv");

  if (!in_file) {
    std::cerr << "Failed to open file. File may not exist." << std::endl;
    return;
  }

  tasks_.clear();

  std::string line;

  while (std::getline(in_file, line)) {
    std::stringstream ss(line);

    std::string name, description, completed_str;

    std::getline(ss, name, ',');
    std::getline(ss, description, ',');
    std::getline(ss, completed_str, ',');

    Task t;
    t.name = name;
    t.description = description;

    // convert string -> bool
    t.completed = (completed_str == "1" || completed_str == "true");

    tasks_.push_back(t);
    }

  in_file.close();
}

void TaskClass::AddTask() {
  Task t;

  std::cout << "Enter the task name: ";
  std::cin.ignore();
  std::getline(std::cin, t.name);

  std::cout << "Enter the description (Optional): ";
  std::getline(std::cin, t.description);

  t.completed = false;

  tasks_.push_back(t);

  std::cout << "Added Task\n" << std::endl;
}

void TaskClass::ViewTasks() {
  std::cout << "Todo List:" << std::endl;

  for (uint32_t i = 0; i < tasks_.size(); i++) {
    std::cout << i + 1 << ": Name: " << tasks_[i].name << ", description_: " << tasks_[i].description << ", completed_: " << (tasks_[i].completed ? "y\n" : "n\n") << std::endl;
  }
}

void TaskClass::MarkTaskComplete() {
  uint32_t chosen_id;
  std::cout << "Enter The Task ID: ";
  std::cin >> chosen_id;

  if (chosen_id <= 0 || chosen_id > tasks_.size()) {
    std::cout << "You entered an incorrect ID.\n" << std::endl;
    return;
  }

  tasks_[chosen_id - 1].completed = true;

  std::cout << "Set Task " << chosen_id << " To Complete.\n" << std::endl;
}

void TaskClass::MarkTaskIncomplete() {
  uint32_t chosen_id;
  std::cout << "Enter The Task ID: ";
  std::cin >> chosen_id;

  if (chosen_id <= 0 || chosen_id > tasks_.size()) {
    std::cout << "You entered an incorrect ID.\n" << std::endl;
    return;
  }

  tasks_[chosen_id - 1].completed = false;

  std::cout << "Set Task " << chosen_id << " To Incomplete.\n" << std::endl;
}

void TaskClass::DeleteTask() {
  uint32_t chosen_id;
  std::cout << "Enter the task ID you want to delete: ";
  std::cin >> chosen_id;
  if (chosen_id <= 0 || chosen_id > tasks_.size()) {
    std::cout << "You entered an incorrect ID.\n" << std::endl;
    return;
  }
  tasks_.erase(tasks_.begin() + chosen_id - 1);

  std::cout << "Removed task " << chosen_id << " from list." << std::endl;
}

void TaskClass::SaveTasksToFile() {
  std::ofstream out_file("task_list.csv");
  
  if (!out_file) {
    std::cerr << "Failed to open file" << std::endl;
    return;
  }

  for (uint32_t i = 0; i < tasks_.size(); i++) {
    out_file << tasks_[i].name << "," << tasks_[i].description << "," << tasks_[i].completed << std::endl;
  }
  out_file.close();
}
