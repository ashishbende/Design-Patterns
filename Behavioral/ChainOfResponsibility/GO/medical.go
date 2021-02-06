package main

import "fmt"

type medical struct {
	next iDepartment
}

func (m *medical) execute(p *patient) {
	if p.medicineDone {
		fmt.Println("Medicine already given to the patient")
		m.next.execute(p)
		return
	}
	fmt.Println("Medical giving medicine to the patient")
	p.medicineDone = true
	m.next.execute(p)
}

func (m *medical) setNext(next iDepartment) {
	m.next = next
}
