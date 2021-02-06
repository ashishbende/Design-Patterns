package main

import "fmt"

type cashier struct {
	next iDepartment
}

func (c *cashier) execute(p *patient) {
	if p.paymentDone {
		fmt.Println("Payment done. Good day!")
		return
	}
	fmt.Println("Cashier getting money from the patient.")
}

func (c *cashier) setNext(next iDepartment) {
	c.next = next
}
