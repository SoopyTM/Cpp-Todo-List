#include <iostream>

#include "TaskStuff.h"

int main(){
  TaskClass TaskObj;
  int choice;
    
  TaskObj.readTasks();
  do {
    std::cout << "Please listen carefully for our menu options have changed:" << std::endl;
    std::cout << "1:Add New Task\n2:View Tasks\n3.Mark Complete\n4.Delete Task\n5.Exit\n> ";
    std::cin >> choice;
        
    switch (choice) {
      case 1:
      TaskObj.addTask();
      break;
            
      case 2:
      TaskObj.viewTasks();
      break;
            
      case 3:
        TaskObj.markTaskComplete();
        break;
      
      case 4:
        TaskObj.deleteTask();
      default:
        break;
    }
        
  } while (choice != 5);
  
  TaskObj.saveTasks();

  return 0;
}
