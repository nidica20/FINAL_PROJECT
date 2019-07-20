#ifndef DOCTOR_H_
#define DOCTOR_H_
#include "Caregiver.h"

class Doctor : public Caregiver {
    private:
        int num_of_caregivers;
        int treatment_time;
    
    public:
        Doctor() : Caregiver() {} //No-arg constructor

        //Getters
        int get_num_of_caregivers() 
        {
            return num_of_caregivers; //returns the number of doctors
        }

        int get_treatment_time()
        {
            return treatment_time; //returns the time it takes to treat a patient
        }

        //Setters
        void set_num_of_caregivers(int num_of_caregivers)
        {
            this->num_of_caregivers = num_of_caregivers;
        }

        int set_treatment_time()
        {
            return rand() % 20 + 1; //allowing the doctors to only take between 1 to 20 minutes
        }
};

#endif