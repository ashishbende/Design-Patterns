package main
// refined abstraction of computer

import "fmt"

type mac struct {
	printer iPrinter
}

func (m *mac) print() {
	fmt.Println("Mac requesting print")
	m.printer.printFile()
}

func (m *mac) setPrinter(p iPrinter) {
	m.printer = p
}
