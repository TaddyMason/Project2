// basic file operations
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>

#include "Customer.cpp"
#include "Event.cpp"
#include "PriorityQueue.cpp"
#include "RegisterQueue.cpp"
using namespace std;

class StoreSimulator{

private:
    MyPriorityQueue<Event> events;
    vector<RegisterQueue> registers;
    double simClock;

public:
    StoreSimulator(){
        simClock = 0;
    }

    void startSimulation() {
        loadRegisters( 8, 0); //<--Update this line as needed.  Currently all standard registers.
        loadCustomerData();

        while(events.size() > 0){
            Event e = events.remove();
            simClock = e.simTime;
            if(e.type == Arrival){
                handleArrival(e);
            }else if(e.type == EndShopping){
                handleEndShopping(e);
            }else{
                handleEndCheckout(e);
            }
        }

        statsHandling();

    }

    void loadCustomerData(){
        double arriveTime, avgSelectionTime;
        int items;
        ifstream myfile ("arrival.txt");
        if (myfile.is_open()){
            while ( myfile >> arriveTime >> items >> avgSelectionTime){

                Customer cust(arriveTime, items, avgSelectionTime) ;
                Event e(Arrival, arriveTime, cust);
                events.insert(e);
            }
            myfile.close();
        }else{
            throw(1);
        }
    }

    void loadRegisters(int numNormal, int numSelfScan){
        for(int i = 0; i < numNormal; i ++){
            RegisterQueue r(2.3, .02);
            registers.push_back(r);
        }
        for(int i = 0; i < numSelfScan; i++){
            RegisterQueue r(3.7, .08);
            registers.push_back(r);
        }
    }

    void handleArrival(Event& e){
        //You will fill in this method.
    }

    void handleEndShopping(Event& e){
        //You will fill in this method.
    }



    void handleEndCheckout(Event& e){
        //You will fill in this method.
    }

    int getShortestLine(){
        //You will fill in this method.
    }

    void statsHandling(){
        //You will fill in this method.
    }
};
