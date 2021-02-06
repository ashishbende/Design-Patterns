package main

// concrete implementation

import "fmt"

type hp struct{}

func (p *hp) printFile() {
	fmt.Println("HP Printer : ... printing")
}
