#ifndef PATIENTRECORDS_H_
#define PATIENTRECORDS_H_
#include "Patient.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <map>

struct PatientRecords {

    std::vector<Patient *> records;
    std::vector<int> illnessPerVisit;
    std::map <std::string, std::vector<int>> patientRecordsMap;
    std::string name;

    PatientRecords() {} //No-arg constructor

    //Constructor
    PatientRecords(std::vector<Patient *> records, std::vector<int> illnessPerVisit)
    {
        this->records = records;
        this->illnessPerVisit = illnessPerVisit;
    }

    //Adding patients records in WaitingRoomQueue class
    void addRecords(Patient * patient, int illnessLevel, std::string name)
    {
        records.push_back(patient);
        this->name = name;
        illnessPerVisit.push_back(illnessLevel);
        patientRecordsMap.insert(std::pair <std::string, std::vector<int>>(name, illnessLevel));
    }

    //Lists all patients
    void listAllPatients()
    {
        std::map<std::string, std::vector<int>>::iterator iter;
        int numOfPatientsTreated = 0;
        for (iter = patientRecordsMap.begin(); iter != patientRecordsMap.end(); iter++)
        {
            std::cout << "First name: " << iter->first << "Illness Level: " << iter->second << std::endl;
            //Displays the first name and illness level of patient
            numOfPatientsTreated++; //Counts everytime a patient is treated
        }
    }
};

#endif