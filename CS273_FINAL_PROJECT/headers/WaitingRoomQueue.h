#ifdef WAITINGROOMQUEUE_H_
#define WAITINGROOMQUEUE_H_
#include <queue>
#include "RandomsGenerator.h"
#include "EmergencyRoom.h"
#include "Patient.h"
#include "AllPatients.h"
#include "DischargeQueue.h"
#include "PatientRecords.h"
#include <vector>

class WaitingRoomQueue : public PatientRecords {
    private:
        std::queue<Patient *> queueOfDoctors;
        std::queue<Patient *> queueOfNurses;
        double patients_per_hour;
        int num_of_doctors;
        int num_of_nurses;
        int visit_time;
        int patients_treated;
        Random randomnumber;
        AllPatients all_patients;
        Doctor doctor;
        Nurse nurse;
        Patient patient;
        std::vector<std::string> firstNames;
        std::vector<std::string> lastNames;
    
    public:
        WaitingRoomQueue() //No-arg constructor
        {
            visit_time = 0;
            patients_treated = 0;
            num_of_doctors = 0;
            num_of_nurses = 0;
        }

        //Getters
        std::string getFirstName(int number)
        {
            return firstNames[number]; 
        }

        std::string getLastName(int number)
        {
            return lastNames[number];
        }

        double getPatients()
        {
            return patients_per_hour; //returns the amouont of patients that show up in the emergency room per hour
        }

        int get_num_of_doctors(int num_of_doctors)
        {
            return num_of_doctors; //returns the number of doctors available or are in the emergency room or hospital
        }

        int get_num_of_nurse(int num_of_nurses)
        {
            return num_of_nurses; //returns the number of nurses available or are in the emergency room or hospital
        }

        //Setters
        void set_num_of_patients_per_hour(double patients_per_hour)
        {
            this->patients_per_hour = patients_per_hour;
        }

        //Passing in information of vectors for first and last names
        void setFirstNameVector(std::vector<std::string> firstNames)
        {
            this->firstNames = firstNames;
        }

        void setLastNameVector(std::vector<std::string> lastNames)
        {
            this->lastNames = lastNames;
        }

        //Updated queue
        void addToQueue(int clock)
        {
            double patients_per_minute = (patients_per_hour / 60.0);
            if (randomnumber.nextDouble() < patients_per_minute)
            {
                int number = randomnumber.next_int(2000); //getting a random person/patient with first and last name
                int illness_level = patient.setIllnessLevel(); //total treatment time of random person/patient
                int treatment_from_doctor = doctor.set_treatment_time(); //setting treatment time for the doctor
                int treatment_from_nurse = nurse.set_treatment_time(); //setting treatment time for the nnurse

                if (num_of_doctors > 0 || num_of_nurses > 0)
                {
                    if (illness_level > 10 && num_of_doctors > 0)
                    {
                        queueOfDoctors.push(new Patient(clock, getFirstName(number), getLastName(number), treatment_from_doctor));
                        addRecords(new Patient(clock, getFirstName(number), getLastName(number), treatment_from_doctor), illness_level, getFirstName(number));
                    } else if (illness_level < 11){
                        queueOfNurses.push(new Patient(clock, getFirstName(number), getLastName(number), treatment_from_nurse));
                        addRecords(new Patient(clock, getFirstName(number), getLastName(number), treatment_from_nurse), illness_level, getFirstName(number));
                    }
                }
            }
        }

        friend class TreatmentQueue;
};

#endif