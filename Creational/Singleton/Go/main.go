package main

import "fmt"

func main(){
	for i:=0; i<10000; i++{
		go getInstance()
	}
	fmt.Scanln()
}
