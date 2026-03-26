#ifndef TASK_STUFF
#define TASK_STUFF

#include <string>
#include <vector>

class TaskClass {
  private:
    struct Task {
      std::string Name;
      std::string Description;
      bool Completed;
    };

    std::vector<Task> Tasks;

  public:
    void addTask();
    void viewTasks();
    void markTaskComplete();
    void deleteTask();
};

#endif
