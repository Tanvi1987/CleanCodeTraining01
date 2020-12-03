// Link : https://github.com/getmubarak/cleancode/blob/master/transfer.java
// The assignment was to clean up the above code . Assignment complete. 

class Account
{
  void Populate()
  {
    if ( !rs.next() ) 
    {
        throw new RuntimeException("....");
    }
    // Populate account from db
  }

  void CheckDebitAllowed(BigDecimal amount)
  {
    BigDecimal sourceBalanceAfterDebit = mBalance - amount;

    if ( sourceBalanceAfterDebit < 0 )
    {    
      if ( !mIsOverdraftAllowed ) 
      {
        throw new RuntimeException("Insufficient Balance");
      }
      else if ( (-1*sourceBalanceAfterDebit) > mOverdraftAmount ) 
      {
        throw new RuntimeException("Insufficient Balance, Exceeding Overdraft Limit");
      }
    }  
  }

}

public class UglyMoneyTransferService 
{
  private :

  void CheckDuplicateTransaction(Account* source, Account* target, BigDecimal amount, bool allowDuplicateTxn)
  {
    if ( allowDuplicateTxn )
      return; 
    
    AccountTransaction lastTxn = .. ; //JDBC code to obtain last transaction of sourceAccount
    if ( lastTxn && lastTxn.getTargetAcno().equals(targetAccount.getAcno()) && lastTxn.getAmount() == amount) 
    {
        throw new RuntimeException("Duplicate transaction exception");
    }    
  }

  public : 

  void transferFunds(Account* source, Account* target, BigDecimal amount, bool allowDuplicateTxn)
  {
    source->Populate(source);
    target->Populate(target);

    source->CheckDebitAllowed(amount);
    CheckDuplicateTransaction (sourceAccount, targetAccount, amount, allowDuplicateTxn);
    
    source->debit(amount);
    target->credit(amount);
  }
}
