package main

type iIterator interface {
	hasNext() bool
	getNext() *user
}
