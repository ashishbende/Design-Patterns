package main

// a face for multiple interfaces with complexity
// like a building entrance

import "fmt"

type walletFacade struct {
	account      *account
	wallet       *wallet
	securityCode *securityCode
	notification *notification
	ledger       *ledger
}

func newWalletFacade(accountId string, code int) *walletFacade {
	fmt.Println("Creating a new account")
	walletFacade := &walletFacade{
		account:      newAccount(accountId),
		securityCode: newSecurityCode(code),
		wallet:       newWallet(),
		notification: &notification{},
		ledger:       &ledger{},
	}
	fmt.Println("Account created - ")
	return walletFacade
}

func (w *walletFacade) addMoneyToWallet(accoundId string, securityCode int, amount int) error {
	fmt.Println("adding money to wallet")
	err := w.account.checkAccount(accoundId)
	if err != nil {
		return err
	}

	err = w.securityCode.checkCode(securityCode)
	if err != nil {
		return err
	}
	w.wallet.creditBalance(amount)
	w.notification.sendWalletCreditNotification()
	w.ledger.makeEntry(accoundId, "credit", amount)
	return nil
}

func (w *walletFacade) deductMoneyFromWallet(accountId string, securityCode int, amount int) error {
	fmt.Println(" Deducting amonunt from account")
	err := w.wallet.debitBalance(amount)
	if err != nil {
		return err
	}

	err = w.securityCode.checkCode(securityCode)
	if err != nil {
		return err
	}
	err = w.wallet.debitBalance(amount)
	if err != nil {
		return err
	}

	w.notification.sendWalletDebitNotification()
	w.ledger.makeEntry(accountId, "debited", amount)
	return nil
}
