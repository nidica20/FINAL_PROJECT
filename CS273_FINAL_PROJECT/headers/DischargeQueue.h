#ifndef DISCHARGEQUEUE_H_
#define DISCHARGEQUEUE_H_
#include <queue>
#include "WaitingRoomQueue.h"
#include "Patient.h"
#include "EmergencyRoom.h"

class DischargeQueue {
    private:
        int discharge_time;
        int visit_time;
        int patients_treated;
        std::queue<Patient *> queueOfDoctors;
        std::queue<Patient *> queueOfNurses;
    
    public:
        DischargeQueue() //Constructor
        {
            visit_time = 0;
            patients_treated = 0;
        }

        //Getters
        int getVisitTime()
        {
            return visit_time; //returns the visit time of a patient to the emergency room
        }

        int getDischargeTime()
        {
            return discharge_time; //returns time patient leaves the emergency room
        }

        int getNumOfPatientsTreated()
        {
            return patients_treated; //returns number of patients treated
        }

        //Setters
        void setVisitTime(Patient *patient)
        {
            visit_time = (patient->discharge_time) - (patient->time_of_arrival);
            //set the visit time with when the patient was able to leave emergency room versus when they arrived at emergency room
        }

        void setPatientsTreated()
        {
            patients_treated++; //every time a patient is treated, it increments
        }

        //To update the queue
        void update(int clock)
        {
            //Updates the queue of doctors
            if (!queueOfDoctors.empty())
            {
                Patient *patient = queueOfDoctors.front();
                patient->discharge_time = clock;
                queueOfDoctors.pop();
                setVisitTime(patient);
                setPatientsTreated();
            }

            //Updates the queue of nurses
            if (!queueOfNurses.empty())
            {
                Patient *patient = queueOfNurses.front();
                patient->discharge_time = clock;
                queueOfNurses.pop();
                setVisitTime(patient);
                setPatientsTreated();
            }
        }

    friend class TreatmentQueue;
};

#endif