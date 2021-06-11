#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <array>

class Account{
    public:
        explicit Account(double balance)  : mBalance(balance) {}

        double getBalance() const  {  
            std::lock_guard<std::mutex> lg(mBalance_mut);
            return  mBalance; 
            }

        void deposit(double amount) { 
            std::lock_guard<std::mutex> lg(mBalance_mut);
            mBalance += amount; 
            }

        void withdraw(double);
    private:
        double mBalance;
        std::mutex mBalance_mut;
};

void Account::withdraw(double amount) {
    std::lock_guard<std::mutex> lg(mBalance_mut);
    if(mBalance < amount){
         std::cout << "Insufficient balance, withdraw denied." << std::endl;
         return;
    }
    mBalance -= amount;
}


// Globalni objekt
Account acc(1000);  // Account::mBalance.
//std::mutex acc_mut;

// dodaj puno malih depozita. RAII 
void task(){
    //std::lock_guard<std::mutex> lg(acc_mut);
    //acc_mut.lock();
    for(int i=1; i<=1000; ++i){
        acc.deposit(1.0);
    }
    //acc_mut.unlock();
}

int main(){
    // Kreiraj 5 programskih niti koje će dodavati depozite
    std::array<std::thread, 5> thrds;
    for(auto & x : thrds)
         x = std::thread(task);

    for(auto & x : thrds)
         x.join();

    std::cout << acc.getBalance() << " (=6000)\n";
    return 0;
}
