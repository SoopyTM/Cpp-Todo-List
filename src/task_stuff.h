#ifndef TASK_STUFF
#define TASK_STUFF

#include <string>
#include <vector>

class TaskClass {
  private:
    struct Task {
      std::string name;
      std::string description;
      bool completed;
    };

    // This is used everywhere in this program. Keep it in mind. :D
    std::vector<Task> tasks_;

  public:
    // Reads the task_list.csv file into the tasks_ vector.
    void ReadTasks();
    // Adds A Task to the tasks_ vector.
    void AddTask();
    // Displays the tasks currently in the tasks vector.
    void ViewTasks();
    void MarkTaskComplete();
    void DeleteTask();
    void SaveTasks();
};

#endif
