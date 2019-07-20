#ifndef WAITINGROOMQUEUE_H_
#define WAITINGROOMQUEUE_H_
#include "RandomsGenerator.h"
#include "WaitingRoomQueue.h"
#include "DischargeQueue.h"
#include "AllPatients.h"
#include "TreatmentQueue.h"
#include "PatientRecords.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <limits>

class EmergencyRoom {
    private:
        int clock;
        int num_of_doctors;
        int num_of_nurses;
        int num_of_patients_per_hour;
        int time_in_one_week;

        WaitingRoomQueue *waitingRoomQueue;
        DischargeQueue *dischargeQueue;
        TreatmentQueue *treatmentQueue;
        Random randomNumber;
        AllPatients *allPatients;
        PatientRecords *patientRecords;
    
    public:
        EmergencyRoom() //No-arg constructor
        {
            waitingRoomQueue = new WaitingRoomQueue();
            dischargeQueue = new DischargeQueue();
            allPatients = new AllPatients();
            treatmentQueue = new TreatmentQueue();
            clock = 0;
            num_of_doctors = -1;
            num_of_nurses = -1;
            num_of_patients_per_hour = -1;
            time_in_one_week = 10080; //amount of minutes in a week
        }

        //Getters
        int get_num_of_doctors()
        {
            return num_of_doctors;
        }

        int get_num_of_nurses()
        {
            return num_of_nurses;
        }

        int get_num_of_patients_per_hour()
        {
            return num_of_patients_per_hour;
        }

        //Setters
        void set_num_of_doctors(int num_of_doctors)
        {
            this->num_of_doctors = num_of_doctors;
        }

        void set_num_of_nurses(int num_of_nurses)
        {
            this->num_of_nurses = num_of_nurses;
        }

        void set_num_of_patients_per_hour(int num_of_patients_per_hour)
        {
            this->num_of_patients_per_hour = num_of_patients_per_hour;
        }

        //Exception Handling
        int readInt(const std::string &prompt, int low, int high)
        {
            if (low >= high) //checking for an invalid range
            {
                throw std::invalid_argument("Invalid range! This emergency room can only help a max of 60 people and a minimum of 1 person, while having 100 doctors and 100 nurses on staff.")
            }

            std::cin.exceptions(std::ios_base::failbit);
            int num = 0;
            while (true)
            {
                try
                {
                    while(true)
                    {
                        std::cout << prompt;
                        std::cin >> num;
                        if (num >= low && num <= high) //Within the specified range
                        {
                            std::cout << std::endl;
                            return num;
                        }
                    }
                }
                catch (std::ios_base::failure)
                {
                    std::cout << "Bad numeric string -- try again\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                }
            }
        }

        //User data input via simualtion choosing
        void enteringData()
        {
            this->allPatients->addPeopleToVector();
            std::cout << "Hello and welcome to the Shriners Hospital Emergency Room located in CS273Ville! We are committed to helping anyone that needs it! " << std::endl;
            num_of_patients_per_hour = readInt("Please input how many patients are arriving at Shriners per hour: ", 1, 60);
            num_of_doctors = readInt("Please input the amount of doctors that will be on staff: ", 1, 100);
            num_of_nurses = readInt("Please input the amount of nurses that will be on staff: ", 1, 100);

            // Set
        }

        //Running the simulation
        void runShrinersSimulation()
        {
            while (clock < time_in_one_week)
            {
                waitingRoomQueue->addToQueue(clock);
                treatmentQueue->update(clock);
                dischargeQueue->update(clock);
                clock++;
            }
        }

        //Showing Shriner's Emergency Room Statistics
        void showingStatistics()
        {
            std::cout << "Shriner's Emergency Room has treated " << dischargeQueue->getNumOfPatientsTreated() << " patients this past week." << std::endl;
            std::cout << "The average visit time at Shriner's was: " << dischargeQueue->getDischargeTime() << " minutes. " << std::endl;
            std::cout << "Please select from the options below to view more statistics about Shriner's Emergency Room Simulation: " << std::endl;
            menu();
        }

        void menu()
        {
            int option;
            option = readInt("1. List all patients treated at Shriner's.\n2.Retrieve a patient's record by entering his or her name\n3.End the simulation.\n", 1, 3);
            switch (option % 4)
            {
                case 1:
                    std::cout << "Patients that have been treated: ";
                    patientRecords->listAllPatients();
                    menu();
                    break;

                case 2:
                    std::cout << "Please enter the name of a patient you would like to see records of: ";
                    std::string name;
                    cin >> name;
                    if (std::find(patientRecords->records.begin(), patientRecords->records.end(), name) != patientRecords->records.end())
                    {
                        std::cout << patientRecords->records.at(name) << std::endl;
                    }else {
                        std::cout << "Patient's name could not be found, sorry." << std::endl;
                    }
                    menu();
                    break;
                case 3:
                    std::cout << "End of the programmed simulation. " << std::endl;
                    exit(0);
                    break;
                default: break;
            }
        }
};

#endif