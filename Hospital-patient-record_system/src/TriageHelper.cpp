#include "../include/TriageHelper.h"

// ============================================================
//  TRIAGE HELPER IMPLEMENTATION
//  Contributed by: Shahesh (Mentor)
//  Decision-tree logic without external API
// ============================================================

// ============================================================
//  CONSTRUCTOR
//  Purpose: Build the symptom rule database
// ============================================================

TriageHelper::TriageHelper() {
    // Add each symptom rule to the list
    rules.push_back({"chest pain",   "Cardiology",       "EMERGENCY"});
    rules.push_back({"heart",        "Cardiology",       "EMERGENCY"});
    rules.push_back({"breathless",   "Pulmonology",      "URGENT"});
    rules.push_back({"cough",        "Pulmonology",      "NORMAL"});
    rules.push_back({"fever",        "General Medicine", "NORMAL"});
    rules.push_back({"headache",     "Neurology",        "NORMAL"});
    rules.push_back({"fracture",     "Orthopedics",      "URGENT"});
    rules.push_back({"burn",         "Plastic Surgery",  "EMERGENCY"});
    rules.push_back({"stomach",      "Gastroenterology", "NORMAL"});
    rules.push_back({"eye",          "Ophthalmology",    "NORMAL"});
    rules.push_back({"child",        "Pediatrics",       "URGENT"});
    rules.push_back({"pregnant",     "Obstetrics",       "URGENT"});
}

// ============================================================
//  ASSESSMENT FUNCTION
//  Purpose: Analyze patient symptoms and give recommendation
// ============================================================

void TriageHelper::assess() {
    cout << "\n--- TRIAGE HELPER ---\n";
    cout << "Describe patient symptoms: ";
    
    string input;
    getline(cin, input);
    
    // Convert input to lowercase for matching
    string lowerInput = input;
    transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);
    
    bool found = false;
    
    // Loop through all rules
    for (int i = 0; i < (int)rules.size(); i++) {
        // Check if symptom keyword exists in input
        if (lowerInput.find(rules[i].keyword) != string::npos) {
            // Found matching symptom
            cout << "\n  Recommended Department : " << rules[i].department << "\n";
            cout << "  Urgency Level         : " << rules[i].urgency << "\n";
            
            // Special warning for emergency cases
            if (rules[i].urgency == "EMERGENCY") {
                cout << "  *** SEND TO EMERGENCY ROOM IMMEDIATELY ***\n";
            }
            
            found = true;
            break;  // Stop searching after first match
        }
    }
    
    // If no match found, recommend General Medicine
    if (!found) {
        cout << "\n  Recommended Department : General Medicine\n";
        cout << "  Urgency Level         : NORMAL\n";
    }
}
