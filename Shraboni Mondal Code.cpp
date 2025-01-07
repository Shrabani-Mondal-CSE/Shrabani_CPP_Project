friend void showInfo(BankAccount account);

};
void showInfo(BankAccount account)
    {
        cout<<"Account Holder Name : "<<account.UserName<<endl;
        cout<<"Account Number  : "<<account.accountNum<<endl;
        cout<<"Balance  : "<<account.balance<<endl;


    }
    class person : public BankAccount
    {
        public:
        person(string name,int num,double bal):BankAccount(name,num,bal)
        {

        }
        void CheckBalance()
    {
        cout<<"Updated Balance : "<<balance<<endl;
    }
    };
