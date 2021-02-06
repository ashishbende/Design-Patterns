package main

// an abstraction on tree/hierarchy of objects
// on which user can perform some operation

type iComponent interface {
	search(string)
}
