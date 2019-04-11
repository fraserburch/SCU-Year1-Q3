#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <queue>

using namespace std;
typedef pair<double,double> student;
double exp_rand(double rate);


double average_waiting_time(double arrival_rate, double service_rate, std::size_t N){
    queue<student> studQueue;
    double currTime = exp_rand(arrival_rate);
    double arrivalTime = currTime;
    double serviceTime = exp_rand(service_rate);
    studQueue.push(student(arrivalTime, serviceTime)); //For first student arrives at 1 PM;

    //Filling Queue
    for(std::size_t i = 1; i < N; ++i){
        currTime = currTime + exp_rand(arrival_rate);
        serviceTime = exp_rand(service_rate);
        studQueue.push(student(currTime, exp_rand(service_rate)));
    }

    //Popping and Summing
    double firstTime;
    double tempWaitTime;
    double waitTimeTotal;
    student firstStud = studQueue.front();
    studQueue.pop();
    student secondStud;
    for(std::size_t i = 1; i < N; ++i){
      secondStud = studQueue.front();
      studQueue.pop();
      firstTime = firstStud.first + firstStud.second;
      tempWaitTime = firstTime - secondStud.first;
      if(tempWaitTime > 0){
        waitTimeTotal += tempWaitTime;
        secondStud.second += tempWaitTime;
      }
      else{
        waitTimeTotal += 0;
      }
      firstStud = secondStud;
    }


    return (waitTimeTotal/N);


}



double exp_rand(double rate){
   double u;
   do{
     u = rand()/static_cast<double>(RAND_MAX);
   }
   while (u == 0.0 || u == 1.0);
   return -log(u)/rate;
}



int main(){

srand(time(0));

const std::size_t N(1000000);



cout << average_waiting_time(1.0, 5.0, N) << endl;

cout << average_waiting_time(1.0, 3.0, N) << endl;

cout << average_waiting_time(1.0, 2.0, N) << endl;

cout << average_waiting_time(1.0, 1.5, N) << endl;

cout << average_waiting_time(1.0, 1.1, N) << endl;

cout << average_waiting_time(1.0, 1.05, N) << endl;

cout << average_waiting_time(1.0, 1.025, N) << endl;



return 0;



}
