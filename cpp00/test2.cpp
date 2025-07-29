#include <iostream>
#include <string>

class BankAccount{
    private:
        std::string accountNumber;
        std::string ownerName;
        double balance;
    public:
        BankAccount(std::string name, std::string accNum)
        {
            balance = 0.0;
            ownerName = name;
            accountNumber = accNum;
        }
        void deposit(double amount)
        {
            if (amount > 0)
            {
                balance += amount;
                std::cout << "Amount: " << amount << " deposited Succesfully !" << std::endl;
            }
            else
            {
                std::cout << "The amount has to be positive" << std::endl;
            }
        }
        bool withdraw(double amount)
        {
            if (amount > 0)
            {
                if (amount <= balance)
                {
                    balance -= amount;
                    std::cout << "Amount: " << amount << " has been withdraw sucessfully!" << std::endl;
                    return true;
                } 
                std::cout <<"Sorry you dont have enough balance !";
                return false;
            }
            else 
                std::cout << "Sorry the amount has to be possitive" << std::endl;
                return false;
        }
        double getBalance()
        {
            return (balance);
        }
        std::string getOwnerName()
        {
            return (ownerName);
        }
        std::string getAccountNumber()
        {
            return (accountNumber);
        }
        void displayInfo()
        {
            std::cout << "Acount N: " << accountNumber << std::endl;
            std::cout << "Owner: " << ownerName << std::endl;
            std::cout << "Balance: " << balance << std::endl;
        }
};



int main(void)
{
    BankAccount acc1("Sims", "1501-456615-65136-241");
    acc1.deposit(100);
    acc1.withdraw(25);
    acc1.displayInfo();
}