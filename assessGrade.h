#define MAX_ARR      5
#define MAX_LENGTH   81

// Function prototypes for overloaded functions
int assessGrade(double numberGrade);
int assessGrade(char* letterGrade);
int assessGrade(int arr[]);

// Function prototype for parsing a sring
int parseUserInput(char* inputInfo, double &numberGrade, char *letterGrade, int arrNumber[], char filename[]);