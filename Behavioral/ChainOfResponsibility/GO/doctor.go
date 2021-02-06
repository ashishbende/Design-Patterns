package main

import "fmt"

type doctor struct {
	next iDepartment
}

func (d *doctor) execute(p *patient) {
	if p.doctorCheckupDone {
		fmt.Println("Doctor check up already done")
		d.next.execute(p)
		return
	}
	fmt.Println("Doctor checking the patient")
	p.doctorCheckupDone = true
	d.next.execute(p)
}

func (d *doctor) setNext(next iDepartment) {
	d.next = next
}
