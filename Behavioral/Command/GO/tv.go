package main

import "fmt"

type tv struct {
	isRunning bool
}

func (t *tv) on() {
	t.isRunning = true
	fmt.Println("TV is on!")
}

func (t *tv) off() {
	t.isRunning = false
	fmt.Println("TV is off!")
}
