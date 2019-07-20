#ifndef CAREGIVER_H_
#define CAREGIVER_H_
#include "EmergencyRoom.h"

class Caregiver {
    private:
        int treatment_time;
        int number_of_caregivers;
    public:
        Caregiver() {} // No argument constructor

        // Polymporphism
        virtual int get_num_of_caregivers() = 0;
        virtual int get_treatment_time() = 0;
        virtual int set_treatment_time() = 0;
        virtual void set_num_of_caregivers(int number_of_caregivers) = 0;
};

#endif