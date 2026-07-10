#ifndef TRIAGEHELPER_H
#define TRIAGEHELPER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ============================================================
//  RULE-BASED TRIAGE HELPER
//  Purpose: AI-like symptom checker for emergency triage
//  Contributed by: Shahesh (Mentor)
// ============================================================

class TriageHelper {
private:
    // Structure to store each symptom rule
    struct Rule {
        string keyword;     // Symptom keyword to match
        string department;  // Recommended department
        string urgency;     // Urgency level (EMERGENCY/URGENT/NORMAL)
    };
    
    vector<Rule> rules;  // List of all symptom rules

public:
    // ============================================================
    //  CONSTRUCTOR
    //  Purpose: Initialize the rule database
    // ============================================================
    TriageHelper();

    // ============================================================
    //  ASSESSMENT FUNCTION
    //  Purpose: Analyze symptoms and recommend department
    // ============================================================
    void assess();
};

#endif
