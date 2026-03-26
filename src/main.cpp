#include <iostream>

#include "TaskStuff.h"

int main(){
  TaskClass TaskObj;
  int choice;
    
  do {
    std::cout << "Please listen carefully for our menu options have changed:" << std::endl;
    std::cout << "1:Add New Task\n2:View Tasks\n3.Mark Complete\n4.Exit\n> ";
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
      
      default:
        break;
    }
        
  } while (choice != 4);

  return 0;
}
