package main

import (
	"fmt"
	"sync"
)


var mtxLock = &sync.Mutex{}

type single struct{}

var singleInstance *single

func getInstance() *single{
	if singleInstance == nil{
		mtxLock.Lock()
		defer mtxLock.Unlock()
		if singleInstance != nil{
			// possible if more than one goroutine tries to access instance on first go
			// before the object is even initialized
			fmt.Println("How the heck I got here???")
		}
		singleInstance = &single{}
		fmt.Println("creating single instance!")
	}else{
		fmt.Println("Single instance already created!")
	}
	return singleInstance
}

