/************************************************************
 * Author       :Charity Manns
 * Program       :hw2, q2
 * Date Created  :February 17, 2025,
 * Last Modified :February 20, 2025
 * Usage         :Testing Check Inputs
 * Problem       :this will not run no matter what
 * reason: unknown.
 *
 ************************************************************/
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
// 2a) strut named check
struct Check {
    Check(): CheckAmount(0), CheckNum(0), CheckMemo(""){}
    float CheckAmount ;
    float CheckNum;
    string CheckMemo;

    friend ostream& operator<<(ostream& os, const Check& check) {
        os << check.CheckMemo;
        return os;

    }
    bool operator<(float balance) const {
        return CheckAmount < balance;
    }
};
// 2b) checkbook class
class Checkbook {
private:
    float balance, lastDeposit;
    Check *chkPtr;
    int numOfChecks, checkBookSize;

public:
    void setCheckAmount(float amount) {balance = amount;}
    int getCheckAmount(int CheckAmount) {return CheckAmount;}
    void setCheckNum(float CheckNum);
    float getCheckNum(int CheckNum) {return CheckNum;}
    void setBalance(float balance);
    float getBalance() { return balance;}
    void setNumOfChecks(int numOfChecks);
    int getNumOfChecks() {return numOfChecks;}
    void setcheckBookSize(int checkSize);
    int getCheckBookSize() {return checkBookSize;}
    void setlastDeposit(double lastDeposit);
    double getlastDeposit() {return lastDeposit;}
    void writeCheck(int c_amount);
    // defualt constructor
    Checkbook(): balance(0), numOfChecks(0), checkBookSize(4) {
        chkPtr = new Check[checkBookSize];}
    //second construtor
    Checkbook(const float intbalnce): balance(intbalnce), numOfChecks(0), checkBookSize(2) {
        chkPtr = new Check[checkBookSize];}
    //destroy
    ~Checkbook() {delete[] chkPtr;}
    //copy constructor
    Checkbook(const Checkbook& object): balance(object.balance) , numOfChecks(object.numOfChecks), checkBookSize(object.checkBookSize) {
        chkPtr = new Check[checkBookSize];
        for (int i = 0; i < checkBookSize; i++) {
            chkPtr[i] = object.chkPtr[i];
        }
    }
    // overload
    Checkbook operator=(const Checkbook& object) {
        if (this != &object) {
            delete[] chkPtr;
            chkPtr = new Check[checkBookSize];
            balance = object.balance;
            numOfChecks = object.numOfChecks;
            checkBookSize = object.checkBookSize;
            for (int i = 0; i < checkBookSize; i++) {
                chkPtr[i] = object.chkPtr[i];}}return *this;}
    void deposit(float amount ) {balance= balance+ amount;}
    bool writeCheck( Check c_amount) {
        if (c_amount.CheckAmount < balance) {
            string memo[]={ "Baby Shower", "Dinner Out ", "Surprise Party", "Movies", "High school Play" };
            c_amount.CheckMemo = memo[rand()%5];
            c_amount.CheckNum= numOfChecks+1;
            chkPtr[numOfChecks] = c_amount;
            numOfChecks++;
            balance -= c_amount.CheckAmount;
            return false;
        }
        if (numOfChecks >= checkBookSize/2) {
            cout<<"Attention:: You have ordered a new CheckBook."<<endl;
        }

        return true;
    }

    void  displayChecks() const  {
        if (numOfChecks ==0) {
            cout <<" There is no checks that are written";
        }
    }
    float getbalance () const {return balance;}
    int getnumOfChecks() const  {return numOfChecks;}
     int getcheckBookSize() const {return checkBookSize;}

};
void Checktest(Checkbook& cb, float depositamount) {
    cout << "Starting Test..."<<endl;
    cb.deposit(depositamount);
    while (cb.getBalance() < 10) {
        cb.writeCheck(10);
    }
  cout <<"Final Balance is: $" << cb.getbalance()<< endl;
    cb.displayChecks();
}

int main() {
    Checkbook cb;
    cb.setCheckAmount(200);
    Checktest(cb, 1000);
    cb.displayChecks();
    return 0;

}
