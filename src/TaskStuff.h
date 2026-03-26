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

    // This is used everywhere in this program. Keep it in mind. :D
    std::vector<Task> Tasks;

  public:
    void readTasks();
    void addTask();
    void viewTasks();
    void markTaskComplete();
    void deleteTask();
    void saveTasks();
};

#endif
