package main

// refined abstraction of computer

import "fmt"

type windows struct {
	printer iPrinter
}

func (w *windows) print() {
	fmt.Println("Windows requesting print")
	w.printer.printFile()
}

func (w *windows) setPrinter(p iPrinter) {
	w.printer = p
}
