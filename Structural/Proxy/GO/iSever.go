package main

type iServer interface {
	handleRequest(string, string) (int, string)
}
