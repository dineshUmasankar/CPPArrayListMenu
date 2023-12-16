#include "AppMessages.h"
#include <string>

const string AppMessages::ExitMessage = "Exiting program...";

const string AppMessages::SelectCommandMenu = R"(
===================================
Select which command you want to execute.
===================================
1. Add Data to Instance
2. List Instance
3. Find (Search) Data from Instance
4. Delete Data from Instance
5. Update Data from Instance
6. Save Instance to File Format
7. Load Instance from File Format
8. Exit Program
===================================
)";

const string AppMessages::SelectInstanceMenu = R"(
===================================
Select which instance you want to list.
===================================
1. Int
2. Bool
3. Char
4. Double
5. Float
6. Go Back
===================================
)";

const string AppMessages::SelectChoiceMessage =
    "Please enter the number corresponding to the action you want: ";

const string AppMessages::InputErrorMessage =
    "Invalid Input. Please Try Again.";

const string AppMessages::AddDataMessage = "Enter Data (0/1 for bool): ";

const string AppMessages::SearchDataMessage = "Search Query (0/1 for bool): ";

const string AppMessages::DeleteDataMessage = "Enter Index for Deletion: ";

const string AppMessages::UpdateDataMessage = "Update Data at which Index: ";

const string AppMessages::OperationCanceledMessage =
    "Due to bad data, operation was canceled.";
