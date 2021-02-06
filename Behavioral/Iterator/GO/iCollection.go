package main

type iCollection interface {
	createIterator() iIterator
}
