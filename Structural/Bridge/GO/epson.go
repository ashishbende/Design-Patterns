package main

// concrete implementation

import "fmt"

type epson struct{}

func (p *epson) printFile(){
	fmt.Println("EPSON printer: ... printing")
}