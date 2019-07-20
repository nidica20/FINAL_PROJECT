#ifndef NURSE_H_
#define NURSE_H_
#include "Caregiver.h"

class Nurse : public Caregiver {
    private:
        int num_of_caregivers;
        int treatment_time;

    public:
        Nurse() : Caregiver() {} //No-arg constructor

        //Getters
        int get_num_of_caregivers()
        {
            return num_of_caregivers; //returns the number of nurses
        }

        int get_treatment_time()
        {
            return treatment_time; //returns the treatment time it takes the nurses for a patient
        }

        //Setters
        void set_num_of_caregivers(int num_of_caregivers)
        {
            this->num_of_caregivers = num_of_caregivers;
        }

        int set_treatment_time()
        {
            return rand() % 20 + 1; //nurses will be allowed to take between 1 and 10 minutes to treat patients
        }
};

#endif