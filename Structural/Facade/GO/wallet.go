package main

import "fmt"

type wallet struct{
	balance int
}

func newWallet()*wallet{
	return &wallet{
		balance: 0,
	}
}

func (w *wallet) creditBalance(amount int){
	w.balance += amount
	fmt.Println(amount, " credited to account")
	return
}

func (w *wallet) debitBalance(amount int) error{
	if(w.balance-amount < 0){
		return fmt.Errorf("Insufficient balance")
	}

	fmt.Println("Despending amount from  account")
	w.balance -= amount
	return nil
}