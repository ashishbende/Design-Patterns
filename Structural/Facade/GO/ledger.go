package main

import "fmt"

type ledger struct{}

func (s *ledger) makeEntry(accountId, txnType string, amount int) {
	fmt.Printf("Make ledger entry for accountId %s with transaction type %s for amount %d", accountId, txnType, amount)
	return
}
