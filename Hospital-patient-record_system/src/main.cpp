// ============================================================
//  MAIN FUNCTION
//  Purpose: Entry point of the program
//  Displays welcome screen and starts the hospital system
// ============================================================

int main() {
    // Display welcome screen with project details
    cout << "\n";
    cout << "+--------------------------------------------------+\n";
    cout << "|     HOSPITAL PATIENT RECORD SYSTEM               |\n";
    cout << "|     OOP-based Console Application  v2.0          |\n";
    cout << "+--------------------------------------------------+\n";
    cout << "|     Team Project - Vardhaman College of Engg     |\n";
    cout << "+--------------------------------------------------+\n";
    cout << "\n";

    // Create HospitalSystem object
    // This automatically loads saved data from files
    HospitalSystem system;

    // Start the main menu loop
    // The program will run until user chooses option 0 (Exit)
    system.mainMenu();

    // Return 0 to indicate successful program execution
    return 0;
}
