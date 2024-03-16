#include <cstdio>
#include <stdexcept>
#include <map>
#include <algorithm>

struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
    virtual void display_balance(long account_id, double balance) = 0;
};

struct AccountDatabase {
    virtual double retrieve_balance(long bank_account_id) = 0;
    virtual void set_balance(long bank_account_id, double new_balance) = 0;
};

struct Bank {
    Bank(Logger* logger, AccountDatabase& account_database) :
        logger { logger },
        account_database { account_database} {}

    void set_logger(Logger* new_logger) {
        logger = new_logger;
    }

    void make_transfer(long from, long to, double amount) {
        auto balance_source = account_database.retrieve_balance(from);
        account_database.set_balance(from, balance_source - amount);
         
        auto balance_destination = account_database.retrieve_balance(to);
        account_database.set_balance(to, balance_destination + amount);

        if (logger) {
            logger->log_transfer(from, to, amount);
            logger->display_balance(from, account_database.retrieve_balance(from));
            logger->display_balance(to, account_database.retrieve_balance(to));
        }
    }
private:
    Logger* logger;
    AccountDatabase& account_database;
};

struct ConsoleLogger : Logger {
    ConsoleLogger(const char* identifier) :
        identifier { identifier } {}

    void log_transfer(long from, long to, double amount) override {
        printf("[%s] #%ld -> #%ld: %.2f\n", identifier, from, to, amount);
    }

    void display_balance(long account_id, double balance) {
        printf("[%s] #%ld = %.2f \n", identifier, account_id, balance);
    }
private:
    const char* identifier;
};

struct FileLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[file] #%ld,#%ld,%.2f\n", from, to, amount);
    }

    void display_balance(long account_id, double balance) {
        printf("[file] #%ld,%.2f \n", account_id, balance);
    }
};

struct InMemoryAccountDatabase : AccountDatabase {
    InMemoryAccountDatabase() :
        account_balances{
            {
                { 1000, 100.0 },
                { 2000, 100.0 },
                { 3000, 50.0 },
                { 4000, 10000.0 }
            }
        } {}

    double retrieve_balance(long bank_account_id) override {
        return account_balances.find(bank_account_id)->second;
    }

    void set_balance(long bank_account_id, double new_balance) override {
        account_balances.find(bank_account_id)->second = new_balance;
    }
private:
    std::map<long, double> account_balances;
};

int main() {
    ConsoleLogger console_logger{ "custom console id" };
    FileLogger file_logger;
    InMemoryAccountDatabase account_database;
    Bank bank{ &console_logger, account_database };
    bank.make_transfer(1000, 2000, 49.95);
    bank.set_logger(&file_logger);
    bank.make_transfer(3000, 4000, 20.00);
}