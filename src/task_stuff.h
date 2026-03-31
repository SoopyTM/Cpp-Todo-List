#ifndef TASK_STUFF
#define TASK_STUFF

#include <string>
#include <vector>

class TaskClass {
  private:
    // Each task will include these patameters. name: The name of the task; description: An optional description for the task. This can include extra info or anything the user would like; completed: This just marks if the task is completed or not. false means it has not yet been completed(default), true means it has been completed.
    struct Task {
      std::string name;
      std::string description;
      bool completed;
    };

    // This is used everywhere in this program. Keep it in mind. :D
    std::vector<Task> tasks_;

  public:
    // Reads the task_list.csv file into the tasks_ vector.
    void ReadTasksFromFile();

    // Adds A Task to the tasks_ vector.
    void AddTask();

    // Displays the tasks currently in the tasks vector.
    void ViewTasks();

    // Sets the chosen task's complete variable to true.
    void MarkTaskComplete();

    // Sets the chosen task's complete variable to false.
    void MarkTaskIncomplete();

    // Deletes the chosen task.
    void DeleteTask();

    // Writes the tasks_ vector to a csv (Comma Seperated Values) file.
    void SaveTasksToFile();
};

#endif
