package main

import (
	"fmt"
	"log"
)

func main() {
	walletFacade := newWalletFacade("abc", 123)
	err := walletFacade.addMoneyToWallet("abc", 124, 10)
	if err != nil {
		log.Fatalf("Error : %s\n", err.Error())
	}

	fmt.Println()
	err = walletFacade.deductMoneyFromWallet("abc", 123, 5)
	if err != nil {
		log.Fatalf("Error: %s\n", err.Error())
	}
}
