#include <iostream>

#include "task_stuff.h"

int main(){
  TaskClass TaskObj;
  int choice;
    
  TaskObj.ReadTasks();
  do {
    std::cout << "Please listen carefully for our menu options have changed:" << std::endl;
    std::cout << "1:Add New Task\n2:View Tasks\n3:Mark Task Complete\n4:Mark Task Incomplete\n5:Delete Task\n6:Exit\n> ";
    std::cin >> choice;
        
    switch (choice) {
      case 1:
      TaskObj.AddTask();
      break;
            
      case 2:
      TaskObj.ViewTasks();
      break;
            
      case 3:
        TaskObj.MarkTaskComplete();
        break;
      
      case 4:
        TaskObj.MarkTaskIncomplete();
        break;

      case 5:
        TaskObj.DeleteTask();
        break;
      
      default:
        break;
    }
        
  } while (choice != 6);
  
  TaskObj.SaveTasks();

  return 0;
}
