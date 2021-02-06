package main

// abstraction - has hierarchy

type iComputer interface {
	print()
	setPrinter(iPrinter)
}
